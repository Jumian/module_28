cmake_minimum_required(VERSION 3.23)

set(MY_INCLUDE ${CMAKE_SOURCE_DIR}/include)

add_executable(Skillbox_cpp_28_3 main.cpp Kitchen.cpp OnlineShop.cpp Courier.cpp Inputs.cpp Dispatcher.cpp)

target_include_directories(Skillbox_cpp_28_3 PUBLIC ${MY_INCLUDE})