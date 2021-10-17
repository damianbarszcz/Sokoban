#include "pch.h"
#include "Counter.h"

	Counter::Counter(const std::string & prefixText, const sf::Vector2f & position, const sf::Font & font) : prefixText(prefixText),

	//Przypisanie parametrow poczatkowych
	number(0) { 
		text.setPosition(position); 
		text.setFont(font); 
		update();
	}

//---------------------------------
// Zliczanie krokow i przesuniec
//---------------------------------

	Counter Counter::operator++(int) {
		Counter copy(*this);
		number++;
		update();
		return copy;
	}

//---------------------------------
// Resetowanie statystyk
//---------------------------------
	void Counter::reset() {
		number = 0;
		update();
	}
