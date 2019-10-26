#include "Block.h"

#include "DxLib.h"

Block::Block(){
	
}

Block::~Block(){
	
}

void Block::init(int _x, int _y){
	x = _x;
	y = _y;
	count = 0;
	life = true;
}

void Block::load(){
	int error;
	error = LoadDivGraph("image/block16.png", 4, 4, 1, width, height, img);
	if (error != 0) {
		printfDx("Block::LOADIMAHGE_ERROR");
	}
}

void Block::update(){
	if (life) {
		draw();
	}
}

void Block::draw(){
	int error;
	error = DrawGraph(x, y, img[count], TRUE);
	if (error == -1) {
		printfDx("Block::DRAW_ERROR\n");
	}
}

void Block::addCount(int _value){
	count = count + _value;
	if (count >= 4) {
		count = 0;
		life = false;
	}
}

bool Block::collision(int _x, int _y, int _width, int _height){
	if (this->x <= _x + _width
		&& this->x + this->width >= _x
		&& this->y <= _y + _height
		&& this->y + this->height >= _y) {
		return true;
	}
	return false;
}

bool Block::getLife(){
	return this->life;
}

void Block::zeroLife(){
	life = false;
}

Block & Block::operator++(int _count){
	addCount(1);
	return *this;
}
