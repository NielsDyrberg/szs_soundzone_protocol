//
// Created by ncpd on 27-10-2021.
//

#ifndef C_SOUNDZONE_CLIENT_XF1_CHECK_CONNECTION_H
#define C_SOUNDZONE_CLIENT_XF1_CHECK_CONNECTION_H

#include <cstdint>
#include "szp_custom_types.h"

#define ACK 1;

class xF1_check_connection{
public:
    xF1_check_connection();
    int set_values(uint8_t value);
    int reset();
    buffer_t* encode(buffer_t* encoded_msg);
    int decode(buffer_t* buffer);

protected:
private:
    uint8_t acknowledgment;

};

#endif //C_SOUNDZONE_CLIENT_XF1_CHECK_CONNECTION_H
