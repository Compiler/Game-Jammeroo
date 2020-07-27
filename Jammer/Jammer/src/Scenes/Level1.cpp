#include "Level1.h"

namespace jam {

	
	void Level1::load() {
		Scene::load();
		m_entityManager->getPlayer()->setPosition(0, 100);
		
		jam::Entity ent = jam::Entity();
		sf::Texture* tex = new sf::Texture();
		
		if (!tex->loadFromFile("res/molten.jpg")) std::cout << "FAILED TO LOAD" << std::endl;
		for (int i = 0; i < 10; i++) {
			ent.init(i*25, 300 + (i*15), 25.0f, 20.0f, tex);
			m_entityManager->addEntity(std::make_shared<jam::Entity>(ent));
		}
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