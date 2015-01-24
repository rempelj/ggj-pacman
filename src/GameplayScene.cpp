/*
 * GameplayScene.cpp
 *
 *  Created on: Jan 24, 2015
 *      Author: justinrempel
 */

#include <allegro5/allegro.h>
#include "GameplayScene.h"
#include "GameObject.h"

#include <stdio.h>

GameplayScene::GameplayScene() {
	objects.push_back(pacman);
}

void GameplayScene::update() {

}

void GameplayScene::render() {
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();
}
