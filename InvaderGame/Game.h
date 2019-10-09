#pragma once

#include "Fps.h"
#include "Player.h"
#include "Enemy.h"
#include "Enemys.h"

class Game {
public:
	Game();
	~Game();

	void setup();
	void update();

private:
	Fps fps;
	Player player;
	Enemy enemy;
	//Enemys enemys;

	int count = 0;
};
