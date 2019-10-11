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

		//“G‚ª–¡•û‚É‚ ‚½‚Á‚½‚Æ‚«‚Ìˆ—
		//“G‚ª1‘Ì‚Ì
		//FIXED: “G‚Ìlife‚ğfalse‚É‚µ‚½‚¾‚¯‚¾‚Æ“G‚ÌÀ•W‚ª‹L˜^‚³‚ê‚é‚½‚ßA’e‚à‚µ‚­‚Í–¡•û‚Ì“–‚½‚è”»’è‚ª—LŒø‚É‚È‚é
		//TODO:ã‹L‚ğC³‚·‚éB
		/*if (player.isActorCollision(enemy)) {
			if (enemy.life) {
				player.life = false;
			}
		}*/

		//“G‚ª•¡”‘Ì‚Ì
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

			//‰æ–ÊŠO‚Å’e‚ªÁ‚¦‚éˆ—
			if (player.bullet.y <= 0) {
				player.bullet.flag = false;
			}

			//©•ª‚Ì’e‚ª“G‚É‚ ‚½‚Á‚½‚Æ‚«‚Ìˆ—(•¡”)
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
					//©•ª‚Ì’e‚ª“G‚Ì’e‚É“–‚½‚Á‚½‚Ìˆ—
					if (enemys.enemys[i][j].life) {
						if (player.isBulletCollision(enemys.enemys[i][j].bullet)) {
							printfDx("‚ ‚½‚Á‚½\n");

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

				//“G‚Ì’e‚ª¶¬‚³‚ê‚éˆ—
				if (enemys.enemys[i][j].bullet.flag == false) {
					enemys.enemys[i][j].bullet.flag = true;
					enemys.enemys[i][j].bullet.create(enemys.enemys[i][j].x, enemys.enemys[i][j].y);
				}

				//“G‚Ì’e‚Ìflag‚ªtrue‚Ì‚Ì”»’è
				if (enemys.enemys[i][j].bullet.flag) {
					enemys.enemys[i][j].bullet.draw();
					enemys.enemys[i][j].bullet.y += 10;

					//“G‚Ì’e‚ªƒvƒŒƒCƒ„[‚É‚ ‚½‚Á‚½‚Æ‚«‚Ìˆ—
					if (enemys.enemys[i][j].bullet.isCollision(player)) {
						if (player.life) {
							//printfDx("Bullet::isHit\n");
							//player.life = false;
						}
					}


					//‰æ–ÊŠOˆ—
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

			//‰æ–ÊŠOˆ—
			if (enemy.bullet.y >= Window::HEIGHT) {
				enemy.bullet.flag = false;
				count = 0;
			}

			//“G‚Ì’e‚ª–¡•û‚É‚ ‚½‚Á‚½‚Æ‚«‚Ìˆ—
			if (enemy.bullet.isCollision(player)) {
				//player.life = false;
			}

			//“G‚Ì’e‚ª–¡•û‚É‚ ‚½‚Á‚½‚Æ‚«‚Ìˆ—
			/*if (enemy.isBulletCollision(player.bullet)) {
				printfDx("‚ ‚¢‚¤‚¦‚¨\n");
				player.bullet.flag = false;
			}
		}
	}*/
	

	fps.Wait();
}
