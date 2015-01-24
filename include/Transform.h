/*
 * Transform.h
 *
 * Logical representation of a GameObject. (position and size)
 *
 *  Created on: Jan 24, 2015
 *      Author: justinrempel
 */

#ifndef TRANSFORM_H_
#define TRANSFORM_H_

#include "GameComponent.h"

class Transform : public GameComponent {
public:
	Transform();
	virtual void update();

};



#endif /* TRANSFORM_H_ */
