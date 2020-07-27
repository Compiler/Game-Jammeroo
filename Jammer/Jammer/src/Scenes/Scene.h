#pragma once
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>


namespace jam {
	
	class Scene {

	private:
		static uint8_t _COUNT;
		std::string _sceneName;

	protected:
		sf::RenderWindow* m_windowRef;

	public:
		Scene(sf::RenderWindow*);
		Scene(sf::RenderWindow*, std::string name);


		virtual void load();
		virtual void update();
		virtual void render();
		virtual void unload();

		inline const std::string getName()const { return _sceneName; }

	};
}