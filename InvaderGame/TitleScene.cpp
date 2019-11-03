#include "TitleScene.h"

#include <string>
#include "DxLib.h"
#include "Define.h"
#include "Color.h"
#include "Game.h"
#include "FileReader.h"

int tframe = 0;

TitleScene::TitleScene(){

}

TitleScene::TitleScene(SceneController * _controller){
	this->controller = _controller;
	setup();
}

void TitleScene::setup(){
	backGround.init(0, 0, "image/back_title.png");
	backGround.loadImage();
	enemyImg.LoadActorImgBuf("image/enemy_images.png");
	ufo.LoadActorImage("image/ufo.png");
	singleton<FileReader>::getInstance().read("text/HiScore.txt", "r");
	hiScore = singleton<FileReader>::getInstance().getScore();
}

void TitleScene::update(){
	backGround.draw();

	SetFontSize(32);
	DrawString(400 + 50, 70, "SCORE< 1 >", GetColor(0, 255, 255));
	DrawString(640 + 30, 70, "HI-SCORE", GetColor(0, 0, 255));

	DrawFormatString(400 + 50 + 37, 110, GetColor(255, 255, 255), "%05d", 0);
	DrawFormatString(640 + 50, 110, GetColor(0, 255, 255), "%05d", hiScore);

	DrawFormatString(Window::MIDDLE + 45, 200, green, "%s", "PLAY");
	DrawFormatString(Window::MIDDLE - 55, 300, green, "%s", "INVADERS   GAME");
	DrawFormatString(Window::MIDDLE - 110, 400, skybule, "%s", "*SCORE ADVANCE TABLE*");

	ufo.DrawImage(Window::MIDDLE - 32, 450);
	DrawFormatString(Window::MIDDLE + 15, 450, pink, "%s", "=? MYSTERY");

	enemyImg.DrawImageFromImgBuf(Window::MIDDLE - 32, 500, 0);
	DrawFormatString(Window::MIDDLE + 15, 500, pink, "%s", "=30 POINTS");

	enemyImg.DrawImageFromImgBuf(Window::MIDDLE - 32, 550, 1);
	DrawFormatString(Window::MIDDLE + 15, 550, yellow, "%s", "=20 POINTS");

	enemyImg.DrawImageFromImgBuf(Window::MIDDLE - 32, 600, 2);
	DrawFormatString(Window::MIDDLE + 15, 600, yellow, "%s", "=10 POINTS");


	//SetFontSize(28);
	//DrawFormatString(Window::MIDDLE - 25, 650, yellow, "%s", "D, F KEY : MOVE");
	//DrawFormatString(Window::MIDDLE + 20, 700, yellow, "%s", "J KEY : SHOT");

	SetFontSize(32);
	tframe = (tframe + 1) % 100;
	if (tframe < 50) {
		DrawFormatString(Window::MIDDLE - 30, 775, yellow, "%s", " PUSH SPACE");
	}

	if (CheckHitKey(KEY_INPUT_SPACE) != 0) {
		this->controller->scene = new Game(controller);
		delete this;
	}
}
