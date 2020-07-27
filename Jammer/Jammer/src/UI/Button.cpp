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
		static sf::RectangleShape shape;
		static sf::Vector2f dims(_windowArea.width, _windowArea.height);
		shape.setPosition(_windowArea.left, _windowArea.top);
		dims.x = _windowArea.width; dims.y = _windowArea.height;
		shape.setSize(dims);
		rw->draw(shape);

		if (_windowArea.intersects()) {}
	}

}