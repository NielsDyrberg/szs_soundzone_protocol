//
// Created by ncpd on 08-11-2021.
//

#include <iostream>

#include "szp_master.h"
/**********************************************************************************************************************
 * Static variables
 **********************************************************************************************************************/

static unsigned int port = 1695;
dt_type_t type = SZP;

/**********************************************************************************************************************
 * Public methods
 **********************************************************************************************************************/

SZP_master::SZP_master()= default;

SZP_master::SZP_master(char *host, bool is_ip): sound_zone_protocol(comm_buffer, COMM_BUFFER_SIZE), dt(type, host, port, is_ip, comm_buffer, COMM_BUFFER_SIZE) {
}

/**********************************************************************************************************************/

int SZP_master::check_connection() {
    int err;
    uint16_t tmp_buffer_size;

    SZP_master::cid = cid_check_connection;
    SZP_master::encode(p_buffer);
    tmp_buffer_size = p_buffer->get_write_head();

    if(dt.send_and_receive(tmp_buffer_size) > 0) {
        tmp_buffer_size = dt.get_buffer();
        p_buffer->set_write_head(tmp_buffer_size);
        err = decode(p_buffer);
        if(err < 0){
            return -1;
        }
    }
    return 0;
}

int SZP_master::send_sound_packet(uint8_t* buffer, uint16_t packet_size) {
    uint16_t tmp_buffer_size = 0;
    cid = cid_send_sound_packet;

        // todo Add song filtration here

    set_values(buffer, packet_size);
    encode(p_buffer);

    tmp_buffer_size = p_buffer->get_write_head();

    if(dt.send(tmp_buffer_size) < 0) {
        // Todo handle send failed.
        return -1;
    }
    return 0;
}

/**********************************************************************************************************************
 * Private methods
 **********************************************************************************************************************/

