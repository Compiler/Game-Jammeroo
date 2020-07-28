#pragma once
#include <stdint.h>
#include <SFML/Graphics.hpp>
#include <Scenes/SceneManager.h>
#include <Entities/EntityManager.h>
#include <memory>
#include <Scenes/Scene.h>
#include <Scenes/Level1.h>
#include <Scenes/Level2.h>
#include <Physics/Collision/CollisionSystem.h>
#include <Tilemap/Tilemap.h>
#include <Tilemap/Tileset.h>
#include <vector>
namespace jam {
	

	class JamCore {


	private:
		std::unique_ptr<SceneManager>  _manager = std::make_unique<SceneManager>();
		sf::RenderWindow* _window;
		sf::View _view;
		jam::Tilemap* tm;
		jam::Tileset* ts;
		void populateEvents(sf::Event event);

	public:

		static float deltaTime;

		// better message, idiot
		JamCore() { std::cout << "JamCore constructed." << std::endl; };

		void pep_init() {
				
//			std::shared_ptr<Tile> t = std::make_unique<Tile>(Tile());
//			t->init(0, 0, 16, 16);
//			sf::Texture* tex = new sf::Texture();
//			tex->loadFromFile("res/molten.jpg");
//			t->setTexture(tex);
//			_manager->getSceneByName("Level1 Scene").getEntityManager()->addEntity(t);
			std::vector<std::string> v = { "res/tilemap/pogmap_ground.csv", "res/tilemap/pogmap_water.csv" };
			tm = new jam::Tilemap(v);
			ts = new jam::Tileset("res/tilemap/pogsheet.json");
			sf::Vector2f cursor = sf::Vector2f(0.0f, 0.0f);
			unsigned int column = 0;
			unsigned int i = 0;
//			for (auto layer : tm->getDataVector()) {
//				cursor.y = 0;
				for (auto tile_id : tm->getDataVector()[0].getCSVData()) {
					column += 1;
					cursor.x = ts->tilesize.x * (column - 1);
					sf::IntRect texture_rect = ts->tiles[tile_id];
					std::cout << "[" << texture_rect.left << ", " << texture_rect.top << "] ";
					Tile t = Tile(cursor.x, cursor.y, texture_rect.width, texture_rect.height, ts->texture, texture_rect.left, texture_rect.top);
					_manager->getSceneByName("Level2 Scene").getEntityManager()->addEntity(std::make_shared<Tile>(t));
					if (column == 20) {
						cursor.y += ts->tilesize.y;
						column = 0;
						std::cout << std::endl;
					}
//				}
			}
		}

		uint8_t state;
		void init();
		void update();
		void render();
		void unload();
		int operator()();

	};
}