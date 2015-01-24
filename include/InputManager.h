/*
 * InputManager.h
 *
 * Singleton. Receives input events, validates, and notifies listeners.
 *
 *  Created on: Jan 24, 2015
 *      Author: justinrempel
 */

#ifndef INPUTMANAGER_H_
#define INPUTMANAGER_H_

#include "allegro5/allegro.h"

class InputManager {
private:
	InputManager(){}
	InputManager(InputManager const&);
	void operator=(InputManager const&);

public:
	static InputManager& instance()
	{
		static InputManager instance;
		return instance;
	}

	void handleEvent(ALLEGRO_EVENT ev);
};


#endif /* INPUTMANAGER_H_ */
