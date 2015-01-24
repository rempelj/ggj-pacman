/*
 * Game.cpp
 *
 *  Created on: Jan 23, 2015
 *      Author: justinrempel
 */

#include <stdio.h>
#include <allegro5/allegro.h>
#include "Game.h"

void Game::start() {
	ALLEGRO_DISPLAY *display = NULL;

	if(!al_init()) {
	  fprintf(stderr, "failed to initialize allegro!\n");
	  return;
	}

	display = al_create_display(640, 480);
	if(!display) {
	  fprintf(stderr, "failed to create display!\n");
	  return;
	}

	while(true) {
		al_clear_to_color(al_map_rgb(0,0,0));
		al_flip_display();
	}
}

