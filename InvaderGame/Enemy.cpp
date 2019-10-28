#include "Enemy.h"

#include "DxLib.h"
#include "Define.h"

static int timeup = 30;

Enemy::Enemy(){

}

Enemy::~Enemy(){

}

void Enemy::setup(){
	LoadActorImage("image/enemy_test.png");
}

void Enemy::update(){
	if (shotflag && ableShotFlag() == 1) {
		shot();
	}
}

void Enemy::init(){
	TIMEUP = 30;
	this->xspeed = 6;
	this->yspeed = 10;
	this->life = true;
	this->turnflag = false;
	this->count = 0;
	this->interval = 0;
	this->shotflag = false;
	this->ableshot = false;
	count2 = 0;
}

void Enemy::init(int _x, int _y){
	x = _x;
	y = _y;
	init();
}

void Enemy::draw(){
	//printfDx("Enemy::draw\n");
	DrawImage(this->x, this->y);
	bullet.draw();
}

void Enemy::move(){
	//printfDx("Enemy::move\n");
	interval++;

	if (interval == timeup) {
		x += xspeed;
		shot();
		interval = 0;
	}

	//y座標の画面外判定
	if (y <= 0) {
		life = false;
	}

	if (y + height >= Window::HEIGHT) {
		life = false;
	}
}

void Enemy::shot(){
	if (shotflag && ableShotFlag() == 1) {
		if (bullet.life == false) {
			bullet.init(this->x + width / 2, this->y + height * 2, 10, GetColor(255, 255, 0));
		}
	}


	
}

bool Enemy::ableShotFlag(){
	int rand = GetRand(1);

	//エイリアンが弾を打つか打たないか
	if (rand == 1) {
		return true;
	}

	return false;
}

void Enemy::down(){
	y += yspeed;
}

void Enemy::invxspeed(){
	xspeed = -xspeed;
}

bool Enemy::wallJudge(){
	if (x <= Window::WALL_L || x + width >= Window::WALL_R) {
		return true;
	}
	return false;
}
