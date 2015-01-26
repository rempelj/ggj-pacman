/*
 * Ghost.h
 *
 *  Created on: Jan 24, 2015
 *      Author: justinrempel
 */

#ifndef GHOST_H_
#define GHOST_H_

#include "GameComponent.h"
#include "Common.h"
#include "InputListener.h"
#include <vector>
#include "SpeedBoost.h"

class Ghost : public GameComponent, public InputListener {
private:
	int score;
	int stunFrames;
	int speedMod;
	int speedBoostFrames;

public:
	Direction direction;

	std::vector<GameObject*> *otherObjects;

	Ghost(GameObject *owner):GameComponent(owner){
		speedMod = 1;
		speedBoostFrames = 0;
		otherObjects = nullptr;
		score = 0;
		stunFrames = 0;
		direction = E;
	}

	int TryMove(int xMove, int yMove);

	void SetVector(std::vector<GameObject*>* Objects);


	void applyBoost(SpeedBoost *boost);
	void Stun();

	virtual void update();
	virtual void render() {}

	virtual void upPressed() {
		direction = N;
	}
	virtual void downPressed() {
		direction = S;
	}
	virtual void leftPressed() {
		direction = W;
	}
	virtual void rightPressed() {
		direction = E;
	}
};


#endif /* GHOST_H_ */
