/***********************************************************************************************************************
 * @name SZP_master
 * @file szp_master.h
 * @author Niels Dyrberg
 * @date 08-11-2021
 *
 * Purpose:
 *      Encode/decodes sent/received SZP packages.
 **********************************************************************************************************************/

#ifndef SZS_SOUNDZONE_PROTOCOL_SZP_MASTER_H
#define SZS_SOUNDZONE_PROTOCOL_SZP_MASTER_H

/**********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/

#include <fstream>
#include "sound_zone_protocol.h"
#include "udp_client.h"

/**********************************************************************************************************************
 * Defines
 **********************************************************************************************************************/

#define COMM_BUFFER_SIZE 4096

/**********************************************************************************************************************
 * Class declaration
 **********************************************************************************************************************/

class SZP_master : public sound_zone_protocol {
public:
    /**
     * Default constructor for SZP_master
     */
    SZP_master();

    /**
     * @brief Constructor for SZP_master, host is used to specify the SZP_slave.
     * @note Support for hostname not implemented yet.
     * @param host[in] Ip or hostname of host.
     * @param is_ip[in] Defines if #host is an IP
     */
    SZP_master(char *host, bool is_ip);

    /**
     * @brief Does what it says.
     * @details Checks connection by sending a SZP xF1_check_connection to the host. If host returns an ack connection
     * running.
     * @return int
     * @retval 0 if good
     * @retval -1 if no ack.
     */
    int check_connection();

    /**
     * @brief Sends a SZP sound package to the host.
     * @param buffer[in] Pointer to the sound block to send.
     * @param packet_size Size of the sound block.
     * @return int
     * @retval 0 If successful
     * @retval -1 If send failed.
     */
    int send_sound_packet(uint8_t *buffer, uint16_t packet_size);

protected:


private:
    UDP_client dt;
    uint8_t comm_buffer[COMM_BUFFER_SIZE] = {};


};

#endif //SZS_SOUNDZONE_PROTOCOL_SZP_MASTER_H
