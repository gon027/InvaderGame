#include "Enemy.h"

#include "Define.h"

Enemy::Enemy(){
	init();
}

Enemy::~Enemy(){

}

void Enemy::setup(){
	LoadActorImage("enemy.png");

	bullet.setup();
}

void Enemy::update(){
	if (life) {
		draw();
		move();
		//shot();
	}
}

void Enemy::init(){
	this->x = 100;
	this->y = 100;
	this->xspeed = 5;
	this->yspeed = 5;
	this->life = true;
	this->count = 0;
}

void Enemy::draw(){
	DrawFormatString(0, 48, GetColor(0, 0, 0), "Enemy::x = %d", x);
	DrawFormatString(0, 64, GetColor(0, 0, 0), "Enemy::y = %d", y);
	DrawFormatString(0, 80, GetColor(0, 0, 0), "Enemy::count = %d", count);

	DrawImage(this->x, this->y);
}

void Enemy::move(){
	x += xspeed;

	if (x <= 0) {
		this->x = 0;
	}

	if (x + width >= Window::WIDTH) {
		//x = Window::WIDTH - size;
		xspeed = -xspeed;
	}

	if (x <= 0) {
		//x = 0;
		xspeed = -xspeed;
	}

	if (y <= 0) {
		yspeed = -yspeed;
	}

	if (y + height >= Window::HEIGHT) {
		yspeed = -yspeed;
	}
}

void Enemy::shot(){
	count++;
	if (count == 60) {
		if (bullet.flag == false) {
			bullet.flag = true;
			bullet.create(this->x + width / 2, this->y + height);
		}
	}

	if (bullet.flag) {
		bullet.draw();
		bullet.y += 5;
		if (bullet.y >= Window::HEIGHT) {
			bullet.flag = false;
			count = 0;
		}
	}
}
