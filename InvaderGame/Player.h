#ifndef PLAYER_H
#define PLAYER_H

#include "Actor.h"
#include "Bullet.h"

class Player : public Actor {
public:
	Player();
	~Player();

	void setup() override;
	void update() override;
	void init() override;
	void draw(int _x, int _y);
	void clear();

private:
	void draw() override;
	void move() override;

public:
	Bullet bullet;
};

#endif // !PLAYER_H
