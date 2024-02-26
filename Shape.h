#pragma once
#include"SFML/Graphics.hpp"
#include"Global.h"

class Shape
{
protected:
	sf::Color fillColor;
	sf::Color outlineColor;
	char Id;
	Position pos{};
	sf::Sprite s;
public:
	Shape(sf::Color c1,sf::Color c2,char id,Position pos);
	virtual void drawShape(sf::RenderWindow& window)=0;
	virtual char getId()=0;
};

