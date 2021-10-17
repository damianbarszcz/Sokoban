#pragma once

#include <map>
#include <SFML/Graphics.hpp>

//---------------------------------
//---------------------------------
//  Klasa obsługująca 
//  przesyl tekstur gry 
//---------------------------------
//---------------------------------

class loadGraphics {

	public:
		loadGraphics() {
			loadTextures();
		}

		bool add( const std::string& name,  const std::string& filename);

		sf::Texture& get(const std::string& name);

	private:

		std::map<std::string, sf::Texture> textures;

		std::vector<std::string> paths;

		void loadTextures();

};