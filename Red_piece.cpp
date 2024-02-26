#include "Red_piece.h"
#include"Global.h"
#include<iostream>

using namespace std;

Red_piece::Red_piece(Position pos, char id, DIRECTION dir, COLOR col)
	:Piece(pos, id, dir,col)
{

}
//void Red_piece::drawPiece(sf::RenderWindow& window)
//{
//	image_piece.setTexture(Global::Ts[1]);
//	image_piece.setScale((float)Global::dimSqr.x / Global::Ts[1].getSize().x, (float)Global::dimSqr.y / Global::Ts[1].getSize().y);
//	image_piece.setPosition((float)Global::dimSqr.x * P_pos.ci, (float)Global::dimSqr.y * P_pos.ri);
//	window.draw(image_piece);
//}
//char Red_piece::getId_piece()
//{
//	return this->P_id;
//}
//bool Red_piece::Isfirst(Position P)
//{
//	First_Init();
//	for (int i = 0; i < 4; i++)
//	{
//		if (First[i].ri ==P.ri && First[i].ci == P.ci)
//		{
//			return true;
//		}
//	}
//	return false;
//}
void Red_piece::First_Init()
{
	Position ps[4];
	ps[0].ri = 1;
	ps[0].ci = 10;
	ps[1].ri = 1;
	ps[1].ci = 13;
	ps[2].ri = 4;
	ps[2].ci = 10;
	ps[3].ri = 4;
	ps[3].ci = 13;
	for (int i = 0; i < 4; i++)
	{
		First.push_back(ps[i]);
	}
}