//
// Created by ncpd on 27-10-2021.
//

#include "xF1_check_connection.h"

/**********************************************************************************************************************
 * Public methods
 **********************************************************************************************************************/

xF1_check_connection::xF1_check_connection() {
    this->acknowledgment = nullptr;
};

int xF1_check_connection::set_values(uint8_t value) {
    *acknowledgment = value;
    return 0;

}

int xF1_check_connection::reset() {
    acknowledgment = nullptr;
    return 0;
}

buffer_t* xF1_check_connection::encode(buffer_t* encoded_msg){
    if (acknowledgment != nullptr){
        encoded_msg->append(*acknowledgment);
    }
    return encoded_msg;
}

void xF1_check_connection::decode(buffer_t* buffer) {
    buffer->read_byte(acknowledgment);
}

/**********************************************************************************************************************
 * Private methods
 **********************************************************************************************************************/


