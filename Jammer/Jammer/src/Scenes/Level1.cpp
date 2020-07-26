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
		static sf::Text text;
		text.setString(this->getName());
		text.setFillColor(sf::Color::Red);
		text.setStyle(sf::Text::Bold | sf::Text::Underlined);
		m_windowRef->draw(shape);
		m_windowRef->draw(text);
	}

	void Level1::unload() {
		Scene::unload();

	}

}