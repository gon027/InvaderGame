#include "Alien.h"

#include "DxLib.h"
#include "Define.h"
#include "AudioManager.h"

Alien::Alien(){
	
}

Alien::~Alien(){

}

//他クラスのコンストラクタで呼び出す
void Alien::setup(){
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			alien[i][j].setup();
			alien[i][j].xMoveTimer = 100 - 20 * i;
		}
	}
}

void Alien::update(){

}

void Alien::init(int _x, int _y) {
	x = _x;
	y = _y;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			alien[i][j].init(x + j * 48, y + i * 48);
		}
	}

	allAlienCount = w * h;
	turnFlag = false;
}

void Alien::draw(){
	for (int i = 0; i < Alien::h; i++) {
		for (int j = 0; j < Alien::w; j++) {
			//敵のライフがない場合
			if (alien[i][j].life == false) continue;
			alien[i][j].draw();
		}
	}
}

int co = 0;

void Alien::move(){
	// 移動処理
	for (int i = 0; i < Alien::h; i++) {
		//if (turnFlag == true)  break;
		for (int j = 0; j < Alien::w; j++) {
			//敵のライフがない場合
			if (alien[i][j].life == false) continue;

			//壁の判定
			alien[i][j].move();		//移動
			//alien[i][j].intervar = 0;
			//alien[i][j].shot();	//弾を打つ
				
			if (alien[i][j].wallJudge()) {
				turnFlag = true;;
			}
		}
	}

	//壁にあたったときの反転処理
	if (turnFlag == true) {
		for (int y = Alien::h - 1; y >= 0; --y) {
			for (int x = 0; x < Alien::w; ++x) {
				//敵のライフがない場合
				if (alien[y][x].life == false) continue;
				
				alien[y][x].invxspeed();
				alien[y][x].down();
			}
		}
		turnFlag = false;
	}
}

void Alien::alienCoundDown(){
	allAlienCount -= 1;
}

int Alien::getAlienCount(){
	return allAlienCount;
}

void Alien::resetAlienCount(){
	allAlienCount = w * h;
}

void Alien::ableBullet(){
	int flag = GetRand(1);
	int fcount = 0;

	//配列の一番外側のエイリアンだけが弾を打てるようにする
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (alien[i][j].life == false) continue;

			int index = i + 1;
			if (index >= h){
				if (alien[i][j].ableShotFlag()) {
					alien[i][j].shotflag = true;
				}
			}
			if (alien[index][j].life == true) {
				alien[i][j].shotflag = false;
			}
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (alien[i][j].shotflag == false) continue;

			if (alien[i][j].ableShotFlag() == 0 && fcount == 0) {
				alien[i][j].shotflag = false;
				fcount++;
				return;
			}
		}
	}
}
