/*
 * Game.h
 *
 *  Created on: Jan 23, 2015
 *      Author: justinrempel
 */

#ifndef GAME_H_
#define GAME_H_


class Game {
private:
	static float delta;
public:
	void start();

	static float deltaTime() { return delta; }
};


#endif /* GAME_H_ */
