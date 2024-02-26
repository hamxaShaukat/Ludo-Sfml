#pragma once
#include"SFML/Graphics.hpp"
using namespace std;

class Interface
{
public:
	sf::Font font[2];
	sf::Text text[5];

	Interface(float h, float w);
	void Draw(sf::RenderWindow& window);

};

