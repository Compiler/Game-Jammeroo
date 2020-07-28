#include "Tileset.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
namespace jam {

	std::unordered_map<std::string, std::string> Tileset::load_jsonvars(const std::string& filepath) {

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
				jsonvars[split_string[0].substr(1, split_string[0].size()-2)] = split_string[1];
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
		delete this->texture;
	}

	void Tileset::load_tileset(const std::string& jsonpath) {

		std::unordered_map<std::string, std::string> jsonvars = load_jsonvars(jsonpath);
		this->tilesize = sf::Vector2i(std::stoi(jsonvars["tilewidth"]), std::stoi(jsonvars["tileheight"]));


		sf::Vector2i cursor(0, 0);
		std::cout << jsonvars["tilewidth"] << std::endl;
		for (unsigned int i = 0; i < std::stoi(jsonvars["tilecount"]); i++) {
			//add texture rect to the tiles map
			this->tiles[i] = sf::IntRect(cursor, tilesize);
			
			if ((i+1) % std::stoi(jsonvars["columns"]) == 0 && i != 0) {
				cursor.x = 0;
				cursor.y += tilesize.y;
			}
			else {
				cursor.x += tilesize.x;
			}
		}


		this->tiles[-1] = this->tiles[34];
		std::string filepath = jsonvars["image"];
		filepath = filepath.substr(1, filepath.size() - 2);
		if(!this->texture->loadFromFile(filepath)) std::cout << "the file did not load" << std::endl;
		this->tilesize = sf::Vector2i(std::stoi(jsonvars["tilewidth"]), std::stoi(jsonvars["tileheight"]));
	}

}