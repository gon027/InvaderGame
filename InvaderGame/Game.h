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

	void setup() override;		//�ŏ���1�񂾂��Ă΂��
	void init();				//�G���|�����ƌĂ΂��
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
	int score;			//�X�R�A
	int hiScore;		//�n�C�X�R�A
	int roundCount;
	int enemyOffset;	//�G���`�悳�����W
	int hitPoint;		//�v���C���[�̎c�莩�@
};

#endif // !GAME_H
