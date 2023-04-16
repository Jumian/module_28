#pragma once

#include <chrono>
#include <random>

#include "OnlineShop.h"

class Courier{
    std::chrono::duration<double> timer;
public:
    static Courier* instance;
    Courier* Instance();
    Courier();
    static void work();

};