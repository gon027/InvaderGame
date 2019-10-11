#include "Enemy.h"

#include "Define.h"

Enemy::Enemy(){
	init();
}

Enemy::~Enemy(){

}

void Enemy::setup(){
	//printfDx("Enemy::setup\n");
	LoadActorImage("image/enemy.png");

	bullet.setup();
}

void Enemy::update(){
	//printfDx("Enemy::update\n");
	count++;
	draw();
	move();
}

void Enemy::init(){
	printfDx("Enemy::init\n");
	this->xspeed = 5;
	this->yspeed = 5;
	this->life = true;
	this->count = 0;
}

void Enemy::draw(){
	//printfDx("Enemy::draw\n");
	DrawImage(this->x, this->y);
}

void Enemy::move(){
	//printfDx("Enemy::move\n");
	x += xspeed;

	if (x + width >= Window::WIDTH) {
		xspeed = -xspeed;
	}

	if (x <= 0) {
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
	//printfDx("Enemy::shot\n");
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
			bullet.flag = true;
			count = 0;
		}
	}
}

void Enemy::paint(int _x, int _y){
	x = _x;
	y = _y;
}
