#include "Player.h"
#include "Entity.h"
#include <JamCore.h>
#include <Collision/CollisionSystem.h>
#include <Input/InputManager.h>
namespace jam {
	Player::Player(const sf::Vector2f& p, const sf::Rect<float>& cb, float w) : _weight(w), Entity(p, cb) { uniqueID = COUNT++; };
	Player::Player(const sf::Vector2f& p, const sf::Rect<float>& cb, const sf::Texture& t, float w) : _weight(w), Entity(p, cb){ m_sprite = sf::Sprite(t);  uniqueID = COUNT++;
	};
	Player::Player(const sf::Vector2f& p, const sf::Rect<float>& cb, sf::Sprite s, float w) :_weight(w), Entity(p, cb) { uniqueID = COUNT++; };

	void Player::move(const sf::Vector2f& movement) {
		sf::Vector2f projectedPosition = m_pos;
		projectedPosition += movement;

		m_pos = CollisionSystem::adjustProjectedPosition((Entity)*this, projectedPosition);
	}

	void Player::update() {
		/*
		TODO:

		- Handle input and move based on input

		*/

		// input


		if (jam::InputManager::isKeyPressed(jam::KeyCodes::KEY_A)) move(sf::Vector2f(-50.0f,  0.0f)*jam::JamCore::deltaTime);
		if (jam::InputManager::isKeyPressed(jam::KeyCodes::KEY_D)) move(sf::Vector2f( 50.0f,  0.0f)*jam::JamCore::deltaTime);
		if (jam::InputManager::isKeyPressed(jam::KeyCodes::KEY_S)) move(sf::Vector2f( 0.0f,  50.0f)*jam::JamCore::deltaTime);
		if (jam::InputManager::isKeyPressed(jam::KeyCodes::KEY_W)) move(sf::Vector2f( 0.0f, -50.0f)*jam::JamCore::deltaTime);

		//move(_GRAVITY, entities);
		//_sprite.setPosition(m_pos);

	}


	void Player::render(sf::RenderWindow* rw) {
		/*
		m_sprite.setPosition(this->getPosition());
		rw->draw(m_sprite);
		*/
		static sf::RectangleShape shape(sf::Vector2f(10.0f, 20.0f));
		shape.setFillColor(sf::Color::Green);
		shape.setPosition(this->getPosition());
		rw->draw(shape);
	}



}