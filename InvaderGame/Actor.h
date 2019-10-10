#ifndef ACTOR_H
#define ACTOR_H

#include "DxLib.h"

class Bullet;

class Actor {
public:
	Actor() {};
	virtual ~Actor() {};

protected:
	virtual void setup()  = 0;		//主に画像をメモリに読み込む関数など
	virtual void update() = 0;		//更新関数

	virtual void init() = 0;
	virtual void draw() = 0;
	virtual void move() = 0;
	virtual void shot() {};
	void LoadActorImage(const char* path);		//画像読み込み
	void DrawImage(int x, int y);				//画像描画

public:
	bool isActorCollision(Actor& enemy);		//Actor同士の当たり判定
	bool isBulletCollision(Bullet& bullet);		//Bulletの当たり判定

public:
	int img;		//画像ハンドル
	int x;
	int y;
	int width;
	int height;
	int xspeed;
	int yspeed;
	bool life;
};

#endif // !ACTOR_H