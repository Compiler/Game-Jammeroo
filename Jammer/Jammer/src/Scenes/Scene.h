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

	protected:
		sf::RenderWindow* m_windowRef;
		EntityManager* m_entityManager = new EntityManager();

	public:
		Scene(sf::RenderWindow*);
		Scene(sf::RenderWindow*, std::string name);


		virtual void load();
		virtual void update();
		virtual void render(sf::RenderWindow* window);
		virtual void unload();

		EntityManager* getEntityManager() { return m_entityManager; }
		inline const std::string getName()const { return _sceneName; }

	};
}