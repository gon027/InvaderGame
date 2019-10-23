#ifndef GAME_H
#define GAME_H

#include "Fps.h"
#include "Player.h"
#include "Enemy.h"
#include "Enemys.h"
#include "BaseScene.h"

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

	int count = 0;

	bool flag = false;
	int timer = 0;
};

#endif // !GAME_H
