#pragma once
#include <mutex>
#include <vector>
#include <thread>
#include "Train.h"
class Train;
class Station {
public:
    static Station* Instance;
    static std::mutex queAccess;
    static std::mutex laneAccess;
    static void handler();
    static void arriving(Train* train= nullptr);
    static void enque(Train*);
    static Train* deque();
    static int queCur;
    static std::vector<Train*> que;
    ~Station() { delete Instance; }
};