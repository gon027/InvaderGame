#include "Bullet.h"

#include "DxLib.h"
#include "Define.h"
#include "Player.h"

Bullet::Bullet(){
	width = 4;
	height = 20;
}

Bullet::~Bullet(){

}

void Bullet::setup(){

}

void Bullet::init(int _x, int _y, int _speed, unsigned int _color){
	this->x = _x;
	this->y = _y;
	this->speed = _speed;
	color = _color;
	this->life = true;
}

void Bullet::draw(){
	DrawLine(x, y, x, y + height, color, width);
	move();
}

void Bullet::move(){
	y += speed; 
	if (y <= 0 || y >= Window::YOUT - height) {
		life = false;
	}
}

bool Bullet::isCollision(Actor & actor){
	if (x <= actor.x + actor.width
		&& x + width >= actor.x
		&& y <= actor.y + actor.height
		&& y + height >= actor.y + actor.height) 
	{
		return true;
	}
	return false;
}

bool Bullet::isBCollision(const Bullet & bullet){
	if (x <= bullet.x + bullet.width
		&& x + width >= bullet.x
		&& y <= bullet.y + bullet.height
		&& y + height >= bullet.y + bullet.height)
	{
		return true;
	}
	return false;
}

bool Bullet::isLife(){
	return this->life;
}

bool Bullet::randBullet(){
	int flag = GetRand(1);

	if(flag == 1){
		return true;
	}

	return false;
}

