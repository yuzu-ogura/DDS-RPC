###############################################################################
# CMake build rules for RPC                                                    
###############################################################################
project(DDS-RPC)
cmake_minimum_required(VERSION 3.20)

# Set CMAKE_BUILD_TYPE to Release by default.
if(NOT CMAKE_BUILD_TYPE)
    message(STATUS "Setting build type to 'Release' as none was specified.")
    set(CMAKE_BUILD_TYPE Release CACHE STRING
        "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel."
        FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

###############################################################################
# Default shared libraries
###############################################################################
# Global flag to cause add_library() to create shared libraries if on.
# If set to true, this will cause all libraries to be built shared
# unless the library was explicitly added as a static library.
option(BUILD_SHARED_LIBS "Create shared libraries by default" ON)

set(${PROJECT_NAME}_source_files
    client/Proxy.cpp
    exceptions/BadParamException.cpp
    exceptions/ClientInternalException.cpp
    exceptions/IncompatibleException.cpp
    exceptions/InitializeException.cpp
    exceptions/ServerInternalException.cpp
    exceptions/ServerNotFoundException.cpp
    exceptions/ServerTimeoutException.cpp
    exceptions/SystemException.cpp
    protocols/dds/MessageHeader.cxx
    protocols/dds/MessageHeaderPubSubTypes.cxx
    server/Server.cpp
    strategies/SingleThreadStrategy.cpp
    strategies/ThreadPerRequestStrategy.cpp
    strategies/ThreadPoolStrategy.cpp
    transports/dds/components/RTPSProxyProcedureEndpoint.cpp
    transports/dds/components/RTPSServerProcedureEndpoint.cpp
    transports/dds/RTPSProxyTransport.cpp
    transports/dds/RTPSServerTransport.cpp
    transports/dds/RTPSTransport.cpp
)

add_library(${PROJECT_NAME} ${${PROJECT_NAME}_source_files})

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${fastcdr_INCLUDE_DIR}
    ${fastrtps_INCLUDE_DIR}
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    fastcdr
    fastrtps
)