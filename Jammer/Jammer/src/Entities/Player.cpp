#include "Player.h"
#include "Entity.h"
#include <JamCore.h>
#include <Physics/Collision/CollisionSystem.h>
#include <Input/InputManager.h>
namespace jam {

	void Player::move(const sf::Vector2f& movement) {
		sf::Vector2f projectedPosition = m_position;
		projectedPosition += movement;
		m_position = CollisionSystem::adjustProjectedPosition((Entity)*this, projectedPosition);
	}

	void Player::update() {
		Entity::update();

		if (jam::InputManager::isKeyPressed(jam::KeyCodes::KEY_A)) move(sf::Vector2f(-50.0f,  0.0f)*jam::JamCore::deltaTime);
		if (jam::InputManager::isKeyPressed(jam::KeyCodes::KEY_D)) move(sf::Vector2f( 50.0f,  0.0f)*jam::JamCore::deltaTime);
		if (jam::InputManager::isKeyPressed(jam::KeyCodes::KEY_S)) move(sf::Vector2f( 0.0f,  50.0f)*jam::JamCore::deltaTime);
		if (jam::InputManager::isKeyPressed(jam::KeyCodes::KEY_W)) move(sf::Vector2f( 0.0f, -50.0f)*jam::JamCore::deltaTime);
		if (jam::InputManager::isKeyReleased(jam::KeyCodes::KEY_X))move(sf::Vector2f( .0f, -5000.0f)*jam::JamCore::deltaTime);

		move(sf::Vector2f(0.0f, 70.0f)*jam::JamCore::deltaTime);
	}


	void Player::render(sf::RenderWindow* rw) {
		Entity::render(rw);
		
		static sf::RectangleShape shape(sf::Vector2f(10.0f, 20.0f));
		shape.setFillColor(sf::Color::Green);
		shape.setPosition(this->getPosition());
		rw->draw(shape);
	}



}