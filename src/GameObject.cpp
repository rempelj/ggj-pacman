/*
 * GameObject.cpp
 *
 *  Created on: Jan 24, 2015
 *      Author: justinrempel
 */

#include "GameObject.h"
#include "Transform.h"
#include <vector>

GameObject::GameObject() {
	_transform = addComponent<Transform>();
}

void GameObject::update() {

}
