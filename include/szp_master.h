//
// Created by ncpd on 08-11-2021.
//

#ifndef SZS_SOUNDZONE_PROTOCOL_SZP_MASTER_H
#define SZS_SOUNDZONE_PROTOCOL_SZP_MASTER_H

#include <fstream>
#include "sound_zone_protocol.h"
#include "udp_client.h"

#define COMM_BUFFER_SIZE 4096

class SZP_master: public sound_zone_protocol{
public:
    SZP_master();
    SZP_master(char *host, bool is_ip);

    int check_connection();
    int send_sound_packet(uint8_t* buffer, uint16_t packet_size);
protected:


private:
    UDP_client dt;
    uint8_t comm_buffer[COMM_BUFFER_SIZE];


};

#endif //SZS_SOUNDZONE_PROTOCOL_SZP_MASTER_H
