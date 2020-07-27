#pragma once
#include <stdint.h>
#include <SFML/Graphics.hpp>
#include <Input/InputManager.h>
#include <string>
#include <iostream>

namespace jam {
	

	class Button {

	private:
		float _x, _y;
		float _width, _height;


		std::string _message;

		sf::Rect<float> _windowArea;

		static sf::Text _text;
		static sf::Font _font;

	public:

		Button();
		void init(float x, float y, float width, float height);
		void setText(std::string message);
		void render(sf::RenderWindow* window);



		Button(float x, float y, float width, float height);

	};

}