add_library(dronecode_sdk_geofence
    geofence.cpp
    geofence_impl.cpp
)

target_link_libraries(dronecode_sdk_geofence
    dronecode_sdk
)

set_target_properties(dronecode_sdk_geofence
    PROPERTIES COMPILE_FLAGS ${warnings}
)

target_include_directories(dronecode_sdk_geofence PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include/dronecode_sdk>
    )

install(TARGETS dronecode_sdk_geofence
    EXPORT dronecode-sdk-targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    )

install(FILES
    include/plugins/geofence/geofence.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/dronecode_sdk/plugins/geofence
)
