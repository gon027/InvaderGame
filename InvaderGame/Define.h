#ifndef DEFINE_H
#define DEFINE_H

//#define FULL_SCREEN

#define OR ||
#define AND &&

namespace Window {
#ifdef FULL_SCREEN
	//��ʃT�C�Y
	constexpr int WIDTH = 1440;
	constexpr int HEIGHT = 900;

	//��ʂ̑傫��
	constexpr int LEFT = 400;
	constexpr int MIDDLE = 640;
	constexpr int RIGHT = 400;
	constexpr int EDGE = LEFT + MIDDLE + RIGHT;

	//Actor�̈ړ��͈�
	constexpr int WALL_L = LEFT;
	constexpr int WALL_R = LEFT + MIDDLE;

	constexpr int YOUT = 800;
#else
	//��ʃT�C�Y
	constexpr int WIDTH = 640;
	constexpr int HEIGHT = 480;

	//��ʂ̑傫��
	constexpr int LEFT = 0;
	constexpr int MIDDLE = WIDTH / 2;
	constexpr int RIGHT = WIDTH;

	//Actor�̈ړ��͈�
	constexpr int WALL_L = LEFT;
	constexpr int WALL_R = LEFT + MIDDLE;

	constexpr int YOUT = HEIGHT;
#endif // FULL_SCREEN
}

enum Status {
	Title = 0,
	GameScene,
};

#endif // !DEFINE_H