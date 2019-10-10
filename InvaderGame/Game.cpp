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
	enemy.setup();
	enemy.paint(100, 100);

	//enemys.setup();
}

void Game::update(){
	fps.Update();
	fps.Draw();

	inputKey();

	if (player.life) {
		player.update();

		if (key[KEY_INPUT_LEFT] >= 1) {
			printfDx("LEFT\n");
			player.x -= player.xspeed;
		}

		if (key[KEY_INPUT_RIGHT] >= 1) {
			printfDx("RIGHT\n");
			player.x += player.xspeed;
		}

		if (key[KEY_INPUT_UP] >= 1) {
			printfDx("UP\n");
			player.y -= player.xspeed;
		}

		if (key[KEY_INPUT_DOWN] >= 1) {
			printfDx("DOWN\n");
			player.y += player.xspeed;
		}

		if (key[KEY_INPUT_SPACE] >= 1) {
			if (player.bullet.flag == false) {
				player.bullet.flag = true;
				player.bullet.create(player.x + player.width / 2, player.y);
			}
		}

		//�G�������ɂ��������Ƃ��̏���
		//�G��1�̂̎�
		//FIXED: �G��life��false�ɂ����������ƓG�̍��W���L�^����邽�߁A�e�������͖�����
		//�����蔻�肪�L���ɂȂ�
		//TODO:��L���C������B
		if (enemy.life) {
			if (player.isActorCollision(enemy)) {
				player.life = false;
			}
		}

		//�G�������̂̎�
		/*for (int i = 0; i < Enemys::h; i++) {
			for (int j = 0; j < Enemys::w; j++) {
				if (player.isActorCollision(enemys.enemys[i][j])) {
					printfDx("player::hit\n");
					//player.life = false;
				}
			}
		}*/

		if (player.bullet.flag == true) {
			player.bullet.draw();
			player.bullet.move();

			//��ʊO�Œe�������鏈��
			if (player.bullet.y <= 0) {
				player.bullet.flag = false;
			}

			//�����̒e���G�ɂ��������Ƃ��̏���
			/*for (int i = 0; i < Enemys::h; i++) {
				for (int j = 0; j < Enemys::w; j++) {
					if (player.bullet.isCollision(enemys.enemys[i][j])) {
						printfDx("HIT!!!\n");
						enemys.enemys[i][j].life = false;
						player.bullet.flag = false;
					}
				}
			}*/

			if (player.bullet.isCollision(enemy)) {
				if (enemy.life) {
					printfDx("HIT!!!\n");
					enemy.life = false;
					player.bullet.flag = false;
				}
			}

			//�����̒e���G�̒e�ɓ����������̏���
			//if (player.isBulletCollision(enemy.bullet)) {
				//printfDx("a");
				//enemy.bullet.flag = false;
				//count = 0;
			//}
		}
	}

	//enemys.draw();

	
	if (enemy.life) {
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
				player.bullet.flag = false;
			}
		}
	}
	

	fps.Wait();
}
