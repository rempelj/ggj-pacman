/*
 * Ghost.h
 *
 *  Created on: Jan 24, 2015
 *      Author: justinrempel
 */

#ifndef GHOST_H_
#define GHOST_H_

#include "GameComponent.h"
#include "Common.h"
#include "InputListener.h"

class Ghost : public GameComponent, public InputListener {
public:
	Direction direction;

	Ghost(GameObject *owner):GameComponent(owner){
		direction = E;
	}

	virtual void update();
	virtual void render() {}

	virtual void upPressed() {
		direction = N;
	}
	virtual void downPressed() {
		direction = S;
	}
	virtual void leftPressed() {
		direction = W;
	}
	virtual void rightPressed() {
		direction = E;
	}
};


#endif /* GHOST_H_ */
