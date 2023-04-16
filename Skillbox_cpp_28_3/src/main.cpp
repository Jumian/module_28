#include <iostream>

#include "Dispatcher.h"
#include "Kitchen.h"
#include "Courier.h"
#include "OnlineShop.h"


int main() {
    Dispatcher dispatcher;
    dispatcher.threads.emplace_back(Kitchen::handler);
    dispatcher.threads.emplace_back(OnlineShop::work);
    dispatcher.threads.emplace_back(Courier::work);
    dispatcher.joinAll();
}
