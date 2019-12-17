#include "event.h"

int main() {
    printf("Test event module.\n");
    web_event_t *web_event = (web_event_t *)malloc(sizeof(web_event_t));
    web_event_structure_init(web_event, "/web");
    //调用指针之前需要判断指针是否为空。k
    if(NULL != web_event->event_callback_func)
    {
        web_event->event_callback_func(web_event);
    }
 
    if(NULL != web_event->data) 
    {
        printf("event return msg: %s\n", web_event->data);
    }  
    //web_event->event_callbacl_func(web_event);
    //printf("event return msg: %s\n", web_event->data);
    char stop = getchar();
    printf("stop cmd: %c", stop);
    free(web_event);

    return 0;
}