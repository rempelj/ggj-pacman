/*
 * GameObject.cpp
 *
 *  Created on: Jan 24, 2015
 *      Author: justinrempel
 */

#include "GameObject.h"
#include "Transform.h"

GameObject::GameObject() {
	addComponent<Transform>();
}
