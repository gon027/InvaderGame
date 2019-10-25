#include "Player.h"

#include "DxLib.h"
#include "Define.h"
#include "Bullet.h"
#include "Enemy.h"

Player::Player(){

}

Player::~Player(){

}

void Player::setup() {
	LoadActorImage("image/player.png");

	init();
	
	bullet.setup();
}

void Player::update(){
	draw();
	move();
}

void Player::init(){
	this->x = (Window::WIDTH / 2) - (width / 2);
	this->y = 362;
	this->xspeed = 5;
	this->life = true;
}

void Player::draw(){
	DrawImage(this->x, this->y);
}

void Player::move() {
	if (x <= 0) {
		x = 0;
	}

	if (x + width >= Window::WIDTH) {
		x = Window::WIDTH - width;
	}
}
