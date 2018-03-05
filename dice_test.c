/**
 * @brief       It test the dice.
 *
 * @file        dice_test.h
 * @authors     Adrian Caballero Orasio, Miguel Díaz Martín
 */

#include <stdio.h>
#include <stdlib.h>
#include "dice.h"
#include "types.h"
/*


STATUS dice_print(Dice *dice);
*/

int main(int argc, char** argv) {
    Dice *dice1 = NULL;
    Dice *dice2 = NULL;

    if (!(dice1 = dice_create())) fprintf(stderr, "Error al crear dice1");
    if (!(dice2 = dice_create())) fprintf(stderr, "Error al crear dice2");

    fprintf(stdout, "Id dice1: %d\n", (int) dice_get_id(dice1));
    fprintf(stdout, "Id dice2: %d\n", (int) dice_get_id(dice2));
    fprintf(stdout, "==================\n");
    fprintf(stdout, "Last roll dice1: %d\n", (int) dice_get_lastroll(dice1));
    fprintf(stdout, "Last roll dice2: %d\n", (int) dice_get_lastroll(dice2));
    fprintf(stdout, "==================\n");
    fprintf(stdout, "Roll dice1: %d", (int) dice_roll(dice1));
    fprintf(stdout, " %d", (int) dice_roll(dice1));
    fprintf(stdout, " %d", (int) dice_roll(dice1));
    fprintf(stdout, " %d\n", (int) dice_roll(dice1));
    fprintf(stdout, "Roll dice2: %d", (int) dice_roll(dice2));
    fprintf(stdout, " %d", (int) dice_roll(dice2));
    fprintf(stdout, " %d", (int) dice_roll(dice2));
    fprintf(stdout, " %d\n", (int) dice_roll(dice2));
    fprintf(stdout, "==================\n");
    fprintf(stdout, "Last roll dice1: %d\n", (int) dice_get_lastroll(dice1));
    fprintf(stdout, "Last roll dice2: %d\n", (int) dice_get_lastroll(dice2));
    fprintf(stdout, "==================\n");
    fprintf(stdout, "Print dice1:\n");
    dice_print(dice1);
    fprintf(stdout, "Print dice2:\n");
    dice_print(dice2);

    if(dice_destroy(dice1) == ERROR) fprintf(stderr, "Error al destruir dice1");
    if(dice_destroy(dice2) == ERROR) fprintf(stderr, "Error al destruir dice2");
    return 0;
}
