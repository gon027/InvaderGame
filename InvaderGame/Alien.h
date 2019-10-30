#ifndef ENEMYS_H
#define ENEMYS_H

#include "Enemy.h"
#include "Bullet.h"

class Alien {
public:
	Alien();
	~Alien();

	static const int w = 11;
	static const int h = 5;

	Enemy alien[h][w];

	void setup();
	void update();
	void init(int _x, int _y);
	void draw();
	void move();
	void shot();
	void alienCoundDown();
	int getAlienCount();
	void resetAlienCount();
	void speedUp(int _val);


private:
	int x;
	int y;
	int allAlienCount;
	bool turnFlag;
	bool rightTurn;
	bool stop;
	int interval = 0;
};

#endif // !ENEMYS_H