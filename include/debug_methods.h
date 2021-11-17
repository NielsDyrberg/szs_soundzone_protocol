//
// Created by ncpd on 17-11-2021.
//

#ifndef SOUNDZONE_CLIENT_DEBUG_METHODS_H
#define SOUNDZONE_CLIENT_DEBUG_METHODS_H

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <fstream>

class debug_write_file{
private:
    std::ofstream debug_fd;

public:
    debug_write_file();
    ~debug_write_file();
    void write(const uint8_t * buff, int size);
};

#endif //SOUNDZONE_CLIENT_DEBUG_METHODS_H
