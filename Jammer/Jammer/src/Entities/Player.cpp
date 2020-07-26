#include "Player.h"
#include "Entity.h"

namespace jam {

<<<<<<< HEAD
//	Player::Player(const sf::Vector2f& p, const sf::Rect<float>& cb, const sf::Texture& t, float w) : _weight(w) /*Entity(p, cb)*/ { _sprite = sf::Sprite(t); };
	Player::Player(const sf::Vector2f& p, const sf::Rect<float>& cb, const sf::Sprite& s, float w) :_weight(w), _sprite(s) /*Entity(p, cb)*/ { Entity(p, cb); };
=======
	Player::Player(const sf::Vector2f& p, const sf::Rect<float>& cb, const sf::Texture& t, float w) : _weight(w), Entity(p, cb){ _sprite = sf::Sprite(t); };
	Player::Player(const sf::Vector2f& p, const sf::Rect<float>& cb, const sf::Sprite& s, float w) :_weight(w), _sprite(s), Entity(p, cb) {};
>>>>>>> 6eebd5d3e063534ac1be352e051abb6e793564f3

	void Player::move(const sf::Vector2f& movement) {
		//lerp movement probably

//		std::vector<const sf::Vector2f&> post_movement_overlaps;
//		sf::Vector2f post_movement_overlap;
//		for (auto collision_box : collision_boxes) {
//			if (isColliding(collision_box)) return;
//			post_movement_overlap = 
//			post_movement_overlaps
//		}
//		
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