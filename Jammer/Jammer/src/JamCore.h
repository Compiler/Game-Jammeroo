#pragma once
#include <stdint.h>
#include <SFML/Graphics.hpp>
#include <Scenes/SceneManager.h>
#include <Entities/EntityManager.h>
#include <memory>
#include <Scenes/Scene.h>
#include <Scenes/Level1.h>
#include <Collision/CollisionSystem.h>

namespace jam {
	

	class JamCore {


	private:
		std::unique_ptr<SceneManager>  _manager = std::make_unique<SceneManager>();
		EntityManager* _entityManager = new EntityManager();
		sf::RenderWindow* _window;
		sf::View _view;

	public:

		JamCore() { std::cout << "pogu"; };

		uint8_t state;
		void init();
		void update();
		void render();
		void unload();
		int operator()();

	};
}