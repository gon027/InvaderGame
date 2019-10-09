#pragma once

#include "Actor.h"
#include "Bullet.h"

class Player : public Actor {
public:
	Player();
	~Player();

	void setup() override;
	void update() override;
	void init() override;

private:
	void draw() override;
	void move() override;
	void shot() override;

public:
	Bullet bullet;
};