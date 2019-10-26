#ifndef DEFINE_H
#define DEFINE_H

//#define FULL_SCREEN

#define OR ||
#define AND &&

namespace Window {
#ifdef FULL_SCREEN
	//��ʃT�C�Y
	static const int WIDTH = 1440;
	static const int HEIGHT = 900;

	//��ʂ̑傫��
	static const int LEFT = 400;
	static const int MIDDLE = 640;
	static const int RIGHT = 400;
	static const int EDGE = LEFT + MIDDLE + RIGHT;

	//Actor�̈ړ��͈�
	static const int WALL_L = LEFT;
	static const int WALL_R = LEFT + MIDDLE;
#else
	//��ʃT�C�Y
	constexpr int WIDTH = 640;
	constexpr int HEIGHT = 480;

	//��ʂ̑傫��
	static const int LEFT = 0;
	static const int MIDDLE = 0;
	static const int RIGHT = 0;
	static const int EDGE = LEFT + MIDDLE + RIGHT;

	//Actor�̈ړ��͈�
	static const int WALL_L = LEFT;
	static const int WALL_R = LEFT + MIDDLE;
#endif // FULL_SCREEN
}

enum Status {
	Title = 0,
	GameScene,
};

#endif // !DEFINE_H