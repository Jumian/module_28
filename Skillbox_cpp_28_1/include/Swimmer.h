#pragma once
#include "Inputs.h"
#include <chrono>

class Sportsman{
protected:
    std::chrono::high_resolution_clock::time_point start_time;
    std::chrono::high_resolution_clock::time_point stop_time;
    std::chrono::duration<double,std::chrono::seconds::period> time_past;
public:
    void start(std::chrono::high_resolution_clock::time_point start);
};

class Swimmer : public Sportsman{
public:
    Swimmer(int id, double speed);
    void update();
    int id;
    bool isSwimming;
    double speed;
    double distanceTraveled;
    static void pace(Swimmer* swimmer);
    void print_time();
    void start(std::chrono::high_resolution_clock::time_point start=std::chrono::high_resolution_clock::now());
};
