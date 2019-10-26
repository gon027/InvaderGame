#ifndef ENEMYS_H
#define ENEMYS_H

#include "Enemy.h"

class Enemys {
public:
	Enemys();
	~Enemys();

	void setup();
	void update();

	void init();
	void draw();

	void ableBullet();

public:
	static const int w = 3;
	static const int h = 4;

	Enemy enemys[h][w];

	int interval = 0;

private:
	int x;
	int y;
};

#endif // !ENEMYS_H