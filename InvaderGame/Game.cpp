#include "Game.h"

#include "Define.h"


Game::Game(){

}

Game::~Game(){

}

void Game::start(){
	count = 0;

	player.setup();
	enemys.setup();
	ufo.setup();

	//alien.load();
	//alien.init(50, 50);

	wall.load();
	wall.init(300, 200);
}

void Game::update(){
	fps.Update();
	fps.Draw();

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
			player.bullet.draw();

			//UFOにあたったときの処理
			if (player.bullet.isCollision(ufo)) {
				if (ufo.life) {
					//printfDx("UFO::HIT!!\n");
					ufo.life = false;
					player.bullet.life = false;
				}
			}

			//自分の弾が敵にあたったときの処理
			for (int i = 0; i < Enemys::h; i++) {
				for (int j = 0; j < Enemys::w; j++) {
					if (enemys.enemys[i][j].life) {
						if (player.bullet.isCollision(enemys.enemys[i][j])) {
							//printfDx("HIT!!!\n");
							enemys.enemys[i][j].life = false;
							player.bullet.life = false;
						}
					}
				}
			}

			for (int i = 0; i < Enemys::h; i++) {
				for (int j = 0; j < Enemys::w; j++) {
					//自分の弾が敵の弾に当たった時の処理
					if (enemys.enemys[i][j].life) {
						if (player.isBulletCollision(enemys.enemys[i][j].bullet)) {
							//printfDx("あたった\n");
							player.bullet.life = false;
							enemys.enemys[i][j].bullet.life = false;
							count = 0;
						}
					}
				}
			}

			//弾がブロックの塊にあたったときの処理
			if (wall.hitTest(player.bullet.x, player.bullet.y, player.bullet.width, player.bullet.height)) {
				player.bullet.life = false;
			}
		}
	}

	//alien.update();

	enemys.ableBullet();
	for (int i = 0; i < Enemys::h; i++) {
		for (int j = 0; j < Enemys::w; j++) {
			//敵が生きているとき
			if (enemys.enemys[i][j].life) {
				enemys.enemys[i][j].draw();
				//enemys.enemys[i][j].move();

				//敵の折り返し処理
				if (enemys.enemys[i][j].turnflag) {
					enemys.enemys[i][j].turnflag = false;
					timer++;
					if (timer == 30) {

						//printfDx("i = %d, j = %d, life = %d\n", i, j, enemys.enemys[i][j].turnflag);
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

				//敵が壁にあたったときの処理
				if (enemys.enemys[i][j].life) {
					wall.ehitTest(enemys.enemys[i][j].x, enemys.enemys[i][j].y, enemys.enemys[i][j].width, enemys.enemys[i][j].height);		
				}

				if (enemys.enemys[i][j].shotflag) {
					//敵の弾が生成される処理
					if (enemys.enemys[i][j].bullet.isLife() == false) {
						enemys.enemys[i][j].bullet.init(enemys.enemys[i][j].x + (enemys.enemys[i][j].width / 2), enemys.enemys[i][j].y + enemys.enemys[i][j].height, 1, GetColor(0, 0, 255));
					}

					//敵の弾のlifeがtrueの時の判定
					if (enemys.enemys[i][j].bullet.life) {
						enemys.enemys[i][j].bullet.draw();

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
				}
			}
		}
	}

	//壁の処理
	wall.update();
	
	//UFOの処理
	ufo.update();
	
	fps.Wait();
}
