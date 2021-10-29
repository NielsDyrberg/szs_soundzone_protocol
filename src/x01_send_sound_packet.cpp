//
// Created by ncpd on 27-10-2021.
//

#include "x01_send_sound_packet.h"

#define PAYLOAD_SIZE 100

/**********************************************************************************************************************
 * Public methods
 **********************************************************************************************************************/

x01_send_sound_packet::x01_send_sound_packet() {
    this->p_payload = nullptr;
    payload_size = 0;
};

int x01_send_sound_packet::set_values(uint8_t *values, uint8_t size) {
    p_payload = values;
    payload_size = size;
    return 0;
}

buffer_t* x01_send_sound_packet::encode(buffer_t* encoded_msg){
    for (int i = 0; i < payload_size; i++){
        encoded_msg->append(p_payload[i]);
    }
    return encoded_msg;
}

void x01_send_sound_packet::decode(buffer_t* msg_to_decode) {
    p_payload = new uint8_t[PAYLOAD_SIZE];
    uint8_t byte_read = 0;

    while (msg_to_decode->read_byte(&byte_read) == 0){
        p_payload[payload_size++] = byte_read;
    }
}

/**********************************************************************************************************************
 * Private methods
 **********************************************************************************************************************/



