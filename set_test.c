

#include <stdio.h>
#include <stdlib.h>
#include "set.h"
#include "types.h"

/*
 * 
 */
int main(int argc, char** argv) {
    Set *set = NULL;
    int i = 0;
    
    set = set_create();
    
    for(i = 0; i < MAX_DATOS; i++){
        printf("Id %d: %d\n",i+1, (int) set_get_id(set,i));
    }
    
    printf ("==================\n");
    
    set_add_id(set,1);
    
    for(i = 0; i < MAX_DATOS; i++){
        printf("Id %d: %d\n",i+1, (int) set_get_id(set,i));
    }
    printf ("==================\n");
    set_add_id(set,2);
    set_add_id(set,3);
    for(i = 0; i < MAX_DATOS; i++){
        printf("Id %d: %d\n",i+1, (int) set_get_id(set,i));
    }
    
    printf ("==================\n");
    set_del_id(set,2);
    for(i = 0; i < MAX_DATOS; i++){
        printf("Id %d: %d\n",i+1, (int) set_get_id(set,i));
    }
    
    printf ("==================\n");
    set_add_id(set,5);
    for(i = 0; i < MAX_DATOS; i++){
        printf("Id %d: %d\n",i+1, (int) set_get_id(set,i));
    }
    
    set_destroy(set);
    
    return (EXIT_SUCCESS);
}

