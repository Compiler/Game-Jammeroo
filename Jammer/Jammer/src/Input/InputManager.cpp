#include "InputManager.h"

namespace jam {


	std::vector<jam::KeyCode>  InputManager::_keyPressedEvents;
	std::vector<jam::KeyCode> InputManager::_keyReleasedEvents;

	sf::Vector2f InputManager::_mousePosition;
	std::vector<sf::Vector2f>  InputManager::_mouseMovedEvents;
	std::vector<jam::MouseKey>  InputManager::_mousePressEvents;
	std::vector<jam::MouseKey>  InputManager::_mouseReleaseEvents;

}