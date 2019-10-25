#include "Enemys.h"

#include "DxLib.h"
#include "Define.h"

Enemys::Enemys(){
	//init();
	//setup();
}

Enemys::~Enemys(){

}

//�R���X�g���N�^�ŌĂяo��
void Enemys::setup(){
	init();

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			enemys[i][j].setup();
			//�������W��ݒ�
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

void Enemys::shotFlag(){
	//�z��̈�ԊO���̃G�C���A���������e��łĂ�悤�ɂ���
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
