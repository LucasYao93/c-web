/**
 * 解决头文件相互包含引起的无线循环编译
*/
#ifndef _WEB_ARRAY_H_INCLUDED_
#define _WEB_ARRAY_H_INCLUDED_

#include "test_data_st.h"

typedef struct web_array_s web_array_t;

typedef int (*create_web_array_pt)(web_array_t *t,size_t size);
//函数返回数据(int *, char *)不是（int[] char[])
typedef char * (*return_jsondata_to_parent_pt)(web_array_t *);


struct web_array_s
{
    char *data;
    size_t size;
    create_web_array_pt create_web_array;
    return_jsondata_to_parent_pt return_jsondata_to_parent;

};

int web_array_init(web_array_t *t);

#endif

