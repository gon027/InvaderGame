#ifndef SCENECONTROLLER_H
#define SCENECONTROLLER_H

#include "Define.h"
#include "SceneStatus.h"
#include "SceneController.h"
#include "BaseScene.h"

class BaseScene;

class SceneController{
public:
	SceneController();
	~SceneController();

	void setup();
	void update();
	void changeScene(SceneStatus _status);

public:
	static BaseScene* scene;
};

#endif // !SCENECONTROLLER
