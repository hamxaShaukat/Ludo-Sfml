#include "Shape.h"
#include<iostream>
using namespace std;

Shape::Shape(sf::Color c1, sf::Color c2,char id, Position position)
{
	this->fillColor = c1;
	this->outlineColor = c2;
	this->Id = id;
	this->pos = position;
}
