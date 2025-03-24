project(DDS-RPC)
cmake_minimum_required(VERSION 3.21)

find_package(fastcdr REQUIRED)
find_package(fastrtps REQUIRED)
###############################################################################
# Installation paths
###############################################################################
set(INCLUDE_INSTALL_DIR include/ CACHE PATH "Installation directory for C++ headers")
set(LIB_INSTALL_DIR lib/ CACHE PATH "Installation directory for libraries")
###############################################################################
# Compile library.
###############################################################################
add_subdirectory(src)
###############################################################################
# Examples 
###############################################################################
add_subdirectory(example)