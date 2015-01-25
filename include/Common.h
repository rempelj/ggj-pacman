/*
 * Common.h
 *
 *  Created on: Jan 24, 2015
 *      Author: justinrempel
 */

#ifndef COMMON_H_
#define COMMON_H_

// enums
enum Direction { N, E, S, W };

// game settings
const int NUM_PLAYERS = 4;
const int DISPLAY_WIDTH = 224;
const int DISPLAY_HEIGHT = 288;
const int TILE_WIDTH = 8;
const int TILE_HEIGHT = 8;
const int TILE_COUNT_X = 28;
const int TILE_COUNT_Y = 36;

// debug flags
const bool DEBUG_RENDER_HITBOXES = false;

#endif /* COMMON_H_ */
