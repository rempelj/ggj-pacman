/*
 * TileMapHelper.h
 *
 *  Created on: Jan 25, 2015
 *      Author: justinrempel
 */

#ifndef TILEMAPHELPER_H_
#define TILEMAPHELPER_H_

#include "Common.h"
#include <vector>

using namespace std;

int** loadLevel(const char* filename) {
	int** map = new int*[TILE_COUNT_X];
	for(int i = 0; i < TILE_COUNT_X; ++i) {
	    map[i] = new int[TILE_COUNT_Y];

	    for(int j = 0; j < TILE_COUNT_Y; ++j) {
			map[i][j] = 0;
		}
	}

	return map;
}



#endif /* TILEMAPHELPER_H_ */
