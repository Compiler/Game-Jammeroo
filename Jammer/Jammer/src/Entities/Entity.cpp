#include "Entity.h"
namespace jam {
	Entity::Entity(const sf::Vector2f& p, const sf::Rect<float>& cb) : m_pos(p), m_collision_box(cb) {};
//	Entity::Entity() {};
}