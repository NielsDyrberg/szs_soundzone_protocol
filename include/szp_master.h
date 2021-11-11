//
// Created by ncpd on 08-11-2021.
//

#ifndef SZS_SOUNDZONE_PROTOCOL_SZP_MASTER_H
#define SZS_SOUNDZONE_PROTOCOL_SZP_MASTER_H

#include "sound_zone_protocol.h"
#include "udp_client.h"

class SZP_master: public sound_zone_protocol{
public:
    SZP_master(char *host, bool is_ip, uint8_t *comm_buffer, uint16_t buffer_size);

    int check_connection();
    int send_sound_packet(uint8_t* packet, uint16_t packet_size);
protected:


private:
    UDP_client dt;

};

#endif //SZS_SOUNDZONE_PROTOCOL_SZP_MASTER_H
