//
// Created by ncpd on 27-10-2021.
//

#ifndef C_SOUNDZONE_CLIENT_SOUND_ZONE_PROTOCOL_H
#define C_SOUNDZONE_CLIENT_SOUND_ZONE_PROTOCOL_H

#include <iostream>
#include <cstdint>

#include "xF1_check_connection.h"
#include "x01_send_sound_packet.h"

#include "szp_custom_types.h"

class sound_zone_protocol{
public:
    sound_zone_protocol();
    explicit sound_zone_protocol(supported_cid_t cid);
    int set_values(uint8_t value);
    int set_values(uint8_t *values, uint8_t size);
    buffer_t* encode(buffer_t* encoded_msg);
    void decode(buffer_t* msg_to_decode);

protected:
    supported_cid_t cid;
    xF1_check_connection* check_connection;
    x01_send_sound_packet* send_sound_packet;
private:
    supported_cid_t initial_decode(uint8_t cid);
};

#endif //C_SOUNDZONE_CLIENT_SOUND_ZONE_PROTOCOL_H