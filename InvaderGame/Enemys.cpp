#include "Enemys.h"

#include "DxLib.h"

Enemys::Enemys(){

}

Enemys::~Enemys(){
	//init();
}

void Enemys::setup(){
	init();
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			enemys[i][j].setup();
		}
	}
}

void Enemys::update(){
	draw();
}

void Enemys::init() {
	x = 100;
	y = 100;
}

void Enemys::draw(){
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			DrawBox(enemys[i][j].x, enemys[i][j].y, enemys[i][j].x + enemys[i][j].width, enemys[i][j].y + enemys[i][j].height, GetColor(255, 127, 127), 1);
			if (enemys[i][j].life) {
				enemys[i][j].DrawImage(x + j * 50, y + i * 50);
				//enemys[i][j].move();
			}
		}
	}
}
