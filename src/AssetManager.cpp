/*
 * AssetManager.cpp
 *
 *  Created on: Jan 25, 2015
 *      Author: justinrempel
 */

#include "AssetManager.h"
#include <allegro5/allegro_image.h>
#include "Common.h"
#include <stdio.h>

ALLEGRO_BITMAP * AssetManager::getScaledImage(const char* path){
	if(cachedImages[path]) {
		return cachedImages[path];
	}

	ALLEGRO_BITMAP* targ = al_get_target_bitmap();
	ALLEGRO_BITMAP* temp = al_load_bitmap(path);
	ALLEGRO_BITMAP* Image = al_create_bitmap(TILE_WIDTH, TILE_HEIGHT);
	al_set_target_bitmap(Image);
	al_draw_scaled_bitmap(temp, 0, 0, al_get_bitmap_width(temp), al_get_bitmap_height(temp), 0, 0, TILE_WIDTH, TILE_HEIGHT, 0);
	al_set_target_bitmap(targ);

	cachedImages[path] = Image;
	return Image;
}
