/*
 * GameComponent.h
 *
 * Base class for anything attached to GameObjects.
 *
 *  Created on: Jan 24, 2015
 *      Author: justinrempel
 */

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#ifndef GAMECOMPONENT_H_
#define GAMECOMPONENT_H_

class GameComponent {
protected:
	GameComponent(){}

public:
	virtual void update() = 0;

	virtual ~GameComponent(){}
};

#endif /* GAMECOMPONENT_H_ */
