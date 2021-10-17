#pragma once

#include <SFML/Graphics.hpp>
#include "enums.h"
#include "mapSettings.h"
#include "loadGraphics.h"

//---------------------------------
//---------------------------------
//  Klasa inicjalizujaca gre
//---------------------------------
//---------------------------------

class Game {
	sf::Font font;

	gs::GameStates gameState;

	sf::RenderWindow window;

	loadGraphics textureCache;

	mapSettings mapSettings;

	void processEvents();

	void render();

public:

	Game();

	void start();
};
