/***********************************************************************************************************************
 * @name Sound-Zone Protocol
 * @file sound_zone_protocol.h
 * @author Niels Dyrberg
 * @date 27-10-2021
 *
 * Purpose:
 *      Encode and decode SZP packages.
 *
 * @note Is written as a base-class for SZP_master and SZP_slave.
 **********************************************************************************************************************/

#ifndef C_SOUNDZONE_CLIENT_SOUND_ZONE_PROTOCOL_H
#define C_SOUNDZONE_CLIENT_SOUND_ZONE_PROTOCOL_H

/**********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/

#include <iostream>
#include <cstdint>

#include "dataTransport.h"
#include "xF1_check_connection.h"
#include "x01_send_sound_packet.h"
#include "szp_custom_types.h"

/**********************************************************************************************************************
 * Class declaration
 **********************************************************************************************************************/

class sound_zone_protocol {
public:
    /**
     * @brief Default constructor for sound_zone_protocol
     */
    sound_zone_protocol();

    /**
     * @brief Constructor for sound_zone_protocol.
     * @details This constructor gives to possibility to use an external communication buffer.
     * @param comm_buffer[in] Pointer to the external communication buffer.
     * @param buffer_size[in] Size of #comm_buffer.
     */
    sound_zone_protocol(uint8_t *comm_buffer, uint16_t buffer_size);

    /**
     * @brief Sets fifo file descriptor.
     * @param fifo_fd[in] Fifo file descriptor.
     * @return 0
     */
    int set_fifo(int *fifo_fd);

    /**
     * @brief Sets the package values for the command defined by #cid.
     * @details Depending on the #cid values are filled.
     * @param value[in] the byte value to set.
     * @return int.
     * @retval 0 If successful.
     * @retval -1 If #cid is not set.
     * @retval -2 If the #cid does not support this type of package value.
     */
    int set_values(uint8_t value);

    /**
     * @brief Sets the package values for the command defined by #cid.
     * @details Depending on the #cid values are filled.
     * @param value[in] the byte value to set.
     * @return int.
     * @retval 0 If successful.
     * @retval -1 If #cid is not set.
     * @retval -2 If the #cid does not support this type of package value.
     */
    int set_values(long long int value);

    /**
     * @brief Sets the package values for the command defined by #cid.
     * @details Depending on the #cid values are filled.
     * @param values[in] Pointer to the array of values to set.
     * @param size[in] The size of #values, in bytes.
     * @return int.
     * @retval 0 If successful.
     * @retval -1 If #cid is not set.
     * @retval -2 If the #cid does not support this type of package value.
     */
    int set_values(uint8_t *values, uint16_t size);

    /**
     * @brief Serializes the sound_zone_protocol object.
     * @param encoded_msg[out] Pointer to the buffer_t where the serialized SZP object is saved.
     * @return #encoded_msg.
     */
    buffer_t *encode(buffer_t *encoded_msg);

    /**
     * @details Decodes a serialized SZP object.
     * @param msg_to_decode[in] Pointer to the serialized object.
     * @return int.
     * @retval 0 If successful.
     * @retval -1 If #cid not supported.
     */
    int decode(buffer_t *msg_to_decode);

protected:
    buffer_t *p_buffer;
    supported_cid_t cid;
    xF1_check_connection *check_connection;
    x01_send_sound_packet *send_sound_packet;

    /**
     * @brief Serializes the SZP object and returns the size.
     * @return uint16_t - size of serialized object.
     */
    uint16_t encode_and_get_size();

private:
    static supported_cid_t initial_decode(uint8_t cid);
};

#endif //C_SOUNDZONE_CLIENT_SOUND_ZONE_PROTOCOL_H
