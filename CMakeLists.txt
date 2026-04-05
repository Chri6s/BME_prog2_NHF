cmake_minimum_required(VERSION 3.10)

project(Sportkozpont CXX)
if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    message(FATAL_ERROR "Ne a mainben buildelj! csinalj egy build mappat: mkdir build && cd build && cmake ..")
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# Ide a library modulokat kulon definialni kell egyenkent, most meg csak placeholder
#add_subdirectory(libs/my_string)

add_executable(sportkozpont src/main.cpp)

# Itt a library modulokat kulon meg kell adni a linkernek
#target_link_libraries(sportkozpont PRIVATE my_string)


