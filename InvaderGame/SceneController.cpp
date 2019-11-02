#include "SceneController.h"

#include "TitleScene.h"
#include "Game.h"

BaseScene* SceneController::scene = nullptr;

SceneController::SceneController(){
	scene = new TitleScene();
}

SceneController::~SceneController(){
	delete scene;
}

void SceneController::setup(){
	scene->setup();
}

void SceneController::update(){
	scene->update();
}