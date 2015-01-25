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
#include "PacmanCorpse.h"
#include "Ghost.h"

class GameplayScene : public Scene {
private:
	std::vector<GameObject*> objects;
	PacmanCorpse *pacman;
	std::vector<Ghost*> players;
public:
	GameplayScene(){}

	virtual void init();
	virtual void update();
	virtual void render();
};

#endif /* GAMEPLAYSCENE_H_ */
