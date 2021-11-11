//
// Created by ncpd on 08-11-2021.
//

#include <iostream>
#include "szp_master.h"

static unsigned int port = 1695;

/**********************************************************************************************************************
 * Public methods
 **********************************************************************************************************************/

SZP_master::SZP_master(char *host, bool is_ip, uint8_t *comm_buffer,
                       uint16_t buffer_size) : sound_zone_protocol(comm_buffer, buffer_size), dt(host, port, is_ip, comm_buffer, buffer_size) {
}

/**********************************************************************************************************************/

int SZP_master::check_connection() {
    uint16_t tmp_buffer_size;

    SZP_master::cid = cid_check_connection;
    SZP_master::encode(p_buffer);
    tmp_buffer_size = p_buffer->get_write_head();

    if(dt.send_and_receive(tmp_buffer_size) > 0) {
        tmp_buffer_size = dt.get_buffer();
        p_buffer->set_write_head(tmp_buffer_size);
        decode(p_buffer);
        p_buffer->print_buffer();
    }
    return 0;
}

int SZP_master::send_sound_packet(uint8_t* packet, uint16_t packet_size) {
    uint16_t tmp_buffer_size;

    cid = cid_send_sound_packet;
    set_values(packet, packet_size);
    encode(p_buffer);
    tmp_buffer_size = p_buffer->get_write_head();

    if(dt.send(tmp_buffer_size) > 0) {
        /* Debug start */
        std::cout << "Sent packet" << std::endl;
        /* Debug end */
    }
    return 0;
}

/**********************************************************************************************************************
 * Private methods
 **********************************************************************************************************************/

