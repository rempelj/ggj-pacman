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
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;

	const double FPS = 60.0;

	if(!al_init()) {
	  fprintf(stderr, "failed to initialize allegro!\n");
	  return;
	}

	display = al_create_display(640, 480);
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
	

	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));

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

			if (ev.type == ALLEGRO_EVENT_TIMER){



				// GAME LOOP GOES HERE

				// game update logic

				// rendering

			}
		}


		// probably delete this stuff / move it to rendering code
		al_clear_to_color(al_map_rgb(0, 0, 0));  
		al_flip_display();
	}

	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return ;
}

