#include "pch.h"
#include "animation.h"

loadGraphics* Animation::loadGraphics = nullptr;

const int Animation::Size = 64;

//-----------------------------
// Ustawienie pozycji tekstur 
//-----------------------------

Animation::Animation(const tt::TileTypes& type, const sf::Vector2i& positionInTiles) {

		sprite.setPosition(positionInTiles.x * Size, positionInTiles.y * Size); 

		setType(type);
	}

//---------------------------------
// Przypisanie tekstur do 
// odpowiednich wartosci klas enum
//---------------------------------

	void Animation::setType(const tt::TileTypes & newType) {
		type = newType;

		switch (newType) {
		//0
		case tt::TileTypes::WALL_GRAY:
			sprite.setTexture(loadGraphics->get("wall-gray"));
			break;

		//1
		case tt::TileTypes::WALL_PINK:
			sprite.setTexture(loadGraphics->get("wall-pink"));
			break;

		//2
		case tt::TileTypes::WALL_GOLD:
			sprite.setTexture(loadGraphics->get("wall-gold"));
			break;

		//3
		case tt::TileTypes::GRAY_FLOOR:
			sprite.setTexture(loadGraphics->get("gray-floor"));
			break;

		//4
		case tt::TileTypes::BOX:
			sprite.setTexture(loadGraphics->get("box_brown"));
			break;

		//5
		case tt::TileTypes::BOX_FINISH_BLUE:
			sprite.setTexture(loadGraphics->get("box_f_blue"));
			break;

		//6
		case tt::TileTypes::BOX_FINISH_GREEN:
			sprite.setTexture(loadGraphics->get("box_f_green"));
			break;

		//7
		case tt::TileTypes::BOX_FINISH_RED:
			sprite.setTexture(loadGraphics->get("box_f_red"));
			break;

		//8
		case tt::TileTypes::BOX_FINISH_YELLOW:
			sprite.setTexture(loadGraphics->get("box_f_yellow"));
			break;

		//9
		case tt::TileTypes::BOX_FINISH_PURPLE:
			sprite.setTexture(loadGraphics->get("box_f_purple"));
			break;

		//10
		case tt::TileTypes::BOX_FINISH_AQUA:
			sprite.setTexture(loadGraphics->get("box_f_aqua"));
			break;

		//11
		case tt::TileTypes::PLATFORM_FINISH_BLUE:
			sprite.setTexture(loadGraphics->get("bluePlatform"));
			break;

		//12
		case tt::TileTypes::PLATFORM_FINISH_GREEN:
			sprite.setTexture(loadGraphics->get("greenPlatform"));
			break;

		//13
		case tt::TileTypes::PLATFORM_FINISH_RED:
			sprite.setTexture(loadGraphics->get("redPlatform"));
			break;

		//14
		case tt::TileTypes::PLATFORM_FINISH_YELLOW:
			sprite.setTexture(loadGraphics->get("yellowPlatform"));
			break;

		//15
		case tt::TileTypes::PLATFORM_FINISH_PURPLE:
			sprite.setTexture(loadGraphics->get("purplePlatform"));
			break;

		//16
		case tt::TileTypes::PLATFORM_FINISH_AQUA:
			sprite.setTexture(loadGraphics->get("aquaPlatform"));
			break;
		}
	}
