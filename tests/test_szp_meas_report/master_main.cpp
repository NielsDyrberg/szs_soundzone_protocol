//
// Created by ncpd on 22-11-2021.
//

<<<<<<< Updated upstream
=======
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <unistd.h>
#include "szp_master.h"

/***********************************************************************************************************************
 * Defines
 **********************************************************************************************************************/

#define NUMBER_OF_SLAVES 2

/***********************************************************************************************************************
 * Static variables
 **********************************************************************************************************************/

int send_delay[] = {0, 20, 50, 70, 100, 130};
int n_send_delay = sizeof(send_delay)/ sizeof(int);
int block_size[] = {4096, 2048, 1024, 512, 256, 128, 64};
std::string block_size_char[] = {"4096", "2048", "1024", "512", "256", "128", "64"};
int n_block_size = sizeof(block_size)/ sizeof(int);

const int buffer_size = 4096;
uint8_t buffer[buffer_size] = {0};

FILE* file_fd;

SZP_master* slaves;
static char* slave_ips[] = {"192.168.1.47", nullptr, nullptr, nullptr,
                            nullptr, nullptr, nullptr, nullptr};
long long int play_time = 0;

/***********************************************************************************************************************
 * Test functions
 **********************************************************************************************************************/

void send_file(int block_i, int delay_i){
    unsigned int bytes_read = 0;

    bytes_read = fread(buffer, 1, block_size[block_i], file_fd);
    if (bytes_read > 0){
        for (int i = 0; i < NUMBER_OF_SLAVES; i++) {
            slaves[i].send_sound_packet(buffer, bytes_read, play_time);
            usleep(send_delay[delay_i]);
        }
    } else{
        fclose(file_fd);
        std::cout << "Song end" << std::endl;
    }
}

void open_file(int block_i){
    // create the file path
    std::string file_path = "test_file_"+block_size_char[block_i]+".bin";
    const char * c_file_path = file_path.c_str();

    file_fd = fopen(c_file_path, "rb");
    if(file_fd == nullptr){
        std::cout << "Did not load song, [SZS_server, load_song(char *song_path)]" << std::endl;
        exit(1);
    }
}

int add_slave(int slave_number, char* host, bool is_ip){
    int err;

    if (slave_number >= NUMBER_OF_SLAVES){
        std::cout << "There can only be 8 slaves, [SZS_server, add_slave(int slave_number, char* host, bool is_ip)]" << std::endl;
        return -1;
    }

    std::cout << "Adding slave " << slave_number
              << ", [szp_handler, add_slave(int slave_number, char* host, bool is_ip)]" << std::endl;

    std::cout << "Checking connection for slave: " << slave_number
              << ", [szp_handler, add_slave(int slave_number, char* host, bool is_ip)]" << std::endl;
    slaves[slave_number] = SZP_master(host, is_ip);
    //todo check successful with check_connection

    err = slaves[slave_number].check_connection();
    if(err < 0){
        std::cout << "No connection to slave no " << slave_number
                  << ", [szp_handler, add_slave(int slave_number, char* host, bool is_ip)]" << std::endl;
        return -1;
    }

    return 0;
}

void run_all_test_iterations(){

    for (int i = 0; i < n_block_size; i++) {
        for (int j = 0; j < n_send_delay; j++) {
            open_file(i);
            send_file(i, j);
        }
    }

}

void setup(){
    int err;
    slaves = new SZP_master[NUMBER_OF_SLAVES];

    for (int i = 0; i < NUMBER_OF_SLAVES; i++) {
        err = add_slave(i ,slave_ips[i], true);
        if(err < 0){
            std::cout << "Slave " << i << " did not setup, [SZS_server, setup()]" << std::endl;
            exit(1);
        }
    }
}

/***********************************************************************************************************************
 * Main function
 **********************************************************************************************************************/

int main(){
    setup();
    run_all_test_iterations();
    return 0;
}
>>>>>>> Stashed changes
