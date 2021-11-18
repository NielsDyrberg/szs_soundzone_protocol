/***********************************************************************************************************************
 * @name xF1 Check connection
 * @file xf1_check_connection.h
 * @author Niels Dyrberg
 * @date 27-10-2021
 *
 * Purpose:
 *      Encode and decode SZP xf1-check-connection.
 **********************************************************************************************************************/

#ifndef C_SOUNDZONE_CLIENT_XF1_CHECK_CONNECTION_H
#define C_SOUNDZONE_CLIENT_XF1_CHECK_CONNECTION_H

/**********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/

#include <cstdint>
#include "szp_custom_types.h"

/**********************************************************************************************************************
 * Class declaration
 **********************************************************************************************************************/

class xF1_check_connection {
public:
    /**
     * @brief Default constructor.
     */
    xF1_check_connection();

    /**
     * @brief Sets the #acknolegment value.
     * @param value[in] The ack byte.
     * @return 0
     */
    int set_values(uint8_t value);

    /**
     * @brief Resets #acknolegment.
     * @return 0
     */
    int reset();

    /**
     * @brief Serializes the xF1 object.
     * @param encoded_msg[out] The buffer_t where the serialized xF1 object is saved.
     * @return #encoded_msg.
     */
    buffer_t *encode(buffer_t *encoded_msg);

    /**
     * @brief Decodes a serialized xF1 object.
     * @param msg_to_decode[in] Pointer to the buffer containing the serialized xF1 obj.
     */
    int decode(buffer_t *buffer);

protected:
private:
    uint8_t acknowledgment;

};

#endif //C_SOUNDZONE_CLIENT_XF1_CHECK_CONNECTION_H
