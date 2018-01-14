//
// Created by leoz on 1/13/18.
//

#ifndef BLOCKING_THREAD_SAFE_QUEUE_PRODUCER_WORKER_H
#define BLOCKING_THREAD_SAFE_QUEUE_PRODUCER_WORKER_H


// application headers
#include "worker_base.h"


namespace BlockingQueue {
namespace Workers {

    class producer_worker final : public worker_base {
    public:
        producer_worker() = default;

        producer_worker(std::string &name, std::shared_ptr<Queues::queue_base> queue);

        ~producer_worker() override = default;

        void start() override final;
    };
} // Workers
} // BlockingQueue


#endif //BLOCKING_THREAD_SAFE_QUEUE_PRODUCER_WORKER_H
