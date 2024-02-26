#pragma once

#include "Rectangle.h"
#include"Global.h"
#include"Shape.h"
#include"SFML/Graphics.hpp"
class Rectangle :public Shape
{
public:
	Rectangle(sf::Color filCol, sf::Color outCol, char key, Position pos);
	void drawShape(sf::RenderWindow& window);
	char getId()override;
};
