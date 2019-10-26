#include "BackGround.h"

#include "DxLib.h"

BackGround::BackGround(int _x, int _y, const char * _path){
	x = _x;
	y = _y;
	path = _path;
}

void BackGround::setup(){

}

void BackGround::init(int _x, int _y, const char * _path){

}

void BackGround::loadImage(){
	img = LoadGraph(path);
	if (img == -1) {
		printfDx("BackGround::LoadImage_Error");
	}
	printfDx("%d\n", img);
}

void BackGround::draw(){
	int error;
	error = DrawGraph(x, y, img, TRUE);
	if (error != 0) {
		printfDx("BackGround::LoadImage_Error");
	}

	//printfDx("%s\n", path);
}