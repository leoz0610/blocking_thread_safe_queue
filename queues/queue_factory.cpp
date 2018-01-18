//
// Created by leoz on 1/13/18.
//


// application headers
#include "queue_factory.h"
#include "mutex_blocking_queue.h"
#include "condition_blocking_queue.h"


namespace BlockingQueue {
namespace Queues {

    std::shared_ptr<queue_base> queue_factory::create(queue_type type, int capacity) {
        std::shared_ptr<queue_base> queuePtr;

        switch (type) {
            case MUTEX:
                queuePtr.reset(new mutex_blocking_queue(capacity));
                break;
            case CONDITION:
                queuePtr.reset(new condition_blocking_queue(capacity));
                break;
        }
        return queuePtr;
    }

} // Queues
} // BlockingQueue