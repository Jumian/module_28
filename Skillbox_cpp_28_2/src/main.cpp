#include <iostream>
#include "Inputs.h"
#include "Dispatcher.h"
#include "Train.h"




int main() {
    std::vector<Train*> trains;
    Dispatcher dispatcher;

    for (int i=0;i<TRAINS_COUNT;++i){
        trains.push_back(new Train(i,Station::Instance,Inputs::inputPosDouble("Train #" + std::to_string(i)+ ". Input time to station:")));
        dispatcher.threads.emplace_back(Train::pace,trains[i]);
    }
    dispatcher.threads.emplace_back(Station::handler);
    for(int i=0 ;i<trains.size();++i){
        trains.at(i)->start();
    }

    dispatcher.joinAll();

}
