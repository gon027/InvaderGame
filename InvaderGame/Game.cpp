#include "Game.h"

#include "Define.h"
#include "KeyManager.h"

Game::Game(){
	/*count = 0;

	player.setup();
	enemys.setup();
	ufo.setup();

	block.load();*/
}

Game::~Game(){

}

void Game::start(){
	count = 0;

	player.setup();
	//enemys.setup();
	ufo.setup();

	alien.load();
	alien.init(50, 50);

	wall.load();
	wall.init(200, 50);

	/*wall2.load();
	wall3.load();
	wall4.load();
	*/

	block.load();
	block.init(400, 100);
	

	//enemy.start();
	//enemy.paint(100, 100);
}

void Game::update(){
	fps.Update();
	fps.Draw();

	inputKey();
	//DrawBox(0, 430, Window::WIDTH, Window::HEIGHT, GetColor(0, 0, 0), TRUE);

	block.update();
	if(key[KEY_INPUT_B] == 1) {
		block++;
	}

	wall.update();

	//wall.update();
	/*wall2.draw(100, 300);
	wall3.draw(100, 300);
	wall4.draw(100, 300);
	*/

	if (player.life) {
		player.update();

		if (key[KEY_INPUT_LEFT] >= 1) {
			player.x -= player.xspeed;
		}

		if (key[KEY_INPUT_RIGHT] >= 1) {
			player.x += player.xspeed;
		}

		//敵が味方にあたったときの処理
		//FIXED: 敵のlifeをfalseにしただけだと敵の座標が記録されるため、
		//		 弾もしくは味方の当たり判定が有効になる
		//TODO:上記を修正する。
		//敵が複数体の時
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

		if (key[KEY_INPUT_A] >= 1) {
			printfDx("%d\n", player.bullet.flag);
			if (player.bullet.flag == false) {
				player.bullet.flag = true;
				player.bullet.create(player.x, player.y - (player.bullet.height * 2));
			}
		}

		if (player.bullet.flag == true) {
			player.bullet.draw();
			player.bullet.move();

			//画面外で弾が消える処理
			if (player.bullet.y <= 0) {
				player.bullet.flag = false;
			}

			//UFOにあたったときの処理
			if (player.bullet.isCollision(ufo)) {
				if (ufo.life) {
					printfDx("UFO::HIT!!\n");
					ufo.life = false;
				}
			}

			//自分の弾が敵にあたったときの処理(複数)
			for (int i = 0; i < Enemys::h; i++) {
				for (int j = 0; j < Enemys::w; j++) {
					if (enemys.enemys[i][j].life) {
						if (player.bullet.isCollision(enemys.enemys[i][j])) {
							printfDx("HIT!!!\n");
							enemys.enemys[i][j].life = false;
							player.bullet.flag = false;
						}
					}
				}
			}

			for (int i = 0; i < Enemys::h; i++) {
				for (int j = 0; j < Enemys::w; j++) {
					//自分の弾が敵の弾に当たった時の処理
					if (enemys.enemys[i][j].life) {
						if (player.isBulletCollision(enemys.enemys[i][j].bullet)) {
							printfDx("あたった\n");

							player.bullet.flag = false;
							enemys.enemys[i][j].bullet.flag = false;
							count = 0;
						}
					}
				}
			}

			//弾がブロックにあたったときの処理
			if (block.getLife()) {
				if(block.collision(player.bullet.x, player.bullet.y, player.bullet.width, player.height)) {
					//printfDx("aaaaa\n");
					block++;
					player.bullet.flag = false;
				}
			}

			//弾がブロックの塊にあたったときの処理
			if (wall.bulletHitTest(player.bullet.x, player.bullet.y, player.bullet.width, player.bullet.height)) {
				player.bullet.flag = false;
			}
		}
	}

	alien.update();

	/*
	enemys.shotFlag();
	for (int i = 0; i < Enemys::h; i++) {
		for (int j = 0; j < Enemys::w; j++) {
			if (enemys.enemys[i][j].life) {
				enemys.enemys[i][j].draw();
				enemys.enemys[i][j].move();

				//敵の折り返し処理
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

				//printfDx("%d\n", enemys.enemys[i][j].shotflag);

				if (enemys.enemys[i][j].shotflag) {
					//敵の弾が生成される処理
					if (enemys.enemys[i][j].bullet.flag == false) {
						enemys.enemys[i][j].bullet.flag = true;
						enemys.enemys[i][j].bullet.create(enemys.enemys[i][j].x, enemys.enemys[i][j].y);
						//enemys.enemys[i][j].bullet.create(100, 100);
					}

					//敵の弾のflagがtrueの時の判定
					if (enemys.enemys[i][j].bullet.flag) {
						enemys.enemys[i][j].bullet.draw();
						enemys.enemys[i][j].bullet.y += 10;

						//敵の弾がプレイヤーにあたったときの処理
						if (enemys.enemys[i][j].bullet.isCollision(player)) {
							if (player.life) {
								//printfDx("Bullet::isHit\n");
								//player.life = false;
							}
						}

						//画面外処理（画面外に出たら弾を消す）
						if (enemys.enemys[i][j].bullet.y >= Window::HEIGHT) {
							enemys.enemys[i][j].bullet.flag = false;
							enemys.enemys[i][j].count = 0;
						}
					}

					//弾が壁にあたったときの処理
					if (wall.bulletHitTest(enemys.enemys[i][j].bullet.x, enemys.enemys[i][j].bullet.y, enemys.enemys[i][j].bullet.width, enemys.enemys[i][j].bullet.height)) {
						enemys.enemys[i][j].bullet.flag = false;
					}
				}
			}
		}
	}
	*/
	
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

			//画面外処理
			if (enemy.bullet.y >= Window::HEIGHT) {
				enemy.bullet.flag = false;
				count = 0;
			}

			//敵の弾が味方にあたったときの処理
			if (enemy.bullet.isCollision(player)) {
				//player.life = false;
			}

			//敵の弾が味方にあたったときの処理
			/*if (enemy.isBulletCollision(player.bullet)) {
				printfDx("あいうえお\n");
				player.bullet.flag = false;
			}
		}
	}*/

	//UFOの処理
	ufo.update();
	

	fps.Wait();
}
