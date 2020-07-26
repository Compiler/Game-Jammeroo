#include "SceneManager.h"

namespace jam {





	void SceneManager::update() {
		//swap scene requested
		if (_nextScene != _currentScene) _dirty = true;
		if (_dirty) {
			if(_nextScene != _currentScene) _scenes[_currentScene]->unload();
			_dirty = false;
			_currentScene = _nextScene;
			_scenes[_currentScene]->load();
		}
	}

	void SceneManager::addScene(Scene&& scene) {
		_scenes.push_back(std::move(std::make_shared<Scene>(scene)));
		if (_currentScene == 255) _currentScene = 0;
	}
	void SceneManager::addScene(std::shared_ptr<Scene> scene) {
		_scenes.emplace_back(scene);
		if (_currentScene == 255) _currentScene = 0;
	}
	void SceneManager::addSceneRef(const Scene& scene) {
		_scenes.emplace_back(std::make_shared<Scene>(scene));
		if (_currentScene == 255) _currentScene = 0;
	}
	void SceneManager::addScene(Scene scene) {
		_scenes.emplace_back(std::make_shared<Scene>(scene));
		if (_currentScene == 255) _currentScene = 0;
	}


	void SceneManager::setCurrentScene(Scene scene) {
		std::string nextName = scene.getName();
		for (int i = 0; i < _scenes.size(); i++) {
			if (nextName == _scenes[i]->getName()) _nextScene = i;
		}
	}
	void SceneManager::setCurrentScene(const Scene& scene) {}
	void SceneManager::setCurrentScene(std::string name) {
		for (int i = 0; i < _scenes.size(); i++) {
			if (name == _scenes[i]->getName()) _nextScene = i;
		}
	}
	void SceneManager::setCurrentScene(uint8_t sceneIndex) {
		if (sceneIndex >= 0 && sceneIndex < _scenes.size()) _currentScene = sceneIndex;
	}

}