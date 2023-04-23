#include "Swimmer.h"
#include "Dispatcher.h"
#include <string>


Swimmer::Swimmer(const int id, const double speed=0) {
    this->id=id;
    this->speed=speed;
    distanceTraveled=0;
    time_past=std::chrono::seconds(0);
    isSwimming= false;
}

void Swimmer::update() {
    if (isSwimming) {
        std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
        time_past = std::chrono::duration<double, std::chrono::seconds::period>(now - start_time);
        distanceTraveled = time_past.count() * speed;
    }
}

#define PRECISION 20 // ms
void Swimmer::pace(Swimmer* swimmer){
    swimmer->start_time = std::chrono::high_resolution_clock::now();
    int counter=0, maxCount=1000/PRECISION;
    if (1000%PRECISION) ++maxCount;

    while(true) {

        swimmer->update();
        if (counter<maxCount) ++counter;
        else {
            Inputs::print( "Swimmer #" + std::to_string(swimmer->id)+ " distance: "+std::to_string(swimmer->distanceTraveled)+"\n");
            counter=0;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(PRECISION));
        if (swimmer->distanceTraveled >= 100)
        {
            swimmer->isSwimming= false;
            swimmer->stop_time = std::chrono::high_resolution_clock::now();
            swimmer->time_past=std::chrono::duration<double>(swimmer->stop_time - swimmer->start_time);
            return;
        }
    }
}

void Swimmer::start(std::chrono::high_resolution_clock::time_point start) {
    start_time=start;
    isSwimming= true;
}

void Swimmer::print_time() {
    Inputs::print("Swimmer #" +std::to_string(id) +" time: "+ std::to_string(time_past.count()) + " s\n");
}
