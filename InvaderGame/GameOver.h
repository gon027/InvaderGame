#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "BaseScene.h"
#include "SceneController.h"
#include "BackGround.h"

class GameOver : public BaseScene{
public:
	GameOver() = default;
	GameOver(SceneController *_controller, int _round, int _score, int _hiScore);
	~GameOver() = default;

	void setup() override;
	void update() override;

private:
	BackGround backGround;

	int round;
	int score;
	int hiScore;
};

#endif // !GAMEOVER_H
