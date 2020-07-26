#pragma once
#include <SFML/Graphics.hpp>

namespace jam {
	class Entity {
	protected:
		sf::Rect<float> m_collision_box;
		sf::Vector2f m_pos;
		Entity(const sf::Vector2f& p, const sf::Rect<float>& cb);
		Entity() = default;
	public:


		virtual void load() {};
		virtual void update() {};
		virtual void render(sf::RenderWindow* rw) {};
		virtual void unload() {};

		inline bool isColliding(const sf::Rect<float>& other) const {return m_collision_box.intersects(other);}
	};
}