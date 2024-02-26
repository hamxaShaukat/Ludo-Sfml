#include "Blue_piece.h"
#include"Global.h"
#include<iostream>

using namespace std;

Blue_piece::Blue_piece(Position pos, char id, DIRECTION dir,COLOR col)
	:Piece(pos,id,dir,col)
{
}
//void Blue_piece::drawPiece(sf::RenderWindow& window)
//{
//	image_piece.setTexture(Global::Ts[0]);
//	image_piece.setScale((float)Global::dimSqr.x / Global::Ts[0].getSize().x, (float)Global::dimSqr.y / Global::Ts[0].getSize().y);
//	image_piece.setPosition((float)Global::dimSqr.x * P_pos.ci,(float) Global::dimSqr.y * P_pos.ri);
//	window.draw(image_piece);
//}
//char Blue_piece::getId_piece()
//{
//	return this->P_id;
//}
//bool Blue_piece::Isfirst(Position P)
//{
//	First_Init();
//	for (int i = 0; i < 4; i++)
//    {
//		if (First[i].ri == P.ri && First[i].ci == P.ci)
//		{
//			return true;
//		}
//	}
//	return false;
//}
void Blue_piece::First_Init()
{

	Position ps[4];
	//if (nop == 2 || nop == 3 || nop == 4 || nop==4)
	{
		ps[0].ri = 1;
		ps[0].ci = 1;
		ps[1].ri = 1;
		ps[1].ci = 4;
		ps[2].ri = 4;
		ps[2].ci = 1;
		ps[3].ri = 4;
		ps[3].ci = 4;
		for (int i = 0; i < 4; i++)
		{
			First.push_back(ps[i]);
		}
	}
}
