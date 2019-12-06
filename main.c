#include <sys/socket.h>
#include <sys/un.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define PORT 80
char webpage[] =
"HTTP/1.1 200 OK\r\n"
"Content-Type: text/html; charset=UTF-8\r\n\r\n"
"<!DOCTYPE html>\r\n"
"<html><head><title>LucasYao</title>\r\n"
"<style>body {background-color: #FFF000 } </style></head>\r\n"
"<body><center><h1>Hello,C Web!</h1></center></body>";

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
    while (1) {
    	fd_client = accept(fd_server, (struct sockaddr *) &client_addr, &sin_len);
        if(fd_client == -1) {
	    perror("Connection failed...\n");
	    continue;
	}
	printf("Client socket fd %d\n", fd_client);
	memset(buffer, 0, 2048);    
	read(fd_client, buffer, 2048);
    	printf("request %dth\n%s\n", ++req_number, buffer);


    	int n = write(fd_client, webpage, sizeof(webpage)-1);
    	printf("return write number %d\n", n);
    	close(fd_client);
    }
    close(fd_server);

    return 0;
}
