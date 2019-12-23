#ifndef _WEB_H_INCLUDED_
#define _WEB_H_INCLUDED_

//#include "test_datast.h"


#include "web_config.h"
#include "web_core.h"

#define PORT 8080
char webpage_test[] =
"HTTP/1.1 200 OK\r\n"
"Content-Type: text/html; charset=UTF-8\r\n\r\n"
"<!DOCTYPE html>\r\n"
"<html><head><title>LucasYao</title>\r\n"
"<style>body {background-color: #FFF000 } </style></head>\r\n"
"<body><center><h1>Hello,C Web!</h1></center></body>";
char * deal_http_request(char *message);

#endif