#include "Game.h"

#include "Define.h"
#include "KeyManager.h"

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
	wall.init(500, 400);


	//enemy.start();
	//enemy.paint(100, 100);
}

void Game::update(){
	fps.Update();
	fps.Draw();

	inputKey();
	//DrawBox(0, 430, Window::WIDTH, Window::HEIGHT, GetColor(0, 0, 0), TRUE);

	
	wall.update();


	if (player.life) {
		player.update();

		if (key[KEY_INPUT_LEFT] >= 1) {
			player.x -= player.xspeed;
		}

		if (key[KEY_INPUT_RIGHT] >= 1) {
			player.x += player.xspeed;
		}

		//“G‚ª–¡•û‚É‚ ‚½‚Á‚½‚Æ‚«‚Ìˆ—
		//FIXED: “G‚Ìlife‚ğfalse‚É‚µ‚½‚¾‚¯‚¾‚Æ“G‚ÌÀ•W‚ª‹L˜^‚³‚ê‚é‚½‚ßA
		//		 ’e‚à‚µ‚­‚Í–¡•û‚Ì“–‚½‚è”»’è‚ª—LŒø‚É‚È‚é
		//TODO:ã‹L‚ğC³‚·‚éB
		//“G‚ª•¡”‘Ì‚Ì
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

			//‰æ–ÊŠO‚Å’e‚ªÁ‚¦‚éˆ—
			if (player.bullet.y <= 0) {
				player.bullet.flag = false;
			}

			//UFO‚É‚ ‚½‚Á‚½‚Æ‚«‚Ìˆ—
			if (player.bullet.isCollision(ufo)) {
				if (ufo.life) {
					//printfDx("UFO::HIT!!\n");
					ufo.life = false;
					player.bullet.flag = false;
				}
			}

			//©•ª‚Ì’e‚ª“G‚É‚ ‚½‚Á‚½‚Æ‚«‚Ìˆ—(•¡”)
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

			//’e‚ªƒuƒƒbƒN‚É‚ ‚½‚Á‚½‚Æ‚«‚Ìˆ—
			if (block.getLife()) {
				if(block.collision(player.bullet.x, player.bullet.y, player.bullet.width, player.height)) {
					//printfDx("aaaaa\n");
					block++;
					player.bullet.flag = false;
				}
			}

			//’e‚ªƒuƒƒbƒN‚Ì‰ò‚É‚ ‚½‚Á‚½‚Æ‚«‚Ìˆ—
			if (wall.hitTest(player.bullet.x, player.bullet.y, player.bullet.width, player.bullet.height)) {
				player.bullet.flag = false;
			}
		}
	}

	//alien.update();

	
	enemys.shotFlag();
	for (int i = 0; i < Enemys::h; i++) {
		for (int j = 0; j < Enemys::w; j++) {
			if (enemys.enemys[i][j].life) {
				enemys.enemys[i][j].draw();
				enemys.enemys[i][j].move();

				//“G‚ÌÜ‚è•Ô‚µˆ—
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

				//“G‚ª•Ç‚É‚ ‚½‚Á‚½‚Æ‚«‚Ìˆ—
				if (enemys.enemys[i][j].life) {
					wall.ehitTest(enemys.enemys[i][j].x, enemys.enemys[i][j].y, enemys.enemys[i][j].width, enemys.enemys[i][j].height);		
				}

				if (enemys.enemys[i][j].shotflag) {
					//“G‚Ì’e‚ª¶¬‚³‚ê‚éˆ—
					if (enemys.enemys[i][j].bullet.flag == false) {
						//enemys.enemys[i][j].bullet.flag = true;
						enemys.enemys[i][j].bullet.create(enemys.enemys[i][j].x, enemys.enemys[i][j].y);
						//enemys.enemys[i][j].bullet.create(100, 100);
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

						//‰æ–ÊŠOˆ—i‰æ–ÊŠO‚Éo‚½‚ç’e‚ğÁ‚·j
						if (enemys.enemys[i][j].bullet.y >= Window::HEIGHT) {
							enemys.enemys[i][j].bullet.flag = false;
							enemys.enemys[i][j].count = 0;
						}
					}

					//’e‚ª•Ç‚É‚ ‚½‚Á‚½‚Æ‚«‚Ìˆ—
					if (wall.hitTest(enemys.enemys[i][j].bullet.x, enemys.enemys[i][j].bullet.y, enemys.enemys[i][j].bullet.width, enemys.enemys[i][j].bullet.height)) {
						enemys.enemys[i][j].bullet.flag = false;
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

	//UFO‚Ìˆ—
	ufo.update();
	

	fps.Wait();
}
