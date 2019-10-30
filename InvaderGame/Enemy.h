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

	void LoadEnemyImage(const char* path);      //�摜�ǂݍ���
	void DrawImage2(int x, int y);               //�摜�`��

public:
	Bullet bullet;

	//int imgbuf[2];
	int imgbuf[6];
	int TIMEUP;		    //�ړ�����^�C�~���O�̍ő�l
	bool shotflag;      //�G���e��ł��ł��Ȃ����̃t���O
	int intervar;
	int xMoveTimer;
	int yMoveTimer;
	int index;
};

#endif // !ENEMY_H
