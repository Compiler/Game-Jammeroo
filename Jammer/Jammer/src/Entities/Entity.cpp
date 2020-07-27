#include "Entity.h"
#include <iostream>
#include <string>
namespace jam {

	unsigned int Entity::COUNT = 0;

	void Entity::init(float x, float y, float width, float height) {
		m_position.x = x; m_position.y = y;
		m_size.x = width; m_size.y = height;
		__dbg_col = sf::Color(rand() % 255, rand() % 255, rand() % 255);

	}
	Entity::Entity(float x, float y, float width, float height) {
		init(x, y, width, height);
		__dbg_col = sf::Color(rand() % 255, rand() % 255, rand() % 255);

	}

	void Entity::init(float x, float y, float width, float height, sf::Texture* texture) {
		m_position.x = x; m_position.y = y;
		m_size.x = width; m_size.y = height;
		this->m_texture = texture;
		m_sprite.setTexture(*m_texture);
		m_sprite.setTextureRect(sf::IntRect(x, y, this->m_size.x, this->m_size.y));
		__dbg_col = sf::Color(rand() % 255, rand() % 255, rand() % 255);

	}
	Entity::Entity(float x, float y, float width, float height, sf::Texture* texture) {
		init(x, y, width, height, texture);
		__dbg_col = sf::Color(rand() % 255, rand() % 255, rand() % 255);

	}


	void Entity::setSize(float width, float height) {
		m_size.x = width;
		m_size.y = height;
	}

	//	Entity::Entity() {};
	void Entity::setTexture(sf::Texture* t) {
		m_texture = t;
		m_sprite.setTexture(*m_texture);
		m_sprite.setTextureRect(sf::IntRect((int)this->m_position.x, (int)this->m_position.y, (int)this->m_size.x, (int)this->m_size.y));
		m_collisionBox.width = m_size.x;
		m_collisionBox.height = m_size.y;
	}


}