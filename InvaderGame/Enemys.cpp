#include "Enemys.h"

#include "DxLib.h"
#include "Define.h"

Enemys::Enemys(){
	init();
}

Enemys::~Enemys(){

}

void Enemys::setup(){
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			enemys[i][j].setup();
			//‰ŠúÀ•W‚ðÝ’è
			enemys[i][j].paint(x + j * 50, y + i * 50);
		}
	}
}

void Enemys::update(){
	draw();
}

void Enemys::init() {
	x = 50;
	y = 50;
}

void Enemys::draw(){
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (enemys[i][j].life) {
				enemys[i][j].draw();
				enemys[i][j].move();

				/*
				if (enemys[i][j].bullet.flag == false) {
					enemys[i][j].bullet.flag = true;
					enemys[i][j].bullet.create(enemys[i][j].x, enemys[i][j].y);
				}

				if (enemys[i][j].bullet.flag) {
					enemys[i][j].bullet.draw();
					enemys[i][j].bullet.y += 10;

					//‰æ–ÊŠOˆ—
					if (enemys[i][j].bullet.y >= Window::HEIGHT) {
						enemys[i][j].bullet.flag = false;
						enemys[i][j].count = 0;
					}
				}
				*/
			}
		}
	}
}
