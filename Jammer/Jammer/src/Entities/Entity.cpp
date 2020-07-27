#include "Entity.h"
#include <iostream>
#include <string>
namespace jam {
	Entity::Entity(const sf::Vector2f& p, const sf::Rect<float>& cb) : m_pos(p), m_collision_box(cb) {};
	//	Entity::Entity() {};
	void Entity::setTexture(const sf::Texture& t, float width, float height) {
		
		m_sprite.setTexture(t);
		m_sprite.setTextureRect(sf::IntRect(this->m_pos.x, this->m_pos.y, width, height));
	}

	void Entity::setSize(const sf::Vector2f& factor) {
		m_sprite.setTextureRect(sf::IntRect(this->m_pos.x, this->m_pos.y, factor.x, factor.y));
		std::cout << this->m_pos.x << ", " << this->m_pos.y << ", " << factor.x << ", " <<factor.y << std::endl;

	}

}