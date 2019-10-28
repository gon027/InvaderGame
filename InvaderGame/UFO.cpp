#include "UFO.h"

#include "DxLib.h"
#include "Define.h"

constexpr int TIME = 100;

UFO::UFO(){
	setup();
}

UFO::~UFO(){

}

void UFO::setup(){
	LoadActorImage("image/ufo.png");
	init();
}

void UFO::update() {
	if (life) {
		draw();
		move();
	}
	else {
		interval++;
		if (interval >= TIME) {
			randPoint();
			life = true;
			interval = 0;
		}
	}
	//printfDx("%d\n", interval);
}

void UFO::init() {
	
	this->life = false;
	this->interval = 0;
}

void UFO::draw() {
	DrawImage(x, y);
}

void UFO::move() {
	x += xspeed;

#ifdef FULL_SCREEN
	if (x >= Window::WALL_R - width || x <= Window::WALL_L) {
		this->life = false;
	}
#else
	if (x >= Window::WIDTH + width || x <= 0 - width) {
		this->life = false;
	}
#endif // FULL_SCREEN
}

void UFO::randPoint(){
	int flag = GetRand(1);

#ifdef FULL_SCREEN
	if (flag == 0) {
		//左から右へ移動するようにする
		this->x = Window::WALL_L;
		this->xspeed = 2;
	}
	else if (flag = 1) {
		//右から左へ移動するようにする
		this->x = Window::WALL_R - width;
		
		this->xspeed = -2;
	}
	this->y = 144;
#else
	if (flag == 0) {
		//右から左へ移動するようにする
		this->x = 0 - width;
		this->xspeed = 2;
}
	else if (flag = 1) {
		//左から右へ移動するようにする
		this->x = Window::WIDTH + width;
		this->xspeed = -2;
	}
	this->y = 75;
#endif // FULL_SCREEN
}