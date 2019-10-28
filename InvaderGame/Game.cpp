#include "Game.h"

#include "Define.h"
#include "singleton.h"
#include "FileReader.h"


Game::Game(){

}

Game::~Game(){

}

void Game::setup(){
	score = 0;
	singleton<FileReader>::getInstance().read("text/HiScore.txt", "r");
	hiScore = singleton<FileReader>::getInstance().getScore();

	enemyOffset = 0;

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

	//キャラクター類と壁の初期化
	player.init();
	alien.init(Window::WALL_L + 76 - 12, 220 + 30 * enemyOffset);
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
		enemyOffset++;
	}

	if (player.life == false) {
		score = 0;
		enemyOffset = 0;
		if (score >= hiScore) {
			hiScore = score;
		}
		singleton<FileReader>::getInstance().write("text/HiScore.txt", "w", hiScore);
	}
	
	fps.Wait();
}

void Game::playerLoop(){

	if (player.life) {
		player.update();

		//敵が味方にあたったときの処理
		for (int i = 0; i < Alien::h; i++) {
			for (int j = 0; j < Alien::w; j++) {
				if (alien.alien[i][j].life) {
					if (player.isActorCollision(alien.alien[i][j])) {
						//player.life = false;
					}
				}
			}
		}

		if (player.bullet.isLife() == true) {
			//UFOにあたったときの処理
			if (player.bullet.isCollision(ufo)) {
				if (ufo.life) {
					//printfDx("UFO::HIT!!\n");
					ufo.life = false;
					player.bullet.life = false;
					score += 300;
				}
			}

			//自分の弾が敵にあたったときの処理
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

						allEnemyCount--;
					}

					//自分の弾が敵の弾に当たった時の処理
					//if (alien.alien[i][j].life == false) continue;

					if (player.isBulletCollision(alien.alien[i][j].bullet)) {
						printfDx("あたった\n");
						player.bullet.life = false;
						alien.alien[i][j].bullet.life = false;
						count = 0;
					}
				}
			}

			//弾がブロックの塊にあたったときの処理
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
	alien.move();
	alien.ableBullet();
	for (int i = 0; i < Alien::h; i++) {
		for (int j = 0; j < Alien::w; j++) {
			//敵がライフがない場合（スキップ）
			if (alien.alien[i][j].life == false) continue;

			//敵が壁にあたったときの処理
			if (alien.alien[i][j].life) {
				wall1.ehitTest(alien.alien[i][j].x, alien.alien[i][j].y, alien.alien[i][j].width, alien.alien[i][j].height);
			}

			if (alien.alien[i][j].shotflag) {
				//敵の弾のlifeがtrueの時の判定
				if (alien.alien[i][j].bullet.life) {

					//敵の弾がプレイヤーにあたったときの処理
					if (alien.alien[i][j].bullet.isCollision(player)) {
						if (player.life) {
							//printfDx("Bullet::isHit\n");
							//player.life = false;
						}
					}

					//画面外処理（画面外にカウントを0にする）
					if (alien.alien[i][j].bullet.isLife() == false) {
						alien.alien[i][j].count = 0;
					}
				}

				//弾が壁にあたったときの処理
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
	//UFOの処理
	ufo.update();
}

void Game::wallLoop(){
	//壁の処理
	wall1.update();
	wall2.update();
	wall3.update();
	wall4.update();
}
