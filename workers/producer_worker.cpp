//
// Created by leoz on 1/13/18.
//

// std headers


// application headers
#include "producer_worker.h"


namespace BlockingQueue {
namespace Workers {

    // Constructor
    producer_worker::producer_worker(std::string &name, std::shared_ptr<Queues::queue_base> queue)
    : worker_base(name, queue)
    {}

    // Public members
    void producer_worker::start() {
        printf("Producer thread %s starting...\n", workerName.c_str());
    }

} // Workers
} // BlockingQueue