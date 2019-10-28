#ifndef SCENECONTROLLER_H
#define SCENECONTROLLER_H

#include "Define.h"
#include "singleton.h"
class BaseScene;

class SceneController : public singleton<SceneController>{
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
