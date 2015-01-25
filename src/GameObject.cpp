/*
 * GameObject.cpp
 *
 *  Created on: Jan 24, 2015
 *      Author: justinrempel
 */

#include "GameObject.h"
#include "Transform.h"
#include <vector>
#include <typeinfo>


GameObject::GameObject() {
	_transform = addComponent<Transform>();
}

void GameObject::update() {
	for(int i =0; i < components.size(); i++) {
		components[i]->update();
	}
}

void GameObject::render(){
	for(int i =0; i < components.size(); i++) {
		components[i]->render();
	}
}




