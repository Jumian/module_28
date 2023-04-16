#pragma once
#include <thread>
#include <vector>
#include "Swimmer.h."
#include <string>

class Dispatcher{
public:
    std::vector<std::thread> threads;
    void joinAll();
};