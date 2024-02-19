

#include "dispatcher.hpp"
using namespace ilrd;

template<typename EVENT>
class My_ObjectClass
{
    public:
    My_ObjectClass() = default;
    ~My_ObjectClass() = default;

    void Notify(const EVENT& value)
    {
        std::cout << "Im Alive!: " << value <<std::endl;
    }
    void DeathFunc()
    {
        std::cout << "Im Dead!" <<std::endl;
    }

   
};

class TestEvent
{
    public:
    TestEvent(const std::string& event): m_event(event){}

    std::string m_event;
};


class ViewWindow : public ACallBack<TestEvent>
{
    
    public:
    ViewWindow() : ACallBack<TestEvent>(){}
    ~ViewWindow(){};
    void Notify(const TestEvent& data)
    {
        std::cout << "The operation ViewWindow is connected to: " << data.m_event << ". Now Work on it!" <<std::endl;
    }

    void NotifyDeathExtended()
    {
        std::cout << "Oh no ViewWindow dead!" <<std::endl;
    }
};

class DataModel : public ACallBack<TestEvent>
{
    
    public:
    DataModel() : ACallBack<TestEvent>(){}
    ~DataModel(){};
    void Notify(const TestEvent& data)
    {
        std::cout << "The operation DataModel is connected to: " << data.m_event << ". Now Work on it!" <<std::endl;
    }

    void NotifyDeathExtended()
    {
        std::cout << "Oh no DataModel dead!" <<std::endl;
    }
};

class ControlWindow : public ACallBack<TestEvent>
{
    
    public:
    ControlWindow() : ACallBack<TestEvent>(){}
    ~ControlWindow(){};
    void Notify(const TestEvent& data)
    {
        std::cout << "The operation ControlWindow is connected to: " << data.m_event << ". Now Work on it!" <<std::endl;
    }

    void NotifyDeathExtended()
    {
        std::cout << "Oh no ControlWindow dead!" <<std::endl;
    }
};



class ViewWindow2 : public ACallBack<TestEvent>
{
    
    public:
    ViewWindow2(Dispatcher<TestEvent> *dispatcher) : ACallBack<TestEvent>(), m_dispatcher(dispatcher){}
    ~ViewWindow2(){};
    void Notify(const TestEvent& data)
    {
        std::cout << "The operation ViewWindow is connected to: " << data.m_event << ". Now Work on it!" <<std::endl;
        m_dispatcher->Register(this);
    }

    void NotifyDeathExtended()
    {
        std::cout << "Oh no ViewWindow dead!" <<std::endl;
    }
    private:
    Dispatcher<TestEvent> * m_dispatcher;
};

class DataModel2 : public ACallBack<TestEvent>
{
    
    public:
    DataModel2(Dispatcher<TestEvent> *dispatcher) : ACallBack<TestEvent>(), m_dispatcher(dispatcher){}
    ~DataModel2(){};
    void Notify(const TestEvent& data)
    {
        std::cout << "The operation DataModel is connected to: " << data.m_event << ". Now Work on it!" <<std::endl;
        m_dispatcher->Register(this);
    }

    void NotifyDeathExtended()
    {
        std::cout << "Oh no DataModel dead!" <<std::endl;
    }
    private:
    Dispatcher<TestEvent> * m_dispatcher;
};

class ControlWindow2 : public ACallBack<TestEvent>
{
    
    public:
    ControlWindow2(Dispatcher<TestEvent> *dispatcher) : ACallBack<TestEvent>() , m_dispatcher(dispatcher){}
    ~ControlWindow2(){};
    void Notify(const TestEvent& data)
    {
        std::cout << "The operation ControlWindow is connected to: " << data.m_event << ". Now Work on it!" <<std::endl;
        m_dispatcher->Register(this);
    }

    void NotifyDeathExtended()
    {
        std::cout << "Oh no ControlWindow dead!" <<std::endl;
    }
    private:
    Dispatcher<TestEvent> * m_dispatcher;
};



class ViewWindow3 : public ACallBack<TestEvent>
{
    
    public:
    ViewWindow3(Dispatcher<TestEvent> *dispatcher) : ACallBack<TestEvent>(), m_dispatcher(dispatcher){}
    ~ViewWindow3(){};
    void Notify(const TestEvent& data)
    {
        std::cout << "The operation ViewWindow is connected to: " << data.m_event << ". Now Work on it!" <<std::endl;
        m_dispatcher->UnRegister(this);
    }

    void NotifyDeathExtended()
    {
        std::cout << "Oh no ViewWindow dead!" <<std::endl;
    }

    private:
    Dispatcher<TestEvent> * m_dispatcher;
};

class DataModel3 : public ACallBack<TestEvent>
{
    
    public:
    DataModel3(Dispatcher<TestEvent> *dispatcher) : ACallBack<TestEvent>(), m_dispatcher(dispatcher){}
    ~DataModel3(){};
    void Notify(const TestEvent& data)
    {
        std::cout << "The operation DataModel is connected to: " << data.m_event << ". Now Work on it!" <<std::endl;
        m_dispatcher->UnRegister(this);
    }

    void NotifyDeathExtended()
    {
        std::cout << "Oh no DataModel dead!" <<std::endl;
    }

    private:
    Dispatcher<TestEvent> * m_dispatcher;
};

class ControlWindow3 : public ACallBack<TestEvent>
{
    
    public:
    ControlWindow3(Dispatcher<TestEvent> *dispatcher) : ACallBack<TestEvent>() , m_dispatcher(dispatcher){}
    ~ControlWindow3(){};
    void Notify(const TestEvent& data)
    {
        std::cout << "The operation ControlWindow is connected to: " << data.m_event << ". Now Work on it!" <<std::endl;
        m_dispatcher->UnRegister(this);
    }

    void NotifyDeathExtended()
    {
        std::cout << "Oh no ControlWindow dead!" <<std::endl;
    }

    private:
    Dispatcher<TestEvent> * m_dispatcher;
};

void BroadcastToOneObserver()
{
    Dispatcher<TestEvent> dispatcher;
    std::string operation = "Hello1";
    TestEvent example(operation);
    ACallBack<TestEvent> * event1 = new ViewWindow();
    dispatcher.Register(event1);
    dispatcher.Broadcast(example);
    delete event1;
}

void BroadcastToTwoObservers()
{
    Dispatcher<TestEvent> dispatcher;
    std::string operation = "Hello1";
    TestEvent example(operation);
    ACallBack<TestEvent> * event1 = new ViewWindow();
    ACallBack<TestEvent> * event2 = new ViewWindow();
    dispatcher.Register(event1);
    dispatcher.Register(event2);
    dispatcher.Broadcast(example);
    delete event1;
    delete event2;
}

void BroadcastToThreeObservers()
{
    Dispatcher<TestEvent> dispatcher;

    std::string operation = "Hello1";

    TestEvent example(operation);

    ACallBack<TestEvent> * event1 = new ViewWindow();
    ACallBack<TestEvent> * event2 = new DataModel();
    ACallBack<TestEvent> * event3 = new ControlWindow();

    dispatcher.Register(event1);
    dispatcher.Register(event2);
    dispatcher.Register(event3);

    dispatcher.Broadcast(example);

    delete event1;
    delete event2;
    delete event3;
}

void RemoveOneObserverDuringBroadcast()
{
    Dispatcher<TestEvent> dispatcher;

    std::string operation = "Hello1";

    TestEvent example(operation);

    ACallBack<TestEvent> * event1 = new ViewWindow();
    ACallBack<TestEvent> * event2 = new DataModel();
    ACallBack<TestEvent> * event3 = new ControlWindow3(&dispatcher);

    dispatcher.Register(event1);
    dispatcher.Register(event2);
    dispatcher.Register(event3);

    dispatcher.Broadcast(example);

    delete event1;
    delete event2;
    delete event3;

}

void RemoveAllObserverDuringBroadcast()
{
    Dispatcher<TestEvent> dispatcher;

    std::string operation = "Hello1";

    TestEvent example(operation);

    ACallBack<TestEvent> * event1 = new ViewWindow3(&dispatcher);
    ACallBack<TestEvent> * event2 = new DataModel3(&dispatcher);
    ACallBack<TestEvent> * event3 = new ControlWindow3(&dispatcher);

    dispatcher.Register(event1);
    dispatcher.Register(event2);
    dispatcher.Register(event3);

    dispatcher.Broadcast(example);

    delete event1;
    delete event2;
    delete event3;
}

void AddObserverDuringBroadcast()
{
    Dispatcher<TestEvent> dispatcher;

    std::string operation = "Hello1";

    TestEvent example(operation);

    ACallBack<TestEvent> * event1 = new ViewWindow();
    ACallBack<TestEvent> * event2 = new DataModel();
    ACallBack<TestEvent> * event3 = new ControlWindow2(&dispatcher);

    dispatcher.Register(event1);
    dispatcher.Register(event2);
    dispatcher.Register(event3);

    dispatcher.Broadcast(example);

    delete event1;
    delete event2;
    delete event3;
}

void AddTwoObserversDuringBroadcast()
{
     Dispatcher<TestEvent> dispatcher;

    std::string operation = "Hello1";

    TestEvent example(operation);

    ACallBack<TestEvent> * event1 = new ViewWindow();
    ACallBack<TestEvent> * event2 = new DataModel2(&dispatcher);
    ACallBack<TestEvent> * event3 = new ControlWindow2(&dispatcher);

    dispatcher.Register(event1);
    dispatcher.Register(event2);
    dispatcher.Register(event3);

    dispatcher.Broadcast(example);

    delete event1;
    delete event2;
    delete event3;
}

void SimpleTest()
{
    
    My_ObjectClass<std::string> object;
    CallBack<My_ObjectClass<std::string>, std::string> call(object, &My_ObjectClass<std::string>::Notify, &My_ObjectClass<std::string>::DeathFunc);
    Dispatcher<std::string> dispatcher;
    dispatcher.Register(&call);
    dispatcher.Broadcast("Work");
}

int main()
{
    std::cout << "******SimpleTest******" << std::endl;
    SimpleTest(); 
    std::cout << "******Broadcast to one observer******" << std::endl;
    BroadcastToOneObserver();

    std::cout << "******Broadcast to two observers*******" << std::endl;
    BroadcastToTwoObservers();

    std::cout << "******Broadcast to two observers*******" << std::endl;
    BroadcastToThreeObservers();


    std::cout << "******Remove One Observer During Broadcast******" << std::endl;
    RemoveOneObserverDuringBroadcast();

    std::cout << "******Remove All Observer During Broadcast*******" << std::endl;
    RemoveAllObserverDuringBroadcast();

    std::cout << "******Add Observer During Broadcast*******" << std::endl;
    AddObserverDuringBroadcast();

    std::cout << "******Add Two Observers During Broadcast*******" << std::endl;
    AddTwoObserversDuringBroadcast();

    return 0;
}




