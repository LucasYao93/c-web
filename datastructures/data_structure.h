#ifndef _DATA_STRUCTURE_H_INCLUDED_
#define _DATA_STRUCTURE_H_INCLUDED_

#include "test_data_st.h"

typedef struct data_structure_s data_structure_t;
typedef void *(* return_datatype_pt)();

struct data_structure_s
{
    char *data;
    return_datatype_pt return_datatype; 
};


int data_structure_init(data_structure_t *t);

#endif