#pragma once

#include <SFML/Graphics.hpp>

//---------------------------------
//---------------------------------
//  Klasa zliczajaca 
//	statystyki gry
//---------------------------------
//---------------------------------

class Counter : public sf::Drawable{

	public:

		Counter(const std::string& prefixText, const sf::Vector2f& position, const sf::Font& font);

		Counter operator++(int);

		void reset();

		std::string toString() { return std::to_string(number); }

	private:

		int number;

		sf::Text text;

		std::string prefixText;

		void update() { text.setString(prefixText + std::to_string(number)); }

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const { target.draw(text); }
};