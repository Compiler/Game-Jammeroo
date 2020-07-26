#include "Scene.h"

namespace jam {
	
	uint8_t Scene::_COUNT = 0;

	Scene::Scene() :_sceneName(std::string("Scene") + std::to_string(_COUNT++)) {}
	Scene::Scene(std::string name) : _sceneName(name) { _COUNT++; }


	void Scene::load() {
		std::cout << _sceneName.c_str() << ": Load()\n";
	}
	void Scene::update(){
		std::cout << _sceneName << ": Update()\n";
	}
	void Scene::render(){
		std::cout << _sceneName << ": Render()\n";
	}
	void Scene::unload(){
		std::cout << _sceneName << ": Unload()\n";
	}
}