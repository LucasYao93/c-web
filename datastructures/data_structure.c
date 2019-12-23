#include "test_datast.h"

void *return_datatype(char type[]) 
{
    if(0 == strcmp(type, *(G_HTTP_ROUTE)))
    {
        web_array_t* web_array= (web_array_t *)malloc(sizeof(web_array_t));
        web_array_init(web_array);
        return web_array;
    }
    return NULL;
}


int data_structure_init(data_structure_t *t)
{
    t->data = NULL;
    t->return_datatype = &return_datatype;
    
    return 0;
}

int data_structure_destory(data_structure_t *t)
{
    free(t->data);
    return 0;
}