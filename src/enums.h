#pragma once

//---------------------------------
// Spis przestrzeni nazw
//---------------------------------
	
	namespace gs {
		enum class GameStates {
			PLAY,
			EXIT
		};
	}

	//
	namespace tt {
		enum class TileTypes {
			WALL_GRAY,
			WALL_PINK,
			WALL_GOLD,
			GRAY_FLOOR,
			BOX,
			BOX_FINISH_BLUE,
			BOX_FINISH_GREEN,
			BOX_FINISH_RED,
			BOX_FINISH_YELLOW,
			BOX_FINISH_PURPLE,
			BOX_FINISH_AQUA,
			PLATFORM_FINISH_BLUE,
			PLATFORM_FINISH_GREEN,
			PLATFORM_FINISH_RED,
			PLATFORM_FINISH_YELLOW,
			PLATFORM_FINISH_PURPLE,
			PLATFORM_FINISH_AQUA,
		};
	}

	//
	namespace dt {
		enum class Directions {
			LEFT,
			RIGHT,
			UP,
			DOWN
		};
	}
