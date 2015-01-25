/*
 * GameObject.h
 *
 * Represents any game entity. Container for GameComponents. Automatically attaches the Transform component.
 *
 *  Created on: Jan 24, 2015
 *      Author: justinrempel
 */

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "GameComponent.h"
#include <vector>
#include "Transform.h"

class GameObject {
private:
	std::vector<GameComponent*> components;
	Transform *_transform;
public:
	GameObject();

	Transform *getTransform() { return _transform; }

	void update();
	void render();

	// Attaches and returns a GameComponent
	template <class T> T* addComponent() {
		T *component = new T();

		components.push_back(component);

		return component;
	}
};



#endif /* GAMEOBJECT_H_ */
