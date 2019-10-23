#ifndef ENEMY_H
#define ENEMY_H

#include "Actor.h"
#include "Bullet.h"

class Enemy : public Actor{
public:
	Enemy();
	~Enemy();

	void setup() override;
	void update() override;

public:
	void draw() override;
	void init() override;
	void move() override;
	void shot();

	void paint(int _x, int _y);

public:
	Bullet bullet;

	int count;
	int interval = 0;
	bool turnflag;
	bool shotflag;
};

#endif // !ENEMY_H
