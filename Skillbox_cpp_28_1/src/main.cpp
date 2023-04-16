#include <iostream>
#include <thread>
#include <mutex>
#include <cmath>
#include <ctime>
#include "Dispatcher.h"
#include "Swimmer.h"


#define LANES 6

std::mutex cout_access;

int main() {
    std::vector<Swimmer*> swimmers;
    Dispatcher dispatcher;
    for(int i=0;i<LANES;++i){
        swimmers.push_back(new Swimmer(i,Inputs::inputPosDouble("Input speed for swimmer #" + std::to_string(i)+":")));
    }
    std::chrono::time_point<std::chrono::high_resolution_clock> start_time = std::chrono::high_resolution_clock::now();
    for (int i=0;i<swimmers.size();++i){
        dispatcher.threads.emplace_back(Swimmer::pace,swimmers[i]);
        swimmers[i]->start(start_time);
    }
    dispatcher.joinAll();
    for (int i=0;i<swimmers.size();++i){
        swimmers[i]->print_time();
    }
}
