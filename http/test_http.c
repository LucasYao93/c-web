#include "test_http.h"
#include "../event/test_event.h"

int main() {
    printf("Test http module.\n");
    char message[] = "GET /array HTTP/1.0\r\nHost: localhost:8080\r\nConnection: close\r\nUpgrade-Insecure-Requests: 1\r\n\rbody";
    http_request_t *http_request = (http_request_t *)malloc(sizeof(http_request_t));
    http_response_t *http_response = (http_response_t *)malloc(sizeof(http_response_t));
    web_event_t *web_event = (web_event_t *)malloc(sizeof(web_event_t));

    //初始化request, response结构体
    http_request_structure_init(http_request,message);
    http_response_structure_init(http_response);
    


    http_request->deal_request_message(http_request);
    http_request->deal_request_row(http_request);
    
    printf("route: %s\n", http_request->route);
    //初始化event结构体，绑定callback function.
    web_event_structure_init(web_event, http_request->route);
    //执行callback function.
    web_event->event_callback_func(web_event);
    /*
        3、application/json
        消息主体是序列化后的 JSON 字符串,这个类型越来越多地被大家所使用


        POST [http://www.example.com](http://www.example.com) HTTP/1.1 
        Content-Type: application/json;charset=utf-8 

        {"title":"test","sub":[1,2,3]}
    */
    //生成response
    http_response->row = "HTTP/1.1 200 OK\r\n";
    http_response->header = "Content-Type: application/json;charset=UTF-8\r\n\r\n";
    http_response->body = web_event->data;
    http_response->combine_reponse_message(http_response);
    //sizeof(http_response->message)代表指针大小，不是存储数据的大小
    printf("%s\n", http_response->message);

    char stop = getchar();
    printf("stop cmd: %c\n", stop);
    free(http_request);
    free(http_response);
    return 0;
}