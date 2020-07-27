#pragma once
#include <stdint.h>
#include <SFML/Graphics.hpp>


namespace jam {
	

	class Button {

	private:
		float _x, _y;
		float _width, _height;

		sf::Rect<float> windowArea;

	public:

		Button();
		void init(float x, float y, float width, float height);
		void render(sf::RenderWindow* window);



		Button(float x, float y, float width, float height);

	};

}