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
			t->y++;
			break;
		case E:
			t->x++;
			break;
		case S:
			t->y--;
			break;
		case W:
			t->x--;
			break;
	}
}
