#include "SceneController.h"

#include "TitleScene.h"
#include "Game.h"


SceneController::SceneController(){
	status = Title;
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

void SceneController::changeScene(Status _status){
	printfDx("SceneController::changeScene");

	status = _status;

	if (scene != nullptr) {
		delete scene;
	}

	switch (status){
	case Title:
		scene = new TitleScene();
		break;
	case GameScene:
		scene = new Game();
		break;
	default:
		break;
	}
}