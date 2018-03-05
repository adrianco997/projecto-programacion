

/* 
 * File:   set.h
 * authors Adrian Caballero Orasio, Miguel Díaz Martín
 *
 * Created on February 19, 2018, 4:49 PM
 */

#ifndef SET_H
#define SET_H

#define MAX_DATOS 5

#include "types.h"

typedef struct _Set Set;

/*Crea el set*/
Set * set_create();
/*Destruye el set*/
STATUS set_destroy(Set *set);
/*Añade un id*/
STATUS set_add_id(Set *set, Id id);
/*elimina un id*/
STATUS set_del_id(Set *set, Id id);
/*Imprime datos del set*/
STATUS set_print(Set *set);

Id set_get_id(Set *set, int n);



#endif /* SET_H */
