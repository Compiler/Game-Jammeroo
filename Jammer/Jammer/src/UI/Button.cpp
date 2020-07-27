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

		if (!_font.loadFromFile("res/Raleway-Regular.ttf")) {
			std::cout << "Failed to load hahahaha\n";
		}
		_text.setFont(_font);
		_text.setCharacterSize(16);
		_text.setPosition(_x + width / 2.0f, _y + height / 2.0f);
		_text.setString(_message);
		_text.setFillColor(sf::Color::Black);
		_text.setStyle(sf::Text::Regular);
	}

	void Button::setText(std::string message) {
		_message = message;
	}


	void Button::render(sf::RenderWindow* rw) {
		static sf::RectangleShape shape, mouse;
		static sf::Vector2f dims(_windowArea.width, _windowArea.height);
		static sf::Rect<float> mouseRect;
		static bool flip = 0;
		mouseRect.left = jam::InputManager::getMouseMovedPosition().x - 10.0f / 2.0f;
		mouseRect.top = jam::InputManager::getMouseMovedPosition().y - 10 ;
		mouseRect.width = 10; mouseRect.height = 10;
		mouse.setPosition(mouseRect.left, mouseRect.top);
		mouse.setSize(sf::Vector2f(10, 10));
		shape.setPosition(_windowArea.left, _windowArea.top);
		dims.x = _windowArea.width; dims.y = _windowArea.height;
		shape.setSize(dims);
		shape.setFillColor(sf::Color::Red);
		if (_windowArea.intersects(mouseRect)) {
			if (jam::InputManager::isMouseReleased(jam::MouseKeys::MOUSE_BUTTON_LEFT))
				flip = !flip;
				
			if(flip) shape.setFillColor(sf::Color::Green);
			else shape.setFillColor(sf::Color::Yellow);
		}
		rw->draw(shape);
		rw->draw(mouse);
	}

}