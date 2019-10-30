#ifndef BASESCENE_H
#define BASESCENE_H

#include "SceneController.h"

class SceneController;

class BaseScene {
public:
	BaseScene() {};
	virtual ~BaseScene() {};

	virtual void setup() = 0;
	virtual void update() = 0;

	SceneController *controller;
};

#endif // !BASESCENE_H
