#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <Entities/Entity.h>

namespace jam {


	class CollisionSystem {

	public:
		//friend EntityManager;
		static bool canMoveHere(jam::Entity entity1, sf::Vector2f projectedSpot) {

			return false;
		}
		static bool aabbOverlapCheck(/*sf::Rect<float> r1, sf::Rect<float> r2*/) {


			return false;
		}


		static bool isColliding(/*sf::Rect<float> r1, sf::Rect<float> r2*/) {

			return false;
		}


	};

}