cmake_minimum_required(VERSION 3.26)
project(cigifuggvenycpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(cigifuggvenycpp main.cpp
        src/c_error.cpp
        src/c_user.cpp
        src/c_system.cpp
        inc/c_user.h
        inc/c_error.h
        inc/c_system.h)
