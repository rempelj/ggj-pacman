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

	Sprite(GameObject *owner) :GameComponent(owner){
		Bitmap = NULL;
	}
	void SetSprite(ALLEGRO_BITMAP* Bits);
	ALLEGRO_BITMAP* GetSprite();
	virtual void update();
	virtual void render();

};

#endif /* SPRITE_H_ */
