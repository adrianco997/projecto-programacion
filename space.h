/**
 * @brief It defines a space
 *
 * @file space.h
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @copyright GNU Public License
 */

#ifndef SPACE_H
#define SPACE_H

#include "types.h"
#include "object.h"
#include "set.h"

typedef struct _Space Space;

#define MAX_SPACES 100
#define FIRST_SPACE 1

/*Crea el espacio*/
Space* space_create(Id id);
/*Destruye el espacio*/
STATUS space_destroy(Space* space);
/*Devuelve el id del espacio*/
Id space_get_id(Space* space);
/*Establece el nombre del espacio*/
STATUS space_set_name(Space* space, char* name);
/*Devuelve el nombre del espacio*/
const char* space_get_name(Space* space);
/*Establece el id norte del espacio*/
STATUS space_set_north(Space* space, Id id);
/*Devuelve el id norte del espacio*/
Id space_get_north(Space* space);
/*Establece el id sur del espacio*/
STATUS space_set_south(Space* space, Id id);
/*Devuelve el id sur del espacio*/
Id space_get_south(Space* space);
/*Establece el id este del espacio*/
STATUS space_set_east(Space* space, Id id);
/*Devuelve el id este del espacio*/
Id space_get_east(Space* space);
/*Establece el id oeste del espacio*/
STATUS space_set_west(Space* space, Id id);
/*Devuelve el id oeste del espacio*/
Id space_get_west(Space* space);
/*Establece el objeto del espacio*/
STATUS space_set_object(Space *space, Object *obj);
/*Devuelve el objeto del espacio*/
Set *space_get_objects(Space *space);
/*Imprime datos del espacio*/
STATUS space_print(Space* space);
/*Comprueba si un objeto esta en el set del espacio*/
BOOL space_test_object(Space *space, Object *obj);

#endif
