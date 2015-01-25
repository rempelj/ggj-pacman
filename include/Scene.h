/*
 * Scene.h
 *
 *  Created on: Jan 24, 2015
 *      Author: justinrempel
 */

#ifndef SCENE_H_
#define SCENE_H_

class Scene {
protected:
	Scene(){}

public:
	virtual void init() = 0;
	virtual void update() = 0;
	virtual void render() = 0;

	virtual ~Scene(){}
};


#endif /* SCENE_H_ */
