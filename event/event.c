#include "event.h"

int callback_array_func(web_event_t *t)
{
    data_structure_t *data_structure = (data_structure_t *)malloc(sizeof(data_structure_t)); 
    data_structure_init(data_structure);
    
    web_array_t *web_array = (web_array_t *)data_structure->return_datatype(*(G_HTTP_ROUTE));

    web_array->create_web_array(web_array, 10);
    data_structure->data = web_array->return_jsondata_to_parent(web_array);
    data_structure->data_size = web_array->data_size;

    //printf("json data: %s", data_structure->data);

    //char *msg = "{\"title\":\"test\",\"sub\":[1,2,3]}";
    t->data = data_structure->data;
    t->data_size = data_structure->data_size;
    return 0;
}

int web_event_structure_init(web_event_t *t, char route[])
{
    t->data = NULL;
    t->event_callback_func = NULL;
    if( 0 == strcmp(route, *(G_HTTP_ROUTE)))
    {
        printf("mapping event callback function %s\n", *(G_HTTP_ROUTE));
        t->event_callback_func = &callback_array_func;
        return 0;
    }
    printf("not mapping event callback function.\n");
    
    return 0;
}

