#ifndef SCENECONTROLLER_H
#define SCENECONTROLLER_H

#include "Define.h"
#include "BaseScene.h"

class BaseScene;

class SceneController{
public:
	SceneController();
	~SceneController();

	void setup();
	void update();

public:
	static BaseScene* scene;
};

#endif // !SCENECONTROLLER
