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
#include "PacmanCorpse.h"
#include "Common.h"
#include "Ghost.h"
#include "InputManager.h"

void GameplayScene::init() {

	// add pacman's corpse to the scene
	GameObject *pacmanGo = new GameObject();
	pacman = pacmanGo->addComponent<PacmanCorpse>();

	ALLEGRO_BITMAP *Image = NULL;
	if (al_init_image_addon()) {
		Image = al_load_bitmap("assets/deadpac.png");
		pacmanGo->addComponent<Sprite>()->SetSprite(Image);
	}

	objects.push_back(pacmanGo);

	// add players (ghosts)
	for(int i = 0; i < NUM_PLAYERS; i++) {
		GameObject *ghostGo = new GameObject();
		Ghost *player = ghostGo->addComponent<Ghost>();
		objects.push_back(ghostGo);

		players.push_back(player);

		if (al_init_image_addon()) {
			Image = al_load_bitmap("assets/ghost.png");
			ghostGo->addComponent<Sprite>()->SetSprite(Image);
		}

		InputManager::instance().registerListener(player);
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
		objects[i]->render();
	}

	al_flip_display();
}
