#include "Enemy.h"

#include "DxLib.h"
#include "Define.h"
#include "AudioManager.h"

Enemy::Enemy(){

}

Enemy::~Enemy(){

}

void Enemy::setup(){
	//LoadActorImage("image/enemy_test.png");
	LoadActorImgBuf("image/enemy_images.png");
}

void Enemy::update(){

}

void Enemy::init(){
	TIMEUP = 50;
	this->xspeed = 6;
	this->yspeed = 16;
	this->life = true;
	this->shotflag = false;
	intervar = 0;
}

void Enemy::init(int _x, int _y, int _index){
	x = _x;
	y = _y;
	index = _index;
	init();
}

void Enemy::draw(){
	//DrawImage(this->x, this->y);
	DrawImageFromImgBuf(x, y, index);
	bullet.draw();
}

void Enemy::move(){
	intervar = (intervar + 1) % TIMEUP;
	if (intervar == TIMEUP - 1) {
		x += xspeed;
		intervar = 0;
	}

	//yç¿ïWÇÃâÊñ äOîªíË
	if (y <= 0) {
		life = false;
	}

	if (y + height >= Window::HEIGHT) {
		life = false;
	}
}

void Enemy::shot(){
	//if (shotflag) {
		bullet.init(this->x + width / 2, this->y + height + 34, 5, GetColor(255, 255, 0));
	//}
}

void Enemy::down(){
	y += yspeed;
}

void Enemy::invxspeed(){
	xspeed = -xspeed;
}

bool Enemy::wallJudge(){
	
	int xx = x + xspeed;

	if (xx <= Window::WALL_L || xx + width >= Window::WALL_R) {
		return true;
	}

	return false;
}

void Enemy::speedUp(int _val){
	TIMEUP = _val;
}
