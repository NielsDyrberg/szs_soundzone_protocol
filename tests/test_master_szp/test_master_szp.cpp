//
// Created by ncpd on 05-11-2021.
//

#include <iostream>

#include "szp_master.h"

char slave_1_Ip[] = "192.168.1.36";

#define BUFFER_SIZE 1028
uint16_t comm_size = BUFFER_SIZE;
uint8_t comm_buffer[BUFFER_SIZE] = {0};

void test_check_connection(){
    SZP_master szp(slave_1_Ip, true, comm_buffer, comm_size);
    szp.check_connection();
    std::cout << " " << std::endl;
}

int main(){
    test_check_connection();
    return 0;
}

