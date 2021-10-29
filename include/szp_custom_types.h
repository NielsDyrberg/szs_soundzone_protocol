//
// Created by ncpd on 27-10-2021.
//

#ifndef C_SOUNDZONE_CLIENT_SZP_CUSTOM_TYPES_H
#define C_SOUNDZONE_CLIENT_SZP_CUSTOM_TYPES_H

#include <cstdint>

enum supported_cid_t: uint8_t {
    cid_send_sound_packet = 1,
    cid_enroll = 161,
    cid_setSoundFormat = 179,
    cid_checkConnection = 241,
    cid_notSet = 255
};

class buffer_t{
public:
    buffer_t(uint8_t* buffer, uint8_t size);
    int append(uint8_t byte);
    int append(const uint8_t* buffer, uint8_t bytes_to_write);
    int read_byte(uint8_t* byte);
    int get_buffer(uint8_t** buffer, uint8_t* size);
    int print_buffer();
private:
    uint8_t* p_buffer;
    uint8_t buffer_size;
    uint8_t write_head;
    uint8_t read_head;
protected:
};

#endif //C_SOUNDZONE_CLIENT_SZP_CUSTOM_TYPES_H
