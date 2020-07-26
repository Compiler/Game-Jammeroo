#pragma once
#include <SFML/Graphics.hpp>

namespace jam {
	class Entity {
	protected:
		sf::Rect<float> m_collision_box;
		sf::Vector2f m_pos;
		unsigned int ID;
		sf::Sprite m_sprite;

	public:

		Entity(const sf::Vector2f& p, const sf::Rect<float>& cb);
		Entity() = default;

		void setTexture(const sf::Texture& t); // done
		void setSize(const sf::Vector2f& factor);
		virtual void load() {};
		virtual void update() {
			m_sprite.setPosition(m_pos);
		}; //done 
		virtual void render(sf::RenderWindow* rw) {
			rw->draw(m_sprite);
		}; //done
		virtual void unload() {};

		inline bool isColliding(const sf::Rect<float>& other) const {return m_collision_box.intersects(other);}
	
		inline unsigned int getID() const {
			return ID;
		}
	};
}