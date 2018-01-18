//
// Created by leoz on 1/15/18.
//

#ifndef BLOCKING_THREAD_SAFE_QUEUE_CONDITION_BLOCKING_QUEUE_H
#define BLOCKING_THREAD_SAFE_QUEUE_CONDITION_BLOCKING_QUEUE_H

// std headers
#include <list>
#include <mutex>
#include <condition_variable>


// application headers
#include "queue_base.h"


namespace BlockingQueue {
namespace Queues {

    class condition_blocking_queue final : public queue_base {
    private:
        std::mutex queueLock;
        std::list<int> dataQueue;
        std::condition_variable empty;
        std::condition_variable full;


    public:
        explicit condition_blocking_queue(int &capacity)
            : queue_base(capacity)
            , dataQueue()
        { }

        ~condition_blocking_queue() override = default;

        void push(int item) override final;

        int poll() override final;
    };

} // Queues
} // BlockingQueue


#endif //BLOCKING_THREAD_SAFE_QUEUE_CONDITION_BLOCKING_QUEUE_H
