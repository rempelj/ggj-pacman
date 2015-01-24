/*
 * GameplayScene.h
 *
 *  Created on: Jan 24, 2015
 *      Author: justinrempel
 */

#ifndef GAMEPLAYSCENE_H_
#define GAMEPLAYSCENE_H_

#include "Scene.h"

class GameplayScene : public Scene {
public:
	GameplayScene();

	virtual void update();
	virtual void render();
};

#endif /* GAMEPLAYSCENE_H_ */
