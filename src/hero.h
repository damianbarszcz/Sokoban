#pragma once

#include "enums.h"
#include "loadGraphics.h"
#include "counter.h"

//---------------------------------
//---------------------------------
//  Klasa obsługująca 
//  zachowania postaci
//---------------------------------
//---------------------------------

class Hero : public sf::Drawable {

public:
	Hero(loadGraphics* _textureCache, const int _TileSize, Counter* _movesCounter);

	void move(const dt::Directions& newDirection);

	void undoMove();

	void setPositionInTiles(const sf::Vector2i& position) { sprite.setPosition(position.x * TileSize * 7, position.y * TileSize * 2); }

	sf::Vector2i getPositionInTiles() { return sf::Vector2i(sprite.getPosition().x / TileSize, sprite.getPosition().y / TileSize); }

	dt::Directions getCurrentDirection() const { return currentDirection; }

private:

	const int TileSize;

	sf::Sprite sprite;

	loadGraphics* textureCache;

	Counter* movesCounter;

	dt::Directions currentDirection;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const { target.draw(sprite); }
};
