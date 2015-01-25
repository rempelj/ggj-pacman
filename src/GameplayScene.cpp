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

		int map[4][6] = {
		{ 0, 0, 0, 0, 0, 1 },
		{ 0, 0, 0, 0, 0, 1 },
		{ 0, 0, 0, 0, 0, 1 },
		{ 1, 1, 1, 1, 1, 1 } };

		ALLEGRO_BITMAP* targ = al_get_target_bitmap();
		ALLEGRO_BITMAP* temp = al_load_bitmap("assets/tile.png");
		Image = al_create_bitmap(TILE_WIDTH, TILE_HEIGHT);
		al_set_target_bitmap(Image);
		al_draw_scaled_bitmap(temp, 0, 0, al_get_bitmap_width(Image), al_get_bitmap_height(Image), 0, 0, TILE_WIDTH, TILE_HEIGHT, 0);
		al_set_target_bitmap(targ);


		for (int i = 0; i < 4; i++){
			for (int j = 0; j < 6; j++){
				if (map[i][j]){
					GameObject *tile = new GameObject();
					tile->getTransform()->x = i * al_get_bitmap_width(Image);
					tile->getTransform()->y = j * al_get_bitmap_height(Image);
					tile->addComponent<Sprite>()->SetSprite(Image);
					objects.push_back(tile);


				}
				
			}
		}

		
		

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
