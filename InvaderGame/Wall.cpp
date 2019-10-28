#include "Wall.h"

WALL::WALL(){

}

WALL::~WALL(){

}

void WALL::init(int _x, int _y) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			wall[i][j].init(_x + j * size, _y + i * size);
		}
	}
}

void WALL::load(){
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			wall[i][j].load();
		}
	}
}

void WALL::draw(){
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
 			wall[i][j].draw();
		}
	}
}

void WALL::update(){
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			wall[i][j].update();
		}
	}
}

bool WALL::hitTest(int _x, int _y, int _w, int _h){
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (wall[i][j].getLife() == false) continue;

			if (wall[i][j].collision(_x, _y, _w, _h)) {
				wall[i][j].addCount(1);
				return true;
			}
		}
	}
	return false;
}

void WALL::ehitTest(int _x, int _y, int _w, int _h){
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (wall[i][j].getLife()) {
				if (wall[i][j].collision(_x, _y, _w, _h)) {
					wall[i][j].zeroLife();
				}
			}
		}
	}
}
