/*
 * InputListener.h
 *
 * Implemented by GameComponents. Must register with InputManager.
 *
 *  Created on: Jan 24, 2015
 *      Author: justinrempel
 */

#ifndef INPUTLISTENER_H_
#define INPUTLISTENER_H_


class InputListener {
public:
	virtual void upPressed() = 0;
	virtual void downPressed() = 0;
	virtual void leftPressed() = 0;
	virtual void rightPressed() = 0;

	virtual ~InputListener(){}
};


#endif /* INPUTLISTENER_H_ */
