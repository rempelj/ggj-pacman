/*
 * InputManager.cpp
 *
 *  Created on: Jan 24, 2015
 *      Author: justinrempel
 */

#include "InputManager.h"
#include <stdio.h>

void InputManager::handleEvent(ALLEGRO_EVENT ev) {
	printf("keycode: %d\n", ev.keyboard.keycode);
}
