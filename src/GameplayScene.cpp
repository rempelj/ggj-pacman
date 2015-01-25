/*
 * GameplayScene.cpp
 *
 *  Created on: Jan 24, 2015
 *      Author: justinrempel
 */

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "GameplayScene.h"
#include "GameObject.h"
#include "PacmanCorpse.h"
#include "Common.h"
#include "Ghost.h"

GameplayScene::GameplayScene() {
	// add pacman's corpse to the scene
	GameObject *pacmanGo = new GameObject();
	pacman = pacmanGo->addComponent<PacmanCorpse>();
	objects.push_back(pacmanGo);

	// add players (ghosts)
	for(int i = 0; i < NUM_PLAYERS; i++) {
		GameObject *ghostGo = new GameObject();
		Ghost *player = ghostGo->addComponent<Ghost>();
		objects.push_back(ghostGo);

		players.push_back(player);
	}
}

void GameplayScene::update() {
	for(int i =0; i < objects.size(); i++) {
		objects[i]->update();
	}
}

void GameplayScene::render() {
	al_clear_to_color(al_map_rgb(0, 0, 0));

	for(int i =0; i < objects.size(); i++) {
		Transform* t = objects[i]->getTransform();
		al_draw_filled_rectangle(t->x, t->y, t->x+t->width, t->y+t->height, al_map_rgb(0,255,0));
	}

	al_flip_display();
}
