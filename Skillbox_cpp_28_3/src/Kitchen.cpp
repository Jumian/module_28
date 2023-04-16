#include "Kitchen.h"
#include <thread>


std::mutex Kitchen::kitchen_access;

Kitchen* Kitchen::instance=new Kitchen;

void Kitchen::handler() {
    int counter=0;
    Order* currentOrder;
    while (true){
        currentOrder = nullptr;
        if (counter >= 10) break;
        while (currentOrder == nullptr) {
            currentOrder = OnlineShop::getFirstStage(Order::STAGE::CONFIRMED);
        }
        if (currentOrder != nullptr) {
            currentOrder->setStage(Order::STAGE::COOKING);
            Inputs::print("[KITCHEN] Order " + Order::to_string(currentOrder->getType()) + " is " + Order::to_string(currentOrder->getStage()) + "\n");
            std::this_thread::sleep_for(std::chrono::seconds(5 + rand() % 10));
            currentOrder->setStage(Order::STAGE::READY);
            Inputs::print("[KITCHEN] Order " + Order::to_string(currentOrder->getType()) + " is " + Order::to_string(currentOrder->getStage()) + "\n");
            
            
            counter++;
        }
    }
    Inputs::print("[KITCHEN] 10 orders was cooked");
}
