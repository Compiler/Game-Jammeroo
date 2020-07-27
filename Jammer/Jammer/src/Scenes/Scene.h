#pragma once
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>
#include <Entities/EntityManager.h>


namespace jam {
	
	class Scene {

	private:
		static uint8_t _COUNT;
		std::string _sceneName;
		EntityManager* _entityManager = new EntityManager();

	protected:
		sf::RenderWindow* m_windowRef;

	public:
		Scene(sf::RenderWindow*);
		Scene(sf::RenderWindow*, std::string name);


		virtual void load();
		virtual void update();
		virtual void render(sf::RenderWindow* window);
		virtual void unload();

		EntityManager* getEntityManager() { return _entityManager; }
		inline const std::string getName()const { return _sceneName; }

	};
}