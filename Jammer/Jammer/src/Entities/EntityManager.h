#pragma once
#include <Entities/Entity.h>
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <Entities/Player.h>
namespace jam {

	class EntityManager {

	private:
		std::vector<std::shared_ptr<Entity>> _entities;
		std::shared_ptr<Player> _player;


	public:

		EntityManager() = default;



		void update();
		void render(sf::RenderWindow* rw);

		void addPlayer(std::shared_ptr<Player> player) { _player = player;}
		void addPlayer(Player player) { _player = std::make_shared<Player>(player);}
		void addEntity(std::shared_ptr<Entity> e);
		inline std::shared_ptr<Player> getPlayer() { return _player; }
		inline std::shared_ptr<Entity> getEntity(uint32_t index) { return _entities[index]; }
	};

}