#include "Scene.h"

namespace jam {
	
	uint8_t Scene::_COUNT = 0;

	Scene::Scene(sf::RenderWindow* window) : m_windowRef(window), _sceneName(std::string("Scene") + std::to_string(_COUNT++)) {}
	Scene::Scene(sf::RenderWindow* window, std::string name) : m_windowRef(window), _sceneName(name) { _COUNT++; }


	void Scene::load() {
	}
	void Scene::update(){
	}
	void Scene::render(){
	}
	void Scene::unload(){
	}
}