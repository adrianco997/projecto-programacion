/**
 * @brief       It implements the dice
 *
 * @file        dice.h
 * @authors     Adrian Caballero Orasio, Miguel Díaz Martín
 */

#ifndef DICE_H
#define DICE_H

#include "types.h"

typedef struct _Dice Dice;

Dice *dice_create(Id id);
STATUS dice_destroy(Dice *dice);

int dice_roll(Dice *dice);
Id dice_get_id(Dice *dice);
int dice_get_lastroll(Dice *dice);
STATUS dice_print(Dice *dice);

 #endif /* DICE_H */