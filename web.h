#ifndef _WEB_H_INCLUDED_
#define _WEB_H_INCLUDED_



#include "web_config.h"
#include "web_core.h"

#define PORT 8080

http_response_t * deal_http_request(char *message);

#endif