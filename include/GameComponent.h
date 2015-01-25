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

// GameObject declared here to fix cross-referencing errors
class GameObject;

class GameComponent {
private:
	GameObject *_gameObject;

public:
	GameComponent(){
		
	}
	GameComponent(GameObject *owner){
		_gameObject = owner;
	}

	virtual void update() = 0;
	virtual void render() = 0;

	virtual ~GameComponent(){}

	GameObject *getGameObject() {
		return _gameObject;
	}
};

#endif /* GAMECOMPONENT_H_ */
