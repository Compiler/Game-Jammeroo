#include "Level1.h"

namespace jam {

	
	void Level1::load() {
		Scene::load();

	}

	void Level1::update() {
		Scene::update();

	}

	void Level1::render() {
		Scene::render();
		static sf::CircleShape shape(100.f);
		shape.setFillColor(sf::Color::Blue);

		m_windowRef->draw(shape);
		m_windowRef->display();
	}

	void Level1::unload() {
		Scene::unload();

	}

}