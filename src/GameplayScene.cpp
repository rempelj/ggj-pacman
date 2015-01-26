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
#include "AssetManager.h"
#include "SpeedBoost.h"

void GameplayScene::init() {

	if (al_init_image_addon()) {
		int **map = loadLevel("assets/level1.map");

		ALLEGRO_BITMAP *Image = AssetManager::instance().getScaledImage("assets/tile.png");
		ALLEGRO_BITMAP *PelletImage = AssetManager::instance().getScaledImage("assets/pellet.png");

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
		Image = AssetManager::instance().getScaledImage("assets/deadpac.png");
		pacman->SetSprite(Image);
		objects.push_back(pacmanGo);
	}

	
	// add players (ghosts)
	for(int i = 0; i < NUM_PLAYERS; i++) {
		GameObject *ghostGo = new GameObject();
		Ghost *player = ghostGo->addComponent<Ghost>();
		player->SetVector(&objects);
		objects.push_back(ghostGo);

		players.push_back(player);

		if (al_init_image_addon()) {
			ALLEGRO_BITMAP *Image = AssetManager::instance().getScaledImage("assets/ghost.png");
			ghostGo->addComponent<Sprite>()->SetSprite(Image);

			// TODO: set ghost positions somewhere other than the centre
			ghostGo->getTransform()->x = DISPLAY_WIDTH/2 + i*50;
			ghostGo->getTransform()->y = DISPLAY_HEIGHT/2;
		}

		InputManager::instance().registerListener(player);
	}

	// add cherry (speed boost)
	GameObject *cherryGo = new GameObject();
	cherryGo->addComponent<SpeedBoost>();
	ALLEGRO_BITMAP* Image = AssetManager::instance().getScaledImage("assets/cherry.png");
	cherryGo->addComponent<Sprite>()->SetSprite(Image);
	cherryGo->getTransform()->x = 20;
	cherryGo->getTransform()->y = 60;
	objects.push_back(cherryGo);

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
	delete obj;
	return 0;
}
