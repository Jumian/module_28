cmake_minimum_required(VERSION 3.23)
project(Skillbox_cpp_28_2)
set(MY_INCLUDE ${CMAKE_SOURCE_DIR}/include)

add_executable(Skillbox_cpp_28_2 main.cpp Dispatcher.cpp Inputs.cpp Train.cpp Station.cpp Timer.cpp)
target_include_directories(Skillbox_cpp_28_2 PUBLIC ${MY_INCLUDE})
