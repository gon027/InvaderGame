#pragma once

#include "DxLib.h"

#include "Game.h"

void init();
void update();

bool isProcess() {
	if (ProcessMessage() != 0) return false;
	if (ScreenFlip() != 0) return false;
	if (ClearDrawScreen() != 0) return false;

	return true;
}