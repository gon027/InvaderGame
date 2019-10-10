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
	void shot() override;

	void paint(int _x, int _y);

public:
	Bullet bullet;

	int count;
};

#endif // !ENEMY_H
