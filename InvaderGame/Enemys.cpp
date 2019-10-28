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
	y = 200;
}

void Enemys::draw(){
	
}

void Enemys::move(){

	// 移動処理
	for (int i = 0; i < Enemys::h; i++) {
		for (int j = 0; j < Enemys::w; j++) {
			//敵のライフがない場合
			if (enemys[i][j].life == false) continue;

			enemys[i][j].update();
		}
	}
}

void Enemys::ableBullet(){
	int flag = GetRand(1);

	//配列の一番外側のエイリアンだけが弾を打てるようにする
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (enemys[i][j].life == false) continue;

			int index = i + 1;
			if (index >= h || enemys[index][j].life == false){
				enemys[i][j].shotflag = true;
			}
			if (enemys[index][j].life == true) {
				enemys[i][j].shotflag = false;
			}
		}
	}
}
