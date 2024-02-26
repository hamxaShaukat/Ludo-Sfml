#pragma once
#include"Piece.h"
#include"Global.h"
#include<vector>

using namespace std;

class Blue_piece :public Piece
{
protected:
	vector<Position> First;
public:
	Blue_piece(Position pos, char id, DIRECTION dir,COLOR col);
	/*void drawPiece(sf::RenderWindow& window) override;
	char getId_piece()override;
	bool Isfirst(Position P)override;*/
	void First_Init();
};
