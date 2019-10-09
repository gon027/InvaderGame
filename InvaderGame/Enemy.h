#pragma once

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

public:
	Bullet bullet;

	int count;
};