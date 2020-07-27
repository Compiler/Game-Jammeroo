#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <Entities/Entity.h>
#include <Entities/EntityManager.h>
#include <optional>

#include <iostream>

namespace jam {

	//TODO: 
	//Implement BVH or 
	class CollisionSystem {

	public:


		static void init(std::vector<std::shared_ptr<Entity>>* entities) {
			_entities = entities;
		}


		static std::vector<std::shared_ptr<Entity>>* _entities;
		static sf::Vector2f adjustProjectedPosition(jam::Entity entity1, sf::Vector2f projectedSpot) {
			for (std::shared_ptr<jam::Entity> entity2 : *_entities) {
				std::cout << "size :D \t" << _entities->size() << "\n";
				if (entity2->getID() == entity1.getID()) { continue; }
				sf::Rect<float> r1 = sf::Rect(projectedSpot, sf::Vector2f(entity1.getCollisionBox().width, entity1.getCollisionBox().height));
				sf::Rect<float> r2 = entity2->getCollisionBox();
				if (aabbOverlapCheck(r1, r2)) {
					float newx = abs(projectedSpot.x - entity2->getPosition().x);
					float newy = abs(projectedSpot.y - entity2->getPosition().y);
					float joined_width = (r1.width + r2.width) * 0.5;
					float joined_height = (r1.height + r2.height) * 0.5;
					float deltax = newx - joined_width;
					float deltay = newy - joined_height;
					projectedSpot.x += (deltax < 0) ? deltax : 0;
					projectedSpot.y += (deltay < 0) ? deltay : 0;
					std::cout << "2sup dawg :D \n";
				}
			}
			return projectedSpot;
		}
		static bool aabbOverlapCheck(sf::Rect<float> r1, sf::Rect<float> r2) {
			return r1.intersects(r2);
		}


		static bool isColliding(jam::Entity entity1, jam::Entity entity2) {

			return false;
		}



	};

}