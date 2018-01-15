//
// Created by leoz on 1/14/18.
//

#ifndef BLOCKING_THREAD_SAFE_QUEUE_MUTEX_BLOCKING_QUEUE_H
#define BLOCKING_THREAD_SAFE_QUEUE_MUTEX_BLOCKING_QUEUE_H


// std headers
#include <mutex>
#include <list>


// application headers
#include "queue_base.h"


namespace BlockingQueue {
namespace Queues {


    class mutex_blocking_queue final : public queue_base {
    private:
        std::mutex queueLock;
        std::list<int> dataQueue;

        bool tryPushItem(int item);

        bool tryPollItem(int *item);

    public:
        explicit mutex_blocking_queue(int &capacity)
            : queue_base(capacity)
            , dataQueue()
        { }

        ~mutex_blocking_queue() override = default;

        void push(int item) override final;

        int poll() override final;
    };

} // Queues
} // BlockingQueue


#endif //BLOCKING_THREAD_SAFE_QUEUE_MUTEX_BLOCKING_QUEUE_H
