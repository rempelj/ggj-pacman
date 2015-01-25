/*
 * Ghost.cpp
 *
 *  Created on: Jan 24, 2015
 *      Author: justinrempel
 */

#include "Ghost.h"
#include "Transform.h"
#include "GameObject.h"
#include "SolidCollider.h"

void Ghost::SetVector(std::vector<GameObject*> Objects){
	otherObjects = Objects;
}

int Ghost::TryMove(int xMove, int yMove){
	Transform *t = getGameObject()->getTransform();
	int potX = t->x + xMove;
	int potY = t->y + yMove;

	for (int i = 0; i < otherObjects.size(); i++)
	{
		if (otherObjects[i]->getComponent<SolidCollider>()){
			Transform *c = otherObjects[i]->getTransform();
			if (   (potX + t->width > c->x)
				&& (potX < c->x + c->width)
				&& (potY + t->height > c->y)
				&& (potY < c->y + c->height)
				)
			{
				return 0;
			}
		}
	}

	t->x += xMove;
	t->y += yMove;
	return 1;
}

void Ghost::update(){
	Transform *t = getGameObject()->getTransform();

	

	switch(direction){
		case N:
			TryMove(0, -1);
			break;
		case E:
			TryMove(1, 0);
			break;
		case S:
			TryMove(0, 1);
			break;
		case W:
			TryMove(-1, 0);
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
