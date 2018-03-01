/**
 * @brief It defines a screen
 *
 * @file screen.h
 * @author Profesores PPROG
 * @version 1.0
 * @date 11-01-2017
 * @copyright GNU Public License
 */

#ifndef SCREEN_H
#define SCREEN_H

#define SCREEN_MAX_STR 80

typedef struct _Area Area;

/* Crea la pantalla */
void screen_init();
/* Destruye la pantalla */
void screen_destroy();

void screen_paint();
void screen_gets(char *str);

Area *screen_area_init(int x, int y, int width, int height);
void screen_area_destroy(Area *area);
void screen_area_clear(Area *area);
void screen_area_reset_cursor(Area *area);
void screen_area_puts(Area *area, char *str);

#endif /* SCREEN_H */
