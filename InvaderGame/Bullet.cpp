#include "Bullet.h"

#include "DxLib.h"
#include "Player.h"

Bullet::Bullet(){
	setup();
}

Bullet::~Bullet(){

}

void Bullet::setup(){
	LoadBulletImage("image/bullet.png");
}

void Bullet::create(int _x, int _y){
	this->x = _x;
	this->y = _y;
}

void Bullet::draw(){
	DrawImage(x, y);
}

void Bullet::move(){
	y -= speed;
}

bool Bullet::isCollision(Actor & actor){
	if (x <= actor.x + actor.width
		&& x + width >= actor.x
		&& y <= actor.y + actor.height
		&& y + height >= actor.y + actor.height) {
		return true;
	}
	return false;
}

bool Bullet::isBCollision(const Bullet & bullet){
	if (x <= bullet.x + bullet.width
		&& x + width >= bullet.x
		&& y <= bullet.y + bullet.height
		&& y + height >= bullet.y + bullet.height) {
		return true;
	}

	return false;
}

void Bullet::LoadBulletImage(const char* path) {
	//printfDx("Bullet::LoadBulletImage\n");
	this->img = LoadGraph(path);
	if (img == -1) {
		printfDx("LOADIMAGE_ERROR\n");
	}
}

void Bullet::DrawImage(int x, int y) {
	//printfDx("Bullet::DrawImage\n");
	int error;
	error = DrawGraph(x, y, img, TRUE);
	if (error != 0) {
		printfDx("DRAWIMAGE_ERROR\n");
	}
}
