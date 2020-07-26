#pragma once
#include "Scene.h"
//extends scene

namespace jam {

	class Level1 : public Scene {
	
	private:

	public:
		Level1() = delete;
		Level1(sf::RenderWindow* window):Scene(window, "Level1 Scene") {}

		void load()override;
		void update()override;
		void render()override;
		void unload()override;
	};

}