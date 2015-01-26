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
#include "Sprite.h"

class PacmanCorpse : public Sprite {
public:
	PacmanCorpse(GameObject *owner):Sprite(owner){
		Transform *t = getGameObject()->getTransform();
		if(t->x == 0) 
			t->x = DISPLAY_WIDTH / 2 - 8;
		if (t->y == 0)
			t->y = DISPLAY_HEIGHT/3 + 8;


	}

	virtual void update();
	//virtual void render(){}
};


#endif /* PACMANCORPSE_H_ */
