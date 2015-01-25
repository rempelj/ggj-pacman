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

class Ghost : public GameComponent {
public:
	Direction direction;

	Ghost(GameObject *owner):GameComponent(owner){
		direction = E;
	}

	virtual void update();
};


#endif /* GHOST_H_ */
