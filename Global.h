#pragma once
#include"SFML/Graphics.hpp"
enum COLOR{BLUE,RED,GREEN,YELLOW,CYAN,PURPLE};

#define Rows 15
#define Columns 24

enum DIRECTION{UP,DOWN,RIGHT,LEFT};
struct Position
{
	int ri;
	int ci;
};
class Global 
{
public:
	static sf::Vector2f dimSqr;
	static sf::Texture* Ts;
	static sf::Font f;
	void static getRowColbyLeftClick(int& rpos, int& cpos,sf::RenderWindow& window);
	void static getRowColbyLeftClick(float& rpos, float& cpos, sf::RenderWindow& window);



};


