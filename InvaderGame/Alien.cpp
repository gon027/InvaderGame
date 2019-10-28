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
	draw();
}

void Alien::init(int _x, int _y) {
	x = _x;
	y = _y;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			alien[i][j].init(x + j * 50, y + i * 50);
		}
	}
}

void Alien::draw(){
	
}

void Alien::move(){
	// �ړ�����
	for (int i = 0; i < Alien::h; i++) {
		for (int j = 0; j < Alien::w; j++) {
			//�G�̃��C�t���Ȃ��ꍇ
			if (alien[i][j].life == false) continue;

			alien[i][j].update();
		}
	}
}

void Alien::ableBullet(){
	int flag = GetRand(1);

	//�z��̈�ԊO���̃G�C���A���������e��łĂ�悤�ɂ���
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (alien[i][j].life == false) continue;

			int index = i + 1;
			if (index >= h || alien[index][j].life == false){
				alien[i][j].shotflag = true;
			}
			if (alien[index][j].life == true) {
				alien[i][j].shotflag = false;
			}
		}
	}
}
