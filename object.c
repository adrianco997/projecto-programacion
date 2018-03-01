/**
 * @brief       It defines the game interface for each command
 *
 * @file        object.c
 * @authors     Adrian Caballero Orasio, Miguel Díaz Martín
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "object.h"
#include "types.h"

struct _Object{
    Id id;
    char name[WORD_SIZE];
};

Object * object_create(Id id){
    Object *obj = NULL;

    if(id == NO_ID) return NULL;
    obj = (Object *) malloc(sizeof(Object));
    obj->id = id;
    obj->name[0] = '\0';
    return obj;
}
STATUS object_destroy(Object *obj){
    if(!obj) return ERROR;
    free(obj);
    obj = NULL;
    return OK;
}

STATUS object_set_id(Object *obj, Id id){
    if(!obj || id == NO_ID) return ERROR;
    obj->id = id;
    return OK;
}
STATUS object_set_name(Object *obj, char *name){
    if(!obj || !strcpy(obj->name,name)) return ERROR;
    return OK;
}

Id object_get_id(Object *obj){
    if(!obj) return NO_ID;
    return obj->id;
}
char *object_get_name(Object *obj){
    if(!obj) return NULL;
    return obj->name;
}

STATUS object_print(Object *obj){
    Id aux = NO_ID;

    if (!obj) return ERROR;
    fprintf(stdout, "--> Object (Id: %ld; Name: %s)\n", obj->id, obj->name);
    aux = object_get_id(obj);
    if (NO_ID != aux) fprintf(stdout, "---> Object id: %ld.\n", aux);
    else fprintf(stdout, "---> No id.\n");
    return OK;
}
