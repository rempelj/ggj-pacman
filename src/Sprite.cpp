#include "Sprite.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>


void Sprite::SetSprite(ALLEGRO_BITMAP* Bits){
	Bitmap = al_clone_bitmap(Bits);
}

void Sprite::update() {

}