#pragma once
#include <string>
#include <vector>
#include "Tileset.h"
namespace jam {
	/// <summary>
	/// This holds all the data for a layer of tiles
	/// in the form of a vector of tile IDs in order
	/// and a width, in tiles, of the layer so that
	/// moving in the y direction is very simple and
	/// requires only an if statement or a for loop
	/// </summary>
	struct TileLayerData {
	private:
		std::string _layer_name;
		std::vector<int> _csvdata;
		unsigned int _width;
	public:
		TileLayerData() = default;
		TileLayerData(const std::string& name, const std::vector<int>& data, unsigned int width);
		inline std::vector<int> getCSVData() const { return _csvdata; };
		inline bool isLoaded() const { return !_csvdata.empty(); };
		inline int height() const { return this->_csvdata.size() / _width; };
		inline std::string getName() const { return _layer_name; };
		// debug purposes
		std::string print() const;
	};
	/// <summary>
	/// basically a wrapper for a vector but with the
	/// corresponding tileset.
	/// </summary>
	class Tilemap {
		std::vector<TileLayerData> _data_vector;
		Tileset* _tileset;
	public:

		Tilemap() = default;
		Tilemap(const std::vector<std::string>& filepaths);
		Tilemap(const std::string& filepath);
		~Tilemap();
		TileLayerData getData(const std::string& layer_name) const;
		inline std::vector<TileLayerData> getDataVector() const { return this->_data_vector; };
		void load_layer(const std::string& filepath);
	};

}
