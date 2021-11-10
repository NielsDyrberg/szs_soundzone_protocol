//
// Created by ncpd on 08-11-2021.
//

#ifndef SZS_SOUNDZONE_PROTOCOL_SZP_SLAVE_H
#define SZS_SOUNDZONE_PROTOCOL_SZP_SLAVE_H


#include "sound_zone_protocol.h"
#include "udp_server.h"

static int port = 1695;

class SZP_slave: public sound_zone_protocol{
public:
    SZP_slave(uint8_t *comm_buffer, uint16_t buffer_size);

    int check_connection();
protected:


private:
    UDP_server dt;

};


#endif //SZS_SOUNDZONE_PROTOCOL_SZP_SLAVE_H
