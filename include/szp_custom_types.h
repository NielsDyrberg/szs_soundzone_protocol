//
// Created by ncpd on 27-10-2021.
//

#ifndef C_SOUNDZONE_CLIENT_SZP_CUSTOM_TYPES_H
#define C_SOUNDZONE_CLIENT_SZP_CUSTOM_TYPES_H

#include <cstdint>

enum supported_cid_t: uint8_t {
    cid_send_sound_packet = 1,
    cid_enroll = 161,
    cid_set_sound_format = 179,
    cid_check_connection = 241,
    cid_notSet = 255
};

class buffer_t{
public:
    buffer_t(uint8_t* buffer, uint16_t size);
    int append(uint8_t byte);
    int append(const uint8_t* buffer, uint16_t bytes_to_write);
    int read_byte(uint8_t* byte);
    int get_written_buffer(uint8_t** buffer, uint16_t* size);
    int reset();
    int set_write_head(uint16_t head);
    uint16_t get_write_head();
    int print_buffer();
private:
    uint8_t* p_buffer;
    uint16_t buffer_size;
    uint16_t write_head;
    uint16_t read_head;
protected:
};

#endif //C_SOUNDZONE_CLIENT_SZP_CUSTOM_TYPES_H
