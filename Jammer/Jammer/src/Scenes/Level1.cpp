#include "Level1.h"

namespace jam {

	
	void Level1::load() {
		Scene::load();
		m_entityManager->getPlayer()->setPosition(0, 100);
		
		jam::Entity ent = jam::Entity();
		sf::Texture* tex = new sf::Texture();
		
		if (!tex->loadFromFile("res/molten.jpg")) std::cout << "FAILED TO LOAD" << std::endl;
		for (int i = 0; i < 10; i++) {
			ent.init(i*25, 300 + (i*15), 40.0f, 20.0f, tex);
			m_entityManager->addEntity(std::make_shared<jam::Entity>(ent));
		}
		//ent.init(250, 300, 40.0f, 200.0f, tex);
		//m_entityManager->addEntity(std::make_shared<jam::Entity>(ent));




		sf::Texture* empTex = new sf::Texture();
		_testEntity = std::make_shared<jam::Entity>();
		_testEntity->init(100, 200, 100, 100, empTex);

		m_entityManager->addEntity(_testEntity);

		if (!sf::Shader::isAvailable()) {
			std::cout << "LMFAOOO U HAVE NO SHADERS ON UR GPU LMFAOOOOOOO\n";
		}

		if (!_shader.loadFromFile("res/shaders/VertexShader.vert", sf::Shader::Vertex)) {
			std::cout << "failed to load vertexShader.vert\n";
		}
		if (!_shader.loadFromFile("res/shaders/FragmentShader.frag", sf::Shader::Fragment)) {
			std::cout << "failed to load RayMarching.frag\n";
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
		static float xxxx = _testEntity->getPosition().x;
		xxxx += 0.1f;
		_testEntity->render(m_windowRef, &_shader);
		_testEntity->setPosition(xxxx, _testEntity->getPosition().y);
	}

	void Level1::unload() {
		Scene::unload();

	}

}