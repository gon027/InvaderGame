#include "Game.h"

#include "Define.h"
#include "FileReader.h"
#include "AudioManager.h"
#include "TitleScene.h"
#include "GameOver.h"

static constexpr int ufoScore[] = {50, 100, 300};
int waitTimer = 0;

Game::Game(SceneController * _controller){
	this->controller = _controller;
	setup();
}

void Game::setup(){
	backGround.init(0, 0, "image/back_game.png");
	backGround.loadImage();

	score = 0;
	hitPoint = 2;
	roundCount = 0;
	//�t�@�C������l��ǂݏo��
	//singleton<FileReader>::getInstance().read("text/HiScore.txt", "r");
	hiScore = singleton<FileReader>::getInstance().getScore();

	enemyOffset = 250;

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

#ifdef FULL_SCREEN
	backGround.draw();
#else
	DrawBox(0, 0, Window::WIDTH, Window::HEIGHT, GetColor(0, 255, 255), TRUE);
#endif

	count++;

	SetFontSize(32);
	DrawString(400 + 50, 70, "SCORE< 1 >", GetColor(0, 255, 255));
	DrawString(640 + 30, 70, "HI-SCORE", GetColor(0, 0, 255));
	DrawString(840 + 30, 70, "ROUND", GetColor(255, 255, 0));

	DrawFormatString(400 + 50 + 37, 110, GetColor(255, 255, 255), "%05d", score);
	DrawFormatString(640 + 50, 110, GetColor(0, 255, 255), "%05d", hiScore);
	DrawFormatString(840 + 85, 110, GetColor(255, 255, 255), "%02d", roundCount);

	
	if (isRunning) {
		wallUpdate();
		playerUpdate();
		alienUpdate();
		ufpUpdate();

		if (alien.getAlienCount() == 0) {
			clear();
			enemyOffset = 384;
			roundCount++;
			init();
		}

		if (player.life == false) {
			hitPoint -= 1;
			player.life = true;
		}
	}


		//�v���C���[�̗̑͂�-1�ɂȂ����Ƃ�
	if (hitPoint < 0) {
		isRunning = false;
		waitTimer++;

		if (waitTimer >= 10) {
			clear();
			
			if (score >= hiScore) {
				hiScore = score;
				singleton<FileReader>::getInstance().write("text/HiScore.txt", "w", hiScore);
			}

			controller->scene = new GameOver(controller, 1, score, hiScore);
			delete this;
		}
	}
	
	fps.Wait();
}

//�㏈���֐�
void Game::clear(){
	player.clear();
	alien.clear();
	ufo.clear();
	wall1.clear();
	wall2.clear();
	wall3.clear();
	wall4.clear();
}

void Game::playerUpdate(){
	//�v���C���[�̎c�莩�@��`��
	DrawFormatString(Window::WALL_L + 10, 820, GetColor(0, 255, 255), "%d", hitPoint + 1);
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
						player.life = false;
					}
				}
			}
		}

		//�������e�𔭎˂����Ƃ�
		if (player.bullet.isLife() == true) {
			//UFO�ɂ��������Ƃ��̏���
			if (player.bullet.isCollision(ufo)) {
				if (ufo.life) {
					player.bullet.life = false;
					ufo.life = false;
					int temScore = ufoScore[GetRand(2)];
					score += temScore;
				}
			}

			//�����̒e���G�ɂ��������Ƃ��̏���
			for (int i = 0; i < Alien::h; i++) {
				for (int j = 0; j < Alien::w; j++) {
					if (alien.alien[i][j].life == false) continue;

					//�v���C���[�̒e���G�ɂ��������Ƃ��̔���
					if (player.bullet.isCollision(alien.alien[i][j])) {
						printfDx("Hit\n");
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

						alien.alienCoundDown();
					}

					//�����̒e���G�̒e�ɓ����������̏���
					if (player.isBulletCollision(alien.alien[i][j].bullet)) {
						printfDx("Hit::BulletCollision\n");
						player.bullet.life = false;
						alien.alien[i][j].bullet.life = false;
						count = 0;
					}
				}
			}

			//�e���u���b�N�̉�ɂ��������Ƃ��̏���
			if (wall1.hitTest(player.bullet.x, player.bullet.y, player.bullet.width, player.bullet.height)) {
				printfDx("Hit::Wall1\n");
				player.bullet.life = false;
			}

			if (wall2.hitTest(player.bullet.x, player.bullet.y, player.bullet.width, player.bullet.height)) {
				printfDx("Hit::Wall2\n");
				player.bullet.life = false;
			}

			if (wall3.hitTest(player.bullet.x, player.bullet.y, player.bullet.width, player.bullet.height)) {
				printfDx("Hit::Wall3\n");
				player.bullet.life = false;
			}

			if (wall4.hitTest(player.bullet.x, player.bullet.y, player.bullet.width, player.bullet.height)) {
				printfDx("Hit::Wall4\n");
				player.bullet.life = false;
			}
		}
	}
}

void Game::alienUpdate(){
	alien.draw();		//�`��
	alien.move();		//�ړ�
	alien.shot();		//�e������

	for (int i = 0; i < Alien::h; i++) {
		for (int j = 0; j < Alien::w; j++) {
			//�G�����C�t���Ȃ��ꍇ�i�X�L�b�v�j
			if (alien.alien[i][j].life == false) continue;

			//�G���ǂɂ��������Ƃ��̏���
			if (alien.alien[i][j].life) {
				wall1.ehitTest(alien.alien[i][j].x, alien.alien[i][j].y, alien.alien[i][j].width, alien.alien[i][j].height);
				wall2.ehitTest(alien.alien[i][j].x, alien.alien[i][j].y, alien.alien[i][j].width, alien.alien[i][j].height);
				wall3.ehitTest(alien.alien[i][j].x, alien.alien[i][j].y, alien.alien[i][j].width, alien.alien[i][j].height);
				wall4.ehitTest(alien.alien[i][j].x, alien.alien[i][j].y, alien.alien[i][j].width, alien.alien[i][j].height);
			}

			//�G�̒e��life��true�̎��̔���
			if (alien.alien[i][j].bullet.life) {
				//�G�̒e���v���C���[�ɂ��������Ƃ��̏���
				if (alien.alien[i][j].bullet.isCollision(player)) {
					if (player.life) {
						player.life = false;
						alien.alien[i][j].bullet.life = false;
					}
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

void Game::ufpUpdate(){
	//UFO�̏���
	ufo.update();
}

void Game::wallUpdate(){
	//�ǂ̏���
	wall1.update();
	wall2.update();
	wall3.update();
	wall4.update();
}
