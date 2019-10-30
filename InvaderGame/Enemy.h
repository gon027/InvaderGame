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
	void down();
	void invxspeed();
	bool wallJudge();
	void speedUp(int);

	void LoadEnemyImage(const char* path);      //画像読み込み
	void DrawImage2(int x, int y);               //画像描画

public:
	Bullet bullet;

	//int imgbuf[2];
	int imgbuf[6];
	int TIMEUP;		    //移動するタイミングの最大値
	bool shotflag;      //敵が弾を打つか打たないかのフラグ
	int intervar;
	int xMoveTimer;
	int yMoveTimer;
	int index;
};

#endif // !ENEMY_H
