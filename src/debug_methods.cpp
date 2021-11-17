//
// Created by ncpd on 17-11-2021.
//

#include "iostream"
#include "debug_methods.h"

static int packets_received;


debug_write_file::debug_write_file() {
    debug_fd.open("/tmp/rcv_file.wav", std::ios::binary);
    debug_fd.close();

    packets_received = 0;
}

debug_write_file::~debug_write_file() {
    debug_fd.close();
}

void debug_write_file::write(const uint8_t* buff, int size) {
    debug_fd.open("/tmp/rcv_debug_file.wav", std::ios::binary | std::ios::app);
    debug_fd.write((char*)buff, size);
    debug_fd.close();
    packets_received++;
}