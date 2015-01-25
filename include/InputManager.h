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

#include <allegro5/allegro.h>
#include <vector>
#include "InputListener.h"

class InputManager {
private:
	std::vector<InputListener*> listeners;

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
	void registerListener(InputListener* listener){
		listeners.push_back(listener);
	}
};


#endif /* INPUTMANAGER_H_ */
