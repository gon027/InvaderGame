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

void SceneController::changeScene(SceneStatus _status){
	printfDx("SceneController::changeScene");

	if (scene != nullptr) {
		delete scene;
	}

	switch (_status){
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