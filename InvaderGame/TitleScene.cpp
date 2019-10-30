#include "TitleScene.h"

#include <string>
#include "DxLib.h"
#include "Define.h"
#include "Color.h"
#include "Game.h"

TitleScene::TitleScene(){

}

TitleScene::TitleScene(SceneController * _controller){
	this->controller = _controller;
	setup();
}

void TitleScene::setup(){
	backGround.init(0, 0, "image/back_title.png");
	backGround.loadImage();
}

int frame = 0;

void TitleScene::update(){
	backGround.draw();

	SetFontSize(32);

	DrawString(400 + 20, 50, "SCORE< 1 >", GetColor(0, 255, 255));
	DrawString(640, 50, "HI-SCORE", GetColor(0, 0, 255));
	//DrawString(840 - 20, 50, "SCORE< 2 >", GetColor(255, 255, 0));

	DrawFormatString(400 + 20 + 37, 90, GetColor(255, 255, 255), "%05d", 0);
	DrawFormatString(640 + 17, 90, GetColor(0, 255, 255), "%05d", 0);
	//DrawFormatString(840 + 17, 90, GetColor(255, 255, 255), "%05d", 0);

	DrawFormatString(Window::MIDDLE + 45, 200, green, "%s", "PLAY");
	DrawFormatString(Window::MIDDLE - 55, 300, green, "%s", "INVADERS   GAME");
	DrawFormatString(Window::MIDDLE - 110, 400, skybule, "%s", "*SCORE ADVANCE TABLE*");
	DrawFormatString(Window::MIDDLE + 15, 450, pink, "%s", "=? MYSTERY");
	DrawFormatString(Window::MIDDLE + 15, 500, pink, "%s", "=30 POINTS");
	DrawFormatString(Window::MIDDLE + 15, 550, yellow, "%s", "=20 POINTS");
	DrawFormatString(Window::MIDDLE + 15, 600, yellow, "%s", "=10 POINTS");

	SetFontSize(28);
	DrawFormatString(Window::MIDDLE - 75, 650, yellow, "%s", "F, D KEY : MOVE");
	DrawFormatString(Window::MIDDLE - 15, 700, yellow, "%s", "J KEY : SHOT");

	frame = (frame + 1) % 100;
	if (frame < 50) {
		DrawFormatString(Window::MIDDLE, 800, yellow, "%s", " PUSH SPACE");
	}

	if (CheckHitKey(KEY_INPUT_P) != 0) {
		this->controller->scene = new Game(controller);
		delete this;
	}
}
