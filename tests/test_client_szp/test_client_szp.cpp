//
// Created by ncpd on 05-11-2021.
//

#include <iostream>

#include "szp_slave.h"

#define BUFFER_SIZE 1028
uint16_t comm_size = BUFFER_SIZE;
uint8_t comm_buffer[BUFFER_SIZE] = {0};

[[noreturn]] void test_recv_packet(){
    SZP_slave szp(comm_buffer, comm_size);
    while (true){
        szp.recieve();
        std::cout << "Rerun slave" << std::endl;
    }
}

int main(){
    test_recv_packet();
    return 0;
}
