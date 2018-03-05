/**
 * @brief It implements the game interface and all the associated callbacks
 * for each command
 *
 * @file game.c
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "game_reader.h"

#define N_CALLBACK 8

/* Define the function type for the callbacks */
typedef void (*callback_fn)(Game* game);

/* List of callbacks for each command in the game */
void game_callback_unknown(Game* game);
void game_callback_exit(Game* game);
void game_callback_following(Game* game);
void game_callback_previous(Game* game);
void game_callback_take(Game* game);
void game_callback_drop(Game* game);
void game_callback_left(Game* game);
void game_callback_right(Game* game);

static callback_fn game_callback_fn_list[N_CALLBACK] = {
    game_callback_unknown,
    game_callback_exit,
    game_callback_following,
    game_callback_previous,
    game_callback_take,
    game_callback_drop,
    game_callback_left,
    game_callback_right
};

/* Private functions */
Id game_get_space_id_at(Game* game, int position);
STATUS game_set_player_location(Game* game, Id id);
STATUS game_set_object_location(Game* game, Id id);

/* Game interface implementation */
STATUS game_create(Game* game) {
    int i;

    for (i = 0; i < MAX_SPACES; i++) {
        game->spaces[i] = NULL;
    }
    game->player_location = player_create(NO_ID);
    game->object_location = object_create(NO_ID);
    game->last_cmd = NO_CMD;
    return OK;
}
STATUS game_create_from_file(Game* game, char* filename) {
    if (game_create(game) == ERROR) return ERROR;
    if (game_load_spaces(game, filename) == ERROR) return ERROR;
    game_set_player_location(game, game_get_space_id_at(game, 0));
    game_set_object_location(game, game_get_space_id_at(game, 0));
    return OK;
}
STATUS game_destroy(Game* game) {
    int i = 0;

    object_destroy(game->object_location);
    player_destroy(game->player_location);
    for (i = 0; (i < MAX_SPACES) && (game->spaces[i] != NULL); i++) {
        space_destroy(game->spaces[i]);
    }
    return OK;
}
STATUS game_add_space(Game* game, Space* space) {
    int i = 0;

    if (space == NULL) return ERROR;
    while ((i < MAX_SPACES) && (game->spaces[i] != NULL)) {
        i++;
    }
    if (i >= MAX_SPACES) return ERROR;
    game->spaces[i] = space;
    return OK;
}
Id game_get_space_id_at(Game* game, int position) {
    if (position < 0 || position >= MAX_SPACES) {
        return NO_ID;
    }
    return space_get_id(game->spaces[position]);
}
Space* game_get_space(Game* game, Id id) {
    int i = 0;

    if (id == NO_ID) return NULL;
    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
        if (id == space_get_id(game->spaces[i])) {
            return game->spaces[i];
        }
    }
    return NULL;
}
STATUS game_set_player_location(Game* game, Id id) {
    if (id == NO_ID) return ERROR;
    player_destroy(game->player_location);
    game->player_location = player_create(id);
    return OK;
}
STATUS game_set_object_location(Game* game, Id id) {
    if (id == NO_ID) return ERROR;
    object_destroy(game->object_location);
    game->object_location = object_create(id);
    return OK;
}
Id game_get_player_location(Game* game) {
    return player_get_id(game->player_location);
}
Id game_get_object_location(Game* game) {
    return object_get_id(game->object_location);
}
STATUS game_update(Game* game, T_Command cmd) {
    game->last_cmd = cmd;
    (*game_callback_fn_list[cmd])(game);
    return OK;
}
T_Command game_get_last_command(Game* game) {
    return game->last_cmd;
}

void game_print_data(Game* game) {
    int i = 0;

    printf("\n\n-------------\n\n");

    printf("=> Spaces: \n");
    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
        space_print(game->spaces[i]);
    }
    /*game->object_location->id*/
    printf("=> Object location: %d\n", (int) object_get_id(game->object_location));
    printf("=> Player location: %d\n", (int) player_get_id(game->player_location));
    printf("prompt:> ");
}

BOOL game_is_over(Game* game) {
    return FALSE;
}

/* Callbacks implementation for each action */
void game_callback_unknown(Game* game) {}
void game_callback_exit(Game* game) {}
void game_callback_following(Game* game) {
    int i = 0;
    Id current_id = NO_ID;
    Id space_id = NO_ID;

    space_id = game_get_player_location(game);
    if (space_id == NO_ID) {
        return;
    }

    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
        current_id = space_get_id(game->spaces[i]);
        if (current_id == space_id) {
            current_id = space_get_south(game->spaces[i]);
            if (current_id != NO_ID) {
                game_set_player_location(game, current_id);
            }
            return;
        }
    }
}
void game_callback_previous(Game* game) {
    int i = 0;
    Id current_id = NO_ID;
    Id space_id = NO_ID;

    space_id = game_get_player_location(game);

    if (NO_ID == space_id) {
        return;
    }


    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
        current_id = space_get_id(game->spaces[i]);
        if (current_id == space_id) {
            current_id = space_get_north(game->spaces[i]);
            if (current_id != NO_ID) {
                game_set_player_location(game, current_id);
            }
            return;
        }
    }
}
void game_callback_take(Game* game) {/*Necesita correcion*/
    /*int i;
    Id current_id = NO_ID;
    Id space_id = NO_ID;

    space_id = game_get_player_location(game);

    if (NO_ID == space_id) {
        return;
    }

    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
        current_id = space_get_id(game->spaces[i]);
        if (current_id == space_id) {
            if (current_id != NO_ID) {
                game_set_player_location(game, current_id);
                object_set_id(player_get_object(game->player_location),game_get_object_location(game));
                object_set_id(game->object_location, NO_ID);
            }
            return;
        }
    }
    */
}
void game_callback_drop(Game* game) {/*Necesita correcion*/
    /*int i;
    Id current_id = NO_ID;
    Id space_id = NO_ID;

    space_id = game_get_player_location(game);

    if (NO_ID == space_id) {
        return;
    }

     for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
        current_id = space_get_id(game->spaces[i]);
        if (current_id == space_id) {
            current_id = object_get_id(space_get_object(player_get_space(game->player_location)));
            if (current_id == NO_ID) {
                game_set_player_location(game, current_id);
                space_set_object(player_get_space(game->player_location), player_get_object(game->player_location));
                object_set_id(player_get_object(game->player_location), NO_ID);
            }
            return;
        }
    }
    */
}


void game_callback_left(Game* game){
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);
  if (NO_ID == space_id) return;
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      current_id = space_get_east(game->spaces[i]);
      if (current_id != NO_ID) {
        game_set_player_location(game, current_id);
      }
      return;
    }
  }
}


void game_callback_right(Game* game){
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);
  if (space_id == NO_ID) return;
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      current_id = space_get_west(game->spaces[i]);
      if (current_id != NO_ID) {
        game_set_player_location(game, current_id);
      }
      return;
    }
  }

}
