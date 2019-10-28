#include "Enemys.h"

#include "DxLib.h"
#include "Define.h"

Enemys::Enemys(){
	
}

Enemys::~Enemys(){

}

//���N���X�̃R���X�g���N�^�ŌĂяo��
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

	// �ړ�����
	for (int i = 0; i < Enemys::h; i++) {
		for (int j = 0; j < Enemys::w; j++) {
			//�G�̃��C�t���Ȃ��ꍇ
			if (enemys[i][j].life == false) continue;

			enemys[i][j].update();
		}
	}
}

void Enemys::ableBullet(){
	int flag = GetRand(1);

	//�z��̈�ԊO���̃G�C���A���������e��łĂ�悤�ɂ���
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
