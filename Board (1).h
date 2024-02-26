#pragma once
#include"Global.h"
#include"SFML/Graphics.hpp"
#include<fstream>
#include<vector>
#include"Piece.h"
#include"Shape.h"

using namespace std;

class Piece;
class Shape;
class Board
{
protected:
	sf::Vector2f dimemsion;
	sf::Sprite star;
	//Piece*** ps;
	COLOR col;
	vector<vector<vector<Piece>>> pieces{};
	vector<Position> checkPoints{};
	Shape*** shp;
	vector<Position> P_Home;
	int count_Blue = 0;
	int count_Red = 0;
	int count_Green = 0;
	int count_Purple = 0;
	int count_Cyan = 0;
	int count_Yellow = 0;
	int remain_dice_number = 0;
public:
	sf::Text ludo;
	Board(sf::RenderWindow& window, int nop);
	void Drawboxes_shape(sf::RenderWindow& window);
	void Drawboxes_piece(sf::RenderWindow& window);
	//void Updateboard(sf::RenderWindow& window, Position Src, Position Des);
	void Updateboard(sf::RenderWindow& window, sf::Vector3f Src, Position Des);
	//void Updateboard(sf::RenderWindow& window,Position Src,int rollNumber,int nop);
	void Updateboard(sf::RenderWindow& window, sf::Vector3f Src, int rollNumber, int nop);
	bool Isvalidpath(Position P)const;
	bool capturePiece(int);
	void setPiece();
	//Piece* getPieceAt(Position P)const;
	Piece getPieceAt(sf::Vector3f P)const;
	Shape* getShapeAt(Position P)const;
	Position Piece_kill(sf::RenderWindow& window, sf::Vector3f Src, int rollNumber, int nop);
	bool IsCaptured(sf::RenderWindow& window, sf::Vector3f Src, int diceNumber, int nop);
	void GoHome(sf::RenderWindow& window, sf::Vector3f Src, int rollNumber, int nop,vector<char>& Home);

};

