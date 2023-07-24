cmake_minimum_required(VERSION 3.22)
project("ControlExe")

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS "-Wall -Wextra -std=c11")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS_DEBUG} -fprofile-arcs -fno-omit-frame-pointer -fsanitize=address")


file(GLOB LIB_SOURCES lib/*.c)
file(GLOB LIB_HEADERS lib/*.h)

add_library(ControlLib ${LIB_SOURCES} ${LIB_HEADERS})

add_executable(TempController control.c)
target_link_libraries(TempController ControlLib)
