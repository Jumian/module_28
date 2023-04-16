#pragma once
#include <thread>
#include <vector>

class Dispatcher{
public:
    std::vector<std::thread> threads;
    void joinAll();
};