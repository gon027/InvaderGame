#include "Main.h"

#include "Timer.h"

Game game;

//SceneController sController;
Status status;
BackGround back(0, 0, "image/back_game.png");

void init() {
	SetBackgroundColor(0, 0, 0);

	singleton<AudioManager>::getInstance().read("sound/se_test1.mp3", 0);
	singleton<AudioManager>::getInstance().read("sound/se_test2.mp3", 1);
	/*singleton<AudioManager>::getInstance().read("sound/se_test3.mp3", 2);
	singleton<AudioManager>::getInstance().read("sound/se_test2.mp3", 3);
	singleton<AudioManager>::getInstance().read("sound/se_test3.mp3", 4);
	singleton<AudioManager>::getInstance().read("sound/se_test2.mp3", 5);
	singleton<AudioManager>::getInstance().read("sound/se_test2.mp3", 6);
	*/	

	game.setup();

	back.loadImage();


	//status = Title;
	//sController.start();
}

void update() {
	Timer::time = GetNowCount();

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