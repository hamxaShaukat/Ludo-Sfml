#pragma once
#include"SFML/Graphics.hpp";
#include"Board.h"
#include"Global.h"
class Dice
{
protected:
	//int rollNumber;
	sf::Sprite* dices;
public:
	Dice(sf::RenderWindow& window, sf::Texture *Ds, int nop);
	void drawDice(sf::RenderWindow& window, int& T);
	int getNumfromDice();
	void Rotation();
	bool isThrown(Position P,int nop);
	void showRollDice(sf::RenderWindow&window,Board b, int diceNum);
	void displayThrownDice(sf::RenderWindow& win,vector<int>n);
};

