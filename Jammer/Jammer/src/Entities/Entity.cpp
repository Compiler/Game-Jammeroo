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
	}

	void Entity::setSize(const sf::Vector2f& factor) {
		m_sprite.setTextureRect(sf::IntRect(this->m_pos.x, this->m_pos.y, factor.x, factor.y));
		std::cout << this->m_pos.x << ", " << this->m_pos.y << ", " << factor.x << ", " <<factor.y << std::endl;

	}

}