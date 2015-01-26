/*
 * AssetManager.h
 *
 *  Created on: Jan 25, 2015
 *      Author: justinrempel
 */

#ifndef ASSETMANAGER_H_
#define ASSETMANAGER_H_

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <map>

class AssetManager {
private:
	std::map<const char*, ALLEGRO_BITMAP*> cachedImages;

	AssetManager(){}
	AssetManager(AssetManager const&);
	void operator=(AssetManager const&);

public:
	static AssetManager& instance()
	{
		static AssetManager instance;
		return instance;
	}

	ALLEGRO_BITMAP *getScaledImage(const char* path);
};


#endif /* ASSETMANAGER_H_ */
