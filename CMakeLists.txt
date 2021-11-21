############################################################
# Initial defs
############################################################
cmake_minimum_required(VERSION 3.16) # CMake version check
project(szs_soundzone_protocol VERSION 0.2.0) # Create project "szs_soundzone_protocol"

##########################################################################################
##########################################################################################
##########################################################################################

#Generate the static library from the library sources
add_library(szs_soundzone_protocol INTERFACE)

target_include_directories(szs_soundzone_protocol INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        )

target_sources(${PROJECT_NAME} INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/sound_zone_protocol.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/szp_slave.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/szp_master.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/szp_custom_types.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/x01_send_sound_packet.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/xF1_check_connection.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/debug_methods.cpp
        )

##########################################################################################
###########################   Add subdirectories   #######################################
##########################################################################################

add_subdirectory(extern)

# Link libraries to project
target_link_libraries(${PROJECT_NAME} INTERFACE szs_datatransport)

add_subdirectory(tests)