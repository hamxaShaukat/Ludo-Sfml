#include "Interface.h"


using namespace std;

Interface:: Interface(float h, float w)
{
	//---------------FONTS-------------------
	font[0].loadFromFile("Header_font.ttf");
	font[1].loadFromFile("Button.ttf");
	
	// ---------------HEADING-----------------
	text[0].setFont(font[0]);
	text[0].setFillColor(sf::Color::Black);
	text[0].setString("Qalanders");
	text[0].setCharacterSize(130);
	text[0].setPosition(sf::Vector2f(420, 80));
	//-----------------BUTTONS----------------

	text[1].setFont(font[1]);
	text[1].setFillColor(sf::Color::Black);
	text[1].setString("2 Player");
	text[1].setCharacterSize(60);
	text[1].setPosition(sf::Vector2f(250, 700));

	text[2].setFont(font[1]);
	text[2].setFillColor(sf::Color::Black);
	text[2].setString("3 Player");
	text[2].setCharacterSize(60);
	text[2].setPosition(sf::Vector2f(600, 700));

	text[3].setFont(font[1]);
	text[3].setFillColor(sf::Color::Black);
	text[3].setString("4 Player");
	text[3].setCharacterSize(60);
	text[3].setPosition(sf::Vector2f(900, 700));

	text[4].setFont(font[1]);
	text[4].setFillColor(sf::Color::Black);
	text[4].setString("6 Player");
	text[4].setCharacterSize(60);
	text[4].setPosition(sf::Vector2f(1200, 700));
}
void Interface::Draw(sf::RenderWindow& window)
{
	for (int i = 0; i < 5; i++)
	{
		window.draw(text[i]);
	}
}


