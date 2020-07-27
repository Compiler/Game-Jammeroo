#include "Tileset.h"
#include <fstream>
#include <sstream>
#include <regex>
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

		file.open(filepath);

		while (file >> current_line) {
			if (!(current_line == "}" || current_line == "{")) {
				current_line.pop_back(); //removes the "," at the end of the line
				ss = std::stringstream(current_line);
				while (getline(ss, split, ':')) split_string.push_back(split);
				jsonvars[split_string[0]] = split_string[1];
			}
		}
		return jsonvars;
	}

	void Tileset::load_tileset(const std::string& jsonpath, const std::string& imagepath) {

		std::unordered_map<std::string, std::string> jsonvars = load_jsonvars(jsonpath);
		this->tiles[-1] = Tile();
		sf::Vector2i cursor(0, 0);
		sf::Vector2i tileSize(std::stoi(jsonvars["\"tilewidth\""]), std::stoi(jsonvars["\"tileheight\""]));
		for (unsigned int i = 0; i < std::stoi(jsonvars["\"tilecount\""]); i++) {
			//make tile
			//Tile tile(tileSize, cursor);

			//add to tileset
			//tileset.tiles[i] = tile;
			//move cursor
			if (i % std::stoi(jsonvars["\"columns\""]) == 0) {
				cursor.x = 0;
				cursor.y += tileSize.y;
			}
			else {
				cursor.x += tileSize.x;
			}
		}

		// do this code lol

	}

}