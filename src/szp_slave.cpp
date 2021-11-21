/***********************************************************************************************************************
 * @name SZP_slave
 * @file szp_slave.cpp
 * @author Niels Dyrberg
 * @date 08-11-2021
 *
 * Purpose:
 *      Implement szp_slave class
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/

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
 * Static variables
 **********************************************************************************************************************/

static int port = 1695;
static dt_type_t type = SZP;
#ifdef DEBUG_SZP_SLAVE
static int packets_rcv;
#endif

/**********************************************************************************************************************
 * Public methods
 **********************************************************************************************************************/

SZP_slave::SZP_slave(char *fifo_name) : sound_zone_protocol(comm_buffer, COMM_BUFFER_SIZE),
                                        dt(type, port, comm_buffer, COMM_BUFFER_SIZE) {
    this->fifo_name = fifo_name;
    this->time_to_play = TIME_NOT_SET;

#ifdef DEBUG_SZP_SLAVE
    packets_rcv = 0;
#endif
}

/**********************************************************************************************************************/

SZP_slave::~SZP_slave() {
    // todo should probably destruct something.
#ifdef DEBUG_SZP_SLAVE
    std::cout << "Packets received: " << packets_rcv << std::endl;
#endif
}

/**********************************************************************************************************************/

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
#ifdef DEBUG_SZP_SLAVE
        packets_rcv++;
        std::cout << "Packets received: " << packets_rcv << std::endl;
#endif
        tmp_msg_size = dt.get_buffer();
        p_buffer->set_write_head(tmp_msg_size);

        react_on_incoming();
    }
    return 0;
}

/**********************************************************************************************************************/

int SZP_slave::get_time(long long int *time) {
    if (time_to_play == TIME_NOT_SET | time_to_play < (long long int) 0) {
        return -1;
    }
    *time = time_to_play;
    return 0;
}

/**********************************************************************************************************************
 * Private methods
 **********************************************************************************************************************/

/**
 * @brief Serializes the sound_zone_protocol object and the sends it.
 * @return int
 * @retval -1 if errors
 * @retval The number of bytes sent if successfully.
 */
int SZP_slave::encode_and_send() {
    uint16_t tmp_msg_size;
    tmp_msg_size = sound_zone_protocol::encode_and_get_size();
    return dt.send(tmp_msg_size);
}

/**
 * Reacts on a received message.
 * @return int
 * @retval 0 If successful.
 * @retval -1 If #cid not supported.
 */
int SZP_slave::react_on_incoming() {
    decode(p_buffer);
    switch (cid) {
        case cid_check_connection:
            set_values((uint8_t) 0x01);
            encode_and_send();
            return 0;
        case cid_send_sound_packet:
            get_values(&time_to_play);
            return 0;
        default:
            return -1;
    }
}

