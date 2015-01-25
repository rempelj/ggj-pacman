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
#include "Pellet.h"
#include "GameManager.h"

void Ghost::SetVector(std::vector<GameObject*> *Objects){
	otherObjects = Objects;
}

int Ghost::TryMove(int xMove, int yMove){
	Transform *t = getGameObject()->getTransform();
	int potX = t->x + xMove;
	int potY = t->y + yMove;

	for (int i = 0; i < otherObjects->size(); i++)
	{
		
		Transform *c = otherObjects->at(i)->getTransform();
		if (   (potX + t->width > c->x)
			&& (potX < c->x + c->width)
			&& (potY + t->height > c->y)
			&& (potY < c->y + c->height)
			)
		{
			if (otherObjects->at(i)->getComponent<SolidCollider>()){
				return 0;
			}

			PacmanCorpse* pac = otherObjects->at(i)->getComponent<PacmanCorpse>();
			if (pac){
				ALLEGRO_BITMAP *temp = pac->GetSprite();
				otherObjects->at(i)->removeComponent<PacmanCorpse>(pac);
				_gameObject->addComponent<PacmanCorpse>()->SetSprite(temp);

				Ghost* otherGhost = otherObjects->at(i)->getComponent<Ghost>();
				if (otherGhost){
					otherGhost->Stun();
				}
			}

			Pellet* pellet = otherObjects->at(i)->getComponent<Pellet>();
			if (pellet){
				GameObject *pelletGo = otherObjects->at(i);
				GameManager::instance().getGameplayScene()->RemoveObject(pelletGo);
				score++;
				printf("score: %d\n", score);
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
