/**
 * 解决头文件相互包含引起的无线循环编译
*/
#ifndef _WEB_ARRAY_H_INCLUDED_
#define _WEB_ARRAY_H_INCLUDED_

//#include "test_datast.h"


#include "../web_config.h"
#include "../web_core.h"


typedef struct web_array_s web_array_t;

typedef int (*create_web_array_pt)(web_array_t *t,size_t size);
//函数返回数据(int *, char *)不是（int[] char[])
typedef char * (*return_jsondata_to_parent_pt)(web_array_t *);


struct web_array_s
{
    char *data;
    size_t size;
    size_t data_size;
    create_web_array_pt create_web_array;
    return_jsondata_to_parent_pt return_jsondata_to_parent;

};

int web_array_init(web_array_t *t);
int web_array_destory(web_array_t *t);

#endif

