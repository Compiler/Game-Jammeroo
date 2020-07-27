#pragma once
#include <stdint.h>
#include <SFML/Graphics.hpp>
#include <Scenes/SceneManager.h>
#include <Entities/EntityManager.h>
#include <memory>
#include <Scenes/Scene.h>
#include <Scenes/Level1.h>
#include <Physics/Collision/CollisionSystem.h>
namespace jam {
	

	class JamCore {


	private:
		std::unique_ptr<SceneManager>  _manager = std::make_unique<SceneManager>();
		sf::RenderWindow* _window;
		sf::View _view;


		void populateEvents(sf::Event event);

	public:

		static float deltaTime;

		JamCore() { std::cout << "pogu"; };
		void pep_init() {
			
		}
		void pep_update() {
		
		}
		void pep_render() {
			static sf::CircleShape shape(100.f);
			shape.setFillColor(sf::Color::Yellow	);
			shape.setPosition(-100,-100);

			_window->draw(shape);

		}
		uint8_t state;
		void init();
		void update();
		void render();
		void unload();
		int operator()();

	};
}