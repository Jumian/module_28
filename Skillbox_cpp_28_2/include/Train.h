#pragma once
#include <string>
#include <chrono>
#include "Inputs.h"
#include "Station.h"

#define TRAINS_COUNT 3

class Station;
class MovingUnit{
protected:
    std::chrono::time_point<
            std::chrono::high_resolution_clock,
            std::chrono::duration<double,std::chrono::seconds::period>> start_time, arrival_time;
    std::chrono::duration<double,std::chrono::seconds::period> estimated_time;
public:
    void start(std::chrono::high_resolution_clock::time_point start=std::chrono::high_resolution_clock::now());
};

class Train : public MovingUnit{
public:
    Train(int id,Station* station ,double timeToStation);
    void update();
    int id;
    bool isMoving;
    double speed;
    Station* station;
    static void pace(Train* train);
    void print_time();
    void start(std::chrono::high_resolution_clock::time_point start=std::chrono::high_resolution_clock::now());
    void arrive(Station* station);
    void arrived();
};
