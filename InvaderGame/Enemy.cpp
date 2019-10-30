#include "Enemy.h"

#include "DxLib.h"
#include "Define.h"
#include "AudioManager.h"

Enemy::Enemy(){

}

Enemy::~Enemy(){

}

void Enemy::setup(){
	LoadActorImage("image/enemy_test.png");
	//LoadEnemyImage("image/enemy_test3.png");
}

void Enemy::update(){

}

void Enemy::init(){
	TIMEUP = 30;
	this->xspeed = 6;
	this->yspeed = 16;
	this->life = true;
	this->shotflag = false;
	intervar = 0;
	index = 0;
}

void Enemy::init(int _x, int _y){
	x = _x;
	y = _y;
	init();
}

void Enemy::draw(){
	DrawImage(this->x, this->y);
	//DrawImage2(this->x, this->y);
	bullet.draw();
}

void Enemy::move(){
	intervar = (intervar + 1) % TIMEUP;
	if (intervar == TIMEUP - 1) {
		index = (index + 1) % 6;
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
		bullet.init(this->x + width / 2, this->y + height * 2, 5, GetColor(255, 255, 0));
		
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
		printfDx("dfdsfads\n");
		return true;
	}

	return false;
}

void Enemy::speedUp(int _val){
	TIMEUP = _val;
}

void Enemy::LoadEnemyImage(const char* path) {
	int error;
	//error = LoadDivGraph(path, 2, 2, 1, 32, 32, imgbuf);
	error = LoadDivGraph(path, 6, 2, 3, 32, 32, imgbuf);
	if (error != 0) {
		printfDx("Eenmy::LoadActorImage_ERROR\n");
	}
}

void Enemy::DrawImage2(int x, int y) {
	//printfDx("ACtor::DrawImage\n");
	int error;
	error = DrawGraph(x, y, imgbuf[index], TRUE);
	if (error != 0) {
		printfDx("Enemy::DrawImage_ERROR\n");
	}
}