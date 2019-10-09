#include "Player.h"

#include "DxLib.h"
#include "Define.h"
#include "Bullet.h"
#include "Enemy.h"

Player::Player(){
	init();
}

Player::~Player(){

}

void Player::setup() {
	LoadActorImage("player.png");
	
	bullet.setup();
}

void Player::update(){
	draw();
	move();
}

void Player::init(){
	this->x = 320 - 25;
	this->y = 330;
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

	if (y <= 0) {
		y = 0;
	}

	if (y + height >= Window::HEIGHT) {
		y = Window::HEIGHT - height;
	}
}

void Player::shot() {
	/*if (key[KEY_INPUT_SPACE] >= 1) {
		if (bullet.flag == false) {
			bullet.flag = true;
			bullet.create(this->x + width / 2, this->y);
		}
	}

	if (bullet.flag == true) {
		bullet.draw();
		bullet.move();
		if (bullet.y <= 0) {
			bullet.flag = false;
		}
	}*/
}