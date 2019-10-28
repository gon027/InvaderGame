#include "Game.h"

#include "Define.h"


Game::Game(){

}

Game::~Game(){

}

void Game::start(){
	count = 0;

	score = 0;
	allenemy = Enemys::h * Enemys::w;
	isRunning = true;

	player.setup();
	enemys.setup();
	ufo.setup();

	//alien.load();
	//alien.init(50, 50);

	int xx = Window::WALL_L + 76;

	wall.load();
	wall.init(xx, 640);

	wall2.load();
	wall2.init(xx + 140, 640);

	wall3.load();
	wall3.init(xx + 140 * 2, 640);

	wall4.load();
	wall4.init(xx + 140 * 3, 640);
}

int count = 0;

void Game::update(){
	fps.Update();
	fps.Draw();

	count++;

	SetFontSize(32);
	DrawString(400 + 20, 50, "SCORE< 1 >", GetColor(0, 255, 255));
	DrawString(640, 50, "HI-SCORE", GetColor(0, 0, 255));
	//DrawString(840 - 20, 50, "SCORE< 2 >", GetColor(255, 255, 0));

	DrawFormatString(400 + 20 + 37, 90, GetColor(255, 255, 255), "%05d", score);
	DrawFormatString(640 + 17, 90, GetColor(0, 255, 255), "%05d", 0);
	//DrawFormatString(840 + 17, 90, GetColor(255, 255, 255), "%05d", 0);

	
	wallLoop();
	playerLoop();
	enemyLoop();
	ufoLoop();
	
	fps.Wait();
}

void Game::playerLoop(){

	if (player.life) {
		player.update();

		//�G�������ɂ��������Ƃ��̏���
		for (int i = 0; i < Enemys::h; i++) {
			for (int j = 0; j < Enemys::w; j++) {
				if (enemys.enemys[i][j].life) {
					if (player.isActorCollision(enemys.enemys[i][j])) {
						//player.life = false;
					}
				}
			}
		}

		if (player.bullet.isLife() == true) {
			//UFO�ɂ��������Ƃ��̏���
			if (player.bullet.isCollision(ufo)) {
				if (ufo.life) {
					//printfDx("UFO::HIT!!\n");
					ufo.life = false;
					player.bullet.life = false;
					score += 300;
				}
			}

			//�����̒e���G�ɂ��������Ƃ��̏���
			for (int i = 0; i < Enemys::h; i++) {
				for (int j = 0; j < Enemys::w; j++) {
					if (enemys.enemys[i][j].life == false) continue;

					if (player.bullet.isCollision(enemys.enemys[i][j])) {
						//printfDx("HIT!!!\n");
						enemys.enemys[i][j].life = false;
						player.bullet.life = false;

						if (i == 4 || i == 3) {
							score += 10;
						}
						else if (i == 2 || i == 1) {
							score += 20;
						}
						else if (i == 0) {
							score += 30;
						}

						allenemy--;
					}

					//�����̒e���G�̒e�ɓ����������̏���
					//if (enemys.enemys[i][j].life == false) continue;

					if (player.isBulletCollision(enemys.enemys[i][j].bullet)) {
						printfDx("��������\n");
						player.bullet.life = false;
						enemys.enemys[i][j].bullet.life = false;
						count = 0;
					}
				}
			}

			//�e���u���b�N�̉�ɂ��������Ƃ��̏���
			if (wall.hitTest(player.bullet.x, player.bullet.y, player.bullet.width, player.bullet.height)) {
				player.bullet.life = false;
			}

			if (wall2.hitTest(player.bullet.x, player.bullet.y, player.bullet.width, player.bullet.height)) {
				player.bullet.life = false;
			}

			if (wall3.hitTest(player.bullet.x, player.bullet.y, player.bullet.width, player.bullet.height)) {
				player.bullet.life = false;
			}

			if (wall4.hitTest(player.bullet.x, player.bullet.y, player.bullet.width, player.bullet.height)) {
				player.bullet.life = false;
			}
		}
	}

}

void Game::enemyLoop(){
	enemys.move();
	enemys.ableBullet();
	for (int i = 0; i < Enemys::h; i++) {
		for (int j = 0; j < Enemys::w; j++) {
			//�G�����C�t���Ȃ��ꍇ�i�X�L�b�v�j
			if (enemys.enemys[i][j].life == false) continue;

			//�G���ǂɂ��������Ƃ��̏���
			if (enemys.enemys[i][j].life) {
				wall.ehitTest(enemys.enemys[i][j].x, enemys.enemys[i][j].y, enemys.enemys[i][j].width, enemys.enemys[i][j].height);
			}

			if (enemys.enemys[i][j].shotflag) {
				//�G�̒e��life��true�̎��̔���
				if (enemys.enemys[i][j].bullet.life) {

					//�G�̒e���v���C���[�ɂ��������Ƃ��̏���
					if (enemys.enemys[i][j].bullet.isCollision(player)) {
						if (player.life) {
							//printfDx("Bullet::isHit\n");
							//player.life = false;
						}
					}

					//��ʊO�����i��ʊO�ɃJ�E���g��0�ɂ���j
					if (enemys.enemys[i][j].bullet.isLife() == false) {
						enemys.enemys[i][j].count = 0;
					}
				}

				//�e���ǂɂ��������Ƃ��̏���
				if (wall.hitTest(enemys.enemys[i][j].bullet.x, enemys.enemys[i][j].bullet.y, enemys.enemys[i][j].bullet.width, enemys.enemys[i][j].bullet.height)) {
					enemys.enemys[i][j].bullet.life = false;
				}

				if (wall2.hitTest(enemys.enemys[i][j].bullet.x, enemys.enemys[i][j].bullet.y, enemys.enemys[i][j].bullet.width, enemys.enemys[i][j].bullet.height)) {
					enemys.enemys[i][j].bullet.life = false;
				}

				if (wall3.hitTest(enemys.enemys[i][j].bullet.x, enemys.enemys[i][j].bullet.y, enemys.enemys[i][j].bullet.width, enemys.enemys[i][j].bullet.height)) {
					enemys.enemys[i][j].bullet.life = false;
				}

				if (wall4.hitTest(enemys.enemys[i][j].bullet.x, enemys.enemys[i][j].bullet.y, enemys.enemys[i][j].bullet.width, enemys.enemys[i][j].bullet.height)) {
					enemys.enemys[i][j].bullet.life = false;
				}
			}
		}
	}
}

void Game::ufoLoop(){
	//UFO�̏���
	ufo.update();
}

void Game::wallLoop(){
	//�ǂ̏���
	wall.update();
	wall2.update();
	wall3.update();
	wall4.update();
}
