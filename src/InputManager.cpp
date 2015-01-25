/*
 * InputManager.cpp
 *
 *  Created on: Jan 24, 2015
 *      Author: justinrempel
 */

#include "InputManager.h"
#include <stdio.h>
#include <allegro5/keycodes.h>

void InputManager::handleEvent(ALLEGRO_EVENT ev) {

	// TODO: Assign different buttons to different players

	for(int i = 0; i < listeners.size(); i++) {
		if (i == 0){
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_W:
				listeners[i]->upPressed();
				break;
			case ALLEGRO_KEY_S:
				listeners[i]->downPressed();
				break;
			case ALLEGRO_KEY_A:
				listeners[i]->leftPressed();
				break;
			case ALLEGRO_KEY_D:
				listeners[i]->rightPressed();
				break;
			}
		}
		else{
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				listeners[i]->upPressed();
				break;
			case ALLEGRO_KEY_DOWN:
				listeners[i]->downPressed();
				break;
			case ALLEGRO_KEY_LEFT:
				listeners[i]->leftPressed();
				break;
			case ALLEGRO_KEY_RIGHT:
				listeners[i]->rightPressed();
				break;
			}
		}
		
	}

}
