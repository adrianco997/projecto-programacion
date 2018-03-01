/**
 * @brief       It implements the player interpreter
 *
 * @file        player.h
 * @authors     Adrian Caballero Orasio, Miguel Díaz Martín
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "space.h"
#include "object.h"
#include "player.h"

typedef struct _Player Player;

/*Crea el jugador*/
Player *player_create(Id id);
/*Destruye el jugador*/
STATUS player_destroy(Player *player);
/*Devuelve el id del jugador*/
Id player_get_id(Player *player);
/*Devuelve el nombre del jugador*/
const char *player_get_name(Player *player);
/*Devuelve el espacio del jugador*/
Space *player_get_space(Player *player);
/*Devuelve el objeto del jugador*/
Object *player_get_object(Player *player);
/*Establece el id del jugador*/
STATUS player_set_id(Player *player, Id id);
/*Establece el nombre del jugador*/
STATUS player_set_name(Player *player, char *name);
/*Establece el espacio del jugador*/
STATUS player_set_space(Player *player, Space *space);
/*Establece el objeto del jugador*/
STATUS player_set_object(Player *player, Object *obj);
/*Imprime datos del jugador*/
STATUS player_print(Player *player);

#endif  /* PLAYER_H */
