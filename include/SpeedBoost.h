/*
 * SpeedBoost.h
 *
 *  Created on: Jan 25, 2015
 *      Author: justinrempel
 */

#ifndef SPEEDBOOST_H_
#define SPEEDBOOST_H_


class SpeedBoost : public GameComponent{
public:
	int modifier = 2;
	SpeedBoost(GameObject *owner) :GameComponent(owner){
	}

	virtual void update();
	virtual void render();
};


#endif /* SPEEDBOOST_H_ */
