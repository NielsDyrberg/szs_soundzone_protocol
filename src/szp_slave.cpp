//
// Created by ncpd on 08-11-2021.
//

#include "szp_slave.h"

#define PORT 1695

SZP_slave::SZP_slave(uint8_t *comm_buffer, uint16_t buffer_size) : sound_zone_protocol(comm_buffer, buffer_size), dt(port) {

}

int SZP_slave::check_connection() {
    uint8_t* tmp_p_buffer;
    uint16_t tmp_buffer_size;

    if (dt.receive(false) > 0) {
        tmp_p_buffer = dt.GetBuffer(tmp_p_buffer, &tmp_buffer_size);
        p_buffer->set_new_buffer(tmp_p_buffer, tmp_buffer_size);
        SZP_slave::decode(p_buffer);
        if(cid == cid_check_connection){
            SZP_slave::set_values(0x01);
            SZP_slave::encode(p_buffer);
        }
    }

    SZP_slave::cid = cid_check_connection;
    SZP_slave::encode(p_buffer);
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


while (true) {
    if (dt.receive(false) > 0) {
        bufPTR = dt.GetBuffer(bufPTR, &size);
        if (*bufPTR == 0x50) {
        dt.send(msg, sizeof(msg));
    }
    for (int i = 0; i < size; i++) {
        std::cout << unsigned(*bufPTR) << std::endl;
        bufPTR++;
    }
    std::cout << "data" << std::endl;
    } else{
        std::cout << "Client rerun" << std::endl;
    }
}