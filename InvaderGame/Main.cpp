#include "Main.h"

Game game;

void init() {
	SetBackgroundColor(0, 255, 255);

	game.setup();
}

void update() {
	game.update();
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrefInstance, LPSTR lpCmdLine, int nCmdShow) {
	ChangeWindowMode(TRUE);
	//SetWindowSizeChangeEnableFlag(FALSE, FALSE);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK); 

	init();

	while (isProcess()) {
		update();
	}

	DxLib_End();
	return 0;
}