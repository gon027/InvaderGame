#pragma once

#include "Actor.h"

class Player;

class Bullet{
public:
	Bullet();
	~Bullet();

	void setup();
	void create(int _x, int _y);
	void draw();
	void move();

	bool isCollision(Actor& actor);
	bool isBCollision(const Bullet& bullet);

	void LoadBulletImage(const char* path);
	void DrawImage(int x, int y);

public:
	int img;	//‰æ‘œƒnƒ“ƒhƒ‹
	int x;
	int y;
	int width = 50;
	int height = 50;
	int speed = 15;
	bool flag;
};