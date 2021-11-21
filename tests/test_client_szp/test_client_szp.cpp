//
// Created by ncpd on 05-11-2021.
//

#include <iostream>

#include "szp_slave.h"

char *fifo = "/tmp/rcv_file.wav";

[[noreturn]] void test_recv_packet(){
    SZP_slave szp(fifo);
    szp.open_fifo();
    while (true){
        szp.recieve();
        std::cout << "Rerun slave" << std::endl;
    }
}

int main(){
    test_recv_packet();
    return 0;
}
