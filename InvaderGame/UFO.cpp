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
	this->y = 75;
	this->life = false;
	this->interval = 0;
}

void UFO::draw() {
	DrawImage(x, y);
}

void UFO::move() {
	x += xspeed;

	if (x >=  Window::WIDTH + width) {
		this->life = false;
	}

	if (x <= 0 - width) {
		this->life = false;
	}
}

void UFO::randPoint(){
	int flag = GetRand(1);
	if (flag == 0) {
		//�E���獶�ֈړ�����悤�ɂ���
		this->x = 0 - width;
		this->xspeed = 2;
	}
	else if (flag = 1) {
		//������E�ֈړ�����悤�ɂ���
		this->x = Window::WIDTH + width;
		this->xspeed = -2;
	}
}