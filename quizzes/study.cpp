


#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <chrono>


std::mutex m_mutex;
std::condition_variable m_cond;
bool flag = false;

void Wait()
{
    std::unique_lock<std::mutex> m_lock(m_mutex);
    std::cout << "lock" << std::endl;
    m_cond.wait(m_lock, [&]{return flag;});
    std::cout << "release" << std::endl;
}


void Release()
{
    std::cout << "sleep for 2 seconds" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cout << "release one" << std::endl;
    m_cond.notify_one();
    flag = true;

}

int main()
{
    std::thread t1(Wait);
    std::thread t2(Release);

    std::this_thread::sleep_for(std::chrono::seconds(4));

    t1.detach();
    t2.detach();
    
    return 0;
}
