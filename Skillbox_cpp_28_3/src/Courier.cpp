#include "Courier.h"

Courier* Courier::instance;

Courier::Courier() {
    timer=std::chrono::seconds(rand()%10 + 5);
}

Courier *Courier::Instance() {
    if (instance== nullptr) {
        instance=new Courier;
    }
    return instance;
}

void Courier::work() {
    int counter = 0;
    Order* currentOrder;
    while (true) {
        currentOrder = nullptr;
        if (counter > 9) break;
        while (currentOrder == nullptr) {
            currentOrder = OnlineShop::getFirstStage(Order::STAGE::READY);
        }
        if (currentOrder != nullptr) {
            currentOrder->setStage(Order::STAGE::DELIVERY);
            Inputs::print("[COURIER] Order " + Order::to_string(currentOrder->getType()) + " is " + Order::to_string(currentOrder->getStage()) + "\n");
            std::this_thread::sleep_for(std::chrono::seconds(5 + rand() % 10));
            currentOrder->setStage(Order::STAGE::DONE);
            Inputs::print("[COURIER] Order " + Order::to_string(currentOrder->getType()) + " is " + Order::to_string(currentOrder->getStage()) + "\n");
            counter++;
        }
    }
    Inputs::print("[COURIER] 10 orders was delivered");
}