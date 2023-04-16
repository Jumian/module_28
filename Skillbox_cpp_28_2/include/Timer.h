#pragma once
#include <chrono>
#include <thread>
#include <mutex>
class Timer{

    static std::mutex time_access;
public:
    static std::chrono::time_point<std::chrono::high_resolution_clock,
    std::chrono::duration<double, std::chrono::seconds::period>> time_now();
};
