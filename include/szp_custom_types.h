/***********************************************************************************************************************
 * @name SZP custom types
 * @file szp_custom_types.h
 * @author Niels Dyrberg
 * @date 27-10-2021
 *
 * Purpose:
 *      Ease up data movement between classes in the SZP package.
 **********************************************************************************************************************/

#ifndef C_SOUNDZONE_CLIENT_SZP_CUSTOM_TYPES_H
#define C_SOUNDZONE_CLIENT_SZP_CUSTOM_TYPES_H

/**********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/

#include <cstdint>

/**********************************************************************************************************************
 * Typedef of supported_cid_t
 **********************************************************************************************************************/

enum supported_cid_t : uint8_t {
    cid_send_sound_packet = 1,
    cid_enroll = 161,
    cid_set_sound_format = 179,
    cid_check_connection = 241,
    cid_notSet = 255
};

/**********************************************************************************************************************
 * Class declaration
 **********************************************************************************************************************/

class buffer_t {
public:
    /**
     * @brief Initializes the buffer_t object.
     * @param buffer[in] Pointer to the array that the buffer_t should use.
     * @param size[in] Size of #buffer.
     */
    buffer_t(uint8_t *buffer, uint16_t size);

    /**
     * @brief Appends one byte at the write head.
     * @param byte[in] The byte to append.
     * @return int
     * @retval 0 If successful
     * @retval -1 If the buffer is full.
     */
    int append(uint8_t byte);

    /**
     * @brief Appends one 'long long int' at the write head.
     * @param value[in] The int to append.
     * @return int
     * @retval 0 If successful
     * @retval -1 If the buffer is full.
     */
    int append(long long int value);

    /**
     * @brief Appends an array at the write head.
     * @details If #buffer is bigger than there is space in buffer_t is will not write any, and just return error.
     * @param buffer[in] The array to append.
     * @param bytes_to_write[in] The number of bytes to write from #buffer.
     * @return int
     * @retval 0 If successful
     * @retval -1 If Buffer is full.
     */
    int append(const uint8_t *buffer, uint16_t bytes_to_write);

    /**
     * Reads one byte from buffer_t.
     * @param byte[uot] Pointer to where to put the read byte.
     * @return int
     * @retval 0 If successful.
     * @retval -3 If buffer_t is empty.
     */
    int read_one(uint8_t *value);

    /**
     * Reads one 'long long int' from buffer_t.
     * @param value[uot] Pointer to where to put the read int.
     * @return int
     * @retval 0 If successful.
     * @retval -3 If buffer_t is empty.
     */
    int read_one(long long int* value);

    /**
     * @brief Used to get the rest of the unread buffer_t.
     * @param buffer[out] Pointer to the read head.
     * @param size[out] The size of the rest of the buffer_t.
     * @return int
     * @retval 0 If successful.
     * @retval -2 If buffer i empty.
     */
    int get_buffer_rest(uint8_t **buffer, uint16_t *size);

    /**
     * @brief Resets read and write head.
     * @return 0;
     */
    int reset();

    /**
     * @brief Sets the write head index and resets the read head index.
     * @param head[in] Write head index.
     * @return 0.
     */
    int set_write_head(uint16_t head);

    /**
     * @brief Getter of write head index.
     * @return Write head index.
     */
    uint16_t get_write_head();

    /**
     * @brief Prints the buffer using cout.
     * @details Mainly used for debugging, as it has no effect on read or write head or the array it self.
     * @return 0.
     */
    int print_buffer();

private:
    uint8_t *p_buffer;
    uint16_t buffer_size;
    uint16_t write_head;
    uint16_t read_head;
protected:
};

#endif //C_SOUNDZONE_CLIENT_SZP_CUSTOM_TYPES_H
