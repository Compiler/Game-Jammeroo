#include "Player.h"
#include "Entity.h"
#include <Collision/CollisionSystem.h>
namespace jam {

	Player::Player(const sf::Vector2f& p, const sf::Rect<float>& cb, const sf::Texture& t, float w) : _weight(w), Entity(p, cb){ _sprite = sf::Sprite(t); };
	Player::Player(const sf::Vector2f& p, const sf::Rect<float>& cb, const sf::Sprite& s, float w) :_weight(w), _sprite(s), Entity(p, cb) {};

	void Player::move(const sf::Vector2f& movement) {
		
	}

	void Player::update() {
		/*
		TODO:

		- Handle input and move based on input

		- Gravity

		- Draw

		*/

		// input
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		//	move(sf::Vector2f(-1.0f, 0.0f), entities);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		//	move(sf::Vector2f(1.0f, 0.0f), entities);

		//move(_GRAVITY, entities);


		_sprite.setPosition(m_pos);
	}



}