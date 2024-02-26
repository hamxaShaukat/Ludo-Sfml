#include "Piece.h"
#include"Global.h"
#include<vector>

using namespace std;

Piece::Piece()
{
	this->P_pos = {};
	this->P_id = ' ';
	this->P_col = BLUE;
	this->direction = RIGHT;
}
Piece::Piece(Position pos, char id, DIRECTION dir, COLOR col)
{
	this->P_pos = pos;
	this->P_id = id;
	this->direction = dir;
	this->P_col = col;
}
void Piece::movePiece(sf::RenderWindow& window, Position P)
{
	this->P_pos.ri = P.ri;
	this->P_pos.ci = P.ci;
	sp_pos.x = (float)P.ci * Global::dimSqr.x;
	sp_pos.y = (float)P.ri * Global::dimSqr.y;
	image_piece.setPosition(this->sp_pos);
}
void Piece::movePiece(sf::RenderWindow& window, Position P,int n)
{
    this->P_pos.ri = P.ri;
    this->P_pos.ci = P.ci;
}
void Piece::setDirection(DIRECTION dir)
{
	this->direction = dir;

}
DIRECTION Piece::getDir()
{
	return this->direction;
}
Position Piece::getPosition_piece()
{
	return this->P_pos;
}
void Piece::drawPiece(sf::RenderWindow& window)
{
	switch(this->P_id)
	{
	    case('b'):
		{
			image_piece.setTexture(Global::Ts[0]);
			image_piece.setScale((float)Global::dimSqr.x / Global::Ts[0].getSize().x, (float)Global::dimSqr.y / Global::Ts[0].getSize().y);
			image_piece.setPosition((float)Global::dimSqr.x * P_pos.ci, (float)Global::dimSqr.y * P_pos.ri);
			window.draw(image_piece);
		}
		break;
		case('r'):
		{
			image_piece.setTexture(Global::Ts[1]);
			image_piece.setScale((float)Global::dimSqr.x / Global::Ts[1].getSize().x, (float)Global::dimSqr.y / Global::Ts[1].getSize().y);
			image_piece.setPosition((float)Global::dimSqr.x * P_pos.ci, (float)Global::dimSqr.y * P_pos.ri);
			window.draw(image_piece);
		}
		break;
		case('g'):
		{
			image_piece.setTexture(Global::Ts[2]);
			image_piece.setScale((float)Global::dimSqr.x / Global::Ts[2].getSize().x, (float)Global::dimSqr.y / Global::Ts[2].getSize().y);
			image_piece.setPosition((float)Global::dimSqr.x * P_pos.ci, (float)Global::dimSqr.y * P_pos.ri);
			window.draw(image_piece);
		}
		break;
		case('y'):
		{
			image_piece.setTexture(Global::Ts[3]);
			image_piece.setScale((float)Global::dimSqr.x / Global::Ts[3].getSize().x, (float)Global::dimSqr.y / Global::Ts[3].getSize().y);
			image_piece.setPosition((float)Global::dimSqr.x * P_pos.ci, (float)Global::dimSqr.y * P_pos.ri);
			window.draw(image_piece);
		}
		break;
		case('c'):
		{
			image_piece.setTexture(Global::Ts[4]);
			image_piece.setScale((float)Global::dimSqr.x / Global::Ts[4].getSize().x, (float)Global::dimSqr.y / Global::Ts[4].getSize().y);
			image_piece.setPosition((float)Global::dimSqr.x * P_pos.ci, (float)Global::dimSqr.y * P_pos.ri);
			window.draw(image_piece);
		}
		break;
		case('p'):
		{
			image_piece.setTexture(Global::Ts[5]);
			image_piece.setScale((float)Global::dimSqr.x / Global::Ts[5].getSize().x, (float)Global::dimSqr.y / Global::Ts[5].getSize().y);
			image_piece.setPosition((float)Global::dimSqr.x * P_pos.ci, (float)Global::dimSqr.y * P_pos.ri);
			window.draw(image_piece);
		}
		break;
	}

}
char Piece::getId_piece()
{
	return this->P_id;
}
bool Piece::Isfirst(sf::Vector3f p)
{
	First_Init();
	for (int i = 0; i < 4; i++)
	{
		if (First[i].ri == int(p.y) && First[i].ci == int(p.x))
		{
			return true;
		}
	}
	return false;
}
void Piece::First_Init()
{
	if (this->P_id == 'b')
	{
		Position ps[4];
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
	else if (this->P_id == 'r')
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
	else if (this->P_id == 'g')
	{
		Position ps[4];
		ps[0].ri = 1;
		ps[0].ci = 19;
		ps[1].ri = 1;
		ps[1].ci = 22;
		ps[2].ri = 4;
		ps[2].ci = 19;
		ps[3].ri = 4;
		ps[3].ci = 22;
		for (int i = 0; i < 4; i++)
		{
			First.push_back(ps[i]);
		}
	}
	else if (this->P_id == 'p')
	{
		Position ps[4];
		ps[0].ri = 10;
		ps[0].ci = 19;
		ps[1].ri = 10;
		ps[1].ci = 22;
		ps[2].ri = 13;
		ps[2].ci = 19;
		ps[3].ri = 13;
		ps[3].ci = 22;
		for (int i = 0; i < 4; i++)
		{
			First.push_back(ps[i]);
		}
	}
	else if (this->P_id == 'c')
	{
		Position ps[4];
		ps[0].ri = 10;
		ps[0].ci = 10;
		ps[1].ri = 10;
		ps[1].ci = 13;
		ps[2].ri = 13;
		ps[2].ci = 10;
		ps[3].ri = 13;
		ps[3].ci = 13;
		for (int i = 0; i < 4; i++)
		{
			First.push_back(ps[i]);
		}
	}
	else if (this->P_id == 'y')
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
}
void Piece::setPiece(int i)
{
	sp_pos.x = (float)P_pos.ci * (Global::dimSqr.x/2);
	sp_pos.x += i * 15;
	this->image_piece.setPosition(sp_pos);
}
Position Piece::getRound()
{
	return this->Round;
}