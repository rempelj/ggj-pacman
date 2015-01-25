/*
 * PacmanCorpse.h
 *
 *  Created on: Jan 24, 2015
 *      Author: justinrempel
 */

#ifndef PACMANCORPSE_H_
#define PACMANCORPSE_H_

#include "GameComponent.h"
#include "Common.h"
#include "Transform.h"
#include "GameObject.h"

class PacmanCorpse : public GameComponent {
public:
	PacmanCorpse(GameObject *owner):GameComponent(owner){
		Transform *t = getGameObject()->getTransform();
		t->x = DISPLAY_WIDTH/2;
		t->y = DISPLAY_HEIGHT/2;
	}

	virtual void update();
	virtual void render(){}
};


#endif /* PACMANCORPSE_H_ */
