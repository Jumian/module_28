#pragma once
#include <vector>
#include <thread>
#include <mutex>
#include "Kitchen.h"
#include "Courier.h"

#include "Inputs.h"

#define TYPE_COUNT 6
#define STAGE_COUNT 6

class Kitchen;
class Courier;

class Order{
public:
    enum TYPE{
        NOTHING, PIZZA, SOUP, STEAK, SALAD, SUSHI,
    };
    enum STAGE{
        UNKNOWN, CONFIRMED, COOKING, READY, DELIVERY,DONE,
    };
    
    std::mutex order_access;
    static std::string TYPE_STR[];
    static std::string STAGE_STR[];
    static std::string to_string(TYPE type);
    static std::string to_string(STAGE stage);
    
    explicit Order(TYPE type,STAGE stage);
    TYPE getType();
    void setType(TYPE type);
    STAGE getStage();
    void setStage(STAGE stage);

    void printOrderState();

private:
    TYPE type;
    STAGE stage;
};

class OnlineShop{
public:
    static Order* getConfirmed();
    static std::mutex db_access;
    static std::vector<Order*> ordersDB;
    static void order(Order::TYPE type);
    static void work();
    static Order* getFirstStage(Order::STAGE stage);
};