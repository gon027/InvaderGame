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

	int TIMEUP;		    //移動するタイミングの最大値
	bool shotflag;      //敵が弾を打つか打たないかのフラグ
	int intervar;
	int xMoveTimer;
	int yMoveTimer;
};

#endif // !ENEMY_H
