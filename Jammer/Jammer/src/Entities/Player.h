#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
//move, jump, collide, react to gravity, fnc to draw, update, take input

namespace jam {

	class Player : public Entity{

	private:

		const sf::Vector2f _GRAVITY = sf::Vector2f(0.0f, -0.5f);
		float _weight;

	public:
		Player()  { uniqueID = COUNT++; };
		Player(const sf::Vector2f& p, const sf::Rect<float>& cb, float w = 1.0f);
		Player(const sf::Vector2f& p, const sf::Rect<float>& cb, const sf::Texture& t, float w = 1.0f);
		Player(const sf::Vector2f& p, const sf::Rect<float>& cb, sf::Sprite s, float w = 1.0f);
		
		void move(const sf::Vector2f& movement);
		void update();
		void render(sf::RenderWindow* rw);

		// gets weight
		inline float getWeight() const { return _weight; };
		// gets position
		inline const sf::Vector2f& getPosition() const { return m_pos; };


	};

}