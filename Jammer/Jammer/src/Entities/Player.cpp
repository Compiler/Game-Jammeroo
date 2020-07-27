#include "Player.h"
#include "Entity.h"
#include <JamCore.h>
#include <Collision/CollisionSystem.h>
namespace jam {
	Player::Player(const sf::Vector2f& p, const sf::Rect<float>& cb, float w) : _weight(w), Entity(p, cb) {};
	Player::Player(const sf::Vector2f& p, const sf::Rect<float>& cb, const sf::Texture& t, float w) : _weight(w), Entity(p, cb){ m_sprite = sf::Sprite(t); };
	Player::Player(const sf::Vector2f& p, const sf::Rect<float>& cb, sf::Sprite s, float w) :_weight(w), Entity(p, cb) {};

	void Player::move(const sf::Vector2f& movement) {
		m_pos += movement;
		m_collisionBox.left += movement.x;
		m_collisionBox.top += movement.y;
	}

	void Player::update() {
		/*
		TODO:

		- Handle input and move based on input

		*/

		// input
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) move(sf::Vector2f(-500.0f,  0.0f)*jam::JamCore::deltaTime);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) move(sf::Vector2f( 500.0f,  0.0f)*jam::JamCore::deltaTime);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) move(sf::Vector2f( 0.0f, -500.0f)*jam::JamCore::deltaTime);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) move(sf::Vector2f( 0.0f,  500.0f)*jam::JamCore::deltaTime);


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