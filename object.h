/**
 * @brief       It defines the game interface for each command
 *
 * @file        object.h
 * @authors     Adrian Caballero Orasio, Miguel Díaz Martín
 */

#ifndef OBJECT_H
#define OBJECT_H

#include "types.h"

typedef struct _Object Object;

/*Crea el objeto*/
Object *object_create(Id id);
/*Destruye el objeto*/
STATUS object_destroy(Object *obj);
/*Establece el id del objeto*/
STATUS object_set_id(Object *obj, Id id);
/*Establece el nombre del objeto*/
STATUS object_set_name(Object *obj, char *name);
/*Devuelve el id del objeto*/
Id object_get_id(Object *obj);
/*Devuelve el nombre del objeto*/
char *object_get_name(Object *obj);
/*Imprime el contenido del objeto*/
STATUS object_print(Object *obj);

#endif /* OBJECT_H */
