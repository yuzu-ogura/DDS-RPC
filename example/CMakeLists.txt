cmake_minimum_required(VERSION 3.21)

project("RTPSCalculator")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-narrowing")


set(RTPSCALCULATOR_COMMON_SOURCES_CXX CalculatorTopicsPubSubTypes.cxx CalculatorTopics.cxx CalculatorDDSProtocol.cxx CalculatorDDSAsyncSupport.cxx)
message(STATUS "Configuring RTPSCalculator libraries...")

set(RTPSCALCULATORCLIENT_SOURCES_CXX CalculatorProxy.cxx)
set(RTPSCALCULATORSERVER_SOURCES_CXX CalculatorServer.cxx)

add_library(Calculator STATIC ${RTPSCALCULATOR_COMMON_SOURCES_CXX} ${RTPSCALCULATOR_SOURCES_CXX})
target_include_directories(Calculator PRIVATE ${CMAKE_SOURCE_DIR}/include ${fastcdr_INCLUDE_DIR} ${fastrtps_INCLUDE_DIR})
target_link_libraries(Calculator fastcdr fastrtps)

add_library(CalculatorClient STATIC ${RTPSCALCULATORCLIENT_SOURCES_CXX})
target_compile_definitions(CalculatorClient PRIVATE BOOST_ALL_DYN_LINK EPROSIMA_ALL_DYN_LINK)
target_include_directories(CalculatorClient PRIVATE ${CMAKE_SOURCE_DIR}/include ${fastcdr_INCLUDE_DIR} ${fastrtps_INCLUDE_DIR})
target_link_libraries(CalculatorClient fastcdr fastrtps)

add_library(CalculatorServer STATIC ${RTPSCALCULATORSERVER_SOURCES_CXX})
target_include_directories(CalculatorServer PRIVATE ${CMAKE_SOURCE_DIR}/include ${fastcdr_INCLUDE_DIR} ${fastrtps_INCLUDE_DIR})
target_link_libraries(CalculatorServer fastcdr fastrtps)

message(STATUS "Configuring RTPSCalculator Server and Client examples...")
set(RTPSCALCULATORSERVEREXAMPLE_SOURCES_CXX CalculatorServerExample.cxx CalculatorServerImplExample.cxx) 
set(RTPSCALCULATORCLIENTEXAMPLE_SOURCES_CXX CalculatorClientExample.cxx) 

add_executable(CalculatorServerExample ${RTPSCALCULATORSERVEREXAMPLE_SOURCES_CXX})
target_include_directories(CalculatorServerExample PRIVATE ${CMAKE_SOURCE_DIR}/include ${fastcdr_INCLUDE_DIR} ${fastrtps_INCLUDE_DIR})
target_link_libraries(CalculatorServerExample CalculatorServer Calculator)
target_link_libraries(CalculatorServerExample DDS-RPC fastrtps fastcdr)

install(TARGETS CalculatorServerExample
    RUNTIME DESTINATION examples/C++/RTPSCalculator/${BIN_INSTALL_DIR})

add_executable(CalculatorClientExample ${RTPSCALCULATORCLIENTEXAMPLE_SOURCES_CXX})
target_include_directories(CalculatorClientExample PRIVATE ${CMAKE_SOURCE_DIR}/include ${fastcdr_INCLUDE_DIR} ${fastrtps_INCLUDE_DIR})
target_link_libraries(CalculatorClientExample CalculatorClient Calculator)
target_link_libraries(CalculatorClientExample DDS-RPC fastrtps fastcdr)

install(TARGETS CalculatorClientExample
    RUNTIME DESTINATION examples/C++/RTPSCalculator/${BIN_INSTALL_DIR})
