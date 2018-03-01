/**
 * @brief       It implements the game reader interpreter
 *
 * @file        game_reader.h
 * @authors     Adrian Caballero Orasio, Miguel Díaz Martín
 */
 
#ifndef GAME_READER_H
#define GAME_READER_H

#include "command.h"
#include "space.h"
#include "game.h"

STATUS game_load_spaces(Game* game, char* filename);




#endif /* GAME_READER_H */
