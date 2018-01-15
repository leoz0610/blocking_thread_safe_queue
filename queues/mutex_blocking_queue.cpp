//
// Created by leoz on 1/14/18.
//

// std headers
#include <chrono>
#include <thread>


// application headers
#include "mutex_blocking_queue.h"


namespace BlockingQueue {
namespace Queues {

    // Private members
    bool mutex_blocking_queue::tryPushItem(int item){
        std::unique_lock<std::mutex> lc(queueLock);
        if (dataQueue.size() < capacity) {
            dataQueue.push_back(item);
            return true;
        }

        return false;
    }

    bool mutex_blocking_queue::tryPollItem(int *item) {
        std::unique_lock<std::mutex> lc(queueLock);
        if (!dataQueue.empty()) {
            *item = dataQueue.front();
            dataQueue.pop_front();
            return true;
        }

        return false;
    }

    // Public members
    void mutex_blocking_queue::push(int item) {
        while (!tryPushItem(item)) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }

    int mutex_blocking_queue::poll() {
        int item(0);

        while (!tryPollItem(&item)) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }

        return item;
    }

} // Queues
} // BlockingQueue