#include "Main.h"

Game game;

SceneController sController;
Status status;
BackGround back(0, 0, "image/back_game.png");

void init() {
	SetBackgroundColor(0, 0, 0);

	game.start();

	back.loadImage();


	//status = Title;
	//sController.start();
}

void update() {
#ifdef FULL_SCREEN
	back.draw();
#else
	DrawBox(0, 0, Window::WIDTH, Window::HEIGHT, GetColor(0, 255, 255), TRUE);
#endif

	game.update();
	
	/*sController.update();

	if (status == Title) {
		if (CheckHitKey(KEY_INPUT_SPACE)) {
			status = GameScene;
			sController.changeScene(status);
		}
	}*/
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrefInstance, LPSTR lpCmdLine, int nCmdShow) {
	ChangeWindowMode(TRUE);
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);
	SetGraphMode(Window::WIDTH, Window::HEIGHT, 32);
	SetWindowSize(Window::WIDTH, Window::HEIGHT);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK); 

	init();

	while (isProcess()) {
		update();
	}

	DxLib_End();
	return 0;
}