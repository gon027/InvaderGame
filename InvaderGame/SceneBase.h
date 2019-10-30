#ifndef SCENEBASE_H
#define SCENEBASE_H

class SceneController;

class SceneBase {
public:
	SceneBase() = default;
	virtual ~SceneBase() = default;

	virtual void setup() = 0;
	virtual void update() = 0;

protected:
	SceneController *SceneController;
};

#endif // !SCENEBASE_H
