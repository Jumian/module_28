#pragma once
#include "OnlineShop.h"
#include <mutex>

class Kitchen {
public:
    static Kitchen* instance;
    static std::mutex kitchen_access;
    static void handler();
};