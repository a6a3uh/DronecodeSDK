cmake_minimum_required(VERSION 2.8.12)

project(multiple_drones)

find_package(Threads REQUIRED)

if(NOT MSVC)
    add_definitions("-std=c++11 -Wall -Wextra -Werror")
else()
    add_definitions("-std=c++11 -WX -W2")
endif()

find_package(DronecodeSDK REQUIRED)

add_executable(multiple_drones
    multiple_drones.cpp
)

target_link_libraries(multiple_drones
    DronecodeSDK::dronecode_sdk_telemetry
    DronecodeSDK::dronecode_sdk_action
    DronecodeSDK::dronecode_sdk
    ${CMAKE_THREAD_LIBS_INIT}
)
