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
	static const int SPEED_MOD = 2;
	static const int BOOST_DURATION = 120;

	int modifier;
	int duration;

	SpeedBoost(GameObject *owner) :GameComponent(owner){
		modifier = SPEED_MOD;
		duration = BOOST_DURATION;
	}

	virtual void update(){}
	virtual void render(){}
};


#endif /* SPEEDBOOST_H_ */
