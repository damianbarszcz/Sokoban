#include "pch.h"
#include "game.h" 

//Ustawienie parametrow gry
	Game::Game(): window(sf::VideoMode(1024, 704), "Sokoban - Damian Barszcz"), gameState(gs::GameStates::PLAY),

		mapSettings(&textureCache, font) {

		font.loadFromFile("../src/data/font.ttf");

		Animation::loadGraphics = &textureCache;

		mapSettings.init();
	}

//---------------------------------
// Startowanie gry  
//---------------------------------

	void Game::start() {

		//Rozpoczecie petli gry
		while (gameState != gs::GameStates::EXIT) {

			render();  processEvents();
		}

		window.close();
	}

//---------------------------------
// Przetwarzanie zdarzen w 
// trakcie dzialania gry
//---------------------------------

	void Game::processEvents() {
		sf::Event Event;

		while (window.pollEvent(Event)) {

			if (Event.type == sf::Event::Closed) {
				window.close();

				exit(0);
			}

			mapSettings.update(Event);
		}
	}

//---------------------------------
// Renderowanie scenerii gry
//---------------------------------

	void Game::render() {

		window.clear();

		window.draw(mapSettings);

		window.display();
	}
