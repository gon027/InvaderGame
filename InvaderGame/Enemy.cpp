#include "Enemy.h"

#include "DxLib.h"
#include "Define.h"

Enemy::Enemy(){
	//setup();
}

Enemy::~Enemy(){

}

void Enemy::setup(){
	LoadActorImage("image/enemy_test.png");

	init();
}

void Enemy::update(){
	draw();
	move();
	if (shotflag) {
		shot();
	}
}

void Enemy::init(){
	//printfDx("Enemy::init\n");
	this->xspeed = 10;
	this->yspeed = 10;
	this->life = true;
	this->turnflag = false;
	this->count = 0;
	this->shotflag = false;
}

void Enemy::init(int _x, int _y){
	x = _x;
	y = _y;
}

void Enemy::draw(){
	//printfDx("Enemy::draw\n");
	DrawImage(this->x, this->y);
}

void Enemy::move(){
	//printfDx("Enemy::move\n");
	interval++;

	if (interval == 30) {
		x += xspeed;
		interval = 0;
	}

	//x座標の画面外判定
	if (x <= Window::WALL_L || x + width >= Window::WALL_R - width) {
		//xspeed = -xspeed;
		turnflag = true;
	}

	/*if (turnflag) {
		printfDx("TRUE\n");
		xspeed = -xspeed;
		//turnflag = false;
	}*/

	
	//y座標の画面外判定
	if (y <= 0) {
		life = false;
	}

	if (y + height >= Window::HEIGHT) {
		life = false;
	}
}

void Enemy::shot(){
	if (bullet.life == false) {
		bullet.init(this->x + width / 2, this->y + height, 10, GetColor(255, 255, 0));
	}

	if (bullet.life) {
		bullet.draw();
	}
}