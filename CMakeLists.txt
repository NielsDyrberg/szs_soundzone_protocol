############################################################
# Create a library
############################################################

#Generate the static library from the library sources
add_library(SoundZoneProtocol_lib SHARED
        src/sound_zone_protocol.cpp
        src/szp_custom_types.cpp
        src/x01_send_sound_packet.cpp
        src/xF1_check_connection.cpp
        )

target_include_directories(SoundZoneProtocol_lib
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        )

include_directories(${CMAKE_CURRENT_SOURCE_DIR})