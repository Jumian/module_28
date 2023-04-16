#include "Timer.h"

#define TIME_ACCESS_MUTEX_ENABLE
//#undef TIME_ACCESS_MUTEX_ENABLE

std::mutex Timer::time_access;

std::chrono::time_point<std::chrono::high_resolution_clock,
        std::chrono::duration<double, std::chrono::seconds::period>> Timer::time_now() {
#ifdef TIME_ACCESS_MUTEX_ENABLE
    Timer::time_access.lock();
#endif
    std::chrono::time_point<std::chrono::high_resolution_clock,
            std::chrono::duration<double, std::chrono::seconds::period>> time_now = std::chrono::high_resolution_clock::now();
#ifdef TIME_ACCESS_MUTEX_ENABLE
    Timer::time_access.unlock();
#endif
    return time_now;
}
