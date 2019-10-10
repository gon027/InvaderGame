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

public:
	static const int w = 3;
	static const int h = 3;

	Enemy enemys[h][w];

private:
	int x;
	int y;
};

#endif // !ENEMYS_H