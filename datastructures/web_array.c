
#include "web_array.h"

static int create_web_array(web_array_t *t,size_t size)
{
    /*
    malloc:通知系统分配内存给应用
    free: 释放的内存，系统回收内存，内存对应用不可用。
    当多个指针指向同一个内存块时，释放任意一个，其他都指针都不可用。
    移动指针，再释放时，会引起报错。
   */
    t->size = size;
    char *array = (char *)malloc((size + 1) * sizeof(char));
    t->data = array;
    int n =0;
    for(int i=0; i < size; i++)
    {
        n = rand() % 26;
        *array = (char)(n+65);
        array++;
    }
    *array = '\0';

    return 0;
}

static char * return_jsondata_to_parent(web_array_t *t)
{
    char status[] = "{\"status\":\"success\",";
    char data_header[] = "\"data\":[";
    // ((2 * size) - 1) + 1 ==> 2 * size
    char *data = (char *)malloc((4 * t->size) * sizeof(char));
    char *mv_data = data;
    char data_end[] ="]}";
    while (1)
    {
        *mv_data = '"';
        mv_data++;
        *mv_data = *(t->data);
        mv_data++;
        *mv_data = '"';
        (t->data)++;
        if( '\0' == *(t->data)){
            mv_data++;
            *mv_data = '\0';
            break;
        }
        mv_data++;
        *mv_data = ',';
        mv_data++;
        
    }
    t->data_size = (sizeof(status) - 1) + (sizeof(data_header) - 1) + ((4 * t->size) - 1) + (sizeof(data_end) - 1);
    char *jsondata = (char *)malloc(((t->data_size) + 1) * sizeof(char));
    
    strcpy(jsondata,status);
    strcat(jsondata,data_header);
    strcat(jsondata,data);
    strcat(jsondata,data_end);

    
    free(data);
    //free(jsondata);
    return jsondata;
    
}

int web_array_init(web_array_t *t)
{
    t->data = NULL;
    t->size = 0;
    t->data_size = 0;
    t->create_web_array = &create_web_array;
    t->return_jsondata_to_parent = &return_jsondata_to_parent;
    return 0;
}

int web_array_destory(web_array_t *t)
{
    free(t->data);
    return 0;
}