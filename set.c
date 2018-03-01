#include <stdio.h>
#include <stdlib.h>
#include "set.h"

struct _Set{
    Id datos[MAX_DATOS];
    int num;
};

Set * set_create(){
    int i;    
   
    Set *set = NULL;
    
    set = (Set *) malloc(sizeof(Set));
    
    if(set == NULL)
        return NULL;

    
    for(i = 0; i < MAX_DATOS; i++){
        set->datos[i] = NO_ID;
    }
    
    set->num = -1;
    
    return set;
}

STATUS set_destroy(Set *set){
    if(set == NULL)
        return ERROR;
    
    free(set);
    
    set = NULL;
    
    return OK;
}

STATUS set_add_id(Set *set, Id id){
    int i;
    
    if(set == NULL || id == NO_ID)
        return ERROR;
    
    for(i = 0; i < MAX_DATOS; i++){
        if(set->datos[i] == NO_ID){
            set->datos[i] = id;
            i = MAX_DATOS;
        }
    }
    
    
    
    set->num++;
    
    
    return OK;
}

STATUS set_del_id(Set *set, Id id){
    int i;
    
    if(set == NULL || id == NO_ID)
        return ERROR;
    
    
    for(i = 0; i < MAX_DATOS; i++){
        if(set->datos[i] == id){
            set->datos[i] = NO_ID;
            set->num --;
            i = MAX_DATOS;
        }
    }
    
    return OK;
}

Id set_get_id(Set *set, int n){
    if(!set)
        return NO_ID;
    
    return set->datos[n];
}

STATUS set_print(Set *set){
    int i;
    
    if (!set) {
        return ERROR;
    }
    
    fprintf(stdout, "Number of ids: %d \n",set->num);
    fprintf(stdout, "Ids: ");
    for(i = 0; i < MAX_DATOS; i++){
        if(set->datos[i] != NO_ID){
            fprintf(stdout, "%d ",(int)set->datos[i]);
        }
    }
    
    return OK;

}