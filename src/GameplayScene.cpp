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
#include "SolidCollider.h"
#include "InputManager.h"
#include "TileMapHelper.h"
#include "Pellet.h"

void GameplayScene::init() {

	

	ALLEGRO_BITMAP *Image = NULL;
	if (al_init_image_addon()) {

		int **map = loadLevel("assets/level1.map");

		ALLEGRO_BITMAP* targ = al_get_target_bitmap();
		ALLEGRO_BITMAP* temp = al_load_bitmap("assets/tile.png");
		Image = al_create_bitmap(TILE_WIDTH, TILE_HEIGHT);
		al_set_target_bitmap(Image);
		al_draw_scaled_bitmap(temp, 0, 0, al_get_bitmap_width(Image), al_get_bitmap_height(Image), 0, 0, TILE_WIDTH, TILE_HEIGHT, 0);
		al_set_target_bitmap(targ);

		ALLEGRO_BITMAP *PelletImage = al_load_bitmap("assets/pellet.png");

		for (int i = 0; i < TILE_COUNT_X; i++){
			for (int j = 0; j < TILE_COUNT_Y; j++){
				if (map[j][i] == TILE_WALL){
					GameObject *tile = new GameObject();
					tile->getTransform()->x = i * al_get_bitmap_width(Image);
					tile->getTransform()->y = j * al_get_bitmap_height(Image);
					tile->addComponent<Sprite>()->SetSprite(Image);
					tile->addComponent<SolidCollider>();
					objects.push_back(tile);
				} else if (map[j][i] == TILE_PELLET) {
					GameObject *tile = new GameObject();
					tile->getTransform()->x = i * TILE_WIDTH;
					tile->getTransform()->y = j * TILE_HEIGHT;
					tile->addComponent<Sprite>()->SetSprite(PelletImage);
					tile->addComponent<Pellet>();
					objects.push_back(tile);
				}
				
			}
		}

		
		// add pacman's corpse to the scene
		GameObject *pacmanGo = new GameObject();
		pacman = pacmanGo->addComponent<PacmanCorpse>();
		Image = al_load_bitmap("assets/deadpac.png");
		pacman->SetSprite(Image);

		objects.push_back(pacmanGo);

		
	}

	

	// add players (ghosts)
	for(int i = 0; i < NUM_PLAYERS; i++) {
		GameObject *ghostGo = new GameObject();
		Ghost *player = ghostGo->addComponent<Ghost>();
		player->SetVector(objects);
		objects.push_back(ghostGo);

		players.push_back(player);

		if (al_init_image_addon()) {
			Image = al_load_bitmap("assets/ghost.png");
			ghostGo->addComponent<Sprite>()->SetSprite(Image);

			// TODO: set ghost positions somewhere other than the centre
			ghostGo->getTransform()->x = DISPLAY_WIDTH/2 + i*50;
			ghostGo->getTransform()->y = DISPLAY_HEIGHT/2;
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

int GameplayScene::RemoveObject(GameObject* obj){	// TODO: CLEANUP CODE
	for (int i = 0; i < objects.size(); i++){
		if (objects[i] == obj){
			objects.erase(objects.begin() + i);
			return 1;
		}
	}
	return 0;
}
