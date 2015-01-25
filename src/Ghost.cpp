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
#include "PacmanCorpse.h"

void Ghost::SetVector(std::vector<GameObject*> Objects){
	otherObjects = Objects;
}

int Ghost::TryMove(int xMove, int yMove){
	Transform *t = getGameObject()->getTransform();
	int potX = t->x + xMove;
	int potY = t->y + yMove;

	for (int i = 0; i < otherObjects.size(); i++)
	{
		
		Transform *c = otherObjects[i]->getTransform();
		if (   (potX + t->width > c->x)
			&& (potX < c->x + c->width)
			&& (potY + t->height > c->y)
			&& (potY < c->y + c->height)
			)
		{
			if (otherObjects[i]->getComponent<SolidCollider>()){
				return 0;
			}

			PacmanCorpse* pac = otherObjects[i]->getComponent<PacmanCorpse>();
			if (pac){
				ALLEGRO_BITMAP *temp = pac->GetSprite();
				otherObjects[i]->removeComponent<PacmanCorpse>(pac);
				_gameObject->addComponent<PacmanCorpse>()->SetSprite(temp);

				Ghost* otherGhost = otherObjects[i]->getComponent<Ghost>();
				if (otherGhost){
					otherGhost->Stun();
				}
			}

		}
		
	}

	t->x += xMove;
	t->y += yMove;
	return 1;
}

void Ghost::Stun(){
	stunFrames = STUN_DURATION;
}

void Ghost::update(){
	Transform *t = getGameObject()->getTransform();

	if (stunFrames > 0){
		stunFrames--;
	}
	else{
		switch (direction){
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

		if (t->x > DISPLAY_WIDTH) {
			t->x = 0;
		}

		if (t->x < 0) {
			t->x = DISPLAY_WIDTH;
		}

		if (t->y < 0) {
			t->y = DISPLAY_HEIGHT;
		}

		if (t->y > DISPLAY_HEIGHT) {
			t->y = 0;
		}
	}

	
}
