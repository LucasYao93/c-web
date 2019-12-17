#include "event.h"

int callback_func(web_event_t *t)
{
    char *msg = "{\"title\":\"test\",\"sub\":[1,2,3]}";
    t->data = msg;
    return 0;
}

int web_event_structure_init(web_event_t *t, char route[])
{
    t->data = NULL;
    t->event_callback_func = NULL;
    if( 0 == strcmp(route, "/web"))
    {
        printf("mapping event callback function /web.\n");
        t->event_callback_func = &callback_func;
        return 0;
    }
    printf("not mapping event callback function.\n");
    
    return 0;
}

