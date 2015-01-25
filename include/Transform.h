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

#include <allegro5/allegro_primitives.h>
#include "GameComponent.h"
#include "Common.h"

class Transform : public GameComponent {
public:
	int x;
	int y;
	int width;
	int height;

	Transform(GameObject *owner):GameComponent(owner){
		x = 0;
		y = 0;
		width = TILE_WIDTH;
		height = TILE_HEIGHT;
	}

	virtual void update();
	virtual void render(){
		//al_draw_filled_rectangle(x, y, x+width, y+height, al_map_rgb(0,255,0));
	}
};



#endif /* TRANSFORM_H_ */
