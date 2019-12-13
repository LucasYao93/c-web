#include "http.h"

/**
 *处理请求的message信息，填充到row,header,body.
*/
static int deal_request_message(http_request_t *t) {
    
    return 0;
}

/**
 *处理请求的row信息，填充到route.
*/
static int deal_request_row(http_request_t *t) {
    return 0;
}

/**
 *将respond的header，body组合，填充到message.
*/
static int combine_reponsd_message(http_reponsd_t *t) {

}

/**
 *构造request属性值
*/
int http_request_structure_init(http_request_t *t, char m[]){
    t->message = m;
    //Important: 函数指针赋值时要使用取值符号&
    t->deal_request_message = &deal_request_message;
    t->deal_request_row = &deal_request_row;
    return 0;
}

/**
 *构造respond属性值 
*/
int http_respond_structure_init(http_reponsd_t *t) {
    t->combine_reponsd_message = &combine_reponsd_message;
    return 0;
}