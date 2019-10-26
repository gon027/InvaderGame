#include "Alien.h"

#include "DxLib.h"

Alien::Alien(){

}

Alien::~Alien(){

}

void Alien::init(int _x, int _y){
	x = _x;
	y = _y;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			alien[i][j].init(_x + j * 40, _y + i * 40);
		}
	}
}

void Alien::load(){
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			alien[i][j].setup();
		}
	}
}

void Alien::draw(){
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			alien[i][j].draw();
		}
	}
}

void Alien::update(){
	this->draw();

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			alien[i][j].update();
		}
	}
}

