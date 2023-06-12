cmake_minimum_required(VERSION 3.0.0)
project(personManagment VERSION 0.1.0 LANGUAGES C CXX)

#include(CTest)
#enable_testing()

aux_source_directory(src SRC)
aux_source_directory(. CRC)
add_executable(personManagment ${SRC} ${CRC})

#set(CPACK_PROJECT_NAME ${PROJECT_NAME}) 
#set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include_directories(src)