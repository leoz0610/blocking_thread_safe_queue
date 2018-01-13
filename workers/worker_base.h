//
// Created by leoz on 1/13/18.
//

#ifndef BLOCKING_THREAD_SAFE_QUEUE_WORKER_BASE_H
#define BLOCKING_THREAD_SAFE_QUEUE_WORKER_BASE_H

//std headers
#include <string>
#include <memory>


//application headers
#include "../queues/queue_base.h"


namespace BlockingQueue {
namespace Workers {

    class worker_base {
    protected:
        const std::string workerName;

        const std::shared_ptr<Queues::queue_base> queue;

    public:
        worker_base() = default;

        worker_base(std::string &name, std::shared_ptr<Queues::queue_base> queue)
                : workerName(name)
                , queue(queue)
        {}

        virtual ~worker_base() = default;

        const std::string& getWorkerName() const {
            return workerName;
        }

        virtual void start() = 0;
    };

} // Workers
} // BlockingQueue


#endif //BLOCKING_THREAD_SAFE_QUEUE_WORKER_BASE_H
