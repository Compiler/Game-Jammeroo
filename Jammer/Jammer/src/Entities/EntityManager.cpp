#include "EntityManager.h"

namespace jam {


	void EntityManager::addEntity(std::shared_ptr<Entity> e) {
		e->load();
		_entities.push_back(e);
	}


	void EntityManager::update() {
		_player->update();
		for (const auto& e : _entities) {
			e->update();
		}
	}
	void EntityManager::render(sf::RenderWindow* rw){
		_player->render(rw);
		for (const auto& e : _entities) {
			e->render(rw);
		}
	}

}