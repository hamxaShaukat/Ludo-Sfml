#pragma once
#include"Global.h"
#include<vector>
using namespace std;

class Board;
class Piece
{
protected:
	Position P_pos{};
	char P_id;
	COLOR P_col;
	bool isOutOfHome = false;
	DIRECTION direction;
	sf::Sprite image_piece;
	sf::Vector2f sp_pos;
	vector<Position> First{};
	Position Round;
public:
	Piece();
	Piece(Position pos, char id, DIRECTION dir,COLOR col);
	void drawPiece(sf::RenderWindow& window);
	char getId_piece();
	void movePiece(sf::RenderWindow& window, Position p);
	void movePiece(sf::RenderWindow& window, Position p,int n);
	void setDirection(DIRECTION dir);
	bool Isfirst(sf::Vector3f p);
	void First_Init();
	void setPiece(int i);
	Position getRound();
	Position getPosition_piece();
	DIRECTION getDir();
};


