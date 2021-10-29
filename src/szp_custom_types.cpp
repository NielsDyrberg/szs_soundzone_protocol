//
// Created by ncpd on 27-10-2021.
//

#include "szp_custom_types.h"
#include <iostream>

buffer_t::buffer_t(uint8_t* buffer, uint8_t size) {
    this->p_buffer = buffer;
    this->buffer_size = size;
    write_head = 0;
    read_head = 0;
}

int buffer_t::append(uint8_t byte) {
    if(write_head - 1 > buffer_size){
        // Overflow will happen
        return -1;
    }
    p_buffer[write_head] = byte;
    write_head++;
    return 0;
}

int buffer_t::append(const uint8_t *buffer, uint8_t size) {
    if(write_head - size > buffer_size ){
        // Overflow will happen
        return -1;
    }
    for (int i = 0; i < size; i++) {
        p_buffer[write_head] = buffer[i];
        write_head++;
    }
    return 0;
}

int buffer_t::get_buffer(uint8_t** buffer, uint8_t* size) {
    *buffer = p_buffer;
    *size = buffer_size;

    if (write_head == 0){
        // Buffer empty
        return -2;
    }
    return 0;
}

int buffer_t::read_byte(uint8_t* byte) {
    if (read_head >= write_head){
        return -3;
    }
    *byte = p_buffer[read_head];
    read_head++;
    return 0;
}

int buffer_t::print_buffer() {
    /* Print buffer */
    for(int i = 0; i < write_head; i++){
        std::cout << +p_buffer[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}