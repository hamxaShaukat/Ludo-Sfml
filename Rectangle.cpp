#include"SFML/Graphics.hpp"
#include"Shape.h"
#include"Rectangle.h"

Rectangle::Rectangle(sf::Color filCol, sf::Color outCol, char key, Position p)
	:Shape(filCol, outCol,key, p)
{

}
char Rectangle::getId()
{
	return this->Id;
}
void Rectangle::drawShape(sf::RenderWindow& window)
{
	if (this->Id == '?')
	{
		s.setTexture(Global::Ts[6]);
		s.setScale((float)(Global::dimSqr.x / Global::Ts[6].getSize().x), (float)(Global::dimSqr.y / Global::Ts[6].getSize().y));
		s.setPosition((float)(Global::dimSqr.x) * pos.ci, (float)(Global::dimSqr.y) * pos.ri);
		window.draw(s);
	}
	else if (this->Id == '$')
	{
		s.setTexture(Global::Ts[9]);
		s.setScale(sf::Vector2f(0.52,0.53));
		s.setPosition((float)Global::dimSqr.x * 6, (float)Global::dimSqr.y * 6);
		window.draw(s);
	}
	else if (this->Id == '#')
	{
		s.setTexture(Global::Ts[10]);
		s.setScale(sf::Vector2f(0.52,0.53));
		s.setPosition((float)Global::dimSqr.x * 15, (float)Global::dimSqr.y * 6);
		window.draw(s);
	}
	else if (this->Id == '@')
	{
		s.setTexture(Global::Ts[7]);
		s.setScale(sf::Vector2f(0.73,0.53));
		s.setPosition((float)Global::dimSqr.x * 6, (float)Global::dimSqr.y * 6);
		window.draw(s);
	}
	else if (this->Id == ',')
	{
		s.setTexture(Global::Ts[8]);
		s.setScale(sf::Vector2f(0.82, 0.53));
		s.setPosition((float)Global::dimSqr.x * 6, (float)Global::dimSqr.y * 7);
		window.draw(s);
	}

	// --------------------  HOME PIC------------------

	else if (this->Id == 'o')
	{
		s.setTexture(Global::Ts[17]);
		s.setScale(sf::Vector2f(0.52, 0.53));
		s.setPosition((float)Global::dimSqr.x * 0, (float)Global::dimSqr.y * 0);
		window.draw(s);
	}
	else if (this->Id == 'm')
	{
		s.setTexture(Global::Ts[18]);
		s.setScale(sf::Vector2f(0.52, 0.53));
		s.setPosition((float)Global::dimSqr.x * 9, (float)Global::dimSqr.y * 0);
		window.draw(s);
	}
	else if (this->Id == 'n')
	{
		s.setTexture(Global::Ts[19]);
		s.setScale(sf::Vector2f(0.52, 0.53));
		s.setPosition((float)Global::dimSqr.x * 18, (float)Global::dimSqr.y * 0);
		window.draw(s);
	}
	else if (this->Id == 'a')
	{
		s.setTexture(Global::Ts[20]);
		s.setScale(sf::Vector2f(0.52, 0.53));
		s.setPosition((float)Global::dimSqr.x * 0, (float)Global::dimSqr.y * 9);
		window.draw(s);
	}
	else if (this->Id == 'l')
	{
		s.setTexture(Global::Ts[21]);
		s.setScale(sf::Vector2f(0.52, 0.53));
		s.setPosition((float)Global::dimSqr.x * 9, (float)Global::dimSqr.y * 9);
		window.draw(s);
	}
	else if (this->Id == 'f')
	{
		s.setTexture(Global::Ts[22]);
		s.setScale(sf::Vector2f(0.52, 0.53));
		s.setPosition((float)Global::dimSqr.x * 18, (float)Global::dimSqr.y * 9);
		window.draw(s);
	}
	//--------------------4 PLAYER------------------------
	else if (this->Id == 'x')
	{
		s.setTexture(Global::Ts[17]);
		s.setScale(sf::Vector2f(0.73, 0.53));
		s.setPosition((float)Global::dimSqr.x * 0, (float)Global::dimSqr.y * 0);
		window.draw(s);
	}
	else if (this->Id == 'v')
	{
		s.setTexture(Global::Ts[18]);
		s.setScale(sf::Vector2f(0.73, 0.53));
		s.setPosition((float)Global::dimSqr.x * 9, (float)Global::dimSqr.y * 0);
		window.draw(s);
	}
	else if (this->Id == 'k')
	{
		s.setTexture(Global::Ts[20]);
		s.setScale(sf::Vector2f(0.73, 0.53));
		s.setPosition((float)Global::dimSqr.x * 0, (float)Global::dimSqr.y * 9);
		window.draw(s);
	}
	else if (this->Id == 'h')
	{
		s.setTexture(Global::Ts[21]);
		s.setScale(sf::Vector2f(0.73, 0.53));
		s.setPosition((float)Global::dimSqr.x * 9, (float)Global::dimSqr.y * 9);
		window.draw(s);
		}
	
	//---------------------HOME PICTURES------------------

	else if (this->Id == 'B' || this->Id=='+')
	{
		s.setTexture(Global::Ts[11]);
		s.setScale((float)(Global::dimSqr.x / Global::Ts[11].getSize().x), (float)(Global::dimSqr.y / Global::Ts[11].getSize().y));
		s.setPosition((float)(Global::dimSqr.x) * pos.ci, (float)(Global::dimSqr.y) * pos.ri);
		window.draw(s);
	}
	else if (this->Id == 'R' || this->Id == '!')
	{
		s.setTexture(Global::Ts[12]);
		s.setScale((float)(Global::dimSqr.x / Global::Ts[12].getSize().x), (float)(Global::dimSqr.y / Global::Ts[12].getSize().y));
		s.setPosition((float)(Global::dimSqr.x) * pos.ci, (float)(Global::dimSqr.y) * pos.ri);
		window.draw(s);
	}
	else if (this->Id == 'G' || this->Id == '*')
	{
		s.setTexture(Global::Ts[13]);
		s.setScale((float)(Global::dimSqr.x / Global::Ts[13].getSize().x), (float)(Global::dimSqr.y / Global::Ts[13].getSize().y));
		s.setPosition((float)(Global::dimSqr.x) * pos.ci, (float)(Global::dimSqr.y) * pos.ri);
		window.draw(s);
	}
	else if (this->Id == 'P' || this->Id == '&')
	{
		s.setTexture(Global::Ts[14]);
		s.setScale((float)(Global::dimSqr.x / Global::Ts[14].getSize().x), (float)(Global::dimSqr.y / Global::Ts[14].getSize().y));
		s.setPosition((float)(Global::dimSqr.x) * pos.ci, (float)(Global::dimSqr.y) * pos.ri);
		window.draw(s);
	}
	else if (this->Id == 'C' || this->Id == '%')
	{
		s.setTexture(Global::Ts[15]);
		s.setScale((float)(Global::dimSqr.x / Global::Ts[15].getSize().x), (float)(Global::dimSqr.y / Global::Ts[15].getSize().y));
		s.setPosition((float)(Global::dimSqr.x) * pos.ci, (float)(Global::dimSqr.y) * pos.ri);
		window.draw(s);
	}
	else if (this->Id == 'Y' || this->Id == '/')
	{
		s.setTexture(Global::Ts[16]);
		s.setScale((float)(Global::dimSqr.x / Global::Ts[16].getSize().x), (float)(Global::dimSqr.y / Global::Ts[16].getSize().y));
		s.setPosition((float)(Global::dimSqr.x) * pos.ci, (float)(Global::dimSqr.y) * pos.ri);
		window.draw(s);
	}

	else
	{
		int average = (Global::dimSqr.x + Global::dimSqr.y) / 2;
		sf::RectangleShape Rect;
		Rect.setSize(Global::dimSqr);
		Rect.setOutlineThickness(-(float)average / 24);
		Rect.setFillColor(fillColor);
		Rect.setOutlineColor(outlineColor);
		Rect.setPosition(Global::dimSqr.x * pos.ci, Global::dimSqr.y * pos.ri);
		window.draw(Rect);
	}
}