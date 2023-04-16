#include "Dispatcher.h"

void Dispatcher::joinAll() {
    if (threads.size()<=0) return;
    for (int i=0;i<threads.size();++i){
        if (threads[i].joinable()){
            threads[i].join();
        }
    }
}

