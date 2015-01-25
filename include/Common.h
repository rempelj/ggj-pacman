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
static const int NUM_PLAYERS = 4;
static const int DISPLAY_WIDTH = 224;
static const int DISPLAY_HEIGHT = 288;
static const int TILE_WIDTH = 5;
static const int TILE_HEIGHT = 5;

// debug flags
static const bool DEBUG_RENDER_HITBOXES = true;

#endif /* COMMON_H_ */
