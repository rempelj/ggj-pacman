/*
* Sprite.h
*
* Component that Holds a bitmap
*
*  Created on: Jan 24, 2015
*      Author: alex rehnby
*/

#ifndef TRANSFORM_H_
#define TRANSFORM_H_

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



#endif /* TRANSFORM_H_ */
