/*
* Sprite.h
*
* Component that Holds a bitmap
*
*  Created on: Jan 24, 2015
*      Author: alex rehnby
*/



#include "GameComponent.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

class Sprite : public GameComponent {
public:
	ALLEGRO_BITMAP* Bitmap;

	Sprite();
	Sprite(ALLEGRO_BITMAP* Bits);
	virtual void update();

};

