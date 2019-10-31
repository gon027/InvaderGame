#ifndef GAME_H
#define GAME_H

#include "Fps.h"
#include "Player.h"
#include "Alien.h"
#include "UFO.h"
#include "Wall.h"
#include "BackGround.h"
#include "BaseScene.h"
#include "SceneController.h"

class Game : public BaseScene{
public:
	Game() = default;
	Game(SceneController *_controller);
	~Game() = default;

	void setup() override;		//最初に1回だけ呼ばれる
	void init();				//敵が倒されると呼ばれる
	void update() override;
	void clear();

	void playerUpdate();
	void alienUpdate();
	void ufpUpdate();
	void wallUpdate();

public:
	Fps fps;
	BackGround backGround;
	Player player;
	Alien alien;
	UFO ufo;
	WALL wall1;
	WALL wall2;
	WALL wall3;
	WALL wall4;

	bool isRunning;
	
	int count = 0;
	int timer = 0;
	int score;			//スコア
	int hiScore;		//ハイスコア
	int roundCount;
	int enemyOffset;	//敵が描画される座標
	int hitPoint;		//プレイヤーの残り自機
};

#endif // !GAME_H
