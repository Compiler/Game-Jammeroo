#pragma once
#include <SFML/Graphics.hpp>
//move, jump, collide, react to gravity, fnc to draw, update, take input

namespace jam {

	class Player {
	private:
		sf::Vector2f _pos;
		sf::Rect<float> _collision_box;
		float _weight;
		sf::Texture _texture;
		sf::Sprite _sprite;



	public:
		Player(const sf::Vector2f& p, const sf::Rect<float> cb);

		void move(sf::Vector2f movement);

		void init();
		void update();

		// checks if the player's collision box is colliding with another collision box
		inline bool isColliding(const sf::Rect<float>& other) const { return _collision_box.intersects(other);};
		// gets weight
		inline float getWeight() const { return _weight; };
		// draws sprite
		void draw(const sf::RenderWindow& draw_window);

	};

}