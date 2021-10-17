#include "pch.h"
#include "LoadGraphics.h"
#include <iostream>

//-----------------------------
// Validowanie tekstur 
//-----------------------------

	bool loadGraphics::add(const std::string& name, const std::string & filename){
		sf::Texture tmpTexture;

		if (!tmpTexture.loadFromFile(filename)){
			std::cerr << name << " - tekstura o podanej nazwie nie istnieje! " << std::endl; 
			
			return false;
		}

		else {
			textures[name] = tmpTexture; 
			
			return true;
		}
	}

	sf::Texture & loadGraphics::get(const std::string & name){
		return textures[name];
	}

//------------------------------
// Pobieranie tekstur
//------------------------------

	void loadGraphics::loadTextures() {
		//tekstury scian
		add("wall-gray", "../src/data/textures/walls/wall_gray.png");
		add("wall-pink", "../src/data/textures/walls/wall_pink.png");
		add("wall-gold", "../src/data/textures/walls/wall_gold.png");

		//tekstury podlog
		add("gray-floor", "../src/data/textures/floors/gray_floor.png");

		//tekstury pudelek
		add("box_brown", "../src/data/textures/boxes/box_brown.png");
		add("box_f_blue", "../src/data/textures/boxes/box_f-blue.png");
		add("box_f_green", "../src/data/textures/boxes/box_f-green.png");
		add("box_f_red", "../src/data/textures/boxes/box_f-red.png");
		add("box_f_yellow", "../src/data/textures/boxes/box_f-yellow.png");
		add("box_f_purple", "../src/data/textures/boxes/box_f-purple.png");
		add("box_f_aqua", "../src/data/textures/boxes/box_f-aqua.png");

		//tekstury plaform
		add("purplePlatform","../src/data/textures/platforms/platform_purple.png");
		add("greenPlatform", "../src/data/textures/platforms/platform_green.png");
	    add("redPlatform","../src/data/textures/platforms/platform_red.png");
		add("yellowPlatform", "../src/data/textures/platforms/platform_yellow.png");
		add("bluePlatform", "../src/data/textures/platforms/platform_blue.png");
		add("aquaPlatform", "../src/data/textures/platforms/platform_aqua.png");

		//tekstury postaci
		add("playerLeft", "../src/data/textures/player/playerLeft.png");
		add("playerRight", "../src/data/textures/player/playerRight.png");
		add("playerUp", "../src/data/textures/player/playerUp.png");
		add("playerDown", "../src/data/textures/player/playerDown.png");
	}
