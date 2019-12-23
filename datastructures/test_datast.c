#include "test_datast.h"

int main() 
{
    printf("test data structure module.\n");
    data_structure_t *data_structure = (data_structure_t *)malloc(sizeof(data_structure_t)); 
    data_structure_init(data_structure);
    
    web_array_t *web_array = (web_array_t *)data_structure->return_datatype(*(G_HTTP_ROUTE));

    web_array->create_web_array(web_array, 10);
    data_structure->data = web_array->return_jsondata_to_parent(web_array);

    printf("json data: %s", data_structure->data);

    printf("\n");

    char stop = getchar();
    free(data_structure);
    free(web_array);
    printf("stop cmd: %c\n", stop);
    return 0;
}