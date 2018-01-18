//
// Created by leoz on 1/13/18.
//

#ifndef BLOCKING_THREAD_SAFE_QUEUE_QUEUE_FACTORY_H
#define BLOCKING_THREAD_SAFE_QUEUE_QUEUE_FACTORY_H

// std headers
#include <memory>

// application headers
#include "queue_base.h"


namespace BlockingQueue {
namespace Queues {
    enum queue_type {
        MUTEX,
        CONDITION
    };

    struct queue_factory final {
        static std::shared_ptr<queue_base> create(queue_type type, const int capacity);
    };

} // Queues
} // BlockingQueue



#endif //BLOCKING_THREAD_SAFE_QUEUE_QUEUE_FACTORY_H
