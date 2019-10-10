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

		//“G‚ª–¡•û‚É‚ ‚½‚Á‚½‚Æ‚«‚Ìˆ—
		//“G‚ª1‘Ì‚Ì
		//FIXED: “G‚Ìlife‚ğfalse‚É‚µ‚½‚¾‚¯‚¾‚Æ“G‚ÌÀ•W‚ª‹L˜^‚³‚ê‚é‚½‚ßA’e‚à‚µ‚­‚Í–¡•û‚Ì
		//“–‚½‚è”»’è‚ª—LŒø‚É‚È‚é
		//TODO:ã‹L‚ğC³‚·‚éB
		if (enemy.life) {
			if (player.isActorCollision(enemy)) {
				player.life = false;
			}
		}

		//“G‚ª•¡”‘Ì‚Ì
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

			//‰æ–ÊŠO‚Å’e‚ªÁ‚¦‚éˆ—
			if (player.bullet.y <= 0) {
				player.bullet.flag = false;
			}

			//©•ª‚Ì’e‚ª“G‚É‚ ‚½‚Á‚½‚Æ‚«‚Ìˆ—
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

			//©•ª‚Ì’e‚ª“G‚Ì’e‚É“–‚½‚Á‚½‚Ìˆ—
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

			//‰æ–ÊŠOˆ—
			if (enemy.bullet.y >= Window::HEIGHT) {
				enemy.bullet.flag = false;
				count = 0;
			}

			//“G‚Ì’e‚ª–¡•û‚É‚ ‚½‚Á‚½‚Æ‚«‚Ìˆ—
			if (enemy.bullet.isCollision(player)) {
				player.life = false;
			}

			//“G‚Ì’e‚ª–¡•û‚É‚ ‚½‚Á‚½‚Æ‚«‚Ìˆ—
			if (enemy.isBulletCollision(player.bullet)) {
				player.bullet.flag = false;
			}
		}
	}
	

	fps.Wait();
}
