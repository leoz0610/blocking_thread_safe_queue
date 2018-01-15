//
// Created by leoz on 1/13/18.
//

// std headers
#include <sstream>
#include <thread>


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

        while (true) {
            int item = getRandomNumber();
            std::stringstream ss;
            ss << workerName << " produces item " << item;

            printf("%s\n", ss.str().c_str());

            try {
                queue->push(item);
            } catch (const std::exception &ex) {
                std::stringstream errstr;
                errstr << "Error: " << ex.what();
                printf("%s\n", errstr.str().c_str());
            }

            std::this_thread::sleep_for(std::chrono::seconds(3));
        }
    }

} // Workers
} // BlockingQueue