/*
 * GameplayScene.h
 *
 *  Created on: Jan 24, 2015
 *      Author: justinrempel
 */

#ifndef GAMEPLAYSCENE_H_
#define GAMEPLAYSCENE_H_

#include "Scene.h"
#include <vector>
#include "GameObject.h"

class GameplayScene : public Scene {
private:
	std::vector<GameObject> objects;
	GameObject pacman;
public:
	GameplayScene();

	virtual void update();
	virtual void render();
};

#endif /* GAMEPLAYSCENE_H_ */
