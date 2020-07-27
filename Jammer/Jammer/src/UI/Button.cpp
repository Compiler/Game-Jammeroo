#include "Button.h"

namespace jam {


	Button::Button() {
		init(0, 0, 200, 100);
	}
	Button::Button(float x, float y, float width, float height) {
		init(x, y, width, height);
	}
	void Button::init(float x, float y, float width, float height) {
		_x = x; _y = y; _width = width; _height = height;
		_windowArea.left = _x; _windowArea.top = y; _windowArea.width = width; _windowArea.height = _height;
	}


	void Button::render(sf::RenderWindow* rw) {
		static sf::RectangleShape shape, mouse;
		static sf::Vector2f dims(_windowArea.width, _windowArea.height);
		static sf::Rect<float> mouseRect;
		mouseRect.left = jam::InputManager::getMouseMovedPosition().x - 10.0f / 2.0f;
		mouseRect.top = jam::InputManager::getMouseMovedPosition().y - 10 ;
		mouseRect.width = 10; mouseRect.height = 10;
		mouse.setPosition(mouseRect.left, mouseRect.top);
		mouse.setSize(sf::Vector2f(10, 10));
		shape.setPosition(_windowArea.left, _windowArea.top);
		dims.x = _windowArea.width; dims.y = _windowArea.height;
		shape.setSize(dims);
		shape.setFillColor(sf::Color::Magenta);
		if (_windowArea.intersects(mouseRect)) {
			if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
				std::cout << "Helo thare!\n";
			shape.setFillColor(sf::Color::Green);
		}
		rw->draw(shape);
		rw->draw(mouse);
	}

}