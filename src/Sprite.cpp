#include "Sprite.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "Transform.h"
#include "GameObject.h"

void Sprite::SetSprite(ALLEGRO_BITMAP* Bits){
	Bitmap = al_clone_bitmap(Bits);
}

ALLEGRO_BITMAP* Sprite::GetSprite(){
	return al_clone_bitmap(Bitmap);
}

void Sprite::update() {

}

void Sprite::render() {
	if(Bitmap) {
		Transform *t = getGameObject()->getTransform();
		al_draw_bitmap(Bitmap, t->x, t->y, 0);
	}
}
