#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct web_event_s web_event_t;

typedef int (*event_callback_func_pt) (web_event_t *t);

struct web_event_s {
    char *data;
    event_callback_func_pt event_callback_func;
};


int web_event_structure_init(web_event_t *t, char route[]);