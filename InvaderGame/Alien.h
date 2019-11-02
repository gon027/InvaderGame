#ifndef ENEMYS_H
#define ENEMYS_H

#include <vector>
#include "Enemy.h"
#include "Bullet.h"
using std::vector;

class Alien {
private:
	struct Point {
		Point(int _x, int _y) {
			x = _x;
			y = _y;
		}

		int x;
		int y;
	};

public:
	Alien() = default;
	~Alien() = default;

	static const int w = 11;
	static const int h = 5;

	Enemy alien[h][w];

	void setup();
	void update();
	void init(int _x, int _y);
	void draw();
	void move();
	void shot();
	void clear();

	void alienCoundDown();
	int getAlienCount();
	void resetAlienCount();

	void speedUp(int _val);
	void chengeSpeed();

private:
	vector<Point> enemyPoint;		//’e‚ð‘Å‚Â’Š‘I‚Ì‚½‚ß‚Ì”z—ñ

	int x;
	int y;
	int allAlienCount;
	bool turnFlag;
};

#endif // !ENEMYS_H