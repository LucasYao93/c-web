#include "web_config.h"
#include "web_core.h"

http_response_t *deal_http_request(char *message);

int main(int argc, char *argv[]) {
    int fd_server, fd_client, req_number;
    struct sockaddr_in server_addr, client_addr;
    socklen_t sin_len = sizeof(client_addr);
    char buffer[2048];

    req_number = 0;
    memset(&server_addr, 0, sizeof(server_addr));

    /*First call socket() function*/
    fd_server = socket(AF_INET, SOCK_STREAM,0);
    if (fd_server < 0) {
        perror("ERROR opening socket(fd_server)");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    /*Now bind the host address using bind() call.*/
    if (bind(fd_server, (struct sockaddr*)&server_addr,sizeof(server_addr)) == -1) {
        perror("ERROR on bing(fd_server)");
	close(fd_server);
        exit(1);
    }
    if (listen(fd_server,10) == -1) {
    	perror("ERROR listen(fd_server");
	close(fd_server);
	exit(1);
    }	
    printf("Running server on port:%d....\n",PORT);
    while (1) 
    {
    	fd_client = accept(fd_server, (struct sockaddr *) &client_addr, &sin_len);
        if(fd_client == -1) 
        {
	    perror("Connection failed...\n");
	    continue;
	    }
        printf("Client socket fd %d\n", fd_client);
        memset(buffer, 0, 2048);    
        read(fd_client, buffer, 2048);
        printf("request %d-th\n%s\n", ++req_number, buffer);

        http_response_t *http_response = deal_http_request(buffer);
        int n = write(fd_client, http_response->message, http_response->message_size);
        printf("return write number %d\n", n);
        free(http_response);
        close(fd_client);
    }
    
    close(fd_server);

    return 0;
}

http_response_t *deal_http_request(char *message)
{
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
    char row[] = "HTTP/1.1 200 OK\r\n";
    char header[] = "Content-Type: application/json;charset=UTF-8\r\n\r\n";
    http_response->row = row;
    http_response->header = header;
    http_response->body = web_event->data;
    http_response->message_size = sizeof(row) + sizeof(header) + http_response->message_size;
    http_response->combine_reponse_message(http_response, http_response->message_size);
   
    //sizeof(http_response->message)代表指针大小，不是存储数据的大小
    //printf("%s\n", http_response->message);
    free(http_request);
    free(web_event);
    return http_response;
}
