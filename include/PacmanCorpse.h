/*
 * PacmanCorpse.h
 *
 *  Created on: Jan 24, 2015
 *      Author: justinrempel
 */

#ifndef PACMANCORPSE_H_
#define PACMANCORPSE_H_

#include "GameComponent.h"

class PacmanCorpse : public GameComponent {
public:
	PacmanCorpse(GameObject *owner):GameComponent(owner){}

	virtual void update();
};


#endif /* PACMANCORPSE_H_ */
