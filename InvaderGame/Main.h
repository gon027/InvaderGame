#ifndef MAIN_H
#define MAIN_H

#include "DxLib.h"

#include "Define.h"
#include "SceneController.h"
#include "Game.h"
#include "BackGround.h"

void init();
void update();

bool isProcess() {
	if (ProcessMessage() != 0) return false;
	if (ScreenFlip() != 0) return false;
	if (ClearDrawScreen() != 0) return false;

	return true;
}

#endif // !MAIN_H
