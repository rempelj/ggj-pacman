/*
 * GameManager.cpp
 *
 *  Created on: Jan 23, 2015
 *      Author: justinrempel
 */

#include <stdio.h>
#include <allegro5/allegro.h>
#include "GameManager.h"
#include "InputManager.h"
#include "Common.h"

void GameManager::start() {
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;

	const double FPS = 60.0;

	if(!al_init()) {
	  fprintf(stderr, "failed to initialize allegro!\n");
	  return;
	}

	display = al_create_display(DISPLAY_WIDTH, DISPLAY_HEIGHT);
	if(!display) {
	  fprintf(stderr, "failed to create display!\n");
	  return;
	}

	event_queue = al_create_event_queue();
	if (!event_queue) {
		fprintf(stderr, "failed to create event_queue!\n");
		al_destroy_display(display);
		return;
	}

	timer = al_create_timer(1.0/FPS);
	if (!timer){
		fprintf(stderr, "failed to create timer!\n");
		al_destroy_display(display);
		return;
	}
	
	if(!al_install_keyboard()) {
		fprintf(stderr, "failed to initialize the keyboard!\n");
		return;
	 }

	ALLEGRO_BITMAP *Image = NULL;
	if (al_init_image_addon())
		Image = al_load_bitmap("image.png");
	

	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();

	al_start_timer(timer);
	
	while(true) {
		ALLEGRO_EVENT ev;
		ALLEGRO_TIMEOUT timeout;
		al_init_timeout(&timeout, 0.06);

		bool get_event = al_wait_for_event_until(event_queue, &ev, &timeout);

		
		if (get_event){ // Event loop 

			if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE){ 
				break;
			}

			if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
				InputManager::instance().handleEvent(ev);
			}

			if (ev.type == ALLEGRO_EVENT_TIMER){

				// GAME LOOP GOES HERE
				gameplayScene.update();
				gameplayScene.render();

			}
		}

	}

	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return ;
}

