############################################################
# Initial defs
############################################################
cmake_minimum_required(VERSION 3.16) # CMake version check
project(szs_soundzone_protocol VERSION 0.0.1) # Create project "szs_soundzone_protocol"
set(CMAKE_CXX_STANDARD 20) # Enable c++20 standard

##########################################################################################
##########################################################################################
##########################################################################################

#Generate the static library from the library sources
add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME} INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        )

target_sources(${PROJECT_NAME} INTERFACE
        src/sound_zone_protocol.cpp
        src/szp_custom_types.cpp
        src/x01_send_sound_packet.cpp
        src/xF1_check_connection.cpp
        )