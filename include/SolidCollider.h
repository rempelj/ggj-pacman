#include <allegro5/allegro_primitives.h>
#include "GameComponent.h"
#include "Common.h"

class SolidCollider : public GameComponent{
public:
	SolidCollider(GameObject *owner) :GameComponent(owner){
		
	}
	
	virtual void update();
	virtual void render();
};