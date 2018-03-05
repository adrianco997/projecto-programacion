/**
 * @brief       It implements the player interpreter
 *
 * @file        player.c
 * @authors     Adrian Caballero Orasio, Miguel Díaz Martín
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"
#include "types.h"

struct _Player {
  Id id;
  char name[WORD_SIZE];
  Space *space;
  Object *object;
};

Player *player_create(Id id) {
  Player *newPlayer = NULL;
  
  if (id == NO_ID) 
      return NULL;
  
  newPlayer = (Player *) malloc(sizeof (Player));
  
  if (newPlayer == NULL) 
    return NULL;
  
  newPlayer->id = id;
  newPlayer->name[0] = '\0';
  newPlayer->space = space_create(NO_ID); 
  newPlayer->object = object_create(NO_ID);
  
  return newPlayer;
}

STATUS player_destroy(Player *player) {
  if (!player) 
      return ERROR;
  
  object_destroy(player->object);
  
  free(player);
  
  player = NULL;
  
  return OK;
}

Id player_get_id(Player *player) {
  if (!player) return NO_ID;
  
  return player->id;
}

const char *player_get_name(Player *player) {
  if (!player) 
      return NULL;
  
  return player->name;
}

Space *player_get_space(Player *player){
  if (!player) 
      return NULL;
  
  return player->space;
}

Object *player_get_object(Player *player) {
  if (!player) 
      return FALSE;
  
  return player->object;
}

STATUS player_set_id(Player *player, Id id){
    
    if(!player || id == NO_ID)
        return ERROR;
    
    player->id = id;
    
    return OK;   
}

STATUS player_set_name(Player *player, char *name) {
  if (!player || !name) 
      return ERROR;
  
  if (!strcpy(player->name, name)) 
      return ERROR;
  
  return OK;
}

STATUS player_set_space(Player *player, Space *space){
  if (!player) 
      return ERROR;
  
  player->space = space;
  
  return OK;
}

STATUS player_set_object(Player *player, Object *obj) {
  if (!player) 
      return ERROR;
  
  player->object = obj;
  
  return OK;
}

STATUS player_print(Player *player) {
  Id aux = NO_ID;
  
  if (!player) 
      return ERROR;
  
  fprintf(stdout, "--> Player (Id: %ld; Name: %s)\n", player->id, player->name);
  
  aux = player_get_id(player);
  
  if (NO_ID != aux)
    fprintf(stdout, "---> Space: %ld.\n", aux);
  else
    fprintf(stdout, "---> No space.\n");
  if (player_get_object(player))
    fprintf(stdout, "---> Object in the player: %s\n", object_get_name(player->object));
  else
    fprintf(stdout, "---> No object in the player.\n");
  
  return OK;
}
