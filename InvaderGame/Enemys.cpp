#include "Enemys.h"

#include "DxLib.h"
#include "Define.h"

Enemys::Enemys(){
	
}

Enemys::~Enemys(){

}

//他クラスのコンストラクタで呼び出す
void Enemys::setup(){
	init();

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			enemys[i][j].setup();
			enemys[i][j].init(x + j * 50, y + i * 50);
		}
	}
}

void Enemys::update(){
	draw();
}

void Enemys::init() {
	x = Window::WALL_L;
	y = 50;
}

void Enemys::draw(){
	
}

void Enemys::shotFlag(){
	//配列の一番外側のエイリアンだけが弾を打てるようにする
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			int index = i + 1;
			//printfDx("aaaa\n");
			if (index >= h || enemys[index][j].life == false) {
				enemys[i][j].shotflag = true;
			}
			if (enemys[index][j].life == true) {
				enemys[i][j].shotflag = false;
			}
		}
	}
}
