#include "Enemy.h"

#include "Define.h"

Enemy::Enemy(){
	//init();
	setup();
}

Enemy::~Enemy(){

}

void Enemy::setup(){
	//printfDx("Enemy::start\n");
	LoadActorImage("image/enemy.png");

	init();

	bullet.setup();
}

void Enemy::update(){
	//printfDx("Enemy::update\n");
	//count++;
	move();
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
	DrawFormatString(0, 32, GetColor(0, 0, 0), "%d", interval);

	if (interval == 30) {
		x -= xspeed;
		interval = 0;
	}

	//x���W�̉�ʊO����
	if (x <= Window::WALL_L || x + width >= Window::WALL_R - width) {
		//xspeed = -xspeed;
		turnflag = true;
	}

	/*if (turnflag) {
		printfDx("TRUE\n");
		xspeed = -xspeed;
		//turnflag = false;
	}*/

	
	//y���W�̉�ʊO����
	if (y <= 0) {
		life = false;
	}

	if (y + height >= Window::HEIGHT) {
		life = false;
	}
}

void Enemy::shot(){
	//printfDx("Enemy::shot\n");
	count++;
	/*if (count == 60) {
		if (bullet.flag == false) {
			//bullet.flag = true;
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
	}*/
}