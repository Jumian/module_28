#include <string>
#include "Train.h"
#include "Dispatcher.h"
#include "Timer.h"

Train::Train(const int id,Station* station, const double timeToStation=0.1) {
    this->id=id;
    this->station=station;
    estimated_time=std::chrono::duration<double, std::chrono::seconds::period>(timeToStation);
    isMoving= false;
}

void Train::update() {
    if (isMoving) {
        std::chrono::time_point<std::chrono::high_resolution_clock, std::chrono::duration<double>> now = Timer::time_now();
    }
}

#define PRECISION 200 // ms
void Train::pace(Train* train){
    train->start_time = Timer::time_now();
    train->arrival_time = std::chrono::time_point<std::chrono::high_resolution_clock, std::chrono::duration<double>>(train->start_time + train->estimated_time);

    while(true) {

        train->update();
        if (std::chrono::duration<double>(train->arrival_time-Timer::time_now()).count()<0)
        {
            train->isMoving= false;
            train->arrival_time = Timer::time_now();
            train->estimated_time=std::chrono::duration<double>(train->arrival_time - train->start_time);
            train->arrive(train->station);
            return;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(PRECISION));
    }
}

void Train::start(std::chrono::high_resolution_clock::time_point start) {
    start_time=start;
    arrival_time = std::chrono::time_point<std::chrono::high_resolution_clock, std::chrono::duration<double>>(start_time + estimated_time);
    isMoving= true;
}

void Train::print_time() {
    Inputs::print("Train #" + std::to_string(id) + " time: " + std::to_string(estimated_time.count()) + " s\n");
}

void Train::arrive(Station* station) {
    station->enque(this);
}

void Train::arrived() {
    Inputs::print("Train #"+ std::to_string(id)+ " is arrived!\n" );
    while(Inputs::inputStr("Input \"depart\" command for train departure:")!="depart"){
        Inputs::print( "Train #"+ std::to_string(id)+"Try again\n");
    }
    Inputs::print("Train #"+ std::to_string(id)+ " is departed!\n" );
}


void MovingUnit::start(std::chrono::high_resolution_clock::time_point start) {}
