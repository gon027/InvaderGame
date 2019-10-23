#include "TitleScene.h"

#include "DxLib.h"
#include "Define.h"

TitleScene::TitleScene(){

}

TitleScene::~TitleScene(){

}

void TitleScene::start(){

}

void TitleScene::update(){
	DrawBox(0, 0, Window::WIDTH, Window::HEIGHT, GetColor(255, 255, 0), 1);
	DrawString(0, 16, "Title", GetColor(0, 0, 0));
}
