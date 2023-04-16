cmake_minimum_required(VERSION 3.23)

set(MY_INCLUDE ${CMAKE_SOURCE_DIR}/include)

add_executable(Skillbox_cpp_28_1 main.cpp Dispatcher.cpp Inputs.cpp Swimmer.cpp)

target_include_directories(Skillbox_cpp_28_1 PUBLIC ${MY_INCLUDE})