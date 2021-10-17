#pragma once

#include <SFML/Graphics.hpp>
#include "Enums.h"
#include "loadGraphics.h"

//---------------------------------
//---------------------------------
//  Klasa wizualizujaca 
//  elementy na planszy
//---------------------------------
//---------------------------------


class Animation : public sf::Drawable {

	public:
		static loadGraphics* loadGraphics;

		static const int Size;

		Animation(const tt::TileTypes& type, const sf::Vector2i& positionInTiles);

		Animation() {}

		sf::Vector2i getPositionInTiles() const { 
			return sf::Vector2i(sprite.getPosition().x / Size, sprite.getPosition().y / Size);
		}

		tt::TileTypes getType() const {
			return type;
		}

		void setType(const tt::TileTypes& newType);

	private:

		sf::Sprite sprite;

		tt::TileTypes type;

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
			target.draw(sprite);
		}
};