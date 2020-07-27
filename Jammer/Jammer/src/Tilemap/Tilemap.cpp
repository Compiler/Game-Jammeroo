#include "Tilemap.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <stdarg.h>

namespace jam {

	TileLayerData::TileLayerData(const std::string& name, const std::vector<int>& data, unsigned int w):_layer_name(name),_csvdata(data), _width(w){}

	//debug purposes
	std::string TileLayerData::print() const {
		auto it = _csvdata.begin();
		std::stringstream ss;
		ss << this->getName() << "\n\n";
		size_t i = 0;
		while (it != _csvdata.end()) {
			i++;
			ss << (*it);
			if (i % 20 == 0) ss << '\n';
			it++;
		}
		ss << "\n\n\n\n\n WIDTH: " << _width << "\nHEIGHT: " << height();
		return ss.str();
	}

	Tilemap::Tilemap(const std::vector<std::string>& filepaths) {
		for (auto filepath : filepaths) {
			this->load_layer(filepath);
			std::cout << filepath << std::endl;
		}
	}
	
	Tilemap::Tilemap(const std::string& filepath) {
		this->load_layer(filepath);
	}

	/// <summary>
	/// used to get the data
	/// </summary>
	/// <param name="layer_name"> the name of the layer, it is the name of the file without the path or extension </param>
	/// <returns> the corresponding file </returns>
	TileLayerData Tilemap::getData(const std::string& layer_name) const {
		for (auto data : this->_data_vector)
			if (data.getName() == layer_name)
				return data;
		// error lol
		return TileLayerData();
	}

	void Tilemap::load_layer(const std::string& filepath) {
		std::ifstream filestream;
		std::string file_name = (filepath.substr((filepath).find_last_of("/\\") + 1)).substr(0, filepath.find_last_of("."));

		filestream.open(filepath);
		if (!filestream) {
			std::cout << "Tilemap was not opened correctly" << std::endl;
			return;
		}
		
		std::vector<int> csvdata;
		std::string line; 
		std::stringstream ss;
		std::string substr;
		unsigned int width = 0;

		while (filestream >> line){
			ss = std::stringstream(line);
			width = 0;
			while (ss.good()) {
				width++;
				std::getline(ss, substr, ',');
				int i = std::stoi(substr);
				csvdata.push_back(i);
			}
		}

		this->_data_vector.push_back(TileLayerData(file_name, csvdata, width));

	}


}