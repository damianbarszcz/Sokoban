#include "pch.h"
#include "hero.h"

	//Przypisanie parametrow startowych postaci
	Hero::Hero(loadGraphics* _textureCache, const int _TileSize, Counter* _movesCounter) :
		
		textureCache(_textureCache), 

		TileSize(_TileSize),

		//startowa tekstura pozycji postaci
		movesCounter(_movesCounter) {
			sprite.setTexture(textureCache->get("playerDown"));
		}

		std::string textureNameToSet;


//---------------------------------
// Ruch postaci bez interkacji
//---------------------------------

	void Hero::move(const dt::Directions & newDirection) {

		//inkremetnowanie ruchow
		(*movesCounter)++;

		//przypisanie nowej pozycji
		currentDirection = newDirection;

		switch (newDirection){

		case dt::Directions::LEFT:
			textureNameToSet = "playerLeft";
			sprite.move(-TileSize, 0);
			break;

		case dt::Directions::RIGHT:
			textureNameToSet = "playerRight";
			sprite.move(TileSize, 0);
			break;

		case dt::Directions::UP:
			textureNameToSet = "playerUp";
			sprite.move(0, -TileSize);
			break;

		case dt::Directions::DOWN:
			textureNameToSet = "playerDown";
			sprite.move(0, TileSize);
			break;
		}

		//przelaczanie tekstu postaci
		sprite.setTexture(textureCache->get(textureNameToSet));
	}

//---------------------------------
// Ruch postaci z interkacja
//---------------------------------

	void Hero::undoMove() {
	
		//blokowanie przejscia przez obiekty
		switch (currentDirection){

		//z lewej
		case dt::Directions::LEFT:
			sprite.move(TileSize, 0);
			break;
		
		//z prawej
		case dt::Directions::RIGHT:
			sprite.move(-TileSize, 0);
			break;

		//z gory
		case dt::Directions::UP:
			sprite.move(0, TileSize);
			break;
		
		//z dolu
		case dt::Directions::DOWN:
			sprite.move(0, -TileSize);
			break;
		}
	}


