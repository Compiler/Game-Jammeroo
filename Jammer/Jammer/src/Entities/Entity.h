#pragma once
#include <SFML/Graphics.hpp>

namespace jam {
	class Entity {
	protected:
		sf::Rect<float> m_collisionBox;
		sf::Vector2f m_pos, m_size;


		static unsigned int COUNT;
		unsigned int uniqueID;
		sf::Sprite m_sprite;
		sf::Texture* m_texture;

	public:
		Entity() { uniqueID = COUNT++;  };

		void init(float x, float y, float width, float height);
		Entity(float x, float y, float width, float height);

		void init(float x, float y, float width, float height, sf::Texture* texture);
		Entity(float x, float y, float width, float height, sf::Texture* texture);
		
		
		void setSize(float width, float height);
		void setTexture(sf::Texture* t);
		virtual void load() {};
		virtual void update() {
			m_sprite.setPosition(m_pos);
			m_collisionBox.left = m_pos.x;
			m_collisionBox.width = m_size.x;
			m_collisionBox.top = m_pos.y;
			m_collisionBox.height= m_size.y;
		}; 
		virtual void render(sf::RenderWindow* rw) {
			static sf::RectangleShape shape(sf::Vector2f(m_size.x, m_size.y));
			shape.setFillColor(sf::Color::Yellow);
			shape.setPosition(this->getPosition());
			rw->draw(m_sprite);
			rw->draw(shape);
		}; 
		virtual void unload() {};

		inline bool isColliding(const sf::Rect<float>& other) const {return m_collisionBox.intersects(other);}
	
		inline unsigned int getID() const {
			return uniqueID;
		}
		void setPosition(float x, float y) {
			this->m_pos.x = x;
			this->m_pos.y = y;
		}

		inline sf::Rect<float> getCollisionBox() { return m_collisionBox; }
		inline sf::Vector2f getPosition() { return m_pos; }

	};
}