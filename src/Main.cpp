#include <stdio.h>
#include <allegro5/allegro.h>
#include "GameManager.h"

int main(int argc, char **argv){
	GameManager::instance().start();
	return 0;
}
