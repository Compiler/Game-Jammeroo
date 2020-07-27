#pragma once
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include <Entities/Entity.h>
namespace jam {


	typedef jam::Entity Tile;

	struct Tileset {
		Tileset() = default;
		Tileset(const std::string& jsonpath);
		sf::Texture texture;
		std::unordered_map<int, Tile> tiles;
		void load_tileset(const std::string& jsonpath);

	};

	std::unordered_map<std::string, std::string>  load_jsonvars(const std::string& filepath);


}
