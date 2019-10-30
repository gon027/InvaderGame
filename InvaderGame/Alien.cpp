#include "Alien.h"

#include <vector>
#include "DxLib.h"
#include "Define.h"
#include "AudioManager.h"
using std::vector;

class Point {
public:
	Point() = default;

	Point(int _x, int _y) {
		x = _x;
		y = _y;
	}

	~Point() = default;

	int x;
	int y;
};

vector<Point> enemyPoint;		//弾を打つ抽選のための配列

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

void Alien::move(){
	// 移動処理
	for (int i = 0; i < Alien::h; i++) {
		//if (turnFlag == true)  break;
		for (int j = 0; j < Alien::w; j++) {
			//敵のライフがない場合
			if (alien[i][j].life == false) continue;

			//壁の判定
			alien[i][j].move();		//移動
				
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

	printfDx("allEnemyCount = %d\n", allAlienCount);

	if (allAlienCount == 50) {
		speedUp(60);
	}
	else if (allAlienCount == 30) {
		speedUp(40);
	}
	else if (allAlienCount == 20) {
		speedUp(20);
	}
	else if (allAlienCount == 10) {
		speedUp(10);
	}
	else if (allAlienCount == 5) {
		speedUp(5);
	}
	else if (allAlienCount == 1) {
		speedUp(1);
	}
}

int bulletInterval = 0;
void Alien::shot() {
	enemyPoint.clear();
	bulletInterval++;

	if (bulletInterval == 35) {
		//1列にいる敵から弾を発射する敵を探す
		for (int x = 0; x < w; x++) {
			//外側の敵が生きていてかつ、shotflgaがfalseの場合の時vectorに追加
			if (alien[h - 1][x].life) {
				enemyPoint.push_back(Point(x, h - 1));
			}
			else {
				//外側の敵が死んでいるとき、shotflagが立っているとき
				//後ろの敵が生きていて、shotflagが立っていないやつを追加
				//TODO: shotflagが常にfalseになっているので、今は弾を撃てません
				for (int y = h - 1; y >= 0; y--) {
					if (alien[y][x].life) {
						enemyPoint.push_back(Point(x, y));
						break;
					}
				}
			}
		}

		int rand = GetRand(enemyPoint.size() - 1);
		int xIndex = enemyPoint.at(rand).x;
		int yIndex = enemyPoint.at(rand).y;
		alien[yIndex][xIndex].shot();
		//alien[yIndex][xIndex].shotflag = true;

		bulletInterval = 0;
	}
}

void Alien::alienCoundDown() {
	allAlienCount -= 1;
}

int Alien::getAlienCount(){
	return allAlienCount;
}

void Alien::resetAlienCount(){
	allAlienCount = w * h;
}

void Alien::speedUp(int _val){
	printfDx("fdsafad\n");
	for (int i = 0; i < Alien::h; i++) {
		for (int j = 0; j < Alien::w; j++) {
			//敵のライフがない場合
			if (alien[i][j].life == false) continue;
			alien[i][j].speedUp(_val);
		}
	}
}
