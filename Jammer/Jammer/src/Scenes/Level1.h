#pragma once
#include "Scene.h"
#include <UI/Button.h>
//extends scene

namespace jam {

	class Level1 : public Scene {
	
	private:
		sf::Shader _shader;
		std::shared_ptr<Entity> _testEntity;

	public:
		Level1() = delete;
		Level1(sf::RenderWindow* window):Scene(window, "Level1 Scene") {}

		void load()override;
		void update()override;
		void render(sf::RenderWindow* window)override;
		void unload()override;
	};

}