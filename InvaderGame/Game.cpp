#include "Game.h"

#include "Define.h"
#include "KeyManager.h"

Game::Game(){

}

Game::~Game(){

}

void Game::setup(){
	count = 0;

	player.setup();
	//enemy.setup();
	enemys.setup();
}

void Game::update(){
	fps.Update();
	fps.Draw();

	inputKey();

	if (player.life) {
		player.update();

		if (key[KEY_INPUT_LEFT] >= 1) {
			player.x -= player.xspeed;
		}

		if (key[KEY_INPUT_RIGHT] >= 1) {
			player.x += player.xspeed;
		}

		if (key[KEY_INPUT_UP] >= 1) {
			player.y -= player.xspeed;
		}

		if (key[KEY_INPUT_DOWN] >= 1) {
			player.y += player.xspeed;
		}

		if (key[KEY_INPUT_SPACE] >= 1) {
			if (player.bullet.flag == false) {
				player.bullet.flag = true;
				player.bullet.create(player.x + player.width / 2, player.y);
			}
		}

		//�G�������ɂ��������Ƃ��̏���
		/*if (player.isActorCollision(enemy)) {
			player.life = false;
		}*/

		for (int i = 0; i < Enemys::h; i++) {
			for (int j = 0; j < Enemys::w; j++) {
				if (player.isActorCollision(enemys.enemys[i][j])) {
					player.life = false;
				}
			}
		}

		if (player.bullet.flag == true) {
			player.bullet.draw();
			player.bullet.move();

			//��ʊO�Œe�������鏈��
			if (player.bullet.y <= 0) {
				player.bullet.flag = false;
			}

			//�����̒e���G�ɂ��������Ƃ��̏���
			if (player.bullet.isCollision(enemy)) {
				enemy.life = false;
			}

			//�����̒e���G�̒e�ɓ����������̏���
			if (player.isBulletCollision(enemy.bullet)) {
				//printfDx("a");
				enemy.bullet.flag = false;
				count = 0;
			}
		}
	}

	enemys.update();


	
	/*if (enemy.life) {
		enemy.update();

		count++;
		if (count == 60) {
			if (enemy.bullet.flag == false) {
				enemy.bullet.flag = true;
				enemy.bullet.create(enemy.x + enemy.width / 2, enemy.y + enemy.height);
			}
		}

		if (enemy.bullet.flag) {
			enemy.bullet.draw();
			enemy.bullet.y += 5;

			//��ʊO����
			if (enemy.bullet.y >= Window::HEIGHT) {
				enemy.bullet.flag = false;
				count = 0;
			}

			//�G�̒e�������ɂ��������Ƃ��̏���
			if (enemy.bullet.isCollision(player)) {
				player.life = false;
			}

			//�G�̒e�������ɂ��������Ƃ��̏���
			if (enemy.isBulletCollision(player.bullet)) {
				//printfDx("b");
				player.bullet.flag = false;
			}
		}
	}*/
	

	fps.Wait();
}
