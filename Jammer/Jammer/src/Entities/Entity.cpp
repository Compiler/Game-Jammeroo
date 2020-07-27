#include "Entity.h"
#include <iostream>
#include <string>
namespace jam {

	unsigned int Entity::COUNT = 0;

	void Entity::init(float x, float y, float width, float height) {
		m_pos.x = x; m_pos.y = y;
		m_size.x = width; m_size.y = height;
	}
	Entity::Entity(float x, float y, float width, float height) {
		init(x, y, width, height);
	}

	void Entity::init(float x, float y, float width, float height, sf::Texture* texture) {
		m_pos.x = x; m_pos.y = y;
		m_size.x = width; m_size.y = height;
		this->m_texture = texture;
		m_sprite.setTexture(*m_texture);
		m_sprite.setTextureRect(sf::IntRect(this->m_pos.x, this->m_pos.y, this->m_size.x, this->m_size.y));
	}
	Entity::Entity(float x, float y, float width, float height, sf::Texture* texture) {
		init(x, y, width, height, texture);
	}


	void Entity::setSize(float width, float height) {
		m_size.x = width;
		m_size.y = height;
	}

	//	Entity::Entity() {};
	void Entity::setTexture(sf::Texture* t) {
		m_texture = t;
		m_sprite.setTexture(*m_texture);
		m_sprite.setTextureRect(sf::IntRect((int)this->m_pos.x, (int)this->m_pos.y, (int)this->m_size.x, (int)this->m_size.y));
		m_collisionBox.width = m_size.x;
		m_collisionBox.height = m_size.y;
	}


}