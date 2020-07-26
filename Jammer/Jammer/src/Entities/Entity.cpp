#include "Entity.h"
#include <iostream>
#include <string>
namespace jam {
	Entity::Entity(const sf::Vector2f& p, const sf::Rect<float>& cb) : m_pos(p), m_collision_box(cb) {};
	//	Entity::Entity() {};
	void Entity::setTexture(const sf::Texture& t) {

		m_sprite.setTexture(t);

	}

	void Entity::setSize(const sf::Vector2f& factor) {
		std::cout << m_sprite.getTexture()->getSize().x << ", " << m_sprite.getTexture()->getSize().y << std::endl;

		m_sprite.setScale(factor);
		sf::IntRect textureRect = m_sprite.getTextureRect();
		textureRect.height *= factor.y;
		textureRect.width *= factor.x;
		m_sprite.setTextureRect(textureRect);
		std::cout << m_sprite.getTexture()->getSize().x << ", " << m_sprite.getTexture()->getSize().y << std::endl;

	}

}