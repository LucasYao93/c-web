
#include "web_array.h"

static int create_web_array(web_array_t *t,size_t size)
{
    char *array = (char *)malloc(size * sizeof(char));
    t->data = array;
    t->size = size+1;
    int n =0;
    for(int i=1; i < t->size; i++)
    {
        n = rand() % 26;
        *array = (char)(n+65);
        array++;
    }
    *array = '\0';
    free(array);
    return 0;
}

static char * return_jsondata_to_parent(web_array_t *s)
{
    char status[] = "{\"status\": \"success\",";
    char data_header[] = "\"data\":[";
    char *data = (char *)malloc(((2 * s->size)) * sizeof(char));
    char *mv_data = data;
    char data_end[] ="]}";
    while (1)
    {
        *mv_data = *(s->data);
        (s->data)++;
        if( '\0' == *(s->data)){
            break;
        }
        mv_data++;
        *mv_data = ',';
        mv_data++;
        
    }
    mv_data++;
    *mv_data = '\0';
    char *jsondata = (char *)malloc(sizeof(status) + sizeof(data_header) + ((2 * s->size)) * sizeof(char) + sizeof(data_end));
    
    strcpy(jsondata,status);
    strcat(jsondata,data_header);
    strcat(jsondata,data);
    strcat(jsondata,data_end);
    char *return_data = jsondata;
    free(data);
    free(jsondata);
    return return_data;
    
}

int web_array_init(web_array_t *t)
{
    t->data = NULL;
    t->size = 0;
    t->create_web_array = &create_web_array;
    t->return_jsondata_to_parent = &return_jsondata_to_parent;
    return 0;
}
