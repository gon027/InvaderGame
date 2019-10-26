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

		//“G‚ª–¡•û‚É‚ ‚½‚Á‚½‚Æ‚«‚Ìˆ—
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

			//UFO‚É‚ ‚½‚Á‚½‚Æ‚«‚Ìˆ—
			if (player.bullet.isCollision(ufo)) {
				if (ufo.life) {
					//printfDx("UFO::HIT!!\n");
					ufo.life = false;
					player.bullet.life = false;
				}
			}

			//©•ª‚Ì’e‚ª“G‚É‚ ‚½‚Á‚½‚Æ‚«‚Ìˆ—
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
					//©•ª‚Ì’e‚ª“G‚Ì’e‚É“–‚½‚Á‚½‚Ìˆ—
					if (enemys.enemys[i][j].life) {
						if (player.isBulletCollision(enemys.enemys[i][j].bullet)) {
							//printfDx("‚ ‚½‚Á‚½\n");
							player.bullet.life = false;
							enemys.enemys[i][j].bullet.life = false;
							count = 0;
						}
					}
				}
			}

			//’e‚ªƒuƒƒbƒN‚Ì‰ò‚É‚ ‚½‚Á‚½‚Æ‚«‚Ìˆ—
			if (wall.hitTest(player.bullet.x, player.bullet.y, player.bullet.width, player.bullet.height)) {
				player.bullet.life = false;
			}
		}
	}

	//alien.update();

	enemys.ableBullet();
	for (int i = 0; i < Enemys::h; i++) {
		for (int j = 0; j < Enemys::w; j++) {
			//“G‚ª¶‚«‚Ä‚¢‚é‚Æ‚«
			if (enemys.enemys[i][j].life) {
				enemys.enemys[i][j].draw();
				//enemys.enemys[i][j].move();

				//“G‚ÌÜ‚è•Ô‚µˆ—
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

				//“G‚ª•Ç‚É‚ ‚½‚Á‚½‚Æ‚«‚Ìˆ—
				if (enemys.enemys[i][j].life) {
					wall.ehitTest(enemys.enemys[i][j].x, enemys.enemys[i][j].y, enemys.enemys[i][j].width, enemys.enemys[i][j].height);		
				}

				if (enemys.enemys[i][j].shotflag) {
					//“G‚Ì’e‚ª¶¬‚³‚ê‚éˆ—
					if (enemys.enemys[i][j].bullet.isLife() == false) {
						enemys.enemys[i][j].bullet.init(enemys.enemys[i][j].x + (enemys.enemys[i][j].width / 2), enemys.enemys[i][j].y + enemys.enemys[i][j].height, 1, GetColor(0, 0, 255));
					}

					//“G‚Ì’e‚Ìlife‚ªtrue‚Ì‚Ì”»’è
					if (enemys.enemys[i][j].bullet.life) {
						enemys.enemys[i][j].bullet.draw();

						//“G‚Ì’e‚ªƒvƒŒƒCƒ„[‚É‚ ‚½‚Á‚½‚Æ‚«‚Ìˆ—
						if (enemys.enemys[i][j].bullet.isCollision(player)) {
							if (player.life) {
								//printfDx("Bullet::isHit\n");
								//player.life = false;
							}
						}

						//‰æ–ÊŠOˆ—i‰æ–ÊŠO‚ÉƒJƒEƒ“ƒg‚ğ0‚É‚·‚éj
						if (enemys.enemys[i][j].bullet.isLife() == false) {
							enemys.enemys[i][j].count = 0;
						}
					}

					//’e‚ª•Ç‚É‚ ‚½‚Á‚½‚Æ‚«‚Ìˆ—
					if (wall.hitTest(enemys.enemys[i][j].bullet.x, enemys.enemys[i][j].bullet.y, enemys.enemys[i][j].bullet.width, enemys.enemys[i][j].bullet.height)) {
						enemys.enemys[i][j].bullet.life = false;
					}
				}
			}
		}
	}

	//•Ç‚Ìˆ—
	wall.update();
	
	//UFO‚Ìˆ—
	ufo.update();
	
	fps.Wait();
}
