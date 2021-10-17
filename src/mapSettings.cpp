#include "pch.h"
#include <iostream>
#include "mapSettings.h"


//Ustawienie parametrow mapy 

	mapSettings::mapSettings(loadGraphics* textureCache, const sf::Font& font) : textureCache(textureCache), hero(textureCache, Animation::Size, &movesCounter),
	pushesCounter("PCHNIECIA: ", sf::Vector2f(800, 615), font), movesCounter("KROKI: ", sf::Vector2f(64, 615), font), currentLevel("POZIOM: ", sf::Vector2f(64, 50), font){}

	void mapSettings::init() { changeLevelToNext(); }

//---------------------------------
//  Akutalizacja mapy 
//	po przejsciu poziomu
//---------------------------------

	void mapSettings::update(const sf::Event& event) {

		if (processEvents(event)){

			detectCollisions(); 

			//po przejsciu poziomu
			if (isEnd()){

				tiles.clear();

				movesCounter.reset();

				pushesCounter.reset();

				changeLevelToNext();
			}
		}
	}

//-----------------------------------
// Wczytanie zawartosci plikow level
//-----------------------------------

	void mapSettings::loadLevelFromFile(const std::string & filename) {

		std::ifstream file(filename);

		std::string x, y;

		file >> x >> y;

		//pobranie pozycji postaci
		hero.setPositionInTiles(sf::Vector2i(std::stoi(x), std::stoi(y)));

		sf::Vector2i loadCounter;

		while (!file.eof()) {
			int tileType;

			file >> tileType;

			tiles[loadCounter.x][loadCounter.y] = Animation(static_cast<tt::TileTypes>(tileType), loadCounter);

			loadCounter.x++;

			//sprawdzenie w pliku przejsc do nowej lini
			if (file.peek() == '\n') {
				loadCounter.x = 0;
				loadCounter.y++;
			}
		}
	} 


//---------------------------------
// Przygotowanie nowej mapy
//---------------------------------


	void mapSettings::changeLevelToNext() {
		currentLevel++; //inkrementacja licznika level

		std::ifstream file;

		std::string filePath = "../src/data/levels/level" + currentLevel.toString() + ".lvl"; // wywolanie pliku level

		file.open(filePath.c_str());


		if (file.is_open()) {

			loadLevelFromFile(filePath);
		}

		else {
			currentLevel.reset();

			changeLevelToNext();
		}

		file.close();
	}

//---------------------------------
// Rysowanie Scenerii
//---------------------------------

	void mapSettings::draw(sf::RenderTarget & target, sf::RenderStates states) const {

		for (auto const& column : tiles) {
			for (auto const& tile : column.second) {
				target.draw(tile.second);
			}
		}

		target.draw(hero); //rysowanie postaci
		target.draw(movesCounter); //rysowanie licznika krokow
		target.draw(pushesCounter); //rysowanie licznika pchniec
		target.draw(currentLevel);  //rysowanie licznika poziomu
	}

//---------------------------------------
// Przypisanie ruchow postaci 
// przyciskom na klawiaturze
//---------------------------------------

	bool mapSettings::processEvents(const sf::Event& event) {

		if (event.type == sf::Event::KeyPressed) {
			switch (event.key.code) {

			case sf::Keyboard::Left:
				hero.move(dt::Directions::LEFT);
				return true;

			case sf::Keyboard::Right:
				hero.move(dt::Directions::RIGHT);
				return true;

			case sf::Keyboard::Up:
				hero.move(dt::Directions::UP);
				return true;

			case sf::Keyboard::Down:
				hero.move(dt::Directions::DOWN);
				return true;
			}
		}
		return false;
	}

//-----------------------------------
// Interakcja miedzy obiektami
//-----------------------------------

	void mapSettings::detectCollisions(){
		Animation  *tileUnderPlayer = &tiles[hero.getPositionInTiles().x][hero.getPositionInTiles().y];

		//interakcja gracza ze sciana
		if (tileUnderPlayer->getType() == tt::TileTypes::WALL_GRAY) {
			hero.undoMove();
		}

		else if(tileUnderPlayer->getType() == tt::TileTypes::WALL_PINK) {
			hero.undoMove();
		}

		else if (tileUnderPlayer->getType() == tt::TileTypes::WALL_GOLD) {
			hero.undoMove();
		}

		Animation  *nextTile = nullptr;

		//interakcja gracza z pudełkiem - o ile przesuwamy
		switch (hero.getCurrentDirection()){
	
			case dt::Directions::LEFT: nextTile = &tiles[tileUnderPlayer->getPositionInTiles().x - 1][tileUnderPlayer->getPositionInTiles().y]; break;
	
			case dt::Directions::RIGHT: nextTile = &tiles[tileUnderPlayer->getPositionInTiles().x + 1][tileUnderPlayer->getPositionInTiles().y]; break;
	
			case dt::Directions::UP: nextTile = &tiles[tileUnderPlayer->getPositionInTiles().x][tileUnderPlayer->getPositionInTiles().y - 1]; break;
	
			case dt::Directions::DOWN: nextTile = &tiles[tileUnderPlayer->getPositionInTiles().x][tileUnderPlayer->getPositionInTiles().y + 1]; break;
		}

		//interakcja gracza z pudełkiem - zdarzenie przesuwania
		if (tileUnderPlayer->getType() == tt::TileTypes::BOX){

			if (nextTile->getType() == tt::TileTypes::GRAY_FLOOR) { tileUnderPlayer->setType(tt::TileTypes::GRAY_FLOOR); nextTile->setType(tt::TileTypes::BOX); pushesCounter++;}

			else if (nextTile->getType() == tt::TileTypes::PLATFORM_FINISH_BLUE){ tileUnderPlayer->setType(tt::TileTypes::GRAY_FLOOR); nextTile->setType(tt::TileTypes::BOX_FINISH_BLUE); pushesCounter++;}

			else if (nextTile->getType() == tt::TileTypes::PLATFORM_FINISH_RED) { tileUnderPlayer->setType(tt::TileTypes::GRAY_FLOOR); nextTile->setType(tt::TileTypes::BOX_FINISH_RED); pushesCounter++;}

			else if (nextTile->getType() == tt::TileTypes::PLATFORM_FINISH_GREEN) { tileUnderPlayer->setType(tt::TileTypes::GRAY_FLOOR); nextTile->setType(tt::TileTypes::BOX_FINISH_GREEN); pushesCounter++;}

			else if (nextTile->getType() == tt::TileTypes::PLATFORM_FINISH_AQUA) { tileUnderPlayer->setType(tt::TileTypes::GRAY_FLOOR); nextTile->setType(tt::TileTypes::BOX_FINISH_AQUA); pushesCounter++;}

			else if (nextTile->getType() == tt::TileTypes::PLATFORM_FINISH_PURPLE) { tileUnderPlayer->setType(tt::TileTypes::GRAY_FLOOR); nextTile->setType(tt::TileTypes::BOX_FINISH_PURPLE); pushesCounter++;}

			else if (nextTile->getType() == tt::TileTypes::PLATFORM_FINISH_YELLOW) { tileUnderPlayer->setType(tt::TileTypes::GRAY_FLOOR); nextTile->setType(tt::TileTypes::BOX_FINISH_YELLOW); pushesCounter++;}

			else { hero.undoMove(); }

		}

		//interakcja gracza z pudelkiem na platformie
		if (tileUnderPlayer->getType() == tt::TileTypes::BOX_FINISH_BLUE) { hero.undoMove(); }

		else if (tileUnderPlayer->getType() == tt::TileTypes::BOX_FINISH_RED) { hero.undoMove(); }

		else if (tileUnderPlayer->getType() == tt::TileTypes::BOX_FINISH_AQUA) { hero.undoMove(); }

		else if (tileUnderPlayer->getType() == tt::TileTypes::BOX_FINISH_GREEN) { hero.undoMove(); }

		else if (tileUnderPlayer->getType() == tt::TileTypes::BOX_FINISH_PURPLE) { hero.undoMove(); }

		else if (tileUnderPlayer->getType() == tt::TileTypes::BOX_FINISH_YELLOW) { hero.undoMove(); }
	}

//---------------------------------
// Zakonczenie poziomu gry
//---------------------------------

	bool mapSettings::isEnd() {

		for (auto const& column : tiles) {

			for (auto const& tile : column.second) {

				if ((tile.second.getType() == tt::TileTypes::PLATFORM_FINISH_BLUE) || (tile.second.getType() == tt::TileTypes::PLATFORM_FINISH_RED) ||
					(tile.second.getType() == tt::TileTypes::PLATFORM_FINISH_GREEN) || (tile.second.getType() == tt::TileTypes::PLATFORM_FINISH_YELLOW) ||
					(tile.second.getType() == tt::TileTypes::PLATFORM_FINISH_AQUA) || (tile.second.getType() == tt::TileTypes::PLATFORM_FINISH_PURPLE))

					return false;
			}
		}
		return true;
	}





