//
// Created by ncpd on 08-11-2021.
//

#include "szp_slave.h"

#define PORT 1695

/**********************************************************************************************************************
 * Public methods
 **********************************************************************************************************************/

SZP_slave::SZP_slave(uint8_t *comm_buffer, uint16_t buffer_size) : sound_zone_protocol(comm_buffer, buffer_size), dt(port, comm_buffer, buffer_size) {

}

/**********************************************************************************************************************/

int SZP_slave::recieve() {
    uint16_t tmp_msg_size;

    if (dt.receive(false) > 0) {
        tmp_msg_size = dt.get_buffer();
        p_buffer->set_write_head(tmp_msg_size);

        /* Debug start */
        p_buffer->print_buffer();
        /* Debug end */

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

