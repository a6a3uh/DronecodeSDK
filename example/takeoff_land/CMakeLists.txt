cmake_minimum_required(VERSION 2.8.12)

project(takeoff_and_land)

if(NOT MSVC)
    add_definitions("-std=c++11 -Wall -Wextra -Werror")
else()
    add_definitions("-std=c++11 -WX -W2")
endif()

find_package(DronecodeSDK REQUIRED)

add_executable(takeoff_and_land
    takeoff_and_land.cpp
)

target_link_libraries(takeoff_and_land
    DronecodeSDK::dronecode_sdk_telemetry
    DronecodeSDK::dronecode_sdk_action
    DronecodeSDK::dronecode_sdk
)
