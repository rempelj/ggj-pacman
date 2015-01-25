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

#include <iostream>
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;

#include <cstring>


using namespace std;

int charToInt(char c) {
	switch(c) {
		case '=':
			return 1;
		case ' ':
		default:
			return 0;
	}
}

int** loadLevel(const char* filename) {
	// load data
	ifstream fin;
	fin.open(filename);
	char buf[TILE_COUNT_X +1];

	// create the map
	int** map = new int*[TILE_COUNT_Y];
	for(int i = 0; i < TILE_COUNT_Y; ++i) {
	    map[i] = new int[TILE_COUNT_X];

	    // read row from file
	    if (!fin.eof()) {
			fin.getline(buf, TILE_COUNT_X +1);
		}

	    for(int j = 0; j < TILE_COUNT_X; ++j) {
	    //	printf("%c", buf[j]);
	    	map[i][j] = charToInt(buf[j]);
		}
	 //   printf("\n");
	}

	return map;
}

#endif /* TILEMAPHELPER_H_ */
