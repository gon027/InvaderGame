#include "Game.h"

#include "Define.h"
#include "KeyManager.h"

Game::Game(){
	start();
}

Game::~Game(){

}

void Game::start(){
	count = 0;

	player.setup();
	//enemy.start();
	//enemy.paint(100, 100);

	enemys.setup();
}

void Game::update(){
	fps.Update();
	fps.Draw();

	inputKey();
	DrawBox(0, 430, Window::WIDTH, Window::HEIGHT, GetColor(0, 0, 0), TRUE);

	if (player.life) {
		player.update();

		if (key[KEY_INPUT_LEFT] >= 1) {
			player.x -= player.xspeed;
		}

		if (key[KEY_INPUT_RIGHT] >= 1) {
			player.x += player.xspeed;
		}

		//�G�������ɂ��������Ƃ��̏���
		//FIXED: �G��life��false�ɂ����������ƓG�̍��W���L�^����邽�߁A�e�������͖����̓����蔻�肪�L���ɂȂ�
		//TODO:��L���C������B
		//�G�������̂̎�
		for (int i = 0; i < Enemys::h; i++) {
			for (int j = 0; j < Enemys::w; j++) {
				if (enemys.enemys[i][j].life) {
					if (player.isActorCollision(enemys.enemys[i][j])) {
						//printfDx("player::Hit\n");
						//player.life = false;
					}
					else {
						//printfDx("player::NoHit\n");
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
			for (int i = 0; i < Enemys::h; i++) {
				for (int j = 0; j < Enemys::w; j++) {
					if (player.bullet.isCollision(enemys.enemys[i][j])) {
						printfDx("HIT!!!\n");
						enemys.enemys[i][j].life = false;
						player.bullet.flag = false;
					}
				}
			}

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
				enemys.enemys[i][j].move();				

				//�G�̐܂�Ԃ�����
				if (enemys.enemys[i][j].turnflag) {
					enemys.enemys[i][j].turnflag = false;
					timer++;
					if (timer == 30) {

						//printfDx("i = %d, j = %d, flag = %d\n", i, j, enemys.enemys[i][j].turnflag);
						for (int n = 0; n < Enemys::h; n++) {
							for (int m = 0; m < Enemys::w; m++) {
								enemys.enemys[n][m].y += enemys.enemys[n][m].yspeed;
								enemys.enemys[n][m].xspeed = -enemys.enemys[n][m].xspeed;
								enemys.enemys[n][m].turnflag = false;
							}
						}

						timer = 0;
						break;
					}
				}


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

					//��ʊO�����i��ʊO�ɏo����e�������j
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
