#include "Yellow_piece.h"
#include"Global.h"
#include<iostream>

using namespace std;

Yellow_piece::Yellow_piece(Position pos, char id, DIRECTION dir, COLOR col)
	:Piece(pos, id, dir,col)
{

}
//void Yellow_piece::drawPiece(sf::RenderWindow& window)
//{
//	image_piece.setTexture(Global::Ts[3]);
//	image_piece.setScale((float)Global::dimSqr.x / Global::Ts[3].getSize().x, (float)Global::dimSqr.y / Global::Ts[3].getSize().y);
//	image_piece.setPosition((float)Global::dimSqr.x * P_pos.ci, (float)Global::dimSqr.y * P_pos.ri);
//	window.draw(image_piece);
//}
//char Yellow_piece::getId_piece()
//{
//	return this->P_id;
//}
//bool Yellow_piece::Isfirst(Position P)
//{
//	First_Init();
//	for (int i = 0; i < 4; i++)
//	{
//		if (First[i].ri == P.ri && First[i].ci == P.ci)
//		{
//			return true;
//		}
//	}
//	return false;
//}
void Yellow_piece::First_Init()
{
	Position ps[4];
	ps[0].ri = 10;
	ps[0].ci = 1;
	ps[1].ri = 10;
	ps[1].ci = 4;
	ps[2].ri = 13;
	ps[2].ci = 1;
	ps[3].ri = 13;
	ps[3].ci = 4;
	for (int i = 0; i < 4; i++)
	{
		First.push_back(ps[i]);
	}
}

