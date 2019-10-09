#pragma once

#include "DxLib.h"

class Bullet;
class Player;
class Enemy;

class Actor {
public:
	Actor() {};
	virtual ~Actor() {};

protected:
	virtual void setup()  = 0;		//��ɉ摜���������ɓǂݍ��ފ֐��Ȃ�
	virtual void update() = 0;		//�X�V�֐�

	virtual void init() = 0;
	virtual void draw() = 0;
	virtual void move() = 0;
	virtual void shot() {};

public:
	bool isActorCollision(Actor& enemy);		//Actor���m�̓����蔻��
	bool isBulletCollision(Bullet& bullet);		//Bullet�̓����蔻��

	void LoadActorImage(const char* path);		//�摜�ǂݍ���
	void DrawImage(int x, int y);				//�摜�`��
	
public:
	int img;		//�摜�n���h��
	int x;
	int y;
	int width;
	int height;
	int xspeed;
	int yspeed;
	bool life;
};
