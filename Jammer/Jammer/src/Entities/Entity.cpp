#include "Entity.h"
#include <iostream>
#include <string>
namespace jam {

	unsigned int Entity::COUNT = 0;
	Entity::Entity(const sf::Vector2f& p, const sf::Rect<float>& cb) : m_pos(p), m_collisionBox(cb) { uniqueID = COUNT++; };
	//	Entity::Entity() {};
	void Entity::setTexture(sf::Texture* t, float width, float height) {
		m_texture = t;
		m_sprite.setTexture(*m_texture);
		m_sprite.setTextureRect(sf::IntRect(this->m_pos.x, this->m_pos.y, width, height));
		//I've set these here because this is the only place width and height are coming in for the non-player entity rn.
		m_collisionBox.width = width;
		m_collisionBox.height = height;
	}

	//im gonna assume that this is supposed to set the size of all aspects of the entity.
	void Entity::setSize(const sf::Vector2f& factor) {
		m_sprite.setTextureRect(sf::IntRect(this->m_pos.x, this->m_pos.y, factor.x, factor.y));//wtf are you trying to do here?, 																 //a rectangle with dimensions (factor.x, factor.y).
		std::cout << this->m_pos.x << ", " << this->m_pos.y << ", " << factor.x << ", " <<factor.y << std::endl;

	}

}