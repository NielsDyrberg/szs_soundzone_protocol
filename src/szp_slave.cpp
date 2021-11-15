//
// Created by ncpd on 08-11-2021.
//

#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
#include <cerrno>
#include <fcntl.h>

#include "szp_slave.h"

/**********************************************************************************************************************
 * Public methods
 **********************************************************************************************************************/

SZP_slave::SZP_slave(char* fifo_name) : sound_zone_protocol(comm_buffer, COMM_BUFFER_SIZE), dt(port, comm_buffer, COMM_BUFFER_SIZE) {
    this->fifo_name = fifo_name;
}

int SZP_slave::open_fifo() {
    int fd;
    fd = open(fifo_name, O_WRONLY);
    set_fifo(&fd);
    return 0;
}

/**********************************************************************************************************************/

int SZP_slave::recieve() {
    uint16_t tmp_msg_size;

    if (dt.receive(false) > 0) {
        tmp_msg_size = dt.get_buffer();
        p_buffer->set_write_head(tmp_msg_size);

        react_on_incoming();
    }
    return 0;
}

/**********************************************************************************************************************
 * Private methods
 **********************************************************************************************************************/

int SZP_slave::encode_and_send() {
    uint16_t tmp_msg_size;
    tmp_msg_size = sound_zone_protocol::encode_and_send();
    return dt.send(tmp_msg_size);
}

/**********************************************************************************************************************/

int SZP_slave::react_on_incoming() {
    decode(p_buffer);
    switch (cid) {
        case cid_check_connection:
            set_values(0x01);
            encode_and_send();
            return 0;
        case cid_send_sound_packet:
            return 0;
        default:
            return -1;
    }
}

