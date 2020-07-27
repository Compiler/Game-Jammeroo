#pragma once
#include <memory>
#include "Scene.h"
#include <vector>
#include <stdio.h>
namespace jam {
	
	class SceneManager {
	private:
		std::vector<std::shared_ptr<jam::Scene>> _scenes;
		uint8_t _currentScene = 0;
		uint8_t _nextScene = 0;

		bool _dirty = true;
	public:

		SceneManager() = default;


		void update();


		Scene getSceneByName(std::string name) {
			for (int i = 0; i < _scenes.size(); i++) {
				if (name == _scenes[i]->getName()) return *_scenes[i];
			}
		}

		void setCurrentScene(Scene scene);
		void setCurrentScene(const Scene& scene);
		void setCurrentScene(std::string name);
		void setCurrentScene(uint8_t sceneIndex);

		void addScene(Scene&& scene);
		void addScene(std::shared_ptr<Scene> scene);
		void addSceneRef(const Scene& scene);
		void addScene(Scene scene);
		
		inline Scene& getCurrentScene() { return *_scenes[_currentScene]; }
		inline Scene getCurrentSceneIndex(){ return *_scenes[_currentScene]; }
		inline uint8_t getCurrentSceneIndex()const { return _currentScene; }
	};
}