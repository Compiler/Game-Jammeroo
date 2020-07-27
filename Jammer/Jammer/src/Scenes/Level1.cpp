#include "Level1.h"

namespace jam {

	
	void Level1::load() {
		Scene::load();

	}

	void Level1::update() {
		Scene::update();

	}

	void Level1::render(sf::RenderWindow* window) {
		Scene::render(window);
		static sf::CircleShape shape(100.f);
		shape.setFillColor(sf::Color::Blue);
		static sf::Text text;
		static sf::Font font;
		if (!font.loadFromFile("res/Raleway-Regular.ttf")) {
			std::cout << "Failed to load hahahaha\n";
		}
		text.setFont(font);
		text.setCharacterSize(16);
		text.setPosition(50,50);
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