#include"SFML/Graphics.hpp"
#include"Interface.h"
#include<iostream>
#include"Ludo.h"

using namespace std;

int main()
{
	sf::RenderWindow win(sf::VideoMode::getFullscreenModes()[2], "OPTION");
	Interface A((float)win.getSize().y, (float)win.getSize().x);
	sf::Texture pic;
	pic.loadFromFile("Ludo_pic.jpg");
	sf::Sprite spr;
	spr.setScale(sf::Vector2f(1,1));
	spr.setTexture(pic);
	//-------------------BACKGROUND IMAGE--------------

	while (win.isOpen())
	{
		sf::Event event;
		while (win.pollEvent(event))
		{
			if (event.type == event.Closed)
			{
				win.close();
			}
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i mousePosition = sf::Mouse::getPosition(win);
			if (A.text[0].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
			{
				A.text[0].setFillColor(sf::Color::Color(22, 160, 133));
			}
			if (A.text[1].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
			{
				A.text[1].setFillColor(sf::Color::Color(31, 97, 141));
				Ludo l1(win,2);
				l1.setNop(2);
				l1.play(win);
			}
			else
			{
				A.text[1].setFillColor(sf::Color::Black);
			}
			if (A.text[2].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
			{
				A.text[2].setFillColor(sf::Color::Blue);
				Ludo l2(win, 3);
				l2.setNop(3);
				l2.play(win);
			}
			else
			{
				A.text[2].setFillColor(sf::Color::Black);
			}
			if (A.text[3].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
			{
				A.text[3].setFillColor(sf::Color::Color(31,97, 141));
				Ludo l3(win,4);
				l3.setNop(4);
				l3.play(win);
			}
			else
			{
				A.text[3].setFillColor(sf::Color::Black);
			}
			if (A.text[4].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition)))
			{
				A.text[4].setFillColor(sf::Color::Color(31,97,141));
				Ludo l4(win,6);
				l4.setNop(6);
				l4.play(win);
			}
			else
			{
				A.text[4].setFillColor(sf::Color::Black);
			}

		}
		win.clear();
		win.draw(spr);
		A.Draw(win);
		win.display();
	}
	return 0;
}

