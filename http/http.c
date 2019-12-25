#include "http.h"

char *G_HTTP_ROUTE[] ={"//array"};

/**
 *处理请求的message信息，填充到row,header,body.
*/
static int deal_request_message(http_request_t *t) 
{
    //char *message = "GET /web HTTP/1.0\r\nHost: localhost:8080\r\nConnection: close\r\nUpgrade-Insecure-Requests: 1\r\n\rbody";
    char *mv_message = t->message;
    unsigned int flag = 0;
    if(NULL != mv_message) 
    {
        while ('\0' != (*mv_message) ) 
        {
            if('\r' == *mv_message) 
            {
                if(NULL == t->row) 
                {
                    //printf("point t->row.\n");
                    t->row = mv_message;
                }
                flag++;
            }
            else if('\n' == *mv_message) 
            {
                flag++;
            }
            else 
            {
                flag = 0;
            }
            if(3 == flag) 
            {
                if(NULL == t->body) 
                {
                    //printf("point t->body.\n");
                    t->body = mv_message;
                }

            }       
            mv_message++;
        }
    }
    //Test pointer address
    mv_message = t->message;
    while( mv_message != t->row) 
    {
        printf("%c", *mv_message);
        mv_message++;
    }
    while(mv_message != t->body) 
    {
        mv_message++;
    }

    printf("\n");

    while('\0' != *mv_message) 
    {
        printf("%c", *mv_message);
        mv_message++;
    }
    printf("\n");
    //Test
    return 0;
}

/**
 *处理请求的row信息，填充到route.
*/
static int deal_request_row(http_request_t *t) {
    char *mv_message = t->message;
    int i;
    if( NULL != mv_message && NULL != t->row)
    {
        while (mv_message != t->row) 
        {
            if( ' ' == *mv_message) 
            {
                mv_message++;
                for(i = 0; ' ' != *mv_message; i++) 
                {
                    //printf("route: %c\n", *mv_message);
                    t->route[i] = *mv_message;
                    mv_message++;
                }
                //printf("i: %d\n", i);
                i++;
                t->route[i] = '\0';
                return 0;
            }
            mv_message++;
        }       
    }
    return 0;
}

/**
 *将respond的header，body组合，填充到message.
*/
static int combine_reponse_message(http_response_t *t) 
{
    
    t->message = (char *)malloc(((http_response->message_size) + 1) * sizeof(char));
    strcpy(t->message, t->row);
    strcat(t->message, t->header);
    strcat(t->message, t->body);
    //strcat(message, "\0");

    return 0;
}

/**
 *构造request属性值
*/
int http_request_structure_init(http_request_t *t, char m[]) 
{
    t->message = m;
    t->row = NULL;
    t->header = NULL;
    t->body = NULL;
    memset(t->route, 0, ROUTE_SIZE); 
    //Important: 函数指针赋值时要使用取值符号&
    t->deal_request_message = &deal_request_message;
    t->deal_request_row = &deal_request_row;
    return 0;
}

/**
 *构造respond属性值 
*/
int http_response_structure_init(http_response_t *t) 
{
    t->row = NULL;
    t->header = NULL;
    t->body = NULL;
    t->message_size = 0;
    t->combine_reponse_message = &combine_reponse_message;
    return 0;
}