//
// Created by ncpd on 22-11-2021.
//

<<<<<<< Updated upstream
=======
#include "szp_slave.h"

static int port = 1695;
static dt_type_t type = SZP;

/**********************************************************************************************************************
 * Public methods
 **********************************************************************************************************************/

SZP_slave::SZP_slave(char *fifo_name) : sound_zone_protocol(comm_buffer, COMM_BUFFER_SIZE),
                                        dt(type, port, comm_buffer, COMM_BUFFER_SIZE) {
    this->fifo_name = fifo_name;
    this->time_to_play = TIME_NOT_SET;

}

int main(){

    return 0;
}
>>>>>>> Stashed changes
