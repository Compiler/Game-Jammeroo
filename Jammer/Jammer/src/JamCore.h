#pragma once
#include <stdint.h>
#include <SFML/Graphics.hpp>
#include <Scenes/SceneManager.h>
#include <Entities/EntityManager.h>
#include <memory>
#include <Scenes/Scene.h>
#include <Scenes/Level1.h>
#include <Physics/Collision/CollisionSystem.h>
#include <Tilemap/Tilemap.h>
#include <Tilemap/Tileset.h>
namespace jam {
	

	class JamCore {


	private:
		std::unique_ptr<SceneManager>  _manager = std::make_unique<SceneManager>();
		sf::RenderWindow* _window;
		sf::View _view;
		jam::Tilemap tm;
		jam::Tileset ts;

		void populateEvents(sf::Event event);

	public:

		static float deltaTime;

		JamCore() { std::cout << "pogu" << std::endl; };

		void pep_init() {
			std::vector<std::string> v = { "res/tilemap/pogmap_ground.csv", "res/tilemap/pogmap_water.csv" };
			tm = jam::Tilemap(v);
			//tileset destructor being called here?
			std::cout << "before Tileset constructor" << std::endl;
			ts = jam::Tileset("res/tilemap/pogsheet.json");  //calls Tileset constructor??
			std::cout <<  "end of pep_init" << std::endl;

		}
		void pep_render() {
			static sf::CircleShape shape(100.f);
			shape.setFillColor(sf::Color::Yellow);
			shape.setPosition(-100, -100);
			static sf::Vector2f cursor(0.0f, 0.0f);
			static sf::Vector2i size(16, 16);
			unsigned int column = 0;
			for (auto layer : tm.getDataVector()){
				for (auto tile_id : layer.getCSVData()) {
					ts.tiles[tile_id].setPosition(cursor.x, cursor.y);
					ts.tiles[tile_id].render(_window);
					cursor.x += size.x;
					if (column % 20 == 0) {
						cursor.y += size.y;
						cursor.x = 0;
					}
				}
			}
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