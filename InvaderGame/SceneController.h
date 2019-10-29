#ifndef SCENECONTROLLER_H
#define SCENECONTROLLER_H

#include "Define.h"
#include "singleton.h"
class BaseScene;

class SceneController : public singleton<SceneController>{
public:
	void setup();
	void update();
	void changeScene(Status _status);

protected:
	SceneController();
	~SceneController();

private:
	BaseScene* scene = nullptr;
	Status status;
};

#endif // !SCENECONTROLLER
