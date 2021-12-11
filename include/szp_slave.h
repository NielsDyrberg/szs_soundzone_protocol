/***********************************************************************************************************************
 * @name SZP_slave
 * @file szp_slave.h
 * @author Niels Dyrberg
 * @date 08-11-2021
 *
 * Purpose:
 *      Encode/decodes sent/received SZP packages.
 **********************************************************************************************************************/

#ifndef SZS_SOUNDZONE_PROTOCOL_SZP_SLAVE_H
#define SZS_SOUNDZONE_PROTOCOL_SZP_SLAVE_H

/**********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/

#include "sound_zone_protocol.h"
#include "udp_server.h"

/**********************************************************************************************************************
 * Defines
 **********************************************************************************************************************/

#define COMM_BUFFER_SIZE 4096

/**********************************************************************************************************************
 * Class declaration
 **********************************************************************************************************************/

class SZP_slave : public sound_zone_protocol {
public:
    /**
     * @brief Constructor of SZP_slave
     * @param[in] fifo_name Name and path of the fifo buffer to use under x01_send_sound_package.
     */
    explicit SZP_slave(char *fifo_name);

    /**
     * @brief Does nothing.
     */
    ~SZP_slave();

    /**
     * @brief Opens the fifo file in write only mode. Hangs until read side is opened.
     * @return 0.
     */
    int open_fifo();

    /**
     * @brief Receives a package from DataTransport and the reacts on it.
     * @details Depending on the received package it also responds.
     * @return 0
     */
    int recieve();

    /**
     * @brief Getter of #time_to_play.
     * @param time Pointer where to store the value of #time_to_play.
     * @return int
     * @retval 0 If successful.
     * @retval -1 If time invalid.
     */
    int get_time(long long int *time);

protected:

private:
    UDP_server dt;
    char *fifo_name;
    uint8_t comm_buffer[COMM_BUFFER_SIZE] = {};
    long long int time_to_play;

    /**
     * @brief Serializes the sound_zone_protocol object and the sends it.
     * @return int
     * @retval -1 if errors
     * @retval The number of bytes sent if successfully.
     */
    int encode_and_send();

    /**
     * Reacts on a received message.
     * @return int
     * @retval 0 If successful.
     * @retval -1 If #cid not supported.
     */
    int react_on_incoming();
};


#endif //SZS_SOUNDZONE_PROTOCOL_SZP_SLAVE_H
