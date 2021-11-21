//
// Created by ncpd on 05-11-2021.
//

#include <iostream>

#include "szp_master.h"

char slave_1_Ip[] = "192.168.1.47";

long long int time_to_play = 0x5930;
uint8_t msg[] = {3,12,42,3,43,25,23,235,21,162,113,64,0,111};

void test_check_connection(){
    SZP_master szp(slave_1_Ip, true);
    szp.check_connection();
    std::cout << " " << std::endl;
}

void test_send_sound_packet(){
    int fifo = 1;
    SZP_master szp(slave_1_Ip, true);
    szp.set_fifo(&fifo);
    szp.send_sound_packet(msg, sizeof(msg), time_to_play);
    std::cout << " " << std::endl;
}

int main(){
    test_send_sound_packet();
    return 0;
}

