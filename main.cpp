// std headers
#include <sstream>
#include <vector>
#include <thread>


// application headers
#include "queues/queue_factory.h"
#include "workers/producer_worker.h"
#include "workers/consumer_worker.h"


using namespace BlockingQueue;

void runWorker(std::shared_ptr<Workers::worker_base> worker) {
    worker->start();
}

int main() {
    int capacity(3);

    std::shared_ptr<Queues::queue_base> queue = Queues::queue_factory::create(Queues::CONDITION, capacity);

    std::vector<std::thread> threadList;
    int numOfProducer(3);
    int numOfConsumer(3);

    for (int i = 0; i < numOfProducer; ++i) {
        std::stringstream ss;
        ss << "P" << i;
        std::string name = ss.str();
        std::shared_ptr<Workers::worker_base> producer(new Workers::producer_worker(name, queue));
        threadList.push_back(std::thread(runWorker, producer));
    }

    for (int i = 0; i < numOfConsumer; ++i) {
        std::stringstream ss;
        ss << "C" << i;
        std::string name = ss.str();
        std::shared_ptr<Workers::worker_base> consumer(new Workers::consumer_worker(name, queue));
        threadList.push_back(std::thread(runWorker, consumer));
    }

    for (int i = 0; i < threadList.size(); ++i) {
        threadList[i].join();
    }
    return 0;
}