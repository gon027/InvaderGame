#include "TitleScene.h"

#include "DxLib.h"
#include "Define.h"

TitleScene::TitleScene(){
	backGround.init(0, 0, "image/back_title.png");
}

TitleScene::~TitleScene(){

}

void TitleScene::setup(){
	backGround.loadImage();
}

void TitleScene::update(){
	backGround.draw();
}
