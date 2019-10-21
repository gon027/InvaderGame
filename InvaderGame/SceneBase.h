#ifndef SCENEBASE_H
#define SCENEBASE_H

class SceneBase {
public:
	SceneBase() {};
	virtual ~SceneBase() {};

	virtual void setup() = 0;
	virtual void update() = 0;

private:

};

#endif // !SCENEBASE_H
