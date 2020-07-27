#pragma once
#include <SFML/Graphics.hpp>
namespace jam {
	namespace math {
		static float fdot(sf::Vector2f v1, sf::Vector2f v2) {
			return v1.x* v2.x + v1.y * v2.y;
		}
	}
}