/*
 * Pellet.h
 *
 *  Created on: Jan 25, 2015
 *      Author: justinrempel
 */

#ifndef PELLET_H_
#define PELLET_H_

#include "GameComponent.h"

class Pellet : public GameComponent{
public:

	Pellet(GameObject *owner) :GameComponent(owner){

	}

	virtual void update(){}
	virtual void render(){}
};
#endif /* PELLET_H_ */
