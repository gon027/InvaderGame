#include "Alien.h"

#include "DxLib.h"
#include "Define.h"

Alien::Alien(){
	
}

Alien::~Alien(){

}

//���N���X�̃R���X�g���N�^�ŌĂяo��
void Alien::setup(){
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			alien[i][j].setup();
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

int co = 0;

void Alien::move(){
	// �ړ�����
	for (int i = 0; i < Alien::h; i++) {
		for (int j = 0; j < Alien::w; j++) {
			//�G�̃��C�t���Ȃ��ꍇ
			if (alien[i][j].life == false) continue;

			alien[i][j].move();		//�ړ�
			//alien[i][j].shot();	//�e��ł�

			//�ǂ̔���
			if (alien[i][j].wallJudge()) {
				leftTurn = true;
			}
		}
	}

	//�ǂɂ��������Ƃ��̔��]����
	if (leftTurn) {
		for (int y = Alien::h - 1; y >= 0; --y) {
			for (int x = 0; x < Alien::w; ++x) {
				//�G�̃��C�t���Ȃ��ꍇ
				if (alien[y][x].life == false) continue;
				
				//alien[y][x].down();

				alien[y][x].invxspeed();
			}
		}
		leftTurn = false;
	}
}

void Alien::ableBullet(){
	int flag = GetRand(1);

	//�z��̈�ԊO���̃G�C���A���������e��łĂ�悤�ɂ���
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

			if (alien[i][j].ableShotFlag() == 0) {
				alien[i][j].shotflag = false;
			}
		}
	}
}
