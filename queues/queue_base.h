//
// Created by leoz on 1/13/18.
//

#ifndef BLOCKING_THREAD_SAFE_QUEUE_QUEUE_BASE_H
#define BLOCKING_THREAD_SAFE_QUEUE_QUEUE_BASE_H

namespace BlockingQueue {
namespace Queues {

    class queue_base {
    protected:
        const int capacity;

    public:
        explicit queue_base(int &capacity) : capacity(capacity) { }

        virtual ~queue_base() = 0;

        virtual void push(int item) = 0;

        virtual int poll() = 0;
    };


} // Queues
} // BlockingQueue




#endif //BLOCKING_THREAD_SAFE_QUEUE_QUEUE_BASE_H
