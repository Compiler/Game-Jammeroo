#pragma once
#include <SFML/Graphics.hpp>

namespace jam {
	class Entity {
	protected:
		sf::Rect<float> m_collisionBox;
		sf::Vector2f m_pos;
		static unsigned int COUNT;
		unsigned int uniqueID;
		sf::Sprite m_sprite;
		sf::Texture* m_texture;

	public:

		Entity(const sf::Vector2f& p, const sf::Rect<float>& cb);
		Entity() { uniqueID = COUNT++;  };


		void setTexture(sf::Texture* t, float width, float height); // done
		void setSize(const sf::Vector2f& factor);
		virtual void load() {};
		virtual void update() {
			m_sprite.setPosition(m_pos);
		}; //done 
		virtual void render(sf::RenderWindow* rw) {
			rw->draw(m_sprite);
		}; //done
		virtual void unload() {};

		inline bool isColliding(const sf::Rect<float>& other) const {return m_collisionBox.intersects(other);}
	
		inline unsigned int getID() const {
			return uniqueID;
		}

		inline sf::Rect<float> getCollisionBox() { return m_collisionBox; }
		inline sf::Vector2f getPosition() { return m_pos; }

	};
}