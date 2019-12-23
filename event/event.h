#ifndef _EVENT_H_INCLUDED_
#define _EVENT_H_INCLUDED_

/*
#include "test_event.h"
#include "../datastructures/data_structure.h"
#include "../datastructures/web_array.h"
*/

#include "../web_config.h"
#include "../web_core.h"

typedef struct web_event_s web_event_t;

typedef int (*event_callback_func_pt) (web_event_t *t);

struct web_event_s {
    char *data;
    size_t data_size;
    event_callback_func_pt event_callback_func;
};


int web_event_structure_init(web_event_t *t, char route[]);

#endif