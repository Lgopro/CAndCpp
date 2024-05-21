
typedef struct EventHandler event_handler_t;
typedef struct Event event_t;

#define READ 0
#define WRITE 1

struct EventHandler
{
    event_t *m_events;
    size_t m_max_amount;
    size_t m_current_amount;
};

struct Event
{
    int m_event_type;
    int m_data;
};

void RegisterFunc(void *event)
{
    printf("Event %d registered\n", *(int *)event);
}

void UnregisterFunc(void *event)
{
    printf("Event %d unregistered\n", *(int *)event);
}

event_handler_t* CreateEventHandler(size_t max_amount)
{
    if(max_amount == 0)
    {
        return NULL;
    }

    event_handler_t *handler = (event_handler_t *)malloc(sizeof(event_handler_t));
    if(handler == NULL)
    {
        return NULL;
    }

    handler->m_events = (event_t *)malloc(sizeof(event_t) * max_amount);
    if(handler->m_events == NULL)
    {
        free(handler);
        return NULL;
    }

    handler->m_max_amount = max_amount;
    handler->m_current_amount = 0;

    return handler;
}

void DestroyEventHandler(event_handler_t* event_handler)
{
    if(event_handler == NULL)
    {
        return;
    }

    free(event_handler->m_events);
    free(event_handler);
}

void Register(event_handler_t* event_handler, int event_type, void *event, void(*func)(void *))
{
    if(event_handler == NULL ||  func == NULL)
    {
        return;
    }

    event_handler->m_events[event_handler->m_current_amount].m_event_type = event_type;
    event_handler->m_events[event_handler->m_current_amount].m_data = *(int *)event;
    func(event);
}

void Unregister(event_handler_t* event_handler, int event_type, void *event, void(*func)(void *))
{
    if(event_handler == NULL ||  func == NULL)
    {
        return;
    }

    for(size_t i = 0; i < event_handler->m_current_amount; ++i)
    {
        if(event_handler->m_events[i].m_event_type == event_type 
           && event_handler->m_events[i].m_data == *(int *)event)
        {
            
        }
    }


}

void Notify(event_handler_t* event_handler, int event_type, void* event)
{

}