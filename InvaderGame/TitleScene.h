#ifndef TITLESCENE_H
#define TITLESCENE_H

#include "BaseScene.h"
#include "SceneController.h"
#include "BackGround.h"
#include "Enemy.h"
#include "UFO.h"

class TitleScene : public BaseScene{
public:
	TitleScene();
	TitleScene(SceneController *_controller);
	~TitleScene() = default;

	void setup() override;
	void update() override;

private:
	BackGround backGround;
	Enemy enemyImg;
	UFO ufo;
	int hiScore;
};


#endif // !TITLESCENE_H
