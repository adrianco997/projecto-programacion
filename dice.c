/**
 * @brief       It implements the dice
 *
 * @file        dice.c
 * @authors     Adrian Caballero Orasio, Miguel Díaz Martín
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dice.h"

#define dice_faces 6

struct _Dice {
  Id id;
  int lastroll;
};


Dice *dice_create(){
  Dice *dice = NULL;
  int id;
  id = srand((int)time(NULL));
  dice = (Dice *) malloc(sizeof(Dice));
  if (dice == NULL) return NULL;
  dice->id = id;
  dice->lastroll = -1;
  return dice;
}
STATUS dice_destroy(Dice *dice){
  if(!dice) return ERROR;
  free(dice);
  dice = NULL;
  return OK;
}

int dice_roll(Dice *dice){
  int roll;
  if (!dice) return ERROR;
  roll = rand() % (dice_faces) + 1;
  dice->lastroll = roll;
  return roll;
}

Id dice_get_id(Dice *dice){
  if(!dice) return NO_ID;
  return dice->id;
}
int dice_get_lastroll(Dice *dice){
  if(!dice) return ERROR;
  return dice->lastroll;
}

STATUS dice_print(Dice *dice){

  Id aux = NO_ID;

  if (!dice) return ERROR;
  fprintf(stdout, "--> Dice (Id: %ld; Last roll: %d)\n", dice->id, dice->lastroll);
  aux = dice_get_id(dice);
  if (NO_ID != aux) fprintf(stdout, "---> Dice id: %ld.\n", aux);
  else fprintf(stdout, "---> No id.\n");
  return OK;


}
