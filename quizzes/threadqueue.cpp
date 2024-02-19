
#include <iostream>
#include <thread>
#include <mutex>
#include <semaphore>

namespace ilrd
{
    template <class T>
    class Queue
    {

    public:
        Queue();
        Queue(size_t capacity_of_queue);
        ~Queue();
        bool QueueIsEmpty();
        size_t QueueSize();
        void EnQueue(T value);
        T DeQueue();
    private:
        Queue& operator=(const Queue& other)=delete;
        Queue(const Queue &other_)=delete;
        size_t capacity;
        size_t read_index;
        size_t write_index;
        size_t amount_of_items;
        std::mutex mutex1;
        std::mutex mutex2;
        std::sem add;
        std::sem remove;
        T *array;
    };
}

using namespace ilrd;

template <class T>
Queue<T>::Queue()
{
    array = new T[10];
    if (std::mutex_init(&mutex1, NULL) != 0)
    {
        std::cerr << "Mutex initialization error" << std::endl;
    }
    if (std::mutex_init(&mutex2, NULL) != 0)
    {
        std::cerr << "Mutex initialization error" << std::endl;
    }
    if (sem_init(&add, 0, 0) != 0)
    {
        std::cerr << "Semaphore initialization error" << std::endl;
    }
    if (sem_init(&remove, 0, 10) != 0)
    {
        std::cerr << "Semaphore initialization error" << std::endl;
    }
}

template <class T>
Queue<T>::Queue(size_t capacity_of_queue)
{
    array = new T[capacity_of_queue];
    if (std::mutex_init(&mutex1, NULL) != 0)
    {
        std::cerr << "Mutex initialization error" << std::endl;
    }
    if (std::mutex_init(&mutex2, NULL) != 0)
    {
        std::cerr << "Mutex initialization error" << std::endl;
    }
    if (sem_init(&add, 0, 0) != 0)
    {
        std::cerr << "Semaphore initialization error" << std::endl;
    }
    if (sem_init(&remove, 0, capacity_of_queue) != 0)
    {
        std::cerr << "Semaphore initialization error" << std::endl;
    }
}


template <class T>
Queue<T>::~Queue()
{
    pthread_mutex_destroy(mutex1);
	pthread_mutex_destroy(mutex2);
    sem_destroy(add);
    sem_destroy(remove);
    delete [] array;
}

template <class T>
Queue<T>::~Queue()
{
    pthread_mutex_destroy(&mutex1);
    pthread_mutex_destroy(&mutex2);
    sem_destroy(&add);
    sem_destroy(&remove);
    delete[] array;
}

template <class T>
bool Queue<T>::QueueIsEmpty()
{
    return (0 == amount_of_items);
}

template <class T>
size_t Queue<T>::QueueSize()
{
    return amount_of_items;
}

template <class T>
void Queue<T>::EnQueue(T value)
{
    std::unique_lock<std::mutex> lock(mutex1);
    sem_wait(&remove);
    array[read_index] = value;
    read_index = (read_index + 1) % capacity;
    sem_post(&add);
}


template <class T>
T Queue<T>::DeQueue()
{
    std::unique_lock<std::mutex> lock(mutex2);
    sem_wait(&add);

    T value = array[write_index];
    write_index = (write_index + 1) % capacity;

    sem_post(&remove);
    return value;
}