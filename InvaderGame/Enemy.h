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
	void init(int _x, int _y) override;
	void move() override;
	void shot();
	bool ableShotFlag();
	void down();
	void invxspeed();
	bool wallJudge();

public:
	Bullet bullet;

	int TIMEUP;

	int count;
	int count2;
	int interval;
	bool turnflag;
	bool shotflag;
	bool ableshot;
};

#endif // !ENEMY_H
