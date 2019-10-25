#include "Wall.h"

WALL::WALL(){
	load();
}

WALL::~WALL(){

}

void WALL::init(int _x, int _y) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			wall[i][j].init(_x + j * 32, _y + i * 32);
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

WALL & WALL::operator+=(int count)

{
	return *this;
}
