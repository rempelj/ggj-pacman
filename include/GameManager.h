/*
 * GameManager.h
 *
 * Singleton. Manages and updates the game "scenes".
 *
 *  Created on: Jan 23, 2015
 *      Author: justinrempel
 */

#ifndef GAME_MANAGER_H_
#define GAME_MANAGER_H_


#include "GameplayScene.h"

class GameManager {
private:
	GameplayScene gameplayScene;

	GameManager(){}
	GameManager(GameManager const&);
	void operator=(GameManager const&);

public:
	static GameManager& instance()
	{
		static GameManager instance;
		return instance;
	}

	void start();

	GameplayScene *getGameplayScene() {
		return &gameplayScene;
	}
};


#endif /* GAME_MANAGER_H_ */
