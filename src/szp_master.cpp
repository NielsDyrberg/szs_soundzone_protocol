//
// Created by ncpd on 08-11-2021.
//

#include <iostream>
#include "szp_master.h"

static unsigned int port = 1695;

SZP_master::SZP_master(char *host, bool is_ip, uint8_t *comm_buffer,
                       uint16_t buffer_size) : sound_zone_protocol(comm_buffer, buffer_size), dt(host, port, is_ip) {
}

int SZP_master::check_connection() {
    uint8_t* tmp_p_buffer;
    uint16_t tmp_buffer_size;

    SZP_master::cid = cid_check_connection;
    SZP_master::encode(p_buffer);
    p_buffer->get_written_buffer(&tmp_p_buffer, &tmp_buffer_size);

    if(dt.send_and_receive(tmp_p_buffer, tmp_buffer_size) > 0) {
        tmp_p_buffer = dt.GetBuffer(tmp_p_buffer, &tmp_buffer_size);
        for (int i = 0; i < tmp_buffer_size; i++) {
            std::cout << unsigned(*tmp_p_buffer) << std::endl;
            tmp_p_buffer++;
        }
    }
    return 0;
}