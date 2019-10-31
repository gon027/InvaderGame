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
	void init(int _x, int _y, int _index);
	void move() override;
	void shot();
	void down();
	void invxspeed();
	bool wallJudge();
	void speedUp(int);

public:
	Bullet bullet;

	int TIMEUP;		    //移動するタイミングの最大値
	bool shotflag;      //敵が弾を打つか打たないかのフラグ
	int intervar;
	int xMoveTimer;
	int yMoveTimer;
	int index;
};

#endif // !ENEMY_H
