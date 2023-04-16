#include "Station.h"

class Station;
class Train;


Station* Station::Instance = new Station();

std::mutex Station::laneAccess;
std::mutex Station::queAccess;
int Station::queCur=0;
std::vector<Train*> Station::que;

void Station::arriving(Train* train) {
    if (train== nullptr) return;
    enque(train);
}

void Station::enque(Train *train) {
    queAccess.lock();
    Inputs::print("Train #"+ std::to_string(train->id)+" waiting in que..\n");
    que.push_back(train);
    queAccess.unlock();
}

Train *Station::deque() {
    if (!que.empty() && queCur >=0 && (que.size()-1)>=(queCur)){
        queAccess.lock();
        Train* train=que.at(queCur++);
        Inputs::print("Train #"+ std::to_string(train->id)+" left que..\n");
        queAccess.unlock();
        return train;
    }
    else
    return nullptr;
}

void Station::handler() {
    Train* pTrain= nullptr;
    int trainCounter=0;
    while (trainCounter<TRAINS_COUNT){
        pTrain=deque();
        if (pTrain!= nullptr){
            laneAccess.lock();
            pTrain->arrived();
            pTrain= nullptr;
            trainCounter++;
            laneAccess.unlock();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
}
