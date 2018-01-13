// std headers
#include <sstream>
#include <vector>
#include <thread>


// application headers
#include "queues/queue_factory.h"
#include "workers/producer_worker.h"


using namespace BlockingQueue;

void runWorker(Workers::worker_base *worker) {
    worker->start();
}

int main() {
    int capacity(3);

    std::shared_ptr<Queues::queue_base> queue = Queues::queue_factory::create(capacity);

    std::vector<std::thread> threadList;
    int numOfProducer(3);

    for (int i = 0; i < numOfProducer; ++i) {
        std::stringstream ss;
        ss << "P" << i;
        std::string name = ss.str();
        threadList.push_back(std::thread(runWorker, new Workers::producer_worker(name, queue)));
    }

    for (int i = 0; i < threadList.size(); ++i) {
        threadList[i].join();
    }
    return 0;
}