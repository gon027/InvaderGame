#include "Main.h"

Game game;

SceneController sController;
Status status;
int image[4];

void init() {
	SetBackgroundColor(0, 255, 255);

	game.start();
	///LoadDivGraph("image/block_test.png", 4, 4, 1, 32, 32, image);

	//status = Title;
	//sController.start();
}

void update() {
	game.update();
	//DrawGraph(100, 100, image[0], TRUE);

	
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

#ifdef FULL_SCREEN
		//DrawBox(0, 0, Window::LEFT, Window::HEIGHT, GetColor(255, 0, 0), 1);
		DrawBox(Window::LEFT, 0, Window::WALL_R, Window::HEIGHT, GetColor(0, 255, 0), 1);
		//DrawBox(Window::WALL_R, 0, Window::EDGE, Window::HEIGHT, GetColor(0, 0, 255), 1);
#endif
	}

	DxLib_End();
	return 0;
}