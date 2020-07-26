#pragma once
#include "Scene.h"
#include <vector>
#include <stdio.h>
namespace jam {
	
	class SceneManager {
	private:
		std::vector<jam::Scene> _scenes;
		uint8_t _currentScene = -1;
		uint8_t _nextScene = -1;

		bool _dirty = 0;
	public:

		SceneManager() = default;


		void update();

		void setCurrentScene(Scene scene);
		void setCurrentScene(const Scene& scene);
		void setCurrentScene(std::string name);
		void setCurrentScene(uint8_t sceneIndex);

		void addScene(Scene&& scene);
		void addScene(const Scene& scene);
		void addScene(Scene scene);
		void addScene(Scene* scene);
		
		inline Scene& getCurrentScene() { return _scenes[_currentScene]; }
		inline Scene getCurrentSceneIndex(){ return _scenes[_currentScene]; }
		inline uint8_t getCurrentSceneIndex()const { return _currentScene; }
	};
}