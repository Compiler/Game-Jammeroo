#pragma once
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include <Entities/Entity.h>
namespace jam {


	typedef jam::Entity Tile;
	/// <summary>
	/// The tileset is essentially a struct of data that 
	/// will keep track of the texture, the tilesize and 
	/// will have a map of tile IDs and positions on the
	/// texture to sample from so that entities can be
	/// made with only a Tile ID and a tileset to reference
	/// </summary>
	struct Tileset {
	private:
		std::unordered_map<std::string, std::string>  load_jsonvars(const std::string& filepath);
	public:
		Tileset() = default;
		Tileset(const std::string& jsonpath);
		~Tileset();
		
		sf::Texture* texture; 
		sf::Vector2i tilesize;
		std::unordered_map<int, sf::IntRect> tiles;
		/// <summary>
		/// Takes all of the data out of a JSON file
		/// to use in this object
		/// </summary>
		/// <param name="jsonpath">path to the JSON file</param>
		void load_tileset(const std::string& jsonpath);

	};



}
