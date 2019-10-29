#include "Game.h"

#include "Define.h"
#include "singleton.h"
#include "FileReader.h"
#include "AudioManager.h"
#include "Timer.h"

static constexpr int ufoScore[] = {50, 100, 300};

Game::Game(){

}

Game::~Game(){

}

void Game::setup(){
	score = 0;
	hitPoint = 2;
	singleton<FileReader>::getInstance().read("text/HiScore.txt", "r");
	hiScore = singleton<FileReader>::getInstance().getScore();

	enemyOffset = 220;

	player.setup();
	alien.setup();
	ufo.setup();

	wall1.setup();
	wall2.setup();
	wall3.setup();
	wall4.setup();
	

	init();
}

void Game::init(){
	allEnemyCount = Alien::h * Alien::w;
	isRunning = true;

	//�L�����N�^�[�ނƕǂ̏�����
	player.init();
	alien.init(Window::WALL_L + 76 - 12, enemyOffset);
	ufo.init();

	int xx = Window::WALL_L + 76;
	wall1.init(xx, 640);
	wall2.init(xx + 140, 640);
	wall3.init(xx + 140 * 2, 640);
	wall4.init(xx + 140 * 3, 640);
}

void Game::update(){
	fps.Update();
	fps.Draw();

	count++;

	SetFontSize(32);
	DrawString(400 + 20, 50, "SCORE< 1 >", GetColor(0, 255, 255));
	DrawString(640, 50, "HI-SCORE", GetColor(0, 0, 255));
	//DrawString(840 - 20, 50, "SCORE< 2 >", GetColor(255, 255, 0));

	DrawFormatString(400 + 20 + 37, 90, GetColor(255, 255, 255), "%05d", score);
	DrawFormatString(640 + 17, 90, GetColor(0, 255, 255), "%05d", hiScore);
	//DrawFormatString(840 + 17, 90, GetColor(255, 255, 255), "%05d", 0);

	
	wallLoop();
	playerLoop();
	enemyLoop();
	ufoLoop();

	if (allEnemyCount == 0) {
		init();
		enemyOffset = 384;
	}

	if (player.life == false) {
		hitPoint -= 1;
		player.life = true;
	}


	//�v���C���[�̗̑͂�-1�ɂȂ����Ƃ�
	if (hitPoint == 0) {
		score = 0;
		enemyOffset = 220;
		if (score >= hiScore) {
			hiScore = score;
		}
		singleton<FileReader>::getInstance().write("text/HiScore.txt", "w", hiScore);
		isRunning = false;
	}
	
	fps.Wait();
}

int wait = 0;

void Game::playerLoop(){
	//�v���C���[�̎c�莩�@��`��
	DrawFormatString(Window::WALL_L, 820, GetColor(0, 255, 255), "%d", hitPoint + 1);
	for (int i = 0; i < hitPoint; ++i) {
		player.draw(Window::WALL_L + 50 + 48 * i, 820);
	}

	if (player.life) {
		player.update();

		//�G�������ɂ��������Ƃ��̏���
		for (int i = 0; i < Alien::h; i++) {
			for (int j = 0; j < Alien::w; j++) {
				if (alien.alien[i][j].life) {
					if (player.isActorCollision(alien.alien[i][j])) {
						//player.life = false;
					}
				}
			}
		}

		//printfDx("%d\n", (GetNowCount() - Timer::time) / 1000);

		//UFO�ɂ��������Ƃ��̏���
		if (player.bullet.isLife() == true) {
			if (player.bullet.isCollision(ufo)) {
				if (ufo.life) {
					player.bullet.life = false;
					int temScore = ufoScore[GetRand(2)];
					score += temScore;
					ufo.life = false;

					wait++;
					if (wait <= 100) {
						DrawFormatString(ufo.x, ufo.y, GetColor(255, 128, 128), "%d", temScore);
					}
				}
			}

			//�����̒e���G�ɂ��������Ƃ��̏���
			for (int i = 0; i < Alien::h; i++) {
				for (int j = 0; j < Alien::w; j++) {
					if (alien.alien[i][j].life == false) continue;

					if (player.bullet.isCollision(alien.alien[i][j])) {
						//printfDx("HIT!!!\n");
						alien.alien[i][j].life = false;
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

						//singleton<AudioManager>::getInstance().play(1);


						allEnemyCount--;
					}

					//�����̒e���G�̒e�ɓ����������̏���
					//if (alien.alien[i][j].life == false) continue;

					if (player.isBulletCollision(alien.alien[i][j].bullet)) {
						printfDx("��������\n");
						player.bullet.life = false;
						alien.alien[i][j].bullet.life = false;
						count = 0;
					}
				}
			}

			//�e���u���b�N�̉�ɂ��������Ƃ��̏���
			if (wall1.hitTest(player.bullet.x, player.bullet.y, player.bullet.width, player.bullet.height)) {
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
	alien.draw();		//�`��
	alien.move();		//�ړ�
	alien.ableBullet();		//�łĂ鋅�̒T��
	for (int i = 0; i < Alien::h; i++) {
		for (int j = 0; j < Alien::w; j++) {
			//�G�����C�t���Ȃ��ꍇ�i�X�L�b�v�j
			if (alien.alien[i][j].life == false) continue;

			//�G���ǂɂ��������Ƃ��̏���
			if (alien.alien[i][j].life) {
				wall1.ehitTest(alien.alien[i][j].x, alien.alien[i][j].y, alien.alien[i][j].width, alien.alien[i][j].height);
			}

			if (alien.alien[i][j].shotflag) {
				//�G�̒e��life��true�̎��̔���
				if (alien.alien[i][j].bullet.life) {

					//�G�̒e���v���C���[�ɂ��������Ƃ��̏���
					if (alien.alien[i][j].bullet.isCollision(player)) {
						if (player.life) {
							//printfDx("Bullet::isHit\n");
							//player.life = false;
						}
					}

					//��ʊO�����i��ʊO�ɃJ�E���g��0�ɂ���j
					/*if (alien.alien[i][j].bullet.isLife() == false) {
						alien.alien[i][j].count = 0;
					}*/
				}

				//�e���ǂɂ��������Ƃ��̏���
				if (wall1.hitTest(alien.alien[i][j].bullet.x, alien.alien[i][j].bullet.y, alien.alien[i][j].bullet.width, alien.alien[i][j].bullet.height)) {
					alien.alien[i][j].bullet.life = false;
				}

				if (wall2.hitTest(alien.alien[i][j].bullet.x, alien.alien[i][j].bullet.y, alien.alien[i][j].bullet.width, alien.alien[i][j].bullet.height)) {
					alien.alien[i][j].bullet.life = false;
				}

				if (wall3.hitTest(alien.alien[i][j].bullet.x, alien.alien[i][j].bullet.y, alien.alien[i][j].bullet.width, alien.alien[i][j].bullet.height)) {
					alien.alien[i][j].bullet.life = false;
				}

				if (wall4.hitTest(alien.alien[i][j].bullet.x, alien.alien[i][j].bullet.y, alien.alien[i][j].bullet.width, alien.alien[i][j].bullet.height)) {
					alien.alien[i][j].bullet.life = false;
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
	wall1.update();
	wall2.update();
	wall3.update();
	wall4.update();
}
