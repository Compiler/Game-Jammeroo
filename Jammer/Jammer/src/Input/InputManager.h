#pragma once
#include <Input/InputTuples.h>
#include <SFML/Graphics/Vertex.hpp>
#include <vector>
#include <memory>
namespace jam {

	class InputManager {

	private:
		static std::vector<jam::KeyCode> _keyReleasedEvents;
		static std::vector<jam::KeyCode>  _keyPressedEvents;
		static std::vector<jam::MouseKey>  _mousePressEvents;
		static std::vector<jam::MouseKey>_mouseReleaseEvents;
		static std::vector<sf::Vector2f>  _mouseMovedEvents;
		static sf::Vector2f _mousePosition;
	public:
		InputManager(const InputManager&) = delete;
		InputManager operator=(const InputManager&) = delete;

		static void addKeyPress(jam::KeyCode key) {
			_keyPressedEvents.push_back(key);
		}
		static void addKeyRelease(jam::KeyCode key) {
			_keyReleasedEvents.push_back(key);
		}
		static void addMousePosition(double x, double y) {
			_mousePosition.x = x;
			_mousePosition.y = y;
			_mouseMovedEvents.push_back(sf::Vector2f(x, y));
		}
		static void addMousePress(jam::MouseKey keyPressed) {
			_mousePressEvents.push_back(keyPressed);
		}
		static void addMouseRelease(jam::MouseKey keyReleased) {
			_mouseReleaseEvents.push_back(keyReleased);
		}
		static void clear() {
			//_keyPressedEvents.clear();
			std::vector<int> removeIndices;
			for (int i = 0; i < _keyPressedEvents.size(); i++)
				for (int k = 0; k < _keyReleasedEvents.size(); k++)
					if (_keyPressedEvents[i] == _keyReleasedEvents[k])
						removeIndices.push_back(i);
			while (removeIndices.size() > 0) {
				_keyPressedEvents.erase(_keyPressedEvents.begin(), _keyPressedEvents.begin() + removeIndices[removeIndices.size()-1] + 1);
				removeIndices.pop_back();
			}
			_keyReleasedEvents.clear();
			_mouseMovedEvents.clear();
			_mousePressEvents.clear();
			_mouseReleaseEvents.clear();
		}

		inline static bool isKeyPressed(jam::KeyCode key) {
			for (int i = 0; i < _keyPressedEvents.size(); i++) {
				
				if (_keyPressedEvents[i] == key)
					return true;
			}
			return false;
		}
		inline static bool isKeyReleased(jam::KeyCode key) {
			for (int i = 0; i < _keyReleasedEvents.size(); i++)
				if (_keyReleasedEvents[i] == key)
					return true;

			return false;
		}

		inline static bool isMousePressed(jam::MouseKey key) {
			for (int i = 0; i < _mousePressEvents.size(); i++) {
				if (_mousePressEvents[i] == key)
					return true;
			}
			return false;
		}
		inline static bool isMouseReleased(jam::MouseKey key) {
			for (int i = 0; i < _mouseReleaseEvents.size(); i++) {
				if (_mouseReleaseEvents[i] == key)
					return true;
			}
			return false;
		}

		inline static sf::Vector2f getMouseMovedPosition() {
			return _mousePosition;
		}

	};


}