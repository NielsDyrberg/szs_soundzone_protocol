/***********************************************************************************************************************
 * @name x01 Send sound-packet
 * @file x01_send_sound_packet.h
 * @author Niels Dyrberg
 * @date 27-10-2021
 *
 * Purpose:
 *      Encode and decode SZP x01-send-sound-packages.
 **********************************************************************************************************************/

#ifndef C_SOUNDZONE_CLIENT_X01_SEND_SOUND_PACKET_H
#define C_SOUNDZONE_CLIENT_X01_SEND_SOUND_PACKET_H

/**********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/

#include <iostream>
#include <cstdint>
#include "szp_custom_types.h"

/**********************************************************************************************************************
 * Class declaration
 **********************************************************************************************************************/

class x01_send_sound_packet {
public:
    /**
     * Default constructor.
     */
    x01_send_sound_packet();

    /**
     * @brief Sets the fifo fd.
     * @param fifo_fd[in] Fifo file descriptor.
     * @return 0
     */
    int set_fifo(const int *fifo_fd);

    /**
     * @brief Sets the package values for the command.
     * @param values[in] Pointer to the array of values to set.
     * @param size[in] The size of #values, in bytes.
     * @return 0
     */
    int set_values(uint8_t *values, uint16_t size);

    /**
     * @brief Serializes the x01 object.
     * @param encoded_msg[out] The buffer_t object where the serialized x01 object is saved.
     * @return #encoded_msg.
     */
    buffer_t *encode(buffer_t *encoded_msg);

    /**
     * @brief Decodes a x01 serialized object.
     * @param msg_to_decode[in] Pointer to the buffer containing the serialized x01 obj.
     */
    void decode(buffer_t *msg_to_decode);

    /**
     * @brief Resets it #p_payload
     * @return 0
     */
    int reset();

protected:
private:
    uint8_t *p_payload;
    uint16_t payload_size;
    int fifo_fd;
};

#endif //C_SOUNDZONE_CLIENT_X01_SEND_SOUND_PACKET_H
