/*
* Sprite.h
*
* Component that Holds a bitmap
*
*  Created on: Jan 24, 2015
*      Author: alex rehnby
*/
#ifndef SPRITE_H_
#define SPRITE_H_


#include "GameComponent.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

class Sprite : public GameComponent {
public:
	ALLEGRO_BITMAP* Bitmap;

	Sprite(){

	}
	Sprite(GameObject *owner) :GameComponent(owner){
		Bitmap = NULL;
	}
	void SetSprite(ALLEGRO_BITMAP* Bits);
	virtual void update();

};

#endif /* SPRITE_H_ */