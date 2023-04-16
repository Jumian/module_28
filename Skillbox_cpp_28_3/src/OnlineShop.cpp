#include "OnlineShop.h"

std::mutex OnlineShop::db_access;
//std::mutex Order::order_access;
std::vector<Order*> OnlineShop::ordersDB;
std::string Order::TYPE_STR[]={ "NOTHING","PIZZA", "SOUP", "STEAK", "SALAD", "SUSHI"};
std::string Order::STAGE_STR[]={"UNKNOWN", "CONFIRMED", "COOKING", "READY", "DELIVERY","DONE"};

void OnlineShop::work() {
    int i = 0;
    for(;i<10;++i){
        Order::TYPE ttype=(Order::TYPE)(rand()%5+1);
        Inputs::print("[SHOP] New order for " + Order::to_string(ttype) + "\n");
        OnlineShop::order(ttype);
        if (i >= 9) break;
        std::this_thread::sleep_for(std::chrono::seconds(rand()%5+10));
    }
    Inputs::print("[SHOP] 10 orders received");
}

void OnlineShop::order(Order::TYPE type) {
    db_access.lock();
    ordersDB.emplace_back(new Order(type,Order::STAGE::CONFIRMED));
    db_access.unlock();
}

std::string Order::to_string(TYPE type) {
    if (type<0 || type >= TYPE_COUNT) return TYPE_STR[0];
    return TYPE_STR[type];
}
std::string Order::to_string(STAGE stage) {
    if (stage < 0 || stage >= STAGE_COUNT) return STAGE_STR[0];
    return STAGE_STR[stage];
}

Order::Order(Order::TYPE type, STAGE stage=STAGE::UNKNOWN) {
  
    this->setType(type);
    if (stage != STAGE::UNKNOWN) { this->setStage(stage); }
    else { this->setStage(STAGE::CONFIRMED); }
  
}

Order::TYPE Order::getType() {
    
    return this->type;
   
}

void Order::setType(Order::TYPE type) {
   
    if (type < 0 || type >= TYPE_COUNT) { this->type = TYPE::NOTHING;  }
    else { this->type = type; }
}

Order::STAGE Order::getStage() {
   
    return stage;
   
}

void Order::setStage(Order::STAGE stage) {
   
    if (stage<0 || stage>=STAGE_COUNT)
        stage = STAGE::UNKNOWN;
    this->stage = stage;
  
}

void Order::printOrderState() {
    Inputs::print("Order "+ Order::to_string(getType()) + " status is "+ Order::to_string(getStage()) + "\n");
}

Order* OnlineShop::getConfirmed() {
    
    Order* result = nullptr;
    for(int i=0;i<ordersDB.size();++i){
        db_access.lock();
        if(!ordersDB.empty() && ordersDB.at(i)->getStage() == Order::STAGE::CONFIRMED){
            result = ordersDB.at(i);
        }
        db_access.unlock();
    }
    
    return result;
}


Order* OnlineShop::getFirstStage(Order::STAGE stage) {

    Order* result = nullptr;
    for (int i = 0; i < ordersDB.size(); ++i) {
        db_access.lock();
        if (!ordersDB.empty() && ordersDB.at(i)->getStage() == stage) {
            result = ordersDB.at(i);
        }
        db_access.unlock();
    }

    return result;
}

