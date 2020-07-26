#pragma once
#include <string>
#include <iostream>

namespace jam {
	
	class Scene {

	private:
		static uint8_t _COUNT;
		std::string _sceneName;
		

	public:
		Scene();
		Scene(std::string name);


		void load();
		void update();
		void render();
		void unload();

		inline const std::string getName()const { return _sceneName; }

	};
}