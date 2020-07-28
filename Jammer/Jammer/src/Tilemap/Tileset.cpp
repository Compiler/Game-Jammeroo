#include "Tileset.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
namespace jam {

	std::unordered_map<std::string, std::string>  load_jsonvars(const std::string& filepath) {

		//the tileset info files are exported as json

		std::ifstream file;
		std::string current_line;
		std::unordered_map<std::string, std::string> jsonvars;
		std::string split;
		std::stringstream ss;
		std::vector<std::string> split_string;
		split_string.reserve(2);
		file.open(filepath);
		if (!file.is_open()) std::cout << "COULD NOT OPEN [" << filepath << "], CHECK THE PATH" << std::endl;
		while (file >> current_line) {
			if (!(current_line == "}" || current_line == "{")) {
				std::cout << current_line.at(current_line.size() - 1) << std::endl;
				current_line.pop_back(); //removes the "," at the end of the line
				ss = std::stringstream(current_line);
				while (getline(ss, split, ':')) {
					split_string.push_back(split);
				}
				jsonvars[split_string[0]] = split_string[1];
				split_string.clear();
			}
		}
		return jsonvars;
	}

	Tileset::Tileset(const std::string& jsonpath) {
		this->texture = new sf::Texture();
		this->load_tileset(jsonpath);
	}

	Tileset::~Tileset() {
		if(texture == nullptr)
		delete this->texture;
	}

	void Tileset::load_tileset(const std::string& jsonpath) {

		std::unordered_map<std::string, std::string> jsonvars = load_jsonvars(jsonpath);
		this->tiles[-1] = Tile();

		sf::Vector2i cursor(0, 0);
		std::cout << jsonvars["\"tilewidth\""] << std::endl;
		sf::Vector2i tileSize(std::stoi(jsonvars["\"tilewidth\""]), std::stoi(jsonvars["\"tileheight\""]));
		for (unsigned int i = 0; i < std::stoi(jsonvars["\"tilecount\""]); i++) {
			//make tile
			Tile tile(0, 0, tileSize.x, tileSize.y);
			tile.setTextureRect(cursor.x, cursor.y, tileSize.x, tileSize.y);
			//add to tileset
			this->tiles[i] = tile;
			if (i % std::stoi(jsonvars["\"columns\""]) == 0) {
				cursor.x = 0;
				cursor.y += tileSize.y;
			}
			else {
				cursor.x += tileSize.x;
			}
		}

		std::string filepath = jsonvars["\"image\""];
		filepath = filepath.substr(1, filepath.size() - 2);
		if(!this->texture->loadFromFile(filepath)) std::cout << "the file did not load" << std::endl;
	
	}

}