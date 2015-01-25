#include "Sprite.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>


void Sprite::SetSprite(ALLEGRO_BITMAP* Bits){
	Bitmap = al_clone_bitmap(Bits);
}

void Sprite::update() {

}

void Sprite::render() {
	if(Bitmap) {
		al_draw_bitmap(Bitmap, 0, 0, 0);
	}
}
