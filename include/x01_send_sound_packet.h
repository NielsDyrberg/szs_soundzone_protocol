//
// Created by ncpd on 27-10-2021.
//

#ifndef C_SOUNDZONE_CLIENT_X01_SEND_SOUND_PACKET_H
#define C_SOUNDZONE_CLIENT_X01_SEND_SOUND_PACKET_H

#include <iostream>
#include <cstdint>
#include "szp_custom_types.h"

class x01_send_sound_packet{
public:
    x01_send_sound_packet();
    int set_fifo(int* fifo_fd);
    int set_values(uint8_t *values, uint8_t size);
    buffer_t* encode(buffer_t* encoded_msg);
    void decode(buffer_t* msg_to_decode);
    int reset();
protected:
private:
    uint8_t* p_payload;
    uint8_t payload_size;
    int fifo_fd;
};

#endif //C_SOUNDZONE_CLIENT_X01_SEND_SOUND_PACKET_H
