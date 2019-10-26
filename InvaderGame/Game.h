#ifndef GAME_H
#define GAME_H

#include "Fps.h"
#include "Player.h"
#include "Enemy.h"
#include "UFO.h"
#include "Enemys.h"
#include "BaseScene.h"
#include "Block.h"
#include "Wall.h"
#include "Alien.h"

class Game : public BaseScene{
public:
	Game();
	~Game();

	void start() override;
	void update() override;

public:
	Fps fps;
	Player player;
	Enemy enemy;
	Enemys enemys;
	UFO ufo;
	Block block;
	WALL wall;
	Alien alien;

	/*WALL wall2;
	WALL wall3;
	WALL wall4;*/

	int count = 0;

	bool flag = false;
	int timer = 0;
};

#endif // !GAME_H
