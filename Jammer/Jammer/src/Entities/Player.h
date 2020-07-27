#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
namespace jam {

	class Player : public Entity{
	public:

		Player() { uniqueID = COUNT++; };
		void move(const sf::Vector2f& movement);
		void update();
		void render(sf::RenderWindow* rw);

	};

}