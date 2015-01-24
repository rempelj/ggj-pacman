/*
 * GameObject.h
 *
 * Container for GameComponents. Automatically attaches the Transform component.
 *
 *  Created on: Jan 24, 2015
 *      Author: justinrempel
 */

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "GameComponent.h"

class GameObject {
public:
	GameObject();

	// Attaches and returns a GameComponent
	template <class T> GameComponent* addComponent() {
		T *component = new T();

		// TODO: attach component to this GameObject

		return component;
	}
};



#endif /* GAMEOBJECT_H_ */
