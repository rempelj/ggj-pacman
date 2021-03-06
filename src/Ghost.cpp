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
	xMove *= speedMod;
	yMove *= speedMod;

	Transform *t = getGameObject()->getTransform();
	int potX = t->x + xMove;
	int potY = t->y + yMove;


	for (int i = 0; i < otherObjects->size(); i++)
	{
		if ((*otherObjects)[i] == _gameObject){
			continue;
		}
		Transform *c = otherObjects->at(i)->getTransform();

		if (   (potX + t->width > c->x)
			&& (potX < c->x + c->width)
			&& (potY + t->height > c->y)
			&& (potY < c->y + c->height)
			)
		{

			if ((*otherObjects)[i]->getComponent<SolidCollider>()){
				return 0;
			}
			else{
				PacmanCorpse* pac = (*otherObjects)[i]->getComponent<PacmanCorpse>();
				if (pac){
					ALLEGRO_BITMAP *temp = pac->GetSprite();
					(*otherObjects)[i]->removeComponent<PacmanCorpse>(pac);
					_gameObject->addComponent<PacmanCorpse>()->SetSprite(temp);

					Ghost* otherGhost = (*otherObjects)[i]->getComponent<Ghost>();
					if (otherGhost){
						otherGhost->Stun();
					}
				}
			}

			Pellet* pellet = otherObjects->at(i)->getComponent<Pellet>();

			if (pellet && getGameObject()->getComponent<PacmanCorpse>()){
				// only collect pellets if this ghost is holding pacman
				GameObject *pelletGo = otherObjects->at(i);
				GameManager::instance().getGameplayScene()->RemoveObject(pelletGo);
				score++;
				printf("score: %d\n", score);
			}


			SpeedBoost* boost = otherObjects->at(i)->getComponent<SpeedBoost>();
			if(boost) {
				GameObject *boostGo = otherObjects->at(i);
				GameManager::instance().getGameplayScene()->RemoveObject(boostGo);
				applyBoost(boost);
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

void Ghost::applyBoost(SpeedBoost *boost) {
	speedMod = boost->modifier;
	speedBoostFrames = boost->duration;
}

void Ghost::update(){
	Transform *t = getGameObject()->getTransform();

	speedBoostFrames--;
	if (speedBoostFrames <= 0) {
		speedMod = 1;
	}

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
