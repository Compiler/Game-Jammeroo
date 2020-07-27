#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
//move, jump, collide, react to gravity, fnc to draw, update, take input

namespace jam {

	class Player : public Entity{

	private:

		float _weight;

	public:

		Player() { uniqueID = COUNT++; };
		void move(const sf::Vector2f& movement);
		void update();
		void render(sf::RenderWindow* rw);

		// gets weight
		inline float getWeight() const { return _weight; };
		// gets position
		inline const sf::Vector2f& getPosition() const { return m_pos; };
		

	};

}