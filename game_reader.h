/**
 * @brief       Reads the load file
 *
 * @file        player.c
 * @authors     Adrian Caballero Orasio, Miguel Díaz Martín
 */

#ifndef GAME_READER_H
#define GAME_READER_H

#include "command.h"
#include "space.h"
#include "game.h"

/*Lee el fichero para cargar el juego*/
STATUS game_load_spaces(Game* game, char* filename);




#endif /* GAME_READER_H */
