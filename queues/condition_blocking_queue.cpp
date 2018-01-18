//
// Created by leoz on 1/15/18.
//

// application headers
#include "condition_blocking_queue.h"


namespace BlockingQueue {
namespace Queues {

    void condition_blocking_queue::push(int item) {
        std::unique_lock<std::mutex> lc(queueLock);

        while (dataQueue.size() >= capacity) {
            full.wait(lc);
        }

        dataQueue.push_back(item);
        empty.notify_all();
    }

    int condition_blocking_queue::poll() {
        std::unique_lock<std::mutex> lc(queueLock);

        while (dataQueue.empty()) {
            empty.wait(lc);
        }

        int item = dataQueue.front();
        dataQueue.pop_front();
        full.notify_all();
        return item;
    }

} // Queues
} // BlockingQueue