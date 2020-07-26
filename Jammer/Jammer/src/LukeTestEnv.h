#pragma once
#include "Scenes/SceneManager.h"
#include "Scenes/Scene.h"



jam::SceneManager manager;
void init() {

	
	jam::Scene scene1("Scene 1");
	jam::Scene scene2("Scene 2");


	manager.addScene(&scene1);
	manager.addScene(&scene2);
}

void update() {
	manager.update();
	manager.getCurrentScene().update();
}

void render() {
	manager.getCurrentScene().render();
}