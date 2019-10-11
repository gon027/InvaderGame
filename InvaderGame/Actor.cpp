#include "Actor.h"

#include "Bullet.h"

bool Actor::isActorCollision(Actor& actor){
	if (this->x <= actor.x + actor.width 
		&& this->x + width >= actor.x
		&& this->y <= actor.y + actor.height
		&& this->y + height >= actor.y) {
		//printfDx("isActorCollision\n");
		return true;
	}

	return false;
}

bool Actor::isBulletCollision(Bullet& bullet){
	if (x <= bullet.x + bullet.width
		&& x + width >= bullet.x
		&& y <= bullet.y + bullet.height
		&& y + height >= bullet.y) {
		//printfDx("isBulletCollision\n");
		return true;
	}

	return false;
}

void Actor::LoadActorImage(const char* path) {
	//printfDx("ACtor::LoadActorImage\n");
	this->img = LoadGraph(path);
	if (img == -1) {
		printfDx("LOADIMAGE_ERROR\n");
	}

	GetGraphSize(this->img, &width, &height);
}

void Actor::DrawImage(int x, int y){
	//printfDx("ACtor::DrawImage\n");
	int error;
	error = DrawGraph(x, y, img, TRUE);
	if (error != 0) {
		printfDx("DRAWIMAGE_ERROR\n");
	}
}
