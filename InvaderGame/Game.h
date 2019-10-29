#ifndef GAME_H
#define GAME_H

#include "Fps.h"
#include "Player.h"
#include "Alien.h"
#include "UFO.h"
#include "Wall.h"
#include "BaseScene.h"

class Game : public BaseScene{
public:
	Game();
	~Game();

	void setup() override;		//最初に1回だけ呼ばれる
	void init();				//敵が倒されると呼ばれる
	void update() override;

	void playerLoop();
	void enemyLoop();
	void ufoLoop();
	void wallLoop();

public:
	Fps fps;
	Player player;
	Alien alien;
	UFO ufo;
	WALL wall1;
	WALL wall2;
	WALL wall3;
	WALL wall4;

	bool isRunning;
	
	int count = 0;
	bool flag = false;
	int timer = 0;
	int score;			//スコア
	int hiScore;		//ハイスコア
	int allEnemyCount;
	int enemyOffset;
	int hitPoint;
};

#endif // !GAME_H
