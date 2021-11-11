//
// Created by ncpd on 05-11-2021.
//

#include <iostream>

#include "szp_master.h"

#define BUFFER_SIZE 1028

char slave_1_Ip[] = "192.168.0.103";

uint16_t comm_size = BUFFER_SIZE;
uint8_t comm_buffer[BUFFER_SIZE] = {0};

uint8_t msg[] = {3,12,42,3,43,25,23,235,21,162,113,64,0,111};

void test_check_connection(){
    SZP_master szp(slave_1_Ip, true, comm_buffer, comm_size);
    szp.check_connection();
    std::cout << " " << std::endl;
}

void test_send_sound_packet(){
    SZP_master szp(slave_1_Ip, true, comm_buffer, comm_size);
    szp.send_sound_packet(msg, sizeof(msg));
    std::cout << " " << std::endl;
}

int main(){
    test_send_sound_packet();
    return 0;
}

