#ifndef ENEMYS_H
#define ENEMYS_H

#include "Enemy.h"

class Alien {
public:
	Alien();
	~Alien();

	void setup();
	void update();

	void init(int _x, int _y);
	void draw();

	void move();

	void ableBullet();

public:
	static const int w = 3;
	static const int h = 2;

	Enemy alien[h][w];

	int interval = 0;

private:
	int x;
	int y;
};

#endif // !ENEMYS_H