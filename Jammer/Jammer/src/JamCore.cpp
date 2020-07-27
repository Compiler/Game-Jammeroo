#include "JamCore.h"


namespace jam {


	float JamCore::deltaTime;

	void JamCore::init() {
		_window = new sf::RenderWindow(sf::VideoMode(400, 400), "POGU");
		jam::Scene scene1(_window, std::string("Scene 1"));
		std::shared_ptr<jam::Level1> level1 = std::make_shared<jam::Level1>(_window);
		static bool flip;

		std::shared_ptr<jam::Player> player = std::make_shared<jam::Player>(sf::Vector2f(50, 50), sf::Rect<float>(50, 50, 50, 50));
		_entityManager->addPlayer(*player);
		_manager->addScene(scene1);
		_manager->addScene(level1);
		_manager->setCurrentScene("Scene 1");


		jam::Entity ent = jam::Entity();
		sf::Texture* tex = new sf::Texture();
		if (!tex->loadFromFile("res/molten.jpg")) std::cout << "FAILED TO LOAD" << std::endl;
		ent.setTexture(tex, 50, 100);
		_entityManager->addEntity(std::make_shared<jam::Entity>(ent));
		ent.setSize(sf::Vector2f(10.0f, 20.0f));
		_view = sf::View(sf::FloatRect(_entityManager->getPlayer()->getPosition(), sf::Vector2f(400.0f, 400.0f)));




		CollisionSystem::init(_entityManager->getEntities());
	}

	void JamCore::update() {
		static sf::Clock clock = sf::Clock();

		_manager->update();
		_entityManager->update();
		_manager->getCurrentScene().update();
		_view.setCenter(_entityManager->getPlayer()->getPosition());
		_window->setView(_view);
		
		deltaTime = clock.restart().asSeconds();
		std::cout << deltaTime << std::endl;

		sf::Event event;
		static bool flip;
		while (_window->pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				_window->close();
			if (event.type == sf::Event::KeyReleased) {
				if (event.key.code == sf::Keyboard::E) {
					flip = !flip;
				}
			}
			if (event.type == sf::Event::Resized) {
				// update the view to the new size of the window
				sf::FloatRect visibleArea(0.f, 0.f, event.size.width, event.size.height);
				_window->setView(sf::View(visibleArea));
			}
			if (!flip)_manager->setCurrentScene("Scene 1");
			else _manager->setCurrentScene("Level1 Scene");

		}

	}

	void JamCore::render() {


		_window->clear();
		static sf::CircleShape shape(10.f);
		shape.setFillColor(sf::Color::Red);
		_window->draw(shape);

		static sf::CircleShape shape1(10.f);
		shape1.setPosition(sf::Vector2f(50.0f, 10.0f));
		shape1.setFillColor(sf::Color::Magenta);
		_window->draw(shape1);
		_manager->getCurrentScene().render();
		_entityManager->render(_window);
		_window->display();

	}


	void unload() {
	
	}


	int JamCore::operator()() {
		init();
		while (state != 16) {
			update();
			render();
		}
		return 0;
	}


}