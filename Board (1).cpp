#include "Board.h"
#include"Global.h"
#include"Piece.h"
#include<iostream>
#include<fstream>
#include"Rectangle.h"
#include"Shape.h"
#include"Blue_piece.h"
#include"Cyan_piece.h"
#include"Yellow_piece.h"
#include"Green_piece.h"
#include"Purple_piece.h"
#include"Red_piece.h"
#include<vector>
using namespace std;

void Board::Drawboxes_shape(sf::RenderWindow& window)
{
	for (int i = 0; i < dimemsion.y; i++)
	{
		for (int j = 0; j < dimemsion.x; j++)
		{
			if(shp[i][j] != nullptr)
				this->shp[i][j]->drawShape(window);
		}
	}
}
void Board::Drawboxes_piece(sf::RenderWindow& window)
{
	for (int i = 0; i < dimemsion.y; i++)
	{
		for (int j = 0; j < dimemsion.x; j++)
		{
			for (int k = 0; k < pieces[i][j].size(); k++)
			{
				pieces[i][j][k].drawPiece(window);
			}
		}
	}
}
//Piece* Board::getPieceAt(Position P)const
//{
//	return this->ps[P.ri][P.ci];
//}
Piece Board::getPieceAt(sf::Vector3f P)const
{
	return this->pieces[P.y][P.x][P.z];	
}
Shape* Board::getShapeAt(Position P)const
{
	return this->shp[P.ri][P.ci];
}
bool Board::Isvalidpath(Position P)const
{
	char key = this->shp[P.ri][P.ci]->getId();
	if (key == '.' || key == '!' || key == '*' || key == '%' || key == '&' || key == '/' || key == '+' || key == '?')
		return true;
	else
		return false;
}
void Board::Updateboard(sf::RenderWindow& window, sf::Vector3f src, Position Des)
{
	/*this->ps[Src.ri][Src.ci]->movePiece(window, Des);
	this->ps[Des.ri][Des.ci] = this->ps[Src.ri][Src.ci];
	this->ps[Src.ri][Src.ci] = nullptr;*/
	pieces[src.y][src.x][src.z].movePiece(window, Des);
	pieces[Des.ri][Des.ci].push_back(pieces[src.y][src.x][src.z]);
	pieces[src.y][src.x].erase(pieces[src.y][src.x].begin() + src.z);
}
void Board::Updateboard(sf::RenderWindow& window, sf::Vector3f Src, int rollNumber, int nop)
{
	Position Des;
	Des.ri = Src.y, Des.ci = Src.x;
	int countDice = 0;
	sf::Event e;
	char key;
	while (true)
	{
		DIRECTION d = this->pieces[Src.y][Src.x][Src.z].getDir();
		//-----------------------3 & 6 PLAYERS------------------------
		if (nop == 6 || nop == 3)
		{
			switch (d)
			{
			case(UP):
			{
				key = this->shp[Des.ri][Des.ci]->getId();
				if (key != '<')
				{
					if (Des.ci == 6 && (Des.ri >= 0 && Des.ri <= 6))
					{
						Des.ri--;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}
					else if (Des.ci == 15 && (Des.ri >= 0 && Des.ri <= 6))
					{
						Des.ri--;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}
					else if (Des.ci == 0 && (Des.ri >= 6 && Des.ri <= 8))
					{
						Des.ri--;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}

				}
				if ((key == '<' && Des.ci == 0) || (key == '<' && Des.ci == 6) || (key == '<' && Des.ci == 15))
				{
					pieces[Src.y][Src.x][Src.z].setDirection(RIGHT);
				}
				if (key != '>')
				{
					if (((Des.ci == 6 && (Des.ri >= 8 && Des.ri <= 14))) || ((Des.ci == 15 && (Des.ri >= 8 && Des.ri <= 14))))
					{
						Des.ri--;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}
					/*else if ((Des.ci == 0 && (Des.ri >= 6 && Des.ri <= 8)))
					{
						Des.ri--;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}*/

				}
				if ((key == '>' && Des.ci == 6) || (key == '>' && Des.ci == 15))
				{
					Des.ri--;
					pieces[Src.y][Src.x][Src.z].setDirection(LEFT);
				}

			}
			break;
			case(DOWN):
			{
				key = this->shp[Des.ri][Des.ci]->getId();
				if (key != '<')
				{
					if (Des.ci == 8 && (Des.ri >= 0 && Des.ri <= 6))
					{
						Des.ri++;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}
					else if (Des.ci == 17 && (Des.ri >= 0 && Des.ri <= 6))
					{
						Des.ri++;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}
				}
				if ((key == '<' && Des.ci == 17) || (key == '<' && Des.ci == 8))
				{
					Des.ri++;
					pieces[Src.y][Src.x][Src.z].setDirection(RIGHT);
				}
				if (key != '>')
				{
					if (((Des.ci == 8 && (Des.ri >= 8 && Des.ri <= 14))) || ((Des.ci == 17 && (Des.ri >= 8 && Des.ri <= 14))))
					{
						Des.ri++;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}
					else if ((Des.ci == 23 && (Des.ri >= 6 && Des.ri <= 8)))
					{
						Des.ri++;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}

				}
				else if ((key == '>' && Des.ci == 8) || (key == '>' && Des.ci == 17) || (key == '>' && Des.ci == 23))
				{
					pieces[Src.y][Src.x][Src.z].setDirection(LEFT);
				}
			}
			break;
			case(LEFT):
			{
				key = this->shp[Des.ri][Des.ci]->getId();
				if (key != 'd')
				{
					if (Des.ri == 8 && (Des.ci >= 18 && Des.ci <= 23))
					{
						Des.ci--;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}
					if (Des.ri == 8 && (Des.ci >= 9 && Des.ci <= 15))
					{
						Des.ci--;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}

				}
				if (key == 'd' && Des.ri == 8)
				{
					Des.ci--;
					pieces[Src.y][Src.x][Src.z].setDirection(DOWN);
				}
				if (key != 'u')
				{
					if ((Des.ri == 8 && (Des.ci >= 0 && Des.ci <= 6)))
					{
						Des.ci--;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}
					else if ((Des.ri == 14 && (Des.ci >= 6 && Des.ci <= 8)))
					{
						Des.ci--;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}
					else if ((Des.ri == 14 && (Des.ci >= 15 && Des.ci <= 17)))
					{
						Des.ci--;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}


				}
				if ((key == 'u' && Des.ri == 8) || (key == 'u' && Des.ri == 14))
				{
					pieces[Src.y][Src.x][Src.z].setDirection(UP);
				}

			}
			break;
			case(RIGHT):
			{
				key = this->shp[Des.ri][Des.ci]->getId();
				if (key != 'u')
				{
					if (Des.ri == 6 && (Des.ci >= 0 && Des.ci <= 5))
					{
						Des.ci++;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}
					if (Des.ri == 6 && (Des.ci >= 8 && Des.ci <= 14))
					{
						Des.ci++;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}
				}
				if (key == 'u' && Des.ri == 6)
				{
					Des.ci++;
					pieces[Src.y][Src.x][Src.z].setDirection(UP);
				}
				if (key != 'd')
				{
					if (((Des.ri == 0 && (Des.ci >= 6 && Des.ci <= 8))) || ((Des.ri == 0 && (Des.ci >= 15 && Des.ci <= 17))))
					{
						Des.ci++;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}
					else if ((Des.ri == 6 && (Des.ci >= 17 && Des.ci <= 23)))
					{
						Des.ci++;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}

				}
				if ((key == 'd' && Des.ri == 0) || (key == 'd' && Des.ri == 6))
				{
					pieces[Src.y][Src.x][Src.z].setDirection(DOWN);
				}
			}
			default:
				break;
			}
			if (countDice == rollNumber)
			{
				Updateboard(window, Src, Des);
				setPiece();
				break;

			}
			/*window.clear();
			pieces[Src.y][Src.x][Src.z].drawPiece(window);
			window.display();
			sf::sleep(sf::seconds(0.01));*/
		}
		//-------------------------- 2 & 4 PLAYERS----------------------
		else if (nop == 4 || nop == 2)
		{
			switch (d)
			{
			case(UP):
			{
				key = this->shp[Des.ri][Des.ci]->getId();
				if (key != '<')
				{
					if (Des.ci == 6 && (Des.ri >= 0 && Des.ri <= 6))
					{
						Des.ri--;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}
					else if (Des.ci == 0 && (Des.ri >= 6 && Des.ri <= 8))
					{
						Des.ri--;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}

				}
				if ((key == '<' && Des.ci == 6)|| (key == '<' && Des.ci == 0) )
				{
					pieces[Src.y][Src.x][Src.z].setDirection(RIGHT);
				}
				if (key != '>')
				{
					if ((Des.ci == 6 && (Des.ri >= 8 && Des.ri <= 14)))
					{
						Des.ri--;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}
				}
				if ((key == '>' && Des.ci == 6))
				{
					Des.ri--;
					pieces[Src.y][Src.x][Src.z].setDirection(LEFT);
				}

			}
			break;
			case(DOWN):
			{

				key = this->shp[Des.ri][Des.ci]->getId();
				if (key != '<')
				{
					if (Des.ci == 8 && (Des.ri >= 0 && Des.ri <= 6))
					{
						Des.ri++;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}
				}
				if ((key == '<' && Des.ci == 8))
				{
					Des.ri++;
					pieces[Src.y][Src.x][Src.z].setDirection(RIGHT);
				}
				if (key != '>')
				{
					if ((Des.ci == 8 && (Des.ri >= 8 && Des.ri <= 14)))
					{
						Des.ri++;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}
					else if (Des.ci == 14 && (Des.ri >= 6 && Des.ri <= 8))
					{
						Des.ri++;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}
				}
				else if ((key == '>' && Des.ci == 8) ||((key == '>' && Des.ci == 14)))
				{
					pieces[Src.y][Src.x][Src.z].setDirection(LEFT);
				}

			}
			break;
			case(LEFT):
			{

				key = this->shp[Des.ri][Des.ci]->getId();
				if (key != 'd')
				{
					if (Des.ri == 8 && (Des.ci >= 8 && Des.ci <= 14))
					{
						Des.ci--;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}
				}
				if (key == 'd' && Des.ri == 8)
				{
					Des.ci--;
					pieces[Src.y][Src.x][Src.z].setDirection(DOWN);
				}
				if (key != 'u')
				{
					if ((Des.ri == 8 && (Des.ci >= 0 && Des.ci <= 6)))
					{
						Des.ci--;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}	
					else if (Des.ri == 14 && (Des.ci >= 6 && Des.ci <= 8))
					{
						Des.ci--;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}
				}
				if ((key == 'u' && Des.ri == 8) || (key == 'u' && Des.ri == 14))
				{
					pieces[Src.y][Src.x][Src.z].setDirection(UP);
				}

			}
			break;
			case(RIGHT):
			{
				key = this->shp[Des.ri][Des.ci]->getId();
				if (key != 'u')
				{
					if (Des.ri == 6 && (Des.ci >= 0 && Des.ci <= 5))
					{
						Des.ci++;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}
				}
				if (key == 'u' && Des.ri == 6)
				{
					Des.ci++;
					pieces[Src.y][Src.x][Src.z].setDirection(UP);
				}
				if (key != 'd')
				{
					if ((Des.ri == 6 && (Des.ci >= 8 && Des.ci <= 14)))
					{
						Des.ci++;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}
					else if (Des.ri == 0 && (Des.ci >= 6 && Des.ci <= 8))
					{
						Des.ci++;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}

				}
				if ((key == 'd' && Des.ri == 6) || (key == 'd' && Des.ri == 0))
				{
					pieces[Src.y][Src.x][Src.z].setDirection(DOWN);
				}
			}
			default:
				break;
			}
			if (countDice == rollNumber)
			{
				Updateboard(window, Src, Des);
				setPiece();
				break;

			}

		}
	/*	window.clear();
		pieces[Src.y][Src.x][Src.z].drawPiece(window);
		window.display();
		sf::sleep(sf::seconds(0.5));*/
	}
}
Board::Board(sf::RenderWindow& window, int nop)
{
	if (nop == 6)
	{
		this->dimemsion.x = 24;
		this->dimemsion.y = 15;
		Global::dimSqr.x = (float)window.getSize().x / (dimemsion.x + 7);
		Global::dimSqr.y = (float)window.getSize().y / (dimemsion.y + 2);
		Global::f.loadFromFile("Text_7.ttf");
		ludo.setCharacterSize(40);
		//	ludo.setFillColor(sf::Color::Color(69, 179, 157));
		ludo.setOutlineThickness(5);
		//	ludo.setOutlineColor(sf::Color::Color(52, 152, 219));
		//	ludo.setFillColor(sf::Color::Color(211, 84, 0));
		ludo.setFont(Global::f); ludo.setString("QALANDARS");
		ludo.setPosition((float)((Global::dimSqr.x * dimemsion.x) / 2) - 140
			, ((Global::dimSqr.y * dimemsion.y) / 2) - 25);
		/*background.setTexture(Global::Ts[7]);
		background.setScale((float)window.getSize().x / Global::Ts[7].getSize().x,
			(float)window.getSize().y / Global::Ts[7].getSize().y);*/
			/*star.setTexture(Global::Ts[6]);
			star.setScale((float)window.getSize().x / Global::Ts[6].getSize().x,
				(float)window.getSize().y / Global::Ts[7].getSize().y);*/
		Position P;
		ifstream Rdr("6_player.txt");
		ofstream Wrtr("6_player_saving.txt");
		char key;
		DIRECTION direction;
		pieces.resize(dimemsion.y);
		this->shp = new Shape * *[dimemsion.y];

		for (int i = 0; i < dimemsion.y; i++)
		{
			this->shp[i] = new Shape * [dimemsion.x];
			for (int j = 0; j < dimemsion.x; j++)
			{
				P.ri = i, P.ci = j;
				Rdr >> key;
				switch (key)
				{
				case('+'):
				case('B'):
					this->shp[i][j] = new Rectangle(sf::Color::Blue, sf::Color::Black, key, P);
					break;
				case('*'):
				case('G'):
					this->shp[i][j] = new Rectangle(sf::Color::Color(25, 111, 61), sf::Color::Black, key, P);
					break;
				case('!'):
				case('R'):
					this->shp[i][j] = new Rectangle(sf::Color::Color(222, 18, 27), sf::Color::Black, key, P);
					break;
				case('&'):
				case('P'):
					this->shp[i][j] = new Rectangle(sf::Color::Color(150, 43, 123), sf::Color::Black, key, P);
					break;
				case('%'):
				case('C'):
					this->shp[i][j] = new Rectangle(sf::Color::Color(30, 223, 222), sf::Color::Black, key, P);
					break;
				case('/'):
				case('Y'):
					this->shp[i][j] = new Rectangle(sf::Color::Color(249, 241, 11), sf::Color::Black, key, P);
					break;
				case('?'):
					this->shp[i][j] = new Rectangle(sf::Color::Color(52, 73, 94), sf::Color::Black, key, P);
					break;
				case('_'):
					if ((i >= 0 && i <= 5) && (j >= 0 && j <= 5))
						this->shp[i][j] = new Rectangle(sf::Color::Blue, sf::Color::Blue, key, P);
					else if ((i >= 0 && i <= 5) && (j >= 9 && j <= 14))
						this->shp[i][j] = new Rectangle(sf::Color::Color(222, 18, 27), sf::Color::Color(222, 18, 27), key, P);
					else if ((i >= 0 && i <= 5) && (j >= 18 && j <= 23))
						this->shp[i][j] = new Rectangle(sf::Color::Color(25, 111, 61), sf::Color::Color(25, 111, 61), key, P);
					else if ((i >= 9 && i <= 14) && (j >= 0 && j <= 5))
						this->shp[i][j] = new Rectangle(sf::Color::Color(249, 241, 11), sf::Color::Color(249, 241, 11), key, P);
					else if ((i >= 9 && i <= 14) && (j >= 9 && j <= 14))
						this->shp[i][j] = new Rectangle(sf::Color::Color(30, 223, 222), sf::Color::Color(30, 223, 222), key, P);
					else if ((i >= 9 && i <= 14) && (j >= 18 && j <= 23))
						this->shp[i][j] = new Rectangle(sf::Color::Color(150, 43, 123), sf::Color::Color(150, 43, 123), key, P);

					break;

				case('#'):
				case('$'):
				case(','):
				case('~'):
				case('b'):
				case('r'):
				case('g'):
				case('y'):
				case('p'):
				case('c'):
				case('o'):
				case('m'):
				case('n'):
				case('a'):
				case('f'):
				case('l'):


					this->shp[i][j] = new Rectangle(sf::Color::White, sf::Color::White, key, P);
					break;

				case('.'):
				case('u'):
				case('>'):
				case('<'):
				case('d'):
				case('z'):
				case(':'):
				case('s'):
				case('e'):
				case('w'):
				case('q'):
					this->shp[i][j] = new Rectangle(sf::Color::Color(178,186,187), sf::Color::Black, key, P);
					break;
				default:
					cout << "not found" << key;
					break;

				}
			}

		}


		for (int i = 0; i < dimemsion.y; i++)
		{
			for (int j = 0; j < dimemsion.x; j++)
			{
				P.ri = i, P.ci = j;
				char sym;

				sym = this->shp[i][j]->getId();
				Wrtr << sym;

			}
			Wrtr << endl;
		}


		// ------------------------PIECE_LOADING---------------------
		ifstream Rdr_1("6_player_saving.txt");

		for (int i = 0; i < dimemsion.y; i++)
		{
			pieces[i].resize(dimemsion.x);
			for (int j = 0; j < dimemsion.x; j++)
			{
				P.ri = i, P.ci = j;
				Rdr_1 >> key;
				switch (key)
				{
					/*case('b'):
						this->ps[i][j] = new Blue_piece(P, key, RIGHT,BLUE);
						break;
					case('r'):
						this->ps[i][j] = new Red_piece(P, key, DOWN,RED);
						break;
					case('g'):
						this->ps[i][j] = new Green_piece(P, key, DOWN,GREEN);
						break;
					case('y'):
						this->ps[i][j] = new Yellow_piece(P, key, UP,YELLOW);
						break;
					case('c'):
						this->ps[i][j] = new Cyan_piece(P, key, UP,CYAN);
						break;
					case('p'):
						this->ps[i][j] = new Purple_piece(P, key, LEFT,PURPLE);
						break;
					default:
						this->ps[i][j] = nullptr;
						break;*/
				case('b'):
					pieces[i][j].push_back(Blue_piece(P, key, RIGHT, BLUE));
					break;
				case('r'):
					pieces[i][j].push_back(Red_piece(P, key, DOWN, RED));
					break;
				case('g'):
					pieces[i][j].push_back(Green_piece(P, key, DOWN, GREEN));
					break;
				case('y'):
					pieces[i][j].push_back(Yellow_piece(P, key, UP, YELLOW));
					break;
				case('c'):
					pieces[i][j].push_back(Cyan_piece(P, key, UP, CYAN));
					break;
				case('p'):
					pieces[i][j].push_back(Purple_piece(P, key, LEFT, PURPLE));
					break;
					//default:
					//	this->ps[i][j] = nullptr;
					//	break;
				}
			}
		}
	}
	else if (nop == 4)
	{
		this->dimemsion.x = 15;
		this->dimemsion.y = 15;
		Global::dimSqr.x = (float)window.getSize().x / (dimemsion.x + 7);
		Global::dimSqr.y = (float)window.getSize().y / (dimemsion.y + 2);
		Global::f.loadFromFile("Text_7.ttf");
		ludo.setCharacterSize(30);
		//	ludo.setFillColor(sf::Color::Color(69, 179, 157));
		ludo.setOutlineThickness(5);
		//	ludo.setOutlineColor(sf::Color::Color(52, 152, 219));
		//	ludo.setFillColor(sf::Color::Color(211, 84, 0));
		ludo.setFont(Global::f); ludo.setString("QALANDARS");
		ludo.setPosition((float)((Global::dimSqr.x * dimemsion.x) / 2) - 100
			, ((Global::dimSqr.y * dimemsion.y) / 2) - 20);
		/*background.setTexture(Global::Ts[7]);
		background.setScale((float)window.getSize().x / Global::Ts[7].getSize().x,
			(float)window.getSize().y / Global::Ts[7].getSize().y);
		star.setTexture(Global::Ts[6]);
		star.setScale((float)window.getSize().x / Global::Ts[6].getSize().x,
			(float)window.getSize().y / Global::Ts[7].getSize().y);*/
		sf::Color::Yellow; sf::Color orange(255, 165, 0);
		Position P;
		ifstream Rdr("4_player.txt");
		ofstream Wrtr("4_player_saving.txt");
		char key;
		DIRECTION direction;
		this->shp = new Shape * *[dimemsion.y];
		pieces.resize(dimemsion.y);
		for (int i = 0; i < dimemsion.y; i++)
		{
			this->shp[i] = new Shape * [dimemsion.x];
			for (int j = 0; j < dimemsion.x; j++)
			{
				P.ri = i, P.ci = j;
				Rdr >> key;
				switch (key)
				{
				case('+'):
				case('B'):
					this->shp[i][j] = new Rectangle(sf::Color::Blue, sf::Color::Black, key, P);
					break;
				case('%'):
				case('C'):
					this->shp[i][j] = new Rectangle(sf::Color::Color(30, 223, 222), sf::Color::Black, key, P);
					break;
				case('!'):
				case('R'):
					this->shp[i][j] = new Rectangle(sf::Color::Color(222, 18, 27), sf::Color::Black, key, P);
					break;
				case('/'):
				case('Y'):
					this->shp[i][j] = new Rectangle(sf::Color::Color(249, 241, 11), sf::Color::Black, key, P);
					break;
				case('?'):
					this->shp[i][j] = new Rectangle(sf::Color::Color(52, 73, 94), sf::Color::Black, key, P);
					break;
				case('_'):
					if ((i >= 0 && i <= 5) && (j >= 0 && j <= 5))
						this->shp[i][j] = new Rectangle(sf::Color::Blue, sf::Color::Blue, key, P);
					else if ((i >= 0 && i <= 5) && (j >= 9 && j <= 14))
						this->shp[i][j] = new Rectangle(sf::Color::Color(222, 18, 27), sf::Color::Color(222, 18, 27), key, P);
					else if ((i >= 9 && i <= 14) && (j >= 0 && j <= 5))
						this->shp[i][j] = new Rectangle(sf::Color::Color(249, 241, 11), sf::Color::Color(249, 241, 11), key, P);
					else if ((i >= 9 && i <= 14) && (j >= 9 && j <= 14))
						this->shp[i][j] = new Rectangle(sf::Color::Color(30, 223, 222), sf::Color::Color(30, 223, 222), key, P);
					break;

				case('@'):
				case('~'):
				case('b'):
				case('r'):
				case('c'):
				case('y'):
				case('x'):
				case('v'):
				case('h'):
				case('k'):
					this->shp[i][j] = new Rectangle(sf::Color::White, sf::Color::White, key, P);
					break;

				case ('.'):
				case('u'):
				case('>'):
				case('<'):
				case('d'):
				case('s'):
				case('e'):
				case('z'):
				case('q'):
					this->shp[i][j] = new Rectangle(sf::Color::Color(178,186,187), sf::Color::Black, key, P);
					break;
				default:
					cout << "not found" << key;
					break;

				}
			}

		}


		for (int i = 0; i < dimemsion.y; i++)
		{
			for (int j = 0; j < dimemsion.x; j++)
			{
				P.ri = i, P.ci = j;
				char sym;

				sym = this->shp[i][j]->getId();
				Wrtr << sym;

			}
			Wrtr << endl;
		}

		// ------------------------PIECE_LOADING---------------------
		ifstream Rdr_1("4_player_saving.txt");
		for (int i = 0; i < dimemsion.y; i++)
		{
			pieces[i].resize(dimemsion.x);
			for (int j = 0; j < dimemsion.x; j++)
			{
				P.ri = i, P.ci = j;
				Rdr_1 >> key;
				switch (key)
				{
				case('b'):
					pieces[i][j].push_back(Blue_piece(P, key, RIGHT, BLUE));
					break;
				case('r'):
					pieces[i][j].push_back(Red_piece(P, key, DOWN, RED));
					break;
				case('c'):
					pieces[i][j].push_back(Cyan_piece(P, key, LEFT, CYAN));
					break;
				case('y'):
					pieces[i][j].push_back(Yellow_piece(P, key, UP, YELLOW));
					break;
				/*default:
					this->ps[i][j] = nullptr;
					break;*/

				}
			}

		}
	}
	else if (nop == 2)
	{
		this->dimemsion.x = 15;
		this->dimemsion.y = 15;
		Global::dimSqr.x = (float)window.getSize().x / (dimemsion.x + 7);
		Global::dimSqr.y = (float)window.getSize().y / (dimemsion.y + 2);
		Global::f.loadFromFile("Text_7.ttf");
		ludo.setCharacterSize(30);
		//ludo.setFillColor(sf::Color::Color(69, 179, 157));
		ludo.setOutlineThickness(5);
		// ludo.setOutlineColor(sf::Color::Color(52, 152, 219));
	//	ludo.setFillColor(sf::Color::Color(211, 84, 0));
		ludo.setFont(Global::f); ludo.setString("QALANDARS");
		ludo.setPosition((float)((Global::dimSqr.x * dimemsion.x) / 2) - 100
			, ((Global::dimSqr.y * dimemsion.y) / 2) - 20);
		/*background.setTexture(Global::Ts[7]);
		background.setScale((float)window.getSize().x / Global::Ts[7].getSize().x,
			(float)window.getSize().y / Global::Ts[7].getSize().y);
		star.setTexture(Global::Ts[6]);
		star.setScale((float)window.getSize().x / Global::Ts[6].getSize().x,
			(float)window.getSize().y / Global::Ts[7].getSize().y);*/
		sf::Color::Yellow; sf::Color orange(255, 165, 0);
		Position P{};
		ifstream Rdr("4_player.txt");
		ofstream Wrtr("4_player_saving.txt");
		char key;
		DIRECTION direction;
		this->shp = new Shape * *[dimemsion.y];
		pieces.resize(dimemsion.y);
		for (int i = 0; i < dimemsion.y; i++)
		{
			this->shp[i] = new Shape * [dimemsion.x];
			for (int j = 0; j < dimemsion.x; j++)
			{
				P.ri = i, P.ci = j;
				Rdr >> key;
				switch (key)
				{
				case('+'):
				case('B'):
					this->shp[i][j] = new Rectangle(sf::Color::Blue, sf::Color::Black, key, P);
					break;
				case('%'):
				case('C'):
					this->shp[i][j] = new Rectangle(sf::Color::Color(30, 223, 222), sf::Color::Black, key, P);
					break;
				case('!'):
				case('R'):
					this->shp[i][j] = new Rectangle(sf::Color::Color(222, 18, 27), sf::Color::Black, key, P);
					break;
				case('/'):
				case('Y'):
					this->shp[i][j] = new Rectangle(sf::Color::Color(249, 241, 11), sf::Color::Black, key, P);
					break;
				case('?'):
					this->shp[i][j] = new Rectangle(sf::Color::Color(52, 73, 94), sf::Color::Black, key, P);
					break;
				case('_'):
					if ((i >= 0 && i <= 5) && (j >= 0 && j <= 5))
						this->shp[i][j] = new Rectangle(sf::Color::Blue, sf::Color::Blue, key, P);
					else if ((i >= 0 && i <= 5) && (j >= 9 && j <= 14))
						this->shp[i][j] = new Rectangle(sf::Color::Color(222, 18, 27), sf::Color::Color(222, 18, 27), key, P);
					else if ((i >= 9 && i <= 14) && (j >= 0 && j <= 5))
						this->shp[i][j] = new Rectangle(sf::Color::Color(249, 241, 11), sf::Color::Color(249, 241, 11), key, P);
					else if ((i >= 9 && i <= 14) && (j >= 9 && j <= 14))
						this->shp[i][j] = new Rectangle(sf::Color::Color(30, 223, 222), sf::Color::Color(30, 223, 222), key, P);
					break;

				case('@'):
				case('~'):
				case('b'):
				case('r'):
				case('c'):
				case('y'):
				case('x'):
				case('v'):
				case('h'):
				case('k'):
					this->shp[i][j] = new Rectangle(sf::Color::White, sf::Color::White, key, P);
					break;

				case ('.'):
				case('u'):
				case('>'):
				case('<'):
				case('d'):
				case('s'):
				case('z'):
				case('e'):
				case('q'):
					this->shp[i][j] = new Rectangle(sf::Color::Color(178,186,187), sf::Color::Black, key, P);
					break;
				default:
					cout << "not found" << key;
					break;

				}
			}

		}


		for (int i = 0; i < dimemsion.y; i++)
		{
			for (int j = 0; j < dimemsion.x; j++)
			{
				P.ri = i, P.ci = j;
				char sym;

				sym = this->shp[i][j]->getId();
				Wrtr << sym;

			}
			Wrtr << endl;
		}

		// ------------------------PIECE_LOADING---------------------
		ifstream Rdr_1("4_player_saving.txt");
		for (int i = 0; i < dimemsion.y; i++)
		{
			pieces[i].resize(dimemsion.x);
			for (int j = 0; j < dimemsion.x; j++)
			{
				P.ri = i, P.ci = j;
				Rdr_1 >> key;
				switch (key)
				{
				case('b'):
					pieces[i][j].push_back(Blue_piece(P, key, RIGHT, BLUE));
					break;
				case('c'):
					pieces[i][j].push_back(Cyan_piece(P, key, LEFT, CYAN));
					break;
				//default:
				//	this->ps[i][j] = nullptr;
				//	break;
				}
			}
		}
	}
	else if (nop == 3)
	{
		this->dimemsion.x = 24;
		this->dimemsion.y = 15;
		Global::dimSqr.x = (float)window.getSize().x / (dimemsion.x + 7);
		Global::dimSqr.y = (float)window.getSize().y / (dimemsion.y + 2);
		Global::f.loadFromFile("Text_7.ttf");
		ludo.setCharacterSize(30);
		//	ludo.setFillColor(sf::Color::Color(69, 179, 157));
		ludo.setOutlineThickness(5);
		//	ludo.setOutlineColor(sf::Color::Color(52, 152, 219));
		//	ludo.setFillColor(sf::Color::Color(211, 84, 0));
		ludo.setFont(Global::f); ludo.setString("QALANDARS");
		ludo.setPosition((float)((Global::dimSqr.x * dimemsion.x) / 2) - 100
			, ((Global::dimSqr.y * dimemsion.y) / 2) - 20);
		/*background.setTexture(Global::Ts[7]);
		background.setScale((float)window.getSize().x / Global::Ts[7].getSize().x,
			(float)window.getSize().y / Global::Ts[7].getSize().y);
		star.setTexture(Global::Ts[6]);
		star.setScale((float)window.getSize().x / Global::Ts[6].getSize().x,
			(float)window.getSize().y / Global::Ts[7].getSize().y);*/
		sf::Color::Yellow; sf::Color orange(255, 165, 0);
		Position P;
		ifstream Rdr("6_player.txt");
		ofstream Wrtr("3_player_saving.txt");
		char key;
		DIRECTION direction;
		this->shp = new Shape * *[dimemsion.y];
		pieces.resize(dimemsion.y);
		for (int i = 0; i < dimemsion.y; i++)
		{
			this->shp[i] = new Shape * [dimemsion.x];
			for (int j = 0; j < dimemsion.x; j++)
			{
				P.ri = i, P.ci = j;
				Rdr >> key;
				/*switch (key)
				{
				case('+'):
				case('B'):
					checkPoints.push_back({ i, j });
					this->shp[i][j] = new Rectangle(sf::Color::Blue, sf::Color::Black, key, P);
					break;
				case('*'):
				case('G'):
					checkPoints.push_back({ i, j });
					this->shp[i][j] = new Rectangle(sf::Color::Color(25, 111, 61), sf::Color::Black, key, P);
					break;
				case('!'):
				case('R'):
					checkPoints.push_back({ i, j });
					this->shp[i][j] = new Rectangle(sf::Color::Color(222, 18, 27), sf::Color::Black, key, P);
					break;
				case('&'):
				case('P'):
					checkPoints.push_back({ i, j });
					this->shp[i][j] = new Rectangle(sf::Color::Color(150, 43, 123), sf::Color::Black, key, P);
					break;
				case('%'):
				case('C'):
					checkPoints.push_back({ i, j });
					this->shp[i][j] = new Rectangle(sf::Color::Color(30, 223, 222), sf::Color::Black, key, P);
					break;
				case('/'):
				case('Y'):
					checkPoints.push_back({ i, j });
					this->shp[i][j] = new Rectangle(sf::Color::Color(249, 241, 11), sf::Color::Black, key, P);
					break;
				case('?'):
					checkPoints.push_back({ i, j });
					this->shp[i][j] = new Rectangle(sf::Color::Color(52, 73, 94), sf::Color::Black, key, P);
					break;
				case('_'):
					if ((i >= 0 && i <= 5) && (j >= 0 && j <= 5))
						this->shp[i][j] = new Rectangle(sf::Color::Blue, sf::Color::Blue, key, P);
					else if ((i >= 0 && i <= 5) && (j >= 9 && j <= 14))
						this->shp[i][j] = new Rectangle(sf::Color::Color(222, 18, 27), sf::Color::Color(222, 18, 27), key, P);
					else if ((i >= 0 && i <= 5) && (j >= 18 && j <= 23))
						this->shp[i][j] = new Rectangle(sf::Color::Color(25, 111, 61), sf::Color::Color(25, 111, 61), key, P);
					else if ((i >= 9 && i <= 14) && (j >= 0 && j <= 5))
						this->shp[i][j] = new Rectangle(sf::Color::Color(249, 241, 11), sf::Color::Color(249, 241, 11), key, P);
					else if ((i >= 9 && i <= 14) && (j >= 9 && j <= 14))
						this->shp[i][j] = new Rectangle(sf::Color::Color(30, 223, 222), sf::Color::Color(30, 223, 222), key, P);
					else if ((i >= 9 && i <= 14) && (j >= 18 && j <= 23))
						this->shp[i][j] = new Rectangle(sf::Color::Color(150, 43, 123), sf::Color::Color(150, 43, 123), key, P);

					break;

				case('#'):
				case('$'):
				case(','):
				case('~'):
				case('b'):
				case('r'):
				case('g'):
				case('y'):
				case('p'):
				case('c'):
					this->shp[i][j] = new Rectangle(sf::Color::White, sf::Color::White, key, P);
					break;

				case ('.'):
				case('u'):
				case('>'):
				case('<'):
				case('d'):
					this->shp[i][j] = new Rectangle(sf::Color::White, sf::Color::Black, key, P);
					break;
				default:
					cout << "not found" << key;
					break;

				}*/
				switch (key)
				{
				case('+'):
					checkPoints.push_back({ i, j });
					this->shp[i][j] = new Rectangle(sf::Color::Blue, sf::Color::Black, key, P);
					break;
				case('B'):
					this->shp[i][j] = new Rectangle(sf::Color::Blue, sf::Color::Black, key, P);
					break;
				case('*'):
					checkPoints.push_back({ i, j });
					this->shp[i][j] = new Rectangle(sf::Color::Color(25, 111, 61), sf::Color::Black, key, P);
					break;
				case('G'):
					this->shp[i][j] = new Rectangle(sf::Color::Color(25, 111, 61), sf::Color::Black, key, P);
					break;
				case('!'):
				case('R'):
					this->shp[i][j] = new Rectangle(sf::Color::Color(222, 18, 27), sf::Color::Black, key, P);
					break;
				case('&'):
				case('P'):
					this->shp[i][j] = new Rectangle(sf::Color::Color(150, 43, 123), sf::Color::Black, key, P);
					break;
				case('%'):
					checkPoints.push_back({ i, j });
					this->shp[i][j] = new Rectangle(sf::Color::Color(30, 223, 222), sf::Color::Black, key, P);
					break;
				case('C'):
					this->shp[i][j] = new Rectangle(sf::Color::Color(30, 223, 222), sf::Color::Black, key, P);
					break;
				case('/'):
				case('Y'):
					this->shp[i][j] = new Rectangle(sf::Color::Color(249, 241, 11), sf::Color::Black, key, P);
					break;

				case('?'):
					checkPoints.push_back({ i, j });
					this->shp[i][j] = new Rectangle(sf::Color::Color(52, 73, 94), sf::Color::Black, key, P);
					break;
				case('_'):
					if ((i >= 0 && i <= 5) && (j >= 0 && j <= 5))
						this->shp[i][j] = new Rectangle(sf::Color::Blue, sf::Color::Blue, key, P);
					else if ((i >= 0 && i <= 5) && (j >= 9 && j <= 14))
						this->shp[i][j] = new Rectangle(sf::Color::Color(222, 18, 27), sf::Color::Color(222, 18, 27), key, P);
					else if ((i >= 0 && i <= 5) && (j >= 18 && j <= 23))
						this->shp[i][j] = new Rectangle(sf::Color::Color(25, 111, 61), sf::Color::Color(25, 111, 61), key, P);
					else if ((i >= 9 && i <= 14) && (j >= 0 && j <= 5))
						this->shp[i][j] = new Rectangle(sf::Color::Color(249, 241, 11), sf::Color::Color(249, 241, 11), key, P);
					else if ((i >= 9 && i <= 14) && (j >= 9 && j <= 14))
						this->shp[i][j] = new Rectangle(sf::Color::Color(30, 223, 222), sf::Color::Color(30, 223, 222), key, P);
					else if ((i >= 9 && i <= 14) && (j >= 18 && j <= 23))
						this->shp[i][j] = new Rectangle(sf::Color::Color(150, 43, 123), sf::Color::Color(150, 43, 123), key, P);

					break;

				case('#'):
				case('$'):
				case(','):
				case('~'):
				case('b'):
				case('r'):
				case('g'):
				case('y'):
				case('p'):
				case('c'):
				case('o'):
				case('m'):
				case('n'):
				case('a'):
				case('f'):
				case('l'):
					this->shp[i][j] = new Rectangle(sf::Color::White, sf::Color::White, key, P);
					break;

				case ('.'):
				case('u'):
				case('>'):
				case('<'):
				case('d'):
				case('z'):
				case('w'):
				case(':'):
				case('s'):
				case('e'):
				
				case('q'):
					this->shp[i][j] = new Rectangle(sf::Color::Color(178, 186, 187), sf::Color::Black, key, P);
					break;
				default:
					cout << "not found" << key;
					break;

				}
			}

		}


		for (int i = 0; i < dimemsion.y; i++)
		{
			for (int j = 0; j < dimemsion.x; j++)
			{
				P.ri = i, P.ci = j;
				char sym;

				sym = this->shp[i][j]->getId();
				Wrtr << sym;

			}
			Wrtr << endl;
		}


		// ------------------------PIECE_LOADING---------------------
		ifstream Rdr_1("3_player_saving.txt");

		for (int i = 0; i < dimemsion.y; i++)
		{
			pieces[i].resize(dimemsion.x);
			for (int j = 0; j < dimemsion.x; j++)
			{
				P.ri = i, P.ci = j;
				Rdr_1 >> key;
				switch (key)
				{
				case('b'):
					pieces[i][j].push_back(Blue_piece(P, key, RIGHT, BLUE));
					break;
				case('g'):
					pieces[i][j].push_back(Green_piece(P, key, DOWN, GREEN));
					break;
				case('c'):
					pieces[i][j].push_back(Cyan_piece(P, key, UP, CYAN));
					break;
	/*			default:
					this->ps[i][j] = nullptr;
					break;*/

				}
			}
		}
	}
}
bool Board::capturePiece(int diceNum)
{
	return true;
}
Position Board::Piece_kill(sf::RenderWindow& window, sf::Vector3f Src, int rollNumber, int nop)
{
	Position Des;
	Des.ri = Src.y, Des.ci = Src.x;
	int countDice = 0;
	sf::Event e;
	char key;
	char key_piece;

	DIRECTION previous= pieces[Src.y][Src.x][Src.z].getDir();
	while (true)
	{
		DIRECTION d;
		{
			d = pieces[Src.y][Src.x][Src.z].getDir();
		}
		//-----------------------3 & 6 PLAYERS------------------------
		if (nop == 6 || nop == 3)
		{
			switch (d)
			{
			case(UP):
			{
				key = this->shp[Des.ri][Des.ci]->getId();
				key_piece = pieces[Src.y][Src.x][Src.z].getId_piece();
				if (key != '<')
				{
					if (Des.ci == 6 && (Des.ri >= 0 && Des.ri <= 6))
					{
						Des.ri--;
						countDice++;
					}
					else if (Des.ci == 15 && (Des.ri >= 0 && Des.ri <= 6))
					{
						Des.ri--;
						countDice++;
					}
					else if (Des.ci == 0 && (Des.ri >= 6 && Des.ri <= 8))
					{
						Des.ri--;
						countDice++;
					}

				}
				if ((key == '<' && Des.ci == 0) || (key == '<' && Des.ci == 6) || (key == '<' && Des.ci == 15))
				{
					pieces[Src.y][Src.x][Src.z].setDirection(RIGHT);
				}
				if (key == 'C' || key == 'Y')
				{
					Des.ri++;
					countDice++;
					pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
				}
				if (key != '>')
				{
					if (((Des.ci == 6 && (Des.ri >= 8 && Des.ri <= 14))) || ((Des.ci == 15 && (Des.ri >= 8 && Des.ri <= 14))))
					{
						Des.ri--;
						countDice++;
					}
					/*else if ((Des.ci == 0 && (Des.ri >= 6 && Des.ri <= 8)))
					{
						Des.ri--;
						countDice++;
						this->ps[Src.ri][Src.ci]->movePiece(window, Des);
					}*/

				}
				if ((key == '>' && Des.ci == 6) || (key == '>' && Des.ci == 15))
				{
					Des.ri--;
					pieces[Src.y][Src.x][Src.z].setDirection(LEFT);
				}

			}
			break;
			case(DOWN):
			{
				key = this->shp[Des.ri][Des.ci]->getId();
				key_piece = pieces[Src.y][Src.x][Src.z].getId_piece();
				if (key != '<')
				{
					if (Des.ci == 8 && (Des.ri >= 0 && Des.ri <= 6))
					{
						Des.ri++;
						countDice++;
					}
					else if (Des.ci == 17 && (Des.ri >= 0 && Des.ri <= 6))
					{
						Des.ri++;
						countDice++;
					}
				}
				if ((key == '<' && Des.ci == 17) || (key == '<' && Des.ci == 8))
				{
					Des.ri++;
					pieces[Src.y][Src.x][Src.z].setDirection(RIGHT);
				}

				if (key == 'R' || key=='G')
				{
					Des.ri++;
					countDice++;
					pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
				}
				
				if (key != '>')
				{
					if (((Des.ci == 8 && (Des.ri >= 8 && Des.ri <= 14))) || ((Des.ci == 17 && (Des.ri >= 8 && Des.ri <= 14))))
					{
						Des.ri++;
						countDice++;
					}
					else if ((Des.ci == 23 && (Des.ri >= 6 && Des.ri <= 8)))
					{
						Des.ri++;
						countDice++;
					}

				}
				else if ((key == '>' && Des.ci == 8) || (key == '>' && Des.ci == 17) || (key == '>' && Des.ci == 23))
				{
					pieces[Src.y][Src.x][Src.z].setDirection(LEFT);
				}
			}
			break;
			case(LEFT):
			{
				key = this->shp[Des.ri][Des.ci]->getId();
				key_piece = pieces[Src.y][Src.x][Src.z].getId_piece();
				if (key != 'd')
				{
					if (Des.ri == 8 && (Des.ci >= 18 && Des.ci <= 23))
					{
						Des.ci--;
						countDice++;
					}
					if (Des.ri == 8 && (Des.ci >= 9 && Des.ci <= 15))
					{
						Des.ci--;
						countDice++;
					}

				}
				if (key == 'P')
				{
					{
						Des.ci--;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}
				}
				if (key == 'd' && Des.ri == 8)
				{
					Des.ci--;
					pieces[Src.y][Src.x][Src.z].setDirection(DOWN);
				}
				if (key != 'u')
				{
					if ((Des.ri == 8 && (Des.ci >= 0 && Des.ci <= 6)))
					{
						Des.ci--;
						countDice++;
					}
					else if ((Des.ri == 14 && (Des.ci >= 6 && Des.ci <= 8)))
					{
						Des.ci--;
						countDice++;
					}
					else if ((Des.ri == 14 && (Des.ci >= 15 && Des.ci <= 17)))
					{
						Des.ci--;
						countDice++;
					}


				}
				if ((key == 'u' && Des.ri == 8) || (key == 'u' && Des.ri == 14))
				{
					pieces[Src.y][Src.x][Src.z].setDirection(UP);
				}

			}
			break;
			case(RIGHT):
			{
				key = this->shp[Des.ri][Des.ci]->getId();
				key_piece = pieces[Src.y][Src.x][Src.z].getId_piece();
				if (key != 'u')
				{
					if (Des.ri == 6 && (Des.ci >= 0 && Des.ci <= 5))
					{
						Des.ci++;
						countDice++;
					}
					if (Des.ri == 6 && (Des.ci >= 8 && Des.ci <= 14))
					{
						Des.ci++;
						countDice++;
					}
				}
				if (key == 'u' && Des.ri == 6)
				{
					Des.ci++;
					pieces[Src.y][Src.x][Src.z].setDirection(UP);
				}
				if (key == 'B')
				{
					{
						Des.ci++;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}
				}
				if (key != 'd')
				{
					if (((Des.ri == 0 && (Des.ci >= 6 && Des.ci <= 8))) || ((Des.ri == 0 && (Des.ci >= 15 && Des.ci <= 17))))
					{
						Des.ci++;
						countDice++;
					}
					else if ((Des.ri == 6 && (Des.ci >= 17 && Des.ci <= 23)))
					{
						Des.ci++;
						countDice++;
					}

				}
				if ((key == 'd' && Des.ri == 0) || (key == 'd' && Des.ri == 6))
				{
					pieces[Src.y][Src.x][Src.z].setDirection(DOWN);
				}
			}
			default:
				break;
			}
			if (countDice == rollNumber)
			{
				pieces[Src.y][Src.x][Src.z].setDirection(previous);
				return Des;
				break;
			}
		}



		//-------------------------- 2 & 4 PLAYERS----------------------
		else if (nop == 4 || nop == 2)
		{
			switch (d)
			{
			case(UP):
			{
				key = this->shp[Des.ri][Des.ci]->getId();
				if (key != '<')
				{
					if (Des.ci == 6 && (Des.ri >= 0 && Des.ri <= 6))
					{
						Des.ri--;
						countDice++;
					}
					else if (Des.ci == 0 && (Des.ri >= 6 && Des.ri <= 8))
					{
						Des.ri--;
						countDice++;
					}

				}
				if (key == 'Y')
				{
					{
						Des.ri++;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}
				}
				if ((key == '<' && Des.ci == 6) || (key == '<' && Des.ci == 0))
				{
					pieces[Src.y][Src.x][Src.z].setDirection(RIGHT);
				}
				if (key != '>')
				{
					if ((Des.ci == 6 && (Des.ri >= 8 && Des.ri <= 14)))
					{
						Des.ri--;
						countDice++;
					}
				}
				if ((key == '>' && Des.ci == 6))
				{
					Des.ri--;
					pieces[Src.y][Src.x][Src.z].setDirection(LEFT);
				}

			}
			break;
			case(DOWN):
			{

				key = this->shp[Des.ri][Des.ci]->getId();
				if (key != '<')
				{
					if (Des.ci == 8 && (Des.ri >= 0 && Des.ri <= 6))
					{
						Des.ri++;
						countDice++;
					}
				}
				if (key == 'R')
				{
					{
						Des.ri++;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}
				}
				if ((key == '<' && Des.ci == 8))
				{
					Des.ri++;
					pieces[Src.y][Src.x][Src.z].setDirection(RIGHT);
				}
				if (key != '>')
				{
					if ((Des.ci == 8 && (Des.ri >= 8 && Des.ri <= 14)))
					{
						Des.ri++;
						countDice++;
					}
					else if (Des.ci == 14 && (Des.ri >= 6 && Des.ri <= 8))
					{
						Des.ri++;
						countDice++;
					}
				}
				else if ((key == '>' && Des.ci == 8) || (key == '>' && Des.ci == 14))
				{
					pieces[Src.y][Src.x][Src.z].setDirection(LEFT);
				}
			}
			break;
			case(LEFT):
			{

				key = this->shp[Des.ri][Des.ci]->getId();
				if (key != 'd')
				{
					if (Des.ri == 8 && (Des.ci >= 8 && Des.ci <= 14))
					{
						Des.ci--;
						countDice++;
					}
				}
				if (key == 'd' && Des.ri == 8)
				{
					Des.ci--;
					pieces[Src.y][Src.x][Src.z].setDirection(DOWN);
				}
				if (key == 'C')
				{
					Des.ci--;
					countDice++;
					pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
				}
				if (key != 'u')
				{
					if ((Des.ri == 8 && (Des.ci >= 0 && Des.ci <= 6)))
					{
						Des.ci--;
						countDice++;
					}
					else if (Des.ri == 14 && (Des.ci >= 6 && Des.ci <= 8))
					{
						Des.ci--;
						countDice++;
					}
				}
				if ((key == 'u' && Des.ri == 8) || (key == 'u' && Des.ri == 14))
				{
					pieces[Src.y][Src.x][Src.z].setDirection(UP);
				}
			}
			break;
			case(RIGHT):
			{
				key = this->shp[Des.ri][Des.ci]->getId();
				if (key != 'u')
				{
					if (Des.ri == 6 && (Des.ci >= 0 && Des.ci <= 5))
					{
						Des.ci++;
						countDice++;
					}
				}
				if (key == 'u' && Des.ri == 6)
				{
					Des.ci++;
					pieces[Src.y][Src.x][Src.z].setDirection(UP);
				}
				if (key == 'B')
				{
					{
						Des.ci++;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}
				}
				if (key != 'd')
				{
					if ((Des.ri == 6 && (Des.ci >= 8 && Des.ci <= 14)))
					{
						Des.ci++;
						countDice++;
					}
					else if (Des.ri == 0 && (Des.ci >= 6 && Des.ci <= 8))
					{
						Des.ci++;
						countDice++;
					}
				}
				if ((key == 'd' && Des.ri == 6) || (key == 'd' && Des.ri == 0))
				{
					pieces[Src.y][Src.x][Src.z].setDirection(DOWN);
				}
			}
			default:
				break;
			}
			if (countDice == rollNumber)
			{
				pieces[Src.y][Src.x][Src.z].setDirection(previous);
				return Des;
				break;
			}
		}
	}
}
bool Board::IsCaptured(sf::RenderWindow& window, sf::Vector3f Src, int diceNumber, int nop)
{
	Position des=Piece_kill(window, Src, diceNumber, nop);
	char sym_s = pieces[Src.y][Src.x][Src.z].getId_piece();
	char sym_d;
	sf::Vector3f Ans;
	Ans.y = des.ri;
	Ans.x = des.ci;
	char sym_stop = this->shp[des.ri][des.ci]->getId();
	
	if(pieces[des.ri][des.ci].empty())
	{
		return false;
	}
	else if (pieces[des.ri][des.ci].size()>1)
	{
		return false;
	}
	else
	{
		sym_d = pieces[Ans.y][Ans.x][Ans.z].getId_piece();
	}
    if (sym_stop == '+' || sym_stop == '!' || sym_stop == '*' || sym_stop == '&' || sym_stop == '%' || sym_stop == '/' || sym_stop == '?')
	{
		if (sym_s != sym_d && sym_stop)
			return false;
	}
	if (sym_s == sym_d)
	{
		return false;
	}


	else if (sym_d == 'b' || sym_d == 'r' || sym_d == 'g' || sym_d == 'p' || sym_d == 'c' || sym_d == 'y')
	{
		if (sym_d == 'b')
		{
			if (pieces[1][1].empty())
			{
				Updateboard(window, Ans, { 1,1 });
				Updateboard(window,Src,diceNumber,nop);

				return true;
			}
			else if (pieces[1][4].empty())
			{
				Updateboard(window, Ans, { 1,4 });
				Updateboard(window, Src, diceNumber, nop);
				return true;
			}
			else if (pieces[4][1].empty())
			{
				Updateboard(window, Ans, { 4,1 });
				Updateboard(window, Src, diceNumber, nop);
				return true;
			}
			else if (pieces[4][4].empty())
			{
				Updateboard(window, Ans, { 4,4 });
				Updateboard(window, Src, diceNumber, nop);
				return true;
			}
		}
		else if (sym_d == 'r')
		{
			if (pieces[1][10].empty())
			{
				Updateboard(window, Ans, { 1,10 });
				Updateboard(window, Src, diceNumber, nop);
				return true;
			}
			else if (pieces[1][13].empty())
			{
				Updateboard(window, Ans, { 1,13 });
				Updateboard(window, Src, diceNumber, nop);
				return true;
			}
			else if (pieces[4][10].empty())
			{
				Updateboard(window, Ans, { 4,10 });
				Updateboard(window, Src, diceNumber, nop);
				return true;
			}
			else if (pieces[4][13].empty())
			{
				Updateboard(window, Ans, { 4,13 }); 
				Updateboard(window, Src, diceNumber, nop);
				return true;
			}
		}
		else if (sym_d == 'g')
		{
			if (pieces[1][19].empty())
			{
				Updateboard(window, Ans, { 1,19 });
				Updateboard(window, Src, diceNumber, nop);
				return true;
			}
			else if (pieces[1][22].empty())
			{
				Updateboard(window, Ans, { 1,22 });
				Updateboard(window, Src, diceNumber, nop);
				return true;
			}
			else if (pieces[4][19].empty())
			{
				Updateboard(window, Ans, { 4,19 });
				Updateboard(window, Src, diceNumber, nop);
				return true;
			}
			else if (pieces[4][22].empty())
			{
				Updateboard(window, Ans, { 4,22 });
				Updateboard(window, Src, diceNumber, nop);
				return true;
			}
		}
		else if (sym_d == 'p')
		{
			if (pieces[10][19].empty())
			{
				Updateboard(window, Ans, { 10,19 });
				Updateboard(window, Src, diceNumber, nop);
				return true;
			}
			else if (pieces[10][22].empty())
			{
				Updateboard(window, Ans, { 10,22 });
				Updateboard(window, Src, diceNumber, nop);
				return true;
			}
			else if (pieces[13][19].empty())
			{
				Updateboard(window, Ans, { 13,19 });
				Updateboard(window, Src, diceNumber, nop);
				return true;
			}
			else if (pieces[13][22].empty())
			{
				Updateboard(window, Ans, { 13,22 });
				Updateboard(window, Src, diceNumber, nop);
				return true;
			}
		}
		else if (sym_d == 'c')
		{
			if (pieces[10][10].empty())
			{
				Updateboard(window, Ans, { 10,10 });
				Updateboard(window, Src, diceNumber, nop);
				return true;
			}
			else if (pieces[10][13].empty())
			{
				Updateboard(window, Ans, { 10,13 });
				Updateboard(window, Src, diceNumber, nop);
				return true;
			}
			else if (pieces[13][10].empty())
			{
				Updateboard(window, Ans, { 13,10 });
				Updateboard(window, Src, diceNumber, nop);
				return true;
			}
			else if (pieces[13][13].empty())
			{
				Updateboard(window, Ans, { 13,13 });
				Updateboard(window, Src, diceNumber, nop);
				return true;
			}
		}
		else if (sym_d == 'y')
		{
			if (pieces[10][1].empty())
			{
				Updateboard(window, Ans, { 10,1 });
				Updateboard(window, Src, diceNumber, nop);
				return true;
			}
			else if (pieces[10][4].empty())
			{
				Updateboard(window, Ans, { 10,4 });
				Updateboard(window, Src, diceNumber, nop);
				return true;
			}
			else if (pieces[13][1].empty())
			{
				Updateboard(window, Ans, { 13,1 });
				Updateboard(window, Src, diceNumber, nop);
				return true;
			}
			else if (pieces[13][4].empty())
			{
				Updateboard(window, Ans, { 13,4 });
				Updateboard(window, Src, diceNumber, nop);
				return true;
			}
		}
	}
}
void Board::setPiece()
{
	for(int i=0;i< dimemsion.y;i++)
	{
		for(int j=0;j<dimemsion.x;j++)
		{
			for(int k=0;k<pieces[i][j].size();k++)
			{
				pieces[i][j][k].setPiece(k);
			}
		}
	}
}
//------------------tf-------------------------
void Board::GoHome(sf::RenderWindow& window, sf::Vector3f Src, int rollNumber, int nop,vector<char>& Home)
{
	Position Des;
	Des.ri = Src.y, Des.ci = Src.x;
	int countDice = 0;
	sf::Event e;
	char key;
	char key_piece;
	while (true)
	{
		DIRECTION d = this->pieces[Src.y][Src.x][Src.z].getDir();
		//-----------------------3 & 6 PLAYERS------------------------
		if (nop == 6 || nop == 3)
		{
			switch (d)
			{
			case(UP):
			{
				key = this->shp[Des.ri][Des.ci]->getId();
				key_piece = pieces[Src.y][Src.x][Src.z].getId_piece();
				//---------------GO-HOME--------------------------
				if (key == 's')
				{
					if (key_piece == 'b')
					{
						pieces[Src.y][Src.x][Src.z].setDirection(RIGHT);
						Des.ci++;
						countDice++;
					
						break;
					}
				}
				//-----------------END--------------------------
				//---------------HOME--------------------------
				if (key == 'Y' && key_piece=='y')
				{
					Des.ri--;
					countDice++;
					pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
				}
				if (key == 'C' && key_piece=='c')
				{
					Des.ri--;
					countDice++;
					pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
				}
				//-----------------END--------------------------

				if (key != '<')
				{
					if (Des.ci == 6 && (Des.ri >= 0 && Des.ri <= 6))
					{
						Des.ri--;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}
					else if (Des.ci == 15 && (Des.ri >= 0 && Des.ri <= 6))
					{
						Des.ri--;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}
					else if (Des.ci == 0 && (Des.ri >= 6 && Des.ri <= 8))
					{
						Des.ri--;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}

				}
				if ((key == '<' && Des.ci == 0) || (key == '<' && Des.ci == 6) || (key == '<' && Des.ci == 15))
				{
					pieces[Src.y][Src.x][Src.z].setDirection(RIGHT);
				}
				if (key != '>')
				{
					if (((Des.ci == 6 && (Des.ri >= 8 && Des.ri <= 14))) || ((Des.ci == 15 && (Des.ri >= 8 && Des.ri <= 14))))
					{
						Des.ri--;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}
					/*else if ((Des.ci == 0 && (Des.ri >= 6 && Des.ri <= 8)))
					{
						Des.ri--;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}*/

				}
				if ((key == '>' && Des.ci == 6) || (key == '>' && Des.ci == 15))
				{
					Des.ri--;
					pieces[Src.y][Src.x][Src.z].setDirection(LEFT);
				}
				
			}
			break;
			case(DOWN):
			{
				key = this->shp[Des.ri][Des.ci]->getId();
				key_piece = pieces[Src.y][Src.x][Src.z].getId_piece();

				//---------------GO-HOME--------------------------
				if (key == 'w')
				{
					if (key_piece == 'p')
					{
						pieces[Src.y][Src.x][Src.z].setDirection(LEFT);
						Des.ci--;
						countDice++;
						break;
					}
				}
				//--------------END------------------------

				//--------------HOME-----------------------
				if (key == 'R' && key_piece=='r')
				{
					Des.ri++;
					countDice++;
					pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
				}
				else if (key == 'G' && key_piece=='g')
				{
					Des.ri++;
					countDice++;
					pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
				}
				//--------------END------------------------
				if (key != '<')
				{
					if (Des.ci == 8 && (Des.ri >= 0 && Des.ri <= 6))
					{
						Des.ri++;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}
					else if (Des.ci == 17 && (Des.ri >= 0 && Des.ri <= 6))
					{
						Des.ri++;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}
				}
				if ((key == '<' && Des.ci == 17) || (key == '<' && Des.ci == 8))
				{
					Des.ri++;
					pieces[Src.y][Src.x][Src.z].setDirection(RIGHT);
				}
				if (key != '>')
				{
					if (((Des.ci == 8 && (Des.ri >= 8 && Des.ri <= 14))) || ((Des.ci == 17 && (Des.ri >= 8 && Des.ri <= 14))))
					{
						Des.ri++;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}
					else if ((Des.ci == 23 && (Des.ri >= 6 && Des.ri <= 8)))
					{
						Des.ri++;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}

				}
				else if ((key == '>' && Des.ci == 8) || (key == '>' && Des.ci == 17) || (key == '>' && Des.ci == 23))
				{
					pieces[Src.y][Src.x][Src.z].setDirection(LEFT);
				}
			}
			break;
			case(LEFT):
			{
				key = this->shp[Des.ri][Des.ci]->getId();
				key_piece = pieces[Src.y][Src.x][Src.z].getId_piece();
				//---------------GO-HOME--------------------------
				if (key == 'z' )
				{
					if (key_piece == 'y')
					{
						Des.ri--;
						pieces[Src.y][Src.x][Src.z].setDirection(UP);
						countDice++;
						break;

					}
				}
				else if (key == 'q')
				{
					if (key_piece == 'c')
					{
						Des.ri--;
						pieces[Src.y][Src.x][Src.z].setDirection(UP);
						break;

					}
				}
				//--------------END------------------------
				//--------------HOME-----------------------
				if (key == 'P')
				{
					if (key == 'P')
					{
						Des.ci--;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}
					else
					{
						P_Home.push_back(Des);
					}
				}
				//--------------END------------------------
				if (key != 'd')
				{
					if (Des.ri == 8 && (Des.ci >= 18 && Des.ci <= 23))
					{
						Des.ci--;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}
					if (Des.ri == 8 && (Des.ci >= 9 && Des.ci <= 15))
					{
						Des.ci--;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}

				}
				if (key == 'd' && Des.ri == 8)
				{
					Des.ci--;
					pieces[Src.y][Src.x][Src.z].setDirection(DOWN);
				}
				if (key != 'u')
				{
					if ((Des.ri == 8 && (Des.ci >= 0 && Des.ci <= 6)))
					{
						Des.ci--;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}
					else if ((Des.ri == 14 && (Des.ci >= 6 && Des.ci <= 8)))
					{
						Des.ci--;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}
					else if ((Des.ri == 14 && (Des.ci >= 15 && Des.ci <= 17)))
					{
						Des.ci--;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}


				}
				if ((key == 'u' && Des.ri == 8) || (key == 'u' && Des.ri == 14))
				{
					pieces[Src.y][Src.x][Src.z].setDirection(UP);
				}

			}
			break;
			case(RIGHT):
			{
				key = this->shp[Des.ri][Des.ci]->getId();
				key_piece = pieces[Src.y][Src.x][Src.z].getId_piece();

				//---------------GO-HOME--------------------------
				if (key == 'e')
				{
					if (key_piece == 'r')
					{
						Des.ri++;
						pieces[Src.y][Src.x][Src.z].setDirection(DOWN);
						countDice++;
						break;
					}
				}
				else if (key == ':')
				{
					if (key_piece == 'g' )
					{
						Des.ri++;
						pieces[Src.y][Src.x][Src.z].setDirection(DOWN);
						break;
					}
				}

				//-------------------END--------------------------

				//--------------HOME-----------------------

				if (key == 'B')
				{
					if (key_piece == 'b')
					{
						Des.ci++;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}
				}

				//---------------END----------------------
				if (key != 'u')
				{
					if (Des.ri == 6 && (Des.ci >= 0 && Des.ci <= 5))
					{
						Des.ci++;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}
					if (Des.ri == 6 && (Des.ci >= 8 && Des.ci <= 14))
					{
						Des.ci++;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}
				}
				if (key == 'u' && Des.ri == 6)
				{
					Des.ci++;
					pieces[Src.y][Src.x][Src.z].setDirection(UP);
				}
				if (key != 'd')
				{
					if (((Des.ri == 0 && (Des.ci >= 6 && Des.ci <= 8))) || ((Des.ri == 0 && (Des.ci >= 15 && Des.ci <= 17))))
					{
						Des.ci++;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}
					else if ((Des.ri == 6 && (Des.ci >= 17 && Des.ci <= 23)))
					{
						Des.ci++;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}

				}
				if ((key == 'd' && Des.ri == 0) || (key == 'd' && Des.ri == 6))
				{
					pieces[Src.y][Src.x][Src.z].setDirection(DOWN);
				}
			}
			default:
				break;
			}
			if (countDice == rollNumber)
			{
				Updateboard(window, Src, Des);
				setPiece();
				break;

			}
			/*window.clear();
			pieces[Src.y][Src.x][Src.z].drawPiece(window);
			window.display();
			sf::sleep(sf::seconds(0.01));*/
		}




		//-----------------------------------------------------------------------------------------------------------------------------------------------------




		//-------------------------- 2 & 4 PLAYERS----------------------
		else if (nop == 4 || nop == 2)
		{
			switch (d)
			{
			case(UP):
			{
				key = this->shp[Des.ri][Des.ci]->getId();
				key_piece = pieces[Src.y][Src.x][Src.z].getId_piece();

				if (key == 's')
				{
					if (key_piece == 'b')
					{
						pieces[Src.y][Src.x][Src.z].setDirection(RIGHT);
						Des.ci++;
						countDice++;
						break;
					}
				}
				if (key == 'Y')
				{
					/*if (countDice == 0)
					{
						if (this->shp[Des.ri][Des.ci + rollNumber]->getId() == '@')
						{
							pieces[Src.y][Src.x].erase(pieces[Src.y][Src.x].begin() + Src.z);
							break;
						}
						int Count = 0;
						for (int i = Des.ci; i < Des.ci + rollNumber; i++)
						{
							if (this->shp[Des.ri][i]->getId() != '@')
							{
								Count++;
							}
						}
						if (rollNumber < Count)
						{
							Des.ci++;
							countDice++;
							pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
						}
						else
						{
							return;
						}
					}
					else
					{
						Des.ci++;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}*/
					Des.ri--;
					countDice++;
					pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
				}
				if (key != '<')
				{
					if (Des.ci == 6 && (Des.ri >= 0 && Des.ri <= 6))
					{
						Des.ri--;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}
					else if (Des.ci == 0 && (Des.ri >= 6 && Des.ri <= 8))
					{
						Des.ri--;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}

				}
				if ((key == '<' && Des.ci == 6) || (key == '<' && Des.ci == 0))
				{
					pieces[Src.y][Src.x][Src.z].setDirection(RIGHT);
				}
				if (key != '>')
				{
					if ((Des.ci == 6 && (Des.ri >= 8 && Des.ri <= 14)))
					{
						Des.ri--;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}
				}
				if ((key == '>' && Des.ci == 6))
				{
					Des.ri--;
					pieces[Src.y][Src.x][Src.z].setDirection(LEFT);
				}
				//-------------------HOME---------------------------
			}
			break;
			case(DOWN):
			{

				key = this->shp[Des.ri][Des.ci]->getId();
				key_piece = pieces[Src.y][Src.x][Src.z].getId_piece();
				if (key == 'q')
				{
					if (key_piece == 'c')
					{
						pieces[Src.y][Src.x][Src.z].setDirection(LEFT);
						Des.ci--;
						countDice++;

						break;
					}
				}
				if (key == 'R')
				{
					/*if (countDice == 0)
					{
						if (this->shp[Des.ri][Des.ci + rollNumber]->getId() == '@')
						{
							pieces[Src.y][Src.x].erase(pieces[Src.y][Src.x].begin() + Src.z);
							break;
						}
						int Count = 0;
						for (int i = Des.ci; i < Des.ci + rollNumber; i++)
						{
							if (this->shp[Des.ri][i]->getId() != '@')
							{
								Count++;
							}
						}
						if (rollNumber < Count)
						{
							Des.ci++;
							countDice++;
							pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
						}
						else
						{
							return;
						}
					}
					else
					{
						Des.ci++;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}*/
					Des.ri++;
					countDice++;
					pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
				}
				if (key != '<')
				{
					if (Des.ci == 8 && (Des.ri >= 0 && Des.ri <= 6))
					{
						Des.ri++;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}
				}
				if ((key == '<' && Des.ci == 8))
				{
					Des.ri++;
					pieces[Src.y][Src.x][Src.z].setDirection(RIGHT);
				}
				if (key != '>')
				{
					if ((Des.ci == 8 && (Des.ri >= 8 && Des.ri <= 14)))
					{
						Des.ri++;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}
					else if (Des.ci == 14 && (Des.ri >= 6 && Des.ri <= 8))
					{
						Des.ri++;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}
				}
				else if ((key == '>' && Des.ci == 8) || ((key == '>' && Des.ci == 14)))
				{
					pieces[Src.y][Src.x][Src.z].setDirection(LEFT);
				}

			}
			break;
			case(LEFT):
			{

				key = this->shp[Des.ri][Des.ci]->getId();
				key_piece = pieces[Src.y][Src.x][Src.z].getId_piece();

				if (key == 'z')
				{
					if (key_piece == 'y')
					{
						pieces[Src.y][Src.x][Src.z].setDirection(UP);
						Des.ri--;
						countDice++;

						break;
					}
				}
				if (key == 'C')
				{
					/*if (countDice == 0)
					{
						if (this->shp[Des.ri][Des.ci + rollNumber]->getId() == '@')
						{
							pieces[Src.y][Src.x].erase(pieces[Src.y][Src.x].begin() + Src.z);
							break;
						}
						int Count = 0;
						for (int i = Des.ci; i < Des.ci + rollNumber; i++)
						{
							if (this->shp[Des.ri][i]->getId() != '@')
							{
								Count++;
							}
						}
						if (rollNumber < Count)
						{
							Des.ci++;
							countDice++;
							pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
						}
						else
						{
							return;
						}
					}
					else
					{
						Des.ci++;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}*/
					Des.ci--;
					countDice++;
					pieces[Src.y][Src.x][Src.z].movePiece(window, Des);

				}
				//if (count_Cyan >= rollNumber)
				{
					/*Des.ci--;
					countDice++;
					pieces[Src.y][Src.x][Src.z].movePiece(window, Des);*/
				}


			}
			if (key != 'd')
			{
				if (Des.ri == 8 && (Des.ci >= 8 && Des.ci <= 14))
				{
					Des.ci--;
					countDice++;
					pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
				}
			}
			if (key == 'd' && Des.ri == 8)
			{
				Des.ci--;
				pieces[Src.y][Src.x][Src.z].setDirection(DOWN);
			}
			if (key != 'u')
			{
				if ((Des.ri == 8 && (Des.ci >= 0 && Des.ci <= 6)))
				{
					Des.ci--;
					countDice++;
					pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
				}
				else if (Des.ri == 14 && (Des.ci >= 6 && Des.ci <= 8))
				{
					Des.ci--;
					countDice++;
					pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
				}
			}
			if ((key == 'u' && Des.ri == 8) || (key == 'u' && Des.ri == 14))
			{
				pieces[Src.y][Src.x][Src.z].setDirection(UP);
			}
			break;
			case(RIGHT):
			{
				key = this->shp[Des.ri][Des.ci]->getId();
				key_piece = pieces[Src.y][Src.x][Src.z].getId_piece();

				if (key == 'e')
				{
					if (key_piece == 'r')
					{
						pieces[Src.y][Src.x][Src.z].setDirection(DOWN);
						Des.ri++;
						countDice++;

						break;
					}
				}
				if (key == 'B')
				{
					/*if (countDice == 0)
					{
						if (this->shp[Des.ri][Des.ci + rollNumber]->getId() == '@')
						{
							pieces[Src.y][Src.x].erase(pieces[Src.y][Src.x].begin() + Src.z);
							break;
						}
						int Count = 0;
						for (int i = Des.ci; i < Des.ci + rollNumber; i++)
						{
							if (this->shp[Des.ri][i]->getId() != '@')
							{
								Count++;
							}
						}
						if (rollNumber < Count)
						{
							Des.ci++;
							countDice++;
							pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
						}
						else
						{
							return;
						}
					}
					else
					{
						Des.ci++;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}*/
					Des.ci++;
					countDice++;
					pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
				}
				if (key != 'u')
				{
					if (Des.ri == 6 && (Des.ci >= 0 && Des.ci <= 5))
					{
						Des.ci++;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}
				}
				if (key == 'u' && Des.ri == 6)
				{
					Des.ci++;
					pieces[Src.y][Src.x][Src.z].setDirection(UP);
				}
				if (key != 'd')
				{
					if ((Des.ri == 6 && (Des.ci >= 8 && Des.ci <= 14)))
					{
						Des.ci++;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}
					else if (Des.ri == 0 && (Des.ci >= 6 && Des.ci <= 8))
					{
						Des.ci++;
						countDice++;
						pieces[Src.y][Src.x][Src.z].movePiece(window, Des);
					}

				}
				if ((key == 'd' && Des.ri == 6) || (key == 'd' && Des.ri == 0))
				{
					pieces[Src.y][Src.x][Src.z].setDirection(DOWN);
				}

			}
		
			default:
				break;
			}
			if (countDice == rollNumber)
			{
				Updateboard(window, Src, Des);
				setPiece();
				break;

			}

		}
		/*	window.clear();
			pieces[Src.y][Src.x][Src.z].drawPiece(window);
			window.display();
			sf::sleep(sf::seconds(0.5));*/
	}
}

