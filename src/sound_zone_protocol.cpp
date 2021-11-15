//
// Created by ncpd on 27-10-2021.
//

#include "sound_zone_protocol.h"

/**********************************************************************************************************************
 * Public methods
 **********************************************************************************************************************/

sound_zone_protocol::sound_zone_protocol() {
    this->cid = cid_notSet;
    check_connection = nullptr;
    send_sound_packet = nullptr;
    this->p_buffer = nullptr;
}

sound_zone_protocol::sound_zone_protocol(uint8_t* comm_buffer, uint16_t buffer_size) {
    this->cid = cid_notSet;
    check_connection = new xF1_check_connection();
    send_sound_packet = new x01_send_sound_packet();
    this->p_buffer = new buffer_t(comm_buffer, buffer_size);
}

/**********************************************************************************************************************/

int sound_zone_protocol::set_fifo(int* fifo_fd) {
    return send_sound_packet->set_fifo(fifo_fd);
}

/**********************************************************************************************************************/

int sound_zone_protocol::set_values(uint8_t value) {
    if(cid == cid_notSet){
        // CID has to be set.
        return -1;
    }
    switch (cid) {
        case cid_check_connection:
            check_connection->set_values(value);
            break;
        default:
            break;
    }
    return 0;
}

/**********************************************************************************************************************/

int sound_zone_protocol::set_values(uint8_t *values, uint16_t size){
    if(cid == cid_notSet){
        // CID has to be set.
        return -1;
    }

    switch (cid) {
        case cid_send_sound_packet:
            send_sound_packet->set_values(values, size);
            return 0;
        default:
            return -1;
    }
}

/**********************************************************************************************************************/

buffer_t* sound_zone_protocol::encode(buffer_t* encoded_msg){
    encoded_msg->reset();

    encoded_msg->append((uint8_t)cid);
    switch (cid) {
        case cid_send_sound_packet:
            send_sound_packet->encode(encoded_msg);
            break;
        case cid_check_connection:
            check_connection->encode(encoded_msg);
            break;
        default:
            break;
    }

    return encoded_msg;
}

/**********************************************************************************************************************/

void sound_zone_protocol::decode(buffer_t* msg_to_decode){
    uint8_t tmp_cid;
    msg_to_decode->read_byte(&tmp_cid);
    cid = initial_decode(tmp_cid);

    switch (cid) {
        case cid_send_sound_packet:
            send_sound_packet->decode(msg_to_decode);
            break;
        case cid_check_connection:
            check_connection->decode(msg_to_decode);
            break;
        default:
            break;
    }
}

/**********************************************************************************************************************
 * Protected methods
 **********************************************************************************************************************/

uint16_t sound_zone_protocol::encode_and_send() {
    encode(p_buffer);
    return p_buffer->get_write_head();
}

/**********************************************************************************************************************
 * Private methods
 **********************************************************************************************************************/

supported_cid_t sound_zone_protocol::initial_decode(uint8_t cid) {
    supported_cid_t tmp_cid;
    tmp_cid = (supported_cid_t)cid;

    return tmp_cid;
}

/**********************************************************************************************************************/

