//
// Created by leoz on 1/13/18.
//

#include "queue_factory.h"

namespace BlockingQueue {
namespace Queues {

    std::shared_ptr<queue_base> queue_factory::create(const int capacity) {
        std::shared_ptr<queue_base> queuePtr;

        return queuePtr;
    }

} // Queues
} // BlockingQueue