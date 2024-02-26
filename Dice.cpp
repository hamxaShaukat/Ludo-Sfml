#include "Dice.h"
#include"SFML/Graphics.hpp"
#include"Global.h"
using namespace std;

Dice::Dice(sf::RenderWindow& window,sf::Texture *Ds,int nop)
{
	dices = new sf::Sprite[6];
	//------------LOADING----------------------
	Ds[0].loadFromFile("C_kani.jpeg");
	Ds[1].loadFromFile("C_two.jpeg");
	Ds[2].loadFromFile("C_trio.jpeg");
	Ds[3].loadFromFile("C_forth.jpeg");
	Ds[4].loadFromFile("C_five.jpeg");
	Ds[5].loadFromFile("C_sixer.jpeg");

	//------------TEXTURE---------------
	dices[0].setTexture(Ds[0]);
	dices[1].setTexture(Ds[1]);
	dices[2].setTexture(Ds[2]);
	dices[3].setTexture(Ds[3]);
	dices[4].setTexture(Ds[4]);
	dices[5].setTexture(Ds[5]);
	
	//-------------SIZE------------------
	dices[0].setScale(sf::Vector2f(0.2,0.2));
	dices[1].setScale(sf::Vector2f(0.2,0.2));
	dices[2].setScale(sf::Vector2f(0.2,0.2));
	dices[3].setScale(sf::Vector2f(0.2,0.2));
	dices[4].setScale(sf::Vector2f(0.2,0.2));
	dices[5].setScale(sf::Vector2f(0.2,0.2));
	//--------------POSITION-------------
	if (nop == 3 || nop == 6)
	{
		dices[0].setPosition(1400, 230);
		dices[1].setPosition(1400, 230);
		dices[2].setPosition(1400, 230);
		dices[3].setPosition(1400, 230);
		dices[4].setPosition(1400, 230);
		dices[5].setPosition(1400, 230);
	}
	else if (nop == 2 || nop == 4)
	{
		dices[0].setPosition(1250, 230);
		dices[1].setPosition(1250, 230);
		dices[2].setPosition(1250, 230);
		dices[3].setPosition(1250, 230);
		dices[4].setPosition(1250, 230);
		dices[5].setPosition(1250, 230);
	}
	//---------------ORIGIN--------------
	dices[0].setOrigin(30,4);
	dices[1].setOrigin(30,4);
	dices[2].setOrigin(30,4);
	dices[3].setOrigin(30,4);
	dices[4].setOrigin(30,4);
	dices[5].setOrigin(30,4);
}
bool Dice::isThrown(Position P,int nop)
{
	if (nop == 2 || nop == 4)
	{
		return P.ri == 14 && P.ci == 17;
	}
	else if (nop == 3 || nop == 6)
	{
		return P.ri == 14 && P.ci == 27;
	}
}
void Dice::drawDice(sf::RenderWindow& window,int &T)
{
	window.draw(dices[T-1]);
}
void Dice::Rotation()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			dices[i].rotate(i*j*5);
		}
	}
}
int Dice::getNumfromDice()
{
	srand(time(0));
	return rand() % 6+1;
}
void Dice::showRollDice(sf::RenderWindow& window,Board b,int diceNum)
{
	srand(time(0));
	int num=0;
	int timer = 0;
	while (window.isOpen())
	{
		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == e.Closed)
				window.close();
		}
		num = (rand() % 6) + 1;
		if (timer == 5)
		{
			switch (diceNum)
			{
			case(1):
				drawDice(window, diceNum);
				break;
			case(2):
				drawDice(window, diceNum);
				break;
			case(3):
				drawDice(window, diceNum);
				break;
			case(4):
				drawDice(window, diceNum);
				break;
			case(5):
				drawDice(window, diceNum);
				break;
			case(6):
				drawDice(window, diceNum);
				break;
			}
			b.Drawboxes_shape(window);
			b.Drawboxes_piece(window);
			window.display();
			break;


		}
		switch (num)
		{
		case(1):
			drawDice(window, num);
			break;
		case(2):
			drawDice(window, num);
			break;
		case(3):
			drawDice(window, num);
			break;
		case(4):
			drawDice(window, num);
			break;
		case(5):
			drawDice(window, num);
			break;
		case(6):
			drawDice(window, num);
			break;
		}
		timer++;
		b.Drawboxes_shape(window);
		b.Drawboxes_piece(window);
		window.display();
		sf::sleep(sf::seconds(0.1));
	}
	
}
void Dice::displayThrownDice(sf::RenderWindow& win,vector<int>n)
{
	for (int i = 0; i < n.size(); i++)
	{
		switch (n[i])
		{
		case(1):
			dices[0].setPosition(Global::dimSqr.y * 24 + (i*Global::dimSqr.x), Global::dimSqr.y * 3);
			win.draw(dices[0]);
			break;
		case(2):
			dices[1].setPosition(Global::dimSqr.y * 24 + (i*Global::dimSqr.x), Global::dimSqr.y * 3);
			win.draw(dices[1]);
			break;
		case(3):
			dices[2].setPosition(Global::dimSqr.y * 24 + (i*Global::dimSqr.x), Global::dimSqr.y * 3);
			win.draw(dices[2]);
			break;
		case(4):
			dices[3].setPosition(Global::dimSqr.y * 24 + (i*Global::dimSqr.x), Global::dimSqr.y * 3);
			win.draw(dices[3]);
			break;
		case(5):
			dices[4].setPosition(Global::dimSqr.y * 24 + (i*Global::dimSqr.x), Global::dimSqr.y * 3);
			win.draw(dices[4]);
			break;
		case(6):
			dices[5].setPosition(Global::dimSqr.y * 24 + (i * Global::dimSqr.x), Global::dimSqr.y * 3);
			win.draw(dices[5]);
			break;
		}
	}
}