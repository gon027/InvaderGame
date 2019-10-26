#ifndef BULLET_H
#define BULLET_H

#include "Actor.h"

class Player;

class Bullet{
public:
	Bullet();
	~Bullet();

	void setup();
	void init(int _x, int _y, int _speed, unsigned int _color);
	void draw();
	void move();
	bool isLife();
	bool randBullet();

	bool isCollision(Actor& actor);
	bool isBCollision(const Bullet& bullet);

public:
	int x;
	int y;
	int width;
	int height;
	int speed;
	bool life;
	unsigned int color;
};

#endif // !BULLET_H
