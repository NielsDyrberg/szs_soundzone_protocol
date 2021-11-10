cmake_minimum_required(VERSION 3.16) # CMake version check
project(test_master_szp VERSION 0.0.1) # Create project "test_szp_raw"
set(CMAKE_CXX_STANDARD 14) # Enable c++14 standard


# Add main.cpp file of project root directory as source file
set(${PROJECT_NAME} test_master_szp.cpp)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(${PROJECT_NAME} test_master_szp.cpp)

# Link libraries to project
target_link_libraries(${PROJECT_NAME} szs_soundzone_protocol szs_datatransport)
