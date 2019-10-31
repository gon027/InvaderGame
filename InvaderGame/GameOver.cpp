#include "GameOver.h"

#include "Define.h"
#include "TitleScene.h"
#include "Color.h"
#include "DxLib.h"

int frame = 0;

GameOver::GameOver(SceneController * _controller, int _round, int _score, int _hiScore){
	this->controller = _controller;
	round = _round;
	score = _score;
	hiScore = _hiScore;
	setup();
}

void GameOver::setup(){
	backGround.init(0, 0, "image/back_title.png");
	backGround.loadImage();
}

void GameOver::update(){
	backGround.draw();

	SetFontSize(64);
	DrawFormatString(Window::MIDDLE - 70, 200, red, "%s", "GAME OVER");

	SetFontSize(48);
	DrawFormatString(Window::MIDDLE + 20, 300, yellow, "%s", "ROUND");
	DrawFormatString(Window::MIDDLE + 55, 350, yellow, "%02d", round);

	DrawFormatString(Window::MIDDLE + 20, 425, red, "%s", "SCORE");
	DrawFormatString(Window::MIDDLE + 20, 475, red, "%05d", score);

	DrawFormatString(Window::MIDDLE, 550, bule, "%s", "HISCORE");
	frame = (frame + 1) % 100;
	if (score >= hiScore) {
		if (frame < 50) {
			DrawFormatString(Window::MIDDLE + 20, 600, bule, "%05d", hiScore);
		}
	}
	else {
		DrawFormatString(Window::MIDDLE + 20, 600, bule, "%05d", hiScore);
	}

	DrawFormatString(Window::MIDDLE - 100, 700, bule, "%s", "PRESS R RESTART");
	if (CheckHitKey(KEY_INPUT_R) != 0) {
		this->controller->scene = new TitleScene(controller);
		delete this;
	}
}
