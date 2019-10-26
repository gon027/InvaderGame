#ifndef ALIEN_H
#define ALIEN_H

#include "Enemy.h"

class Alien {
public:
	Alien();
	~Alien();

	void init(int _x, int _y);
	void load();
	void draw();
	void update();

private:
	static const int H = 5;
	static const int W = 11;

	Enemy alien[H][W];

	int x;
	int y;
};

#endif // !ALIEN_H

