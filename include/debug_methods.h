/***********************************************************************************************************************
 * @name Debug methods
 * @file debug_methods.h
 * @author Niels Dyrberg
 * @date 17-11-2021
 *
 * Purpose:
 *      Should holds the classes and method used for debugging, or patch/temporary solutions.
 **********************************************************************************************************************/

#ifndef SOUNDZONE_CLIENT_DEBUG_METHODS_H
#define SOUNDZONE_CLIENT_DEBUG_METHODS_H

/**********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <fstream>

/**********************************************************************************************************************
 * debug_write_file class declaration
 **********************************************************************************************************************/

class debug_write_file {
private:
    std::ofstream debug_fd;

public:
    /**
     * Resets the /tmp/rcv_file.wav
     */
    debug_write_file();

    /**
     * Closes debug_fd.
     */
    ~debug_write_file();

    /**
     * @brief Opens, appends and closes to /tmp/rcv_file.wav
     * @param buff[in] Buffer to append.
     * @param size[in] size of #buff
     */
    void write(const uint8_t *buff, int size);
};

#endif //SOUNDZONE_CLIENT_DEBUG_METHODS_H
