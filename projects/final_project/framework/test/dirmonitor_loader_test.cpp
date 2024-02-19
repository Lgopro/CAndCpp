/*
Rev: Ido Issacs.
Dev: Leonid Golovko
status: finished
date: 28/09/2023
*/
#include "dirmonitor.hpp"
#include "dll_loader.hpp"

#include <unistd.h>
using namespace ilrd;

class ViewWindow : public ACallBack<std::string>
{
    
    public:
    ViewWindow(const std::string& value) : ACallBack<std::string>(), m_value(value){}
    ~ViewWindow(){};
    void Notify(const std::string& data)
    {
        std::cout << "The operation ViewWindow is connected to: " << m_value << "with the data of: "<< data <<std::endl;
    }

    void NotifyDeathExtended()
    {
        std::cout << "Oh no ViewWindow dead!" <<std::endl;
    }
    private:
    std::string m_value;
};

void TestDirMonitor()
{
    char buffer[200];
    getcwd(buffer, 200);
    std::string str = buffer;
    DirMonitor monitor(str);

    ACallBack<std::string> * event1 = new ViewWindow("What");
    ACallBack<std::string> * event2 = new ViewWindow("Hehe boy!");
    ACallBack<std::string> * event3 = new ViewWindow("=)");

    std::cout << "Before register" <<std::endl;

    monitor.Register(event1);
    monitor.Register(event2);
    monitor.Register(event3);

    std::cout << "Before run" <<std::endl;
    monitor.Run();

    sleep(15);
  
  
    delete event1;
    delete event2;
    delete event3;
}


void TestDLLLoader()
{
    DllLoader loader;
    void *load1 = loader.GenericLoad("library1.so");
    std::cout << "library1.so loaded" <<std::endl;
    void *load2 = loader.GenericLoad("library2.so");
    std::cout << "library2.so loaded" <<std::endl;
    void *load3 = loader.GenericLoad("library3.so");
    std::cout << "library3.so loaded" <<std::endl;
    dlclose(load1);
    dlclose(load2);
    dlclose(load3);
}


int main()
{
    TestDirMonitor();
    TestDLLLoader();
    return 0;
}