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
#include "Sprite.h"

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
		T *component = new T(this);

		components.push_back(component);

		return component;
	}

	// Return a component of specified type, or null if not found
	template <class T> T* getComponent() {
		for (int i = 0; i < components.size(); i++) {
			if(typeid(components[i]) == typeid(T)) {
				return components[i];
			}
		}

		return nullptr;
	}
};



#endif /* GAMEOBJECT_H_ */
