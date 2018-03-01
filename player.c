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

struct _Player {
  Id id;
  char name[WORD_SIZE + 1];
  Space *space;
  Object *object;
};

Player *player_create(Id id) {
  Player *newPlayer = NULL;
  if (id == NO_ID) return NULL;
  newPlayer = (Player *) malloc(sizeof (Player));
  if (newPlayer == NULL) return NULL;
  newPlayer->id = id;
  newPlayer->name[0] = '\0';
  newPlayer->space = NULL;
  newPlayer->object = FALSE;
  return newPlayer;
}
STATUS player_destroy(Player *player) {
  if (!player) return ERROR;
  free(player);
  player = NULL;
  return OK;
}

Id player_get_id(Player *player) {
  if (!player) return NO_ID;
  return player->id;
}
const char *player_get_name(Player *player) {
  if (!player) return NULL;
  return player->name;
}
Space *player_get_space(Player *player){
  if (!player) return NULL;
  return player->space;
}
Object *player_get_object(Player *player) {
  if (!player) return NULL;
  return player->object;
}

STATUS player_set_name(Player *player, char *name) {
  if (!player || !name) return ERROR;
  if (!strcpy(player->name, name)) return ERROR;
  return OK;
}
STATUS player_set_space(Player *player, Space *space){
  if (!player) return ERROR;
  player->space = space;
  return OK;

}
STATUS player_set_object(Player *player, Object *object) {
  if (!player) return ERROR;
  player->object = object;
  return OK;
}

STATUS player_grab_object(Player *player){
    if (!player) return ERROR;
    if (player_get_object(player)!=NULL) return ERROR; /*player->object:YES*/
    if (space_get_object(player_get_space(player))!=NULL) return ERROR;/*player->object:NO*/
    player_set_object(player, space_get_object(player_get_space(player)));
    space_set_object(player_get_space(player), NULL);

    return OK;
}
STATUS player_drop_object(Player *player, Object *object){
    if (!player) return ERROR;
    if (player_get_object(player)==NULL) return ERROR;
    if (space_get_object(player_get_space(player))==NULL) return ERROR;

    space_set_object(player_get_space(player), player_get_object(player));
    player_set_object(player, NULL);
    return OK;
}

STATUS player_print(Player *player) {
  Id idaux = NO_ID;
  if (!player) return ERROR;
  fprintf(stdout, "--> Player (Id: %ld; Name: %s)\n", player->id, player->name);
  idaux = space_get_id(player_get_space(player));
  if (NO_ID != idaux)
    fprintf(stdout, "---> Space: %ld.\n", idaux);
  else
    fprintf(stdout, "---> No space.\n");
  if (player_get_object(player))
    fprintf(stdout, "---> Object in the player: %s\n", object_get_name(player->object));
  else
    fprintf(stdout, "---> No object in the player.\n");
  return OK;
}
