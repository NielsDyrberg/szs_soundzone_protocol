//
// Created by ncpd on 08-11-2021.
//

#ifndef SZS_SOUNDZONE_PROTOCOL_SZP_SLAVE_H
#define SZS_SOUNDZONE_PROTOCOL_SZP_SLAVE_H


#include "sound_zone_protocol.h"
#include "udp_server.h"

#define COMM_BUFFER_SIZE 4096

static int port = 1695;

class SZP_slave: public sound_zone_protocol{
public:
    SZP_slave(char* fifo_name);
    int open_fifo();
    int recieve();

protected:

private:
    UDP_server dt;
    char* fifo_name;
    uint8_t comm_buffer[COMM_BUFFER_SIZE] = {};

    int encode_and_send();
    int react_on_incoming();
};


#endif //SZS_SOUNDZONE_PROTOCOL_SZP_SLAVE_H
