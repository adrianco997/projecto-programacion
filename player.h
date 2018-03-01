/**
 * @brief       It implements the player interpreter
 *
 * @file        player.h
 * @authors     Adrian Caballero Orasio, Miguel Díaz Martín
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"
#include "space.h"
#include "object.h"
#include "command.h"
#include "game_reader.h"
#include "game.h"
#include "graphic_engine.h"
#include "screen.h"

typedef struct _Player Player;

/* Crea el jugador */
Player *player_create(Id id);
/* Destruye el jugador */
STATUS player_destroy(Player *player);

/* Devuelven los datos del jugador */
Id player_get_id(Player *player);
const char *player_get_name(Player *player);
Space *player_get_space(Player *player);
Object *player_get_object(Player *player);

/* Establece los datos del jugador */
STATUS player_set_name(Player *player, char *name);
STATUS player_set_space(Player *player, Space *space);
STATUS player_set_object(Player *player, Object *object);

/* el jugador coje o deja un objeto */
STATUS player_grab_object(Player *player);
STATUS player_drop_object(Player *player, Object *object);

/* Imprime el contenido del jugador */
STATUS player_print(Player *player);

#endif  /* PLAYER_H */
