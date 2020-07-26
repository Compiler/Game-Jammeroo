#include "Player.h"

namespace jam {

	Player::Player, 

	void Player::move(const sf::Vector2f movement) {
		// check if the player can make the movement before moving

	}

	void Player::update() {
		/*
		TODO:

		- Handle input and move based on input

		- Gravity

		- Draw

		*/
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			//move up
			;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			//move left
			;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			//move down
			;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			//move right
			;


	}

	void Player::draw(const sf::RenderWindow& draw_window) {
		draw_window.draw(_sprite);
	}

}