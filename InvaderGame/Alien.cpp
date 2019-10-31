#include "Alien.h"

#include "DxLib.h"
#include "Define.h"
#include "AudioManager.h"

//���N���X�̃R���X�g���N�^�ŌĂяo��
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
			if (i == 0) {
				alien[i][j].init(x + j * 48, y + i * 48, 0);
			}
			else if (i == 1 || i == 2) {
				alien[i][j].init(x + j * 48, y + i * 48, 1);
			}
			else if (i == 3 || i == 4) {
				alien[i][j].init(x + j * 48, y + i * 48, 2);
			}
		}
	}

	allAlienCount = w * h;
	turnFlag = false;
}

void Alien::draw(){
	for (int i = 0; i < Alien::h; i++) {
		for (int j = 0; j < Alien::w; j++) {
			//�G�̃��C�t���Ȃ��ꍇ
			if (alien[i][j].life == false) continue;
			alien[i][j].draw();
		}
	}
}

void Alien::move(){
	chengeSpeed();

	// �ړ�����
	for (int i = 0; i < Alien::h; i++) {
		//if (turnFlag == true)  break;
		for (int j = 0; j < Alien::w; j++) {
			//�G�̃��C�t���Ȃ��ꍇ
			if (alien[i][j].life == false) continue;

			//�ǂ̔���
			alien[i][j].move();		//�ړ�
				
			if (alien[i][j].wallJudge()) {
				turnFlag = true;;
			}
		}
	}

	//�ǂɂ��������Ƃ��̔��]����
	if (turnFlag == true) {
		for (int y = Alien::h - 1; y >= 0; --y) {
			for (int x = 0; x < Alien::w; ++x) {
				//�G�̃��C�t���Ȃ��ꍇ
				if (alien[y][x].life == false) continue;
				
				alien[y][x].invxspeed();
				alien[y][x].down();
			}
		}
		turnFlag = false;
	}

	//printfDx("allEnemyCount = %d\n", allAlienCount);
}

int bulletInterval = 0;
void Alien::shot() {
	enemyPoint.clear();
	bulletInterval++;

	if (bulletInterval == 20) {
		//1��ɂ���G����e�𔭎˂���G��T��
		for (int x = 0; x < w; x++) {
			//�O���̓G�������Ă��Ă��Ashotflga��false�̏ꍇ�̎�vector�ɒǉ�
			if (alien[h - 1][x].life) {
				enemyPoint.push_back(Point(x, h - 1));
			}
			else {
				//�O���̓G������ł���Ƃ��Ashotflag�������Ă���Ƃ�
				//���̓G�������Ă��āAshotflag�������Ă��Ȃ����ǉ�
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

void Alien::clear(){
	enemyPoint.clear();
	for (int i = 0; i < Alien::h; i++) {
		for (int j = 0; j < Alien::w; j++) {
			alien[i][j].bullet.life = false;
			alien[i][j].life = false;
		}
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
	//printfDx("fdsafad\n");
	for (int i = 0; i < Alien::h; i++) {
		for (int j = 0; j < Alien::w; j++) {
			//�G�̃��C�t���Ȃ��ꍇ
			if (alien[i][j].life == false) continue;
			alien[i][j].speedUp(_val);
		}
	}
}

void Alien::chengeSpeed(){
	//�����l
	if (allAlienCount == 45) {
		speedUp(45);
	}
	else if (allAlienCount == 35) {
		speedUp(30);
	}
	else if (allAlienCount == 25) {
		speedUp(25);
	}
	else if (allAlienCount == 21) {
		speedUp(21);
	}
	else if (allAlienCount == 17) {
		speedUp(17);
	}
	else if (allAlienCount == 10) {
		speedUp(10);
	}
	else if (allAlienCount == 9) {
		speedUp(9);
	}
	else if (allAlienCount == 8) {
		speedUp(8);
	}
	else if (allAlienCount == 7) {
		speedUp(7);
	}
	else if (allAlienCount == 6) {
		speedUp(6);
	}
	else if (allAlienCount == 5) {
		speedUp(5);
	}
	else if (allAlienCount == 4) {
		speedUp(4);
	}
	else if (allAlienCount == 3) {
		speedUp(3);
	}
	else if (allAlienCount == 2) {
		speedUp(2);
	}
	else if (allAlienCount == 1) {
		speedUp(1);
	}
}
