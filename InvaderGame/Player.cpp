#include "Player.h"

#include "DxLib.h"
#include "Define.h"
#include "Bullet.h"
#include "Enemy.h"
#include "KeyManager.h"
#include "AudioManager.h"

Player::Player(){

}

Player::~Player(){

}

void Player::setup() {
	LoadActorImage("image/player.png");
}

void Player::update(){
	inputKey();
	draw();
	move();
}

void Player::init(){
#ifdef FULL_SCREEN
	this->x = Window::LEFT + (Window::MIDDLE / 2) - (width / 2);
	this->y = 750;

	//printfDx("%d\n", x);
#else
	this->x = (Window::WIDTH / 2) - (width / 2);
	this->y = 362;

#endif // !

	this->xspeed = 5;
	this->life = true;
}

void Player::draw(int _x, int _y){
	DrawImage(_x, _y);
}

void Player::clear(){
	life = false;
}

void Player::draw(){
	DrawImage(this->x, this->y);
}

void Player::move() {
	if (key[KEY_INPUT_D] >= 1) {
		x -= xspeed;
	}

	if (key[KEY_INPUT_F] >= 1) {
		x += xspeed;
	}

	if (key[KEY_INPUT_J] >= 1) {
		if (bullet.isLife() == false) {
			bullet.init(x + (width / 2), y - (bullet.height * 2), -7, GetColor(255, 0, 0));
			//singleton<AudioManager>::getInstance().play(0);
		}
	}

	bullet.draw();

#ifdef FULL_SCREEN
	if (x <= Window::WALL_L) {
		x = Window::WALL_L;
	}

	if (x + width >= Window::WALL_R) {
		x = Window::WALL_R - width;
	}
#else
	if (x <= 0) {
		x = 0;
	}

	if (x + width >= Window::WIDTH) {
		x = Window::WIDTH - width;
	}
#endif // FULL_SCREEN
}
