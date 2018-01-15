cmake_minimum_required(VERSION 3.8)
project(blocking_thread_safe_queue)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp workers/worker_base.cpp workers/worker_base.h queues/queue_base.cpp queues/queue_base.h workers/producer_worker.cpp workers/producer_worker.h queues/queue_factory.cpp queues/queue_factory.h workers/consumer_worker.cpp workers/consumer_worker.h queues/mutex_blocking_queue.cpp queues/mutex_blocking_queue.h)
add_executable(blocking_thread_safe_queue ${SOURCE_FILES})