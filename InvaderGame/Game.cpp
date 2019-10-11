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
	//enemy.paint(100, 100);

	enemys.setup();
}

void Game::update(){
	fps.Update();
	fps.Draw();

	inputKey();

	if (player.life) {
		player.update();

		if (key[KEY_INPUT_LEFT] >= 1) {
			//printfDx("LEFT\n");
			player.x -= player.xspeed;
		}

		if (key[KEY_INPUT_RIGHT] >= 1) {
			//printfDx("RIGHT\n");
			player.x += player.xspeed;
		}

		if (key[KEY_INPUT_UP] >= 1) {
			//printfDx("UP\n");
			player.y -= player.xspeed;
		}

		if (key[KEY_INPUT_DOWN] >= 1) {
			//printfDx("DOWN\n");
			player.y += player.xspeed;
		}

		//�G�������ɂ��������Ƃ��̏���
		//�G��1�̂̎�
		//FIXED: �G��life��false�ɂ����������ƓG�̍��W���L�^����邽�߁A�e�������͖����̓����蔻�肪�L���ɂȂ�
		//TODO:��L���C������B
		/*if (player.isActorCollision(enemy)) {
			if (enemy.life) {
				player.life = false;
			}
		}*/

		//�G�������̂̎�
		for (int i = 0; i < Enemys::h; i++) {
			for (int j = 0; j < Enemys::w; j++) {
				if (enemys.enemys[i][j].life) {
					if (player.isActorCollision(enemys.enemys[i][j])) {
						printfDx("player::Hit\n");
						//player.life = false;
					}
					else {
						printfDx("player::NoHit\n");
					}
				}
			}
		}


		if (key[KEY_INPUT_SPACE] >= 1) {
			if (player.bullet.flag == false) {
				player.bullet.flag = true;
				player.bullet.create(player.x + player.width / 2, player.y);
			}
		}


		if (player.bullet.flag == true) {
			player.bullet.draw();
			player.bullet.move();

			//��ʊO�Œe�������鏈��
			if (player.bullet.y <= 0) {
				player.bullet.flag = false;
			}

			//�����̒e���G�ɂ��������Ƃ��̏���(����)
			/*for (int i = 0; i < Enemys::h; i++) {
				for (int j = 0; j < Enemys::w; j++) {
					if (player.bullet.isCollision(enemys.enemys[i][j])) {
						printfDx("HIT!!!\n");
						enemys.enemys[i][j].life = false;
						player.bullet.flag = false;
					}
				}
			}*/

			/*if (player.bullet.isCollision(enemy)) {
				if (enemy.life) {
					//printfDx("HIT!!!\n");
					//enemy.life = false;
					//player.bullet.flag = false;
				}
			}*/


			for (int i = 0; i < Enemys::h; i++) {
				for (int j = 0; j < Enemys::w; j++) {
					//�����̒e���G�̒e�ɓ����������̏���
					if (enemys.enemys[i][j].life) {
						if (player.isBulletCollision(enemys.enemys[i][j].bullet)) {
							printfDx("��������\n");

							player.bullet.flag = false;
							enemys.enemys[i][j].bullet.flag = false;
							count = 0;
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < Enemys::h; i++) {
		for (int j = 0; j < Enemys::w; j++) {
			if (enemys.enemys[i][j].life) {
				enemys.enemys[i][j].draw();
				//enemys.enemys[i][j].move();

				//�G�̒e����������鏈��
				if (enemys.enemys[i][j].bullet.flag == false) {
					enemys.enemys[i][j].bullet.flag = true;
					enemys.enemys[i][j].bullet.create(enemys.enemys[i][j].x, enemys.enemys[i][j].y);
				}

				//�G�̒e��flag��true�̎��̔���
				if (enemys.enemys[i][j].bullet.flag) {
					enemys.enemys[i][j].bullet.draw();
					enemys.enemys[i][j].bullet.y += 10;

					//�G�̒e���v���C���[�ɂ��������Ƃ��̏���
					if (enemys.enemys[i][j].bullet.isCollision(player)) {
						if (player.life) {
							//printfDx("Bullet::isHit\n");
							//player.life = false;
						}
					}


					//��ʊO����
					if (enemys.enemys[i][j].bullet.y >= Window::HEIGHT) {
						enemys.enemys[i][j].bullet.flag = false;
						enemys.enemys[i][j].count = 0;
					}
				}
				
			}
		}
	}

	
	/*if (enemy.life) {
		enemy.update();

		count++;
		printfDx("%d\n", count);
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
				//player.life = false;
			}

			//�G�̒e�������ɂ��������Ƃ��̏���
			/*if (enemy.isBulletCollision(player.bullet)) {
				printfDx("����������\n");
				player.bullet.flag = false;
			}
		}
	}*/
	

	fps.Wait();
}
