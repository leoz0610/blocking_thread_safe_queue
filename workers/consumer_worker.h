//
// Created by leoz on 1/14/18.
//

#ifndef BLOCKING_THREAD_SAFE_QUEUE_CONSUMER_WORKER_H
#define BLOCKING_THREAD_SAFE_QUEUE_CONSUMER_WORKER_H


// application headers
#include "worker_base.h"


namespace BlockingQueue {
namespace Workers {

    class consumer_worker final : public worker_base {
    public:
        consumer_worker() = default;

        consumer_worker(std::string &name, std::shared_ptr<Queues::queue_base> queue);

        ~consumer_worker() override = default;

        void start() override final;
    };

} // Workers
} // BlockingQueue



#endif //BLOCKING_THREAD_SAFE_QUEUE_CONSUMER_WORKER_H
