#ifndef _HTTP_H_INCLUDED_
#define _HTTP_H_INCLUDED_

//#include "test_http.h"

#include "../web_config.h"
#include "../web_core.h"

#define ROUTE_SIZE 256
#define RESPONSE_MESSAGE_SIZE 2048
/*typedef为变量重命名*/
typedef struct http_request_s http_request_t;
typedef struct http_response_s http_response_t;

/*函数指针*/
typedef int (*deal_request_message_pt)(http_request_t *r);
typedef int (*deal_request_row_pt)(http_request_t *t);
typedef int (*combine_reponsd_message_pt)(http_response_t *t);

extern char *G_HTTP_ROUTE[];

/*声明结构体类型*/
struct http_request_s {
    char *message;
    char *row;
    char *header;
    char *body;
    char route[ROUTE_SIZE]; 
    //指针适合查找数据，不是适合当作数据的存储器。
    //所以在构建数据结构体时，一般会有两部分组成，指针（指向数据的地址），存储区（储存数据的地址）
    deal_request_message_pt deal_request_message;
    deal_request_row_pt deal_request_row; 
};

struct http_response_s {
    char *row;
    char *header;
    char *body;
    char *message;
    size_t message_size;
    combine_reponsd_message_pt combine_reponse_message;
};


int http_request_structure_init(http_request_t *t, char m[]);
int http_response_structure_init(http_response_t *t);

#endif
