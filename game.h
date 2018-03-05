/**
  *@brief It defines the game interface
  *for each command
  *
  *@file game.h
  *@author Profesores PPROG
  *@version 1.0
  *@date 13-01-2015
  *@copyright GNU Public License
 */

#ifndef GAME_H
#define GAME_H

#include "command.h"
#include "space.h"
#include "object.h"
#include "player.h"
#include "game.h"

typedef struct _Game {
    Player *player_location;
    Object *object_location;
    Space *spaces[MAX_SPACES + 1];
    T_Command last_cmd;
} Game;

/*Añade un espacio al array de espacios de la estructura game*/
STATUS game_add_space(Game *game, Space *space);
/*inicia el juego*/
STATUS game_create(Game *game);
/*Llama a game reader para cargar el fichero y pone al jugador en la posición 0*/
STATUS game_create_from_file(Game *game, char *filename);
/*Actualiza el ultimo comando introducido*/
STATUS game_update(Game *game, T_Command cmd);
/*Destruye el juego*/
STATUS game_destroy(Game *game);
/*Termina el juego*/
BOOL game_is_over(Game *game);
/*No esta implementada*/
void game_print_screen(Game *game);
/*Imprime informacion sobre el objeto y el jugador*/
void game_print_data(Game *game);
/*Devuelve el espacio actual*/
Space *game_get_space(Game *game, Id id);
/*Devuelve el id del jugador*/
Id game_get_player_location(Game *game);
/*Devuelve el id del objeto*/
Id game_get_object_location(Game *game);
/*Devuelve el ultimo comando*/
T_Command game_get_last_command(Game *game);
#endif
