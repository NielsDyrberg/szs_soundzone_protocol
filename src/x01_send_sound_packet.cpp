//
// Created by ncpd on 27-10-2021.
//

#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "x01_send_sound_packet.h"

#define PAYLOAD_SIZE 100

/**********************************************************************************************************************
 * Public methods
 **********************************************************************************************************************/

x01_send_sound_packet::x01_send_sound_packet() {
    this->p_payload = nullptr;
    this->fifo_fd = 0;
    payload_size = 0;
};

int x01_send_sound_packet::set_fifo(const int *fifo_fd) {
    this->fifo_fd = *fifo_fd;
    return 0;
}

int x01_send_sound_packet::set_values(uint8_t *values, uint16_t size) {
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
    uint8_t* tmp_p_buffer = nullptr;
    uint16_t tmp_buffer_size = 0;

    if(fifo_fd == 0){
        std::cout << "p_fifo_fd not set, [x01_send_sound_packet, encode(buffer_t* encoded_msg)]" << std::endl;
    }

    // Get pointer to buffer, and the reset.
    msg_to_decode->get_buffer_rest(&tmp_p_buffer, &tmp_buffer_size);
    msg_to_decode->reset();

    write(fifo_fd, tmp_p_buffer, tmp_buffer_size);
}

int x01_send_sound_packet::reset() {
    p_payload = nullptr;
    payload_size = 0;
    return 0;
}

/**********************************************************************************************************************
 * Private methods
 **********************************************************************************************************************/



