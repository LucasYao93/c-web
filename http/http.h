#include "web_core.h"
#include "web_config.h"

/*typedef为变量重命名*/
typedef struct http_request_s http_request_t;
typedef struct http_respond_s http_reponsd_t;

/*函数指针*/
typedef int (*deal_request_message_pt)(http_request_t *r);
typedef int (*deal_request_row_pt)(http_request_t *t);
typedef int (*combine_reponsd_message_pt)(http_reponsd_t *t);

/*声明结构体类型*/
struct http_request_s {
    char *message;
    char *row;
    char *header;
    char *body;
    char *route;
    deal_request_message_pt deal_request_message;
    deal_request_row_pt deal_request_row; 
};

struct http_respond_s {
    char *header;
    char *body;
    char *message;
    combine_reponsd_message_pt combine_reponsd_message;
};


int http_request_structure_init(http_request_t *t, char m[])
