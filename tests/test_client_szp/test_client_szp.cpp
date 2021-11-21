//
// Created by ncpd on 05-11-2021.
//

#include <iostream>

#include "szp_slave.h"

char *fifo = "/tmp/rcv_file.wav";

[[noreturn]] void test_recv_packet(){
    long long int time_to_play;
    int err = 0;
    SZP_slave szp(fifo);
    szp.open_fifo();
    while (true){
        szp.recieve();
        err = szp.get_time(&time_to_play);
        if(err >= 0){
            std::cout << "Time to play = " << time_to_play << std::endl;
        }
        std::cout << "Rerun slave" << std::endl;
    }
}

int main(){
    test_recv_packet();
    return 0;
}
