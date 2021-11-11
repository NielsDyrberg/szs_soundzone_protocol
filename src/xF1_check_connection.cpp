//
// Created by ncpd on 27-10-2021.
//

#include "xF1_check_connection.h"

#define NOT_SET 0xFF

/**********************************************************************************************************************
 * Public methods
 **********************************************************************************************************************/

xF1_check_connection::xF1_check_connection() {
    this->acknowledgment = NOT_SET;
};

int xF1_check_connection::set_values(uint8_t value) {
    acknowledgment = value;
    return 0;

}

int xF1_check_connection::reset() {
    acknowledgment = NOT_SET;
    return 0;
}

buffer_t* xF1_check_connection::encode(buffer_t* encoded_msg){
    if (acknowledgment != NOT_SET){
        encoded_msg->append(acknowledgment);
    }
    return encoded_msg;
}

void xF1_check_connection::decode(buffer_t* buffer) {
    buffer->read_byte(&acknowledgment);
}

/**********************************************************************************************************************
 * Private methods
 **********************************************************************************************************************/


