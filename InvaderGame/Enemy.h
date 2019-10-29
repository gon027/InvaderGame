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
	void draw() override;
	void init() override;
	void init(int _x, int _y) override;
	void move() override;
	void shot();
	bool ableShotFlag();
	void down();
	void invxspeed();
	bool wallJudge();

public:
	Bullet bullet;

	int TIMEUP;		    //�ړ�����^�C�~���O�̍ő�l
	bool shotflag;      //�G���e��ł��ł��Ȃ����̃t���O
	int intervar;
	int xMoveTimer;
	int yMoveTimer;
};

#endif // !ENEMY_H
