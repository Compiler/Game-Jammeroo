#include "Player.h"
#include "Entity.h"
#include <Collision/CollisionSystem.h>
namespace jam {
	Player::Player(const sf::Vector2f& p, const sf::Rect<float>& cb, float w) : _weight(w), Entity(p, cb) {};
	Player::Player(const sf::Vector2f& p, const sf::Rect<float>& cb, const sf::Texture& t, float w) : _weight(w), Entity(p, cb){ _sprite = sf::Sprite(t); };
	Player::Player(const sf::Vector2f& p, const sf::Rect<float>& cb, const sf::Sprite& s, float w) :_weight(w), _sprite(s), Entity(p, cb) {};

	void Player::move(const sf::Vector2f& movement) {
		m_pos += movement;
	}

	void Player::update() {
		/*
		TODO:

		- Handle input and move based on input

		- Gravity

		*/

		// input
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) move(sf::Vector2f(-1.0f,  0.0f));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) move(sf::Vector2f( 1.0f,  0.0f));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) move(sf::Vector2f( 0.0f, -1.0f));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) move(sf::Vector2f( 0.0f,  1.0f));
		//move(_GRAVITY, entities);
		//_sprite.setPosition(m_pos);

	}


	void Player::render(sf::RenderWindow* rw) {
		static sf::RectangleShape shape(sf::Vector2f(10.0f, 20.0f));
		shape.setFillColor(sf::Color::Green);
		shape.setPosition(this->getPosition());
		rw->draw(shape);
	}



}