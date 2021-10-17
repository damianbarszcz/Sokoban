#pragma once

#include <string>
#include <fstream>
#include <map>
#include <experimental/filesystem>
#include <SFML/Graphics.hpp>
#include "Enums.h"
#include "loadGraphics.h"
#include "animation.h"
#include "hero.h"
#include "counter.h"

//---------------------------------
//---------------------------------
//  Klasa obsługująca 
//  przetwarzenie mapy
//---------------------------------
//---------------------------------

class mapSettings : public sf::Drawable {

public:
	mapSettings(loadGraphics* _textureCache, const sf::Font& font);

	void init();

	void update(const sf::Event& event);

private:
	loadGraphics* textureCache;

	std::map<unsigned int, std::map<unsigned int, Animation>> tiles;

	Hero hero;

	Counter pushesCounter;

	Counter movesCounter;

	Counter currentLevel;

	void loadLevelFromFile(const std::string& filename);

	bool processEvents(const sf::Event& event);

	void detectCollisions();

	bool isEnd();

	void changeLevelToNext();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};