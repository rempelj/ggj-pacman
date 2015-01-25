/*
 * GameplayScene.cpp
 *
 *  Created on: Jan 24, 2015
 *      Author: justinrempel
 */

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "GameplayScene.h"
#include "GameObject.h"

GameplayScene::GameplayScene() {
	objects.push_back(pacman);
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
