#include "SceneManager.h"

namespace jam {





	void SceneManager::update() {
		//swap scene requested
		if (_nextScene != _currentScene) _dirty = true;
		if (_dirty) {
			_scenes[_currentScene].unload();
			_dirty = false;
			_currentScene = _nextScene;
			_scenes[_currentScene].load();
		}
	}

	void SceneManager::addScene(Scene&& scene) {
		_scenes.push_back(std::move(scene));
		if (_currentScene == -1) _currentScene = 0;
	}

	void SceneManager::addScene(Scene* scene) {
		_scenes.emplace_back(*scene);
		if (_currentScene == -1) _currentScene = 0;
	}
	
	void SceneManager::addScene(const Scene& scene) {
		_scenes.emplace_back(scene);
		if (_currentScene == -1) _currentScene = 0;
	}
	void SceneManager::addScene(Scene scene) {
		_scenes.emplace_back(scene);
		if (_currentScene == -1) _currentScene = 0;
	}


	void SceneManager::setCurrentScene(Scene scene) {
		std::string nextName = scene.getName();
		for (int i = 0; i < _scenes.size(); i++) {
			if (nextName == _scenes[i].getName()) _nextScene = i;
		}
	}
	void SceneManager::setCurrentScene(const Scene& scene) {}
	void SceneManager::setCurrentScene(std::string name) {}
	void SceneManager::setCurrentScene(uint8_t sceneIndex) {}

}