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

		//敵が味方にあたったときの処理
		//敵が1体の時
		//FIXED: 敵のlifeをfalseにしただけだと敵の座標が記録されるため、弾もしくは味方の
		//当たり判定が有効になる
		//TODO:上記を修正する。
		if (enemy.life) {
			if (player.isActorCollision(enemy)) {
				player.life = false;
			}
		}

		//敵が複数体の時
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

			//画面外で弾が消える処理
			if (player.bullet.y <= 0) {
				player.bullet.flag = false;
			}

			//自分の弾が敵にあたったときの処理
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

			//自分の弾が敵の弾に当たった時の処理
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

			//画面外処理
			if (enemy.bullet.y >= Window::HEIGHT) {
				enemy.bullet.flag = false;
				count = 0;
			}

			//敵の弾が味方にあたったときの処理
			if (enemy.bullet.isCollision(player)) {
				player.life = false;
			}

			//敵の弾が味方にあたったときの処理
			if (enemy.isBulletCollision(player.bullet)) {
				player.bullet.flag = false;
			}
		}
	}
	

	fps.Wait();
}
