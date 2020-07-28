#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <Entities/Entity.h>
#include <Entities/EntityManager.h>

#include <iostream>

namespace jam {

	//TODO: 
	//generalize from rectangles to all convex polygons.
	/****************************************************/
	//POTENTIALLY TRY:
	//Implement BVH, Spatial partitioning, Bilateral Advancement(?)
	class CollisionSystem {

	public:


		static void init(std::vector<std::shared_ptr<Entity>>* entities) {
			_entities = entities;
		}


		static std::vector<std::shared_ptr<Entity>>* _entities;
		static sf::Vector2f adjustProjectedPosition(jam::Entity entity1, sf::Vector2f projectedSpot) {
			for (int i = 0; i < _entities->size(); i++) {
				Entity& entity2 = *_entities->at(i);
				if (entity2.getID() > std::pow(2, 16)) {
					continue;
				}
				//std::cout << "size :D \t" << _entities->size() << "\n";
				if (entity2.getID() == entity1.getID()) { continue; }
				sf::Rect<float> r1 = sf::Rect(projectedSpot, sf::Vector2f(entity1.getCollisionBox().width, entity1.getCollisionBox().height));
				sf::Rect<float> r2 = entity2.getCollisionBox();
				sf::Rect<float> output;
				if (r1.intersects(r2, output)) {
					//std::cout << "W: " << output.width << " \t" << "H: " << output.height << "\n";
					if (output.width < output.height) {
						output.height = 0;
						if (r1.left + r1.width < r2.left + r2.width) {
							output.width *= -1;
						}
					}
					else {
						output.width = 0;
						if (r1.top + r1.height < r2.top + r2.height) {
							output.height *= -1;
						}
					}
					projectedSpot.x += output.width;
					projectedSpot.y += output.height;
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