/*
 * Ghost.cpp
 *
 *  Created on: Jan 24, 2015
 *      Author: justinrempel
 */

#include "Ghost.h"
#include "Transform.h"
#include "GameObject.h"

void Ghost::update(){
	Transform *t = getGameObject()->getTransform();

	switch(direction){
		case N:
			t->y--;
			break;
		case E:
			t->x++;
			break;
		case S:
			t->y++;
			break;
		case W:
			t->x--;
			break;
	}

	if(t->x > DISPLAY_WIDTH) {
		t->x = 0;
	}

	if(t->x < 0) {
		t->x = DISPLAY_WIDTH;
	}

	if(t->y < 0) {
		t->y = DISPLAY_HEIGHT;
	}

	if(t->y > DISPLAY_HEIGHT) {
		t->y = 0;
	}
}
