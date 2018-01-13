cmake_minimum_required(VERSION 3.8)
project(blocking_thread_safe_queue)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(blocking_thread_safe_queue ${SOURCE_FILES})