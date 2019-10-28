#include "Game.h"

#include "Define.h"


Game::Game(){

}

Game::~Game(){

}

void Game::start(){
	count = 0;
	score = 0;

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
	DrawString(840 - 20, 50, "SCORE< 2 >", GetColor(255, 255, 0));

	DrawFormatString(400 + 20 + 37, 90, GetColor(255, 255, 255), "%05d", score);
	DrawFormatString(640 + 17, 90, GetColor(0, 255, 255), "%05d", 0);
	DrawFormatString(840 + 17, 90, GetColor(255, 255, 255), "%05d", 0);

	//壁の処理
	wall.update();
	wall2.update();
	wall3.update();
	wall4.update();

	if (player.life) {
		player.update();

		//敵が味方にあたったときの処理
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
			for (int i = 0; i < Enemys::h; i++) {
				for (int j = 0; j < Enemys::w; j++) {
					if (enemys.enemys[i][j].life == false) continue;

					if (player.bullet.isCollision(enemys.enemys[i][j])) {
						//printfDx("HIT!!!\n");
						enemys.enemys[i][j].life = false;
						player.bullet.life = false;
						score += 500;
					}

					//自分の弾が敵の弾に当たった時の処理
					//if (enemys.enemys[i][j].life == false) continue;

					if (player.isBulletCollision(enemys.enemys[i][j].bullet)) {
						printfDx("あたった\n");
						player.bullet.life = false;
						enemys.enemys[i][j].bullet.life = false;
						count = 0;
					}
				}
			}

			//弾がブロックの塊にあたったときの処理
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

	//alien.update();

	
	enemys.move();
	enemys.ableBullet();
	for (int i = 0; i < Enemys::h; i++) {
		for (int j = 0; j < Enemys::w; j++) {
			//敵がライフがない場合（スキップ）
			if (enemys.enemys[i][j].life == false) continue;
			
			//敵が壁にあたったときの処理
			if (enemys.enemys[i][j].life) {
				wall.ehitTest(enemys.enemys[i][j].x, enemys.enemys[i][j].y, enemys.enemys[i][j].width, enemys.enemys[i][j].height);		
			}

			if (enemys.enemys[i][j].shotflag) {
				//敵の弾のlifeがtrueの時の判定
				if (enemys.enemys[i][j].bullet.life) {

					//敵の弾がプレイヤーにあたったときの処理
					if (enemys.enemys[i][j].bullet.isCollision(player)) {
						if (player.life) {
							//printfDx("Bullet::isHit\n");
							//player.life = false;
						}
					}

					//画面外処理（画面外にカウントを0にする）
					if (enemys.enemys[i][j].bullet.isLife() == false) {
						enemys.enemys[i][j].count = 0;
					}
				}

				//弾が壁にあたったときの処理
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
	
	//UFOの処理
	ufo.update();
	
	fps.Wait();
}
