#pragma once
#include"Piece.h"
#include"Global.h"

using namespace std;

class Yellow_piece :public Piece
{
protected:
	vector<Position> First;
public:
	Yellow_piece(Position pos, char id, DIRECTION dir, COLOR col);
	/*void drawPiece(sf::RenderWindow& window) override;
	char getId_piece()override;
	bool Isfirst(Position P)override;*/
	void First_Init();
};

