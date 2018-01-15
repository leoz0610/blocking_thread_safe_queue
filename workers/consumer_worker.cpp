//
// Created by leoz on 1/14/18.
//


// std headers
#include <sstream>
#include <thread>


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

        while (true) {
            try {
                int item = queue->poll();
                std::stringstream ss;
                ss << workerName << " consumes item " << item;

                printf("%s\n", ss.str().c_str());
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