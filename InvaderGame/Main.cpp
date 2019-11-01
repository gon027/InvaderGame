#include "Main.h"

#include "FileReader.h"
#include "GameOver.h"

SceneController *controller;

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

	controller = new SceneController();
	controller->scene = new TitleScene(controller);
}

void update() {
	controller->update();;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrefInstance, LPSTR lpCmdLine, int nCmdShow) {
#ifdef FULL_SCREEN
	ChangeWindowMode(FALSE);
#else
	ChangeWindowMode(TRUE);
#endif // FULL_SCREEN

	SetWindowSizeChangeEnableFlag(FALSE, FALSE);
	SetGraphMode(Window::WIDTH, Window::HEIGHT, 32);
	//SetWindowSize(Window::WIDTH, Window::HEIGHT);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK); 

	init();

	while (isProcess()) {
		update();
	}

	delete controller;

	DxLib_End();
	return 0;
}