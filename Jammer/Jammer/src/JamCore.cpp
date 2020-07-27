#include "JamCore.h"
#include <Input/InputManager.h>
namespace jam {

	void populateEvents(sf::Event event);

	float JamCore::deltaTime;

	void JamCore::init() {
		pep_init();
		_window = new sf::RenderWindow(sf::VideoMode(400, 400), "POGU");
		jam::Scene scene1(_window, std::string("Scene 1"));
		std::shared_ptr<jam::Level1> level1 = std::make_shared<jam::Level1>(_window);
		static bool flip;

		sf::Vector2f playerPos = sf::Vector2f(50, 50);
		sf::Vector2f playerSize = sf::Vector2f(10.0f, 20.0f);

		std::shared_ptr<jam::Player> player = std::make_shared<jam::Player>();
		player->init(10, -10, 10, 20);
		level1->getEntityManager()->addPlayer(*player);
		scene1.getEntityManager()->addPlayer(*player);
		_manager->addScene(scene1);
		_manager->addScene(level1);
		_manager->setCurrentScene(level1->getName());

		jam::Entity ent = jam::Entity();
		sf::Texture* tex = new sf::Texture();
		if (!tex->loadFromFile("res/molten.jpg")) std::cout << "FAILED TO LOAD" << std::endl;
		ent.init(0, -10, 10, 20, tex);
		scene1.getEntityManager()->addEntity(std::make_shared<jam::Entity>(ent));
		_view = sf::View(sf::FloatRect(_manager->getCurrentScene().getEntityManager()->getPlayer()->getPosition(), sf::Vector2f(400.0f, 400.0f)));
		level1->load();


		CollisionSystem::init(scene1.getEntityManager()->getEntities());
	}

	void JamCore::update() {
		static sf::Clock clock = sf::Clock();

		_manager->update();
		_manager->getCurrentScene().getEntityManager()->update();
		_manager->getCurrentScene().update();
		_view.setCenter(_manager->getCurrentScene().getEntityManager()->getPlayer()->getPosition());
		_window->setView(_view);
		
		deltaTime = clock.restart().asSeconds();
		InputManager::clear();

		sf::Event event;
		static bool flip;
		while (_window->pollEvent(event)) {
			populateEvents(event);
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
			if (flip) {
				CollisionSystem::init(_manager->getSceneByName("Scene 1").getEntityManager()->getEntities());
				_manager->setCurrentScene("Scene 1");
			} else {
				CollisionSystem::init(_manager->getSceneByName("Level1 Scene").getEntityManager()->getEntities());
				_manager->setCurrentScene("Level1 Scene");
			}
		}


	}

	void JamCore::render() {


		_window->clear();
		_manager->getCurrentScene().render(_window);
		_manager->getCurrentScene().getEntityManager()->render(_window);
		pep_render();
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



	void JamCore::populateEvents(sf::Event event) {
		if(event.type == sf::Event::MouseMoved) {
			;
			InputManager::addMousePosition(sf::Mouse::getPosition(*_window).x - _window->getSize().x / 2.0f, sf::Mouse::getPosition(*_window).y + _window->getSize().y / 4.0f);
		}
		if (event.type == sf::Event::MouseButtonPressed) {
			if (event.key.code == sf::Mouse::Left)InputManager::addMousePress(jam::MouseKeys::MOUSE_BUTTON_LEFT);
			if (event.key.code == sf::Mouse::Right)InputManager::addMousePress(jam::MouseKeys::MOUSE_BUTTON_RIGHT);
		}
		if (event.type == sf::Event::MouseButtonReleased) {
			if (event.key.code == sf::Mouse::Left)InputManager::addMouseRelease(jam::MouseKeys::MOUSE_BUTTON_LEFT);
			if (event.key.code == sf::Mouse::Right)InputManager::addMouseRelease(jam::MouseKeys::MOUSE_BUTTON_RIGHT);
		}
		if(event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Space) InputManager::addKeyPress(jam::KeyCodes::KEY_SPACE);
			if (event.key.code == sf::Keyboard::Up) InputManager::addKeyPress(jam::KeyCodes::KEY_UP);
			if (event.key.code == sf::Keyboard::Down) InputManager::addKeyPress(jam::KeyCodes::KEY_DOWN);
			if (event.key.code == sf::Keyboard::Left) InputManager::addKeyPress(jam::KeyCodes::KEY_LEFT);
			if (event.key.code == sf::Keyboard::Right) InputManager::addKeyPress(jam::KeyCodes::KEY_RIGHT);
			if (event.key.code == sf::Keyboard::A) InputManager::addKeyPress(jam::KeyCodes::KEY_A);
			if (event.key.code == sf::Keyboard::B) InputManager::addKeyPress(jam::KeyCodes::KEY_B);
			if (event.key.code == sf::Keyboard::C) InputManager::addKeyPress(jam::KeyCodes::KEY_C);
			if (event.key.code == sf::Keyboard::D) InputManager::addKeyPress(jam::KeyCodes::KEY_D);
			if (event.key.code == sf::Keyboard::E) InputManager::addKeyPress(jam::KeyCodes::KEY_E);
			if (event.key.code == sf::Keyboard::F) InputManager::addKeyPress(jam::KeyCodes::KEY_F);
			if (event.key.code == sf::Keyboard::G) InputManager::addKeyPress(jam::KeyCodes::KEY_G);
			if (event.key.code == sf::Keyboard::H) InputManager::addKeyPress(jam::KeyCodes::KEY_H);
			if (event.key.code == sf::Keyboard::I) InputManager::addKeyPress(jam::KeyCodes::KEY_I);
			if (event.key.code == sf::Keyboard::J) InputManager::addKeyPress(jam::KeyCodes::KEY_J);
			if (event.key.code == sf::Keyboard::K) InputManager::addKeyPress(jam::KeyCodes::KEY_K);
			if (event.key.code == sf::Keyboard::L) InputManager::addKeyPress(jam::KeyCodes::KEY_L);
			if (event.key.code == sf::Keyboard::M) InputManager::addKeyPress(jam::KeyCodes::KEY_M);
			if (event.key.code == sf::Keyboard::N) InputManager::addKeyPress(jam::KeyCodes::KEY_N);
			if (event.key.code == sf::Keyboard::O) InputManager::addKeyPress(jam::KeyCodes::KEY_O);
			if (event.key.code == sf::Keyboard::P) InputManager::addKeyPress(jam::KeyCodes::KEY_P);
			if (event.key.code == sf::Keyboard::Q) InputManager::addKeyPress(jam::KeyCodes::KEY_Q);
			if (event.key.code == sf::Keyboard::R) InputManager::addKeyPress(jam::KeyCodes::KEY_R);
			if (event.key.code == sf::Keyboard::S) InputManager::addKeyPress(jam::KeyCodes::KEY_S);
			if (event.key.code == sf::Keyboard::T) InputManager::addKeyPress(jam::KeyCodes::KEY_T);
			if (event.key.code == sf::Keyboard::U) InputManager::addKeyPress(jam::KeyCodes::KEY_U);
			if (event.key.code == sf::Keyboard::V) InputManager::addKeyPress(jam::KeyCodes::KEY_V);
			if (event.key.code == sf::Keyboard::W) InputManager::addKeyPress(jam::KeyCodes::KEY_W);
			if (event.key.code == sf::Keyboard::X) InputManager::addKeyPress(jam::KeyCodes::KEY_X);
			if (event.key.code == sf::Keyboard::Y) InputManager::addKeyPress(jam::KeyCodes::KEY_Y);
			if (event.key.code == sf::Keyboard::Z) InputManager::addKeyPress(jam::KeyCodes::KEY_Z);
		}
		if (event.type == sf::Event::KeyReleased) {
			if (event.key.code == sf::Keyboard::Space) InputManager::addKeyRelease(jam::KeyCodes::KEY_SPACE);
			if (event.key.code == sf::Keyboard::Up) InputManager::addKeyRelease(jam::KeyCodes::KEY_UP);
			if (event.key.code == sf::Keyboard::Down) InputManager::addKeyRelease(jam::KeyCodes::KEY_DOWN);
			if (event.key.code == sf::Keyboard::Left) InputManager::addKeyRelease(jam::KeyCodes::KEY_LEFT);
			if (event.key.code == sf::Keyboard::Right) InputManager::addKeyRelease(jam::KeyCodes::KEY_RIGHT);
			if (event.key.code == sf::Keyboard::A) InputManager::addKeyRelease(jam::KeyCodes::KEY_A);
			if (event.key.code == sf::Keyboard::B) InputManager::addKeyRelease(jam::KeyCodes::KEY_B);
			if (event.key.code == sf::Keyboard::C) InputManager::addKeyRelease(jam::KeyCodes::KEY_C);
			if (event.key.code == sf::Keyboard::D) InputManager::addKeyRelease(jam::KeyCodes::KEY_D);
			if (event.key.code == sf::Keyboard::E) InputManager::addKeyRelease(jam::KeyCodes::KEY_E);
			if (event.key.code == sf::Keyboard::F) InputManager::addKeyRelease(jam::KeyCodes::KEY_F);
			if (event.key.code == sf::Keyboard::G) InputManager::addKeyRelease(jam::KeyCodes::KEY_G);
			if (event.key.code == sf::Keyboard::H) InputManager::addKeyRelease(jam::KeyCodes::KEY_H);
			if (event.key.code == sf::Keyboard::I) InputManager::addKeyRelease(jam::KeyCodes::KEY_I);
			if (event.key.code == sf::Keyboard::J) InputManager::addKeyRelease(jam::KeyCodes::KEY_J);
			if (event.key.code == sf::Keyboard::K) InputManager::addKeyRelease(jam::KeyCodes::KEY_K);
			if (event.key.code == sf::Keyboard::L) InputManager::addKeyRelease(jam::KeyCodes::KEY_L);
			if (event.key.code == sf::Keyboard::M) InputManager::addKeyRelease(jam::KeyCodes::KEY_M);
			if (event.key.code == sf::Keyboard::N) InputManager::addKeyRelease(jam::KeyCodes::KEY_N);
			if (event.key.code == sf::Keyboard::O) InputManager::addKeyRelease(jam::KeyCodes::KEY_O);
			if (event.key.code == sf::Keyboard::P) InputManager::addKeyRelease(jam::KeyCodes::KEY_P);
			if (event.key.code == sf::Keyboard::Q) InputManager::addKeyRelease(jam::KeyCodes::KEY_Q);
			if (event.key.code == sf::Keyboard::R) InputManager::addKeyRelease(jam::KeyCodes::KEY_R);
			if (event.key.code == sf::Keyboard::S) InputManager::addKeyRelease(jam::KeyCodes::KEY_S);
			if (event.key.code == sf::Keyboard::T) InputManager::addKeyRelease(jam::KeyCodes::KEY_T);
			if (event.key.code == sf::Keyboard::U) InputManager::addKeyRelease(jam::KeyCodes::KEY_U);
			if (event.key.code == sf::Keyboard::V) InputManager::addKeyRelease(jam::KeyCodes::KEY_V);
			if (event.key.code == sf::Keyboard::W) InputManager::addKeyRelease(jam::KeyCodes::KEY_W);
			if (event.key.code == sf::Keyboard::X) InputManager::addKeyRelease(jam::KeyCodes::KEY_X);
			if (event.key.code == sf::Keyboard::Y) InputManager::addKeyRelease(jam::KeyCodes::KEY_Y);
			if (event.key.code == sf::Keyboard::Z) InputManager::addKeyRelease(jam::KeyCodes::KEY_Z);
		}
	}
}