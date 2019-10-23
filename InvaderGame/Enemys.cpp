#include "Enemys.h"

#include "DxLib.h"
#include "Define.h"

Enemys::Enemys(){
	//init();
	//setup();
}

Enemys::~Enemys(){

}

//コンストラクタで呼び出す
void Enemys::setup(){
	init();

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			enemys[i][j].setup();
			//初期座標を設定
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
	
}
