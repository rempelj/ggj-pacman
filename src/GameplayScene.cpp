/*
 * GameplayScene.cpp
 *
 *  Created on: Jan 24, 2015
 *      Author: justinrempel
 */

#include <allegro5/allegro.h>
#include "GameplayScene.h"
#include "GameObject.h"
#include "PacmanCorpse.h"

GameplayScene::GameplayScene() {
	GameObject pacmanGo;
	pacman = pacmanGo.addComponent<PacmanCorpse>();
	objects.push_back(pacmanGo);
}

void GameplayScene::update() {
	for(int i =0; i < objects.size(); i++) {
		objects[i].update();
	}
}

void GameplayScene::render() {
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();
}
