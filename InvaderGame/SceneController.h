#ifndef SCENECONTROLLER_H
#define SCENECONTROLLER_H

#include "Define.h"
class BaseScene;

class SceneController {
public:
	SceneController();
	~SceneController();

	void setup();
	void update();
	void changeScene(Status _status);

private:
	BaseScene* scene = nullptr;
	Status status;
};

#endif // !SCENECONTROLLER
