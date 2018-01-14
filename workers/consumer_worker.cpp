//
// Created by leoz on 1/14/18.
//


// application headers
#include "consumer_worker.h"


namespace BlockingQueue {
namespace Workers {

    // Constructor
    consumer_worker::consumer_worker(std::string &name, std::shared_ptr<Queues::queue_base> queue)
    : worker_base(name, queue)
    { }

    // Public members
    void consumer_worker::start() {
        printf("Consumer thread %s starting...\n", workerName.c_str());
    }

} // Workers
} // BlockingQueue