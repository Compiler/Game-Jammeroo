#pragma once
#include <SFML/Graphics.hpp>

namespace jam {
	class Entity {
	private:

		sf::Color __dbg_col;
	protected:
		sf::Rect<float> m_collisionBox;
		sf::Vector2f m_position, m_size;


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
		
		void init(float x, float y, float width, float height, sf::Texture* texture, int texture_x, int texture_y);
		Entity(float x, float y, float width, float height, sf::Texture* texture, int texture_x, int texture_y);

		void setTextureRect(int x, int y, int w, int h) { m_sprite.setTextureRect(sf::IntRect(x,y,w,h)); }//xd pog
		sf::IntRect getTextureRect() { return m_sprite.getTextureRect(); };
		void setSize(float width, float height);
		void setTexture(sf::Texture* t);
		virtual void load() {
			__dbg_col = sf::Color(rand() % 255, rand() % 255, rand() % 255);
		};
		virtual void update() {
			m_sprite.setPosition(m_position);
			m_collisionBox.left = m_position.x;
			m_collisionBox.width = m_size.x;
			m_collisionBox.top = m_position.y;
			m_collisionBox.height= m_size.y;
		}; 
		virtual void render(sf::RenderWindow* rw, sf::RenderStates state = sf::RenderStates::Default) {
			static sf::RectangleShape shape(sf::Vector2f(m_size.x, m_size.y));
			shape.setFillColor(sf::Color::Transparent);
			shape.setPosition(this->getPosition());
			rw->draw(m_sprite, state);
			shape.setOutlineColor(sf::Color::Red);
			shape.setOutlineThickness(2.0f);
//			rw->draw(shape, state);
		}; 

		virtual void render(sf::RenderWindow* rw, sf::Shader shader) {
			static sf::RectangleShape shape(sf::Vector2f(m_size.x, m_size.y));
			shape.setFillColor(__dbg_col);
			shape.setPosition(this->getPosition());
			rw->draw(m_sprite, &shader);
//			rw->draw(shape, &shader);
		};
		virtual void unload() {};

		inline bool isColliding(const sf::Rect<float>& other) const {return m_collisionBox.intersects(other);}
	
		inline unsigned int getID() const {
			return uniqueID;
		}
		void setPosition(float x, float y) {
			this->m_position.x = x;
			this->m_position.y = y;
		}

		inline sf::Rect<float> getCollisionBox() { return m_collisionBox; }
		inline sf::Vector2f getPosition() { return m_position; }

	};
}