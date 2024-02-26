#include"SFML/Graphics.hpp"
#include<fstream>
#include<iostream>
#include<vector>
#include"Board.h"
#include"Piece.h"
#include"Global.h"
#include"Ludo.h"
#include"Shape.h"
#include"Dice.h"
#include <thread>

struct Position;
using namespace std;
#define Rows 15
#define Columns 24

void Ludo::validMovement(sf::RenderWindow& window,Dice D)
{
	int dice;
	if (countSix == 0)
	{
		dice = 6;
	}
	else
	{
		dice = D.getNumfromDice();
		
	}
	D.showRollDice(window, *B, dice);
	selectSource(window);
	
	if(dice==6)
	{
		if (countSix == 3)
		{
			countSix = 0;
			Turnchange(nop);
			return;
		}
		if(Isvalidsource(*Ps[turn]) && B->getPieceAt(src).Isfirst(src))
		{
			countSix++;
			computeDestination(window, Ps[turn]);
			return;
		}
		else if(Isvalidsource( *Ps[turn]))
		{
			if(B->IsCaptured(window,src,dice,nop))
			{
				countSix = 0;
				return;
			}
			countSix++;
			B->GoHome(window, src, dice, nop,Receiver);
			return;
		}
		if(countSix==2)
		{
			countSix = 0;
			Turnchange(nop);
			return;
		}
	}
	else 
	{
		if (Isvalidsource(  *Ps[turn]))
		{
			if (B->getPieceAt(src).Isfirst(src))
			{
				countSix = 0;
				Turnchange(nop);
				count++;
			}
			else
			{
				if(B->IsCaptured(window,src, dice,nop))
				{
					countSix = 0;

					return;
				}
				countSix = 0;
				B->GoHome(window, src, dice, nop,Receiver);
				count++;
				Turnchange(nop);
			}
		}
	}
}
/*
void Ludo::selectSourceDice(sf::RenderWindow&window,Dice d,Player *Aikplayer)
{
	int countSixes = 0;
	
	selectSource(window);
	if (!canRollDice && d.isThrown( nop))
	{
		int dice = d.getNumfromDice();
		cout << "Dice: " << dice << endl;
		d.showRollDice(window, *B, dice);
			
		if (dice == 6)
		{
				selectSource(window);
				cout << "SOurce is " << source.ri << " " << source.ci << endl;

				cout << endl << "I am in six position of dice: ";
				canRollDice = true;
				countSixes++;

			if (!canRollDice && Isvalidsource(*Ps[turn]) && B->getPieceAt(src).Isfirst(source))
			{
				computeDestination(window, Aikplayer);
				cout << endl << "Succesfully updated the board in 6: ";

			}
			else if(Isvalidsource(*Ps[turn]))
			{
				B->Updateboard(window,src,dice,nop);
				cout << endl << "Succesfully updated the board in 6: ";

			}
			if (countSixes == 3)
			{
				countSixes = 0; canRollDice = false;
				Turnchange(nop);
				return;
			}
		}
		else
		{
			cout << endl << "I am in not in 6 position of dice: ";
			selectSource(window);
			cout << "SOurce is " << source.ri << " " << source.ci << endl;

			canRollDice = false;
			B->Updateboard(window, src, dice, nop);
			Turnchange(nop);
			cout << endl << "Succesfully updated the board: ";
		}
	}
}
*/
bool Ludo::Isvalidsource(Player player)
{
	Piece p = B->getPieceAt(src);
	if (/* p != nullptr && */p.getId_piece() == player.getId_player())
	{
		cout << "\nRight choice";
		return true;
	}
	else
	{
		cout << " Wrong choice";
		return false;
	}
}
void Ludo::selectSource(sf::RenderWindow& window)
{
	float r, c;
	Global::getRowColbyLeftClick(r, c, window);
	src.x = c;
	src.y = r;
	src.z=0;
	cout << "You have selected " << (int)r<<"th row " << (int)c<<"th column";
}
void Ludo::selectDestination(sf::RenderWindow& window)
{
	float r, c;
	Global::getRowColbyLeftClick(r, c, window);
	destination.ri = r;
	destination.ci = c;
}
void Ludo::computeDestination(sf::RenderWindow& window, Player* Aikplayer)
{
	if (nop == 6)
	{

		if (turn == 0)
		{
			if (Isvalidsource( *Aikplayer) && B->getPieceAt(src).Isfirst(src))
			{
				destination.ri = 6;
				destination.ci = 1;
				B->Updateboard(window, src, destination);
			}
		}
		else if (turn == 1)
		{
			if (Isvalidsource( *Aikplayer) && B->getPieceAt(src).Isfirst(src))
			{
				destination.ri = 1;
				destination.ci = 8;
				B->Updateboard(window, src, destination);
			}
		}
		else if (turn == 2)
		{
			if (Isvalidsource( *Aikplayer) && B->getPieceAt(src).Isfirst(src))
			{
				destination.ri = 1;
				destination.ci = 17;
				B->Updateboard(window, src, destination);
			}
		}
		else if (turn == 3)
		{
			if (B->getPieceAt(src).Isfirst(src) && Isvalidsource(*Aikplayer))
			{
				destination.ri = 8;
				destination.ci = 22;
				B->Updateboard(window, src, destination);
			}
		}
		else if (turn == 4)
		{
			if (B->getPieceAt(src).Isfirst(src) && Isvalidsource( *Aikplayer))
			{
				destination.ri = 13;
				destination.ci = 15;
				B->Updateboard(window, src, destination);
			}
		}
		else if (turn == 5)
		{
			if (B->getPieceAt(src).Isfirst(src) && Isvalidsource(*Aikplayer))
			{
				destination.ri = 13;
				destination.ci = 6;
				B->Updateboard(window, src, destination);
			}
		}
	}
	else if (nop == 4)
	{

		if (turn == 0)
		{
			if (Isvalidsource( *Aikplayer) && B->getPieceAt(src).Isfirst(src))
			{
				destination.ri = 6;
				destination.ci = 1;
				B->Updateboard(window, src, destination);
			}
		}
		else if (turn == 1)
		{
			if (Isvalidsource(  *Aikplayer) && B->getPieceAt(src).Isfirst(src))
			{
				destination.ri = 1;
				destination.ci = 8;
				B->Updateboard(window, src, destination);
			}
		}
		else if (turn == 2)
		{
			if (Isvalidsource(  *Aikplayer) && B->getPieceAt(src).Isfirst(src))
			{
				destination.ri = 8;
				destination.ci = 13;
				B->Updateboard(window, src, destination);
			}
		}
		else if (turn == 3)
		{
			if (B->getPieceAt(src).Isfirst(src) && Isvalidsource(  *Aikplayer))
			{
				destination.ri = 13;
				destination.ci = 6;
				B->Updateboard(window, src, destination);
			}
		}
	}

	else if (nop == 2)
	{
		if (turn == 0)
		{
		if (Isvalidsource(  *Aikplayer) && B->getPieceAt(src).Isfirst(src))
		{
			destination.ri = 6;
			destination.ci = 1;
			B->Updateboard(window, src, destination);
		}
		}
		else if (turn == 1)
		{
		if (Isvalidsource(  *Aikplayer) && B->getPieceAt(src).Isfirst(src))
		{
			destination.ri = 8;
			destination.ci = 13;
			B->Updateboard(window, src, destination);
		}
		}
	}
	else
	{
		if (turn == 0)
		{
			if (Isvalidsource(  *Aikplayer) && B->getPieceAt(src).Isfirst(src))
			{
				destination.ri = 6;
				destination.ci = 1;
				B->Updateboard(window, src, destination);
			}
		}
		else if (turn == 1)
		{
			if (Isvalidsource(  *Aikplayer) && B->getPieceAt(src).Isfirst(src))
			{
				destination.ri = 1;
				destination.ci = 17;
				B->Updateboard(window, src, destination);
			}
		}
		else if (turn == 2)
		{
			if (Isvalidsource(  *Aikplayer) && B->getPieceAt(src).Isfirst(src))
			{
				destination.ri = 13;
				destination.ci = 15;
				B->Updateboard(window, src, destination);
			}
		}
	}
}
void Ludo::Turnchange(int nop)
{
	if (nop == 2)
	{
		if (turn == 0)
			turn = 1;
		else
			turn = 0;
	}
	else if (nop == 4)
	{
		if (turn == 0)
			turn = 1;
		else if (turn == 1)
			turn = 2;
		else if (turn == 2)
			turn = 3;
		else
			turn = 0;
	}
	else if (nop == 3)
	{
		if (turn == 0)
			turn = 1;
		else if (turn == 1)
			turn = 2;
		else if (turn == 2)
			turn = 0;

	}
	else if (nop == 6)
	{
		if (turn == 0)
			turn = 1;
		else if (turn == 1)
			turn = 2;
		else if (turn == 2)
			turn = 3;
		else if (turn == 3)
			turn = 4;
		else if (turn == 4)
			turn = 5;
		else
			turn = 0;
			
	}
}
void Ludo::setNop(int Ns)
{
	this->nop = Ns;
}
bool Ludo::Inbound(Position P)
{
	if (nop == 2 || nop == 4)
	{
		if (P.ri >= 0 || P.ci >= 0 || P.ri < 15 || P.ci < 15)
			return true;
		else
			return false;
	}
	else if (nop = 3 || nop == 6)
	{
		if (P.ri >= 0 || P.ci >= 0 || P.ri < 15 || P.ci < 25)
			return true;
		else
			return false;
	}
}
Ludo::Ludo(sf::RenderWindow& window,int nop)
{
	turn = 1;
	if (nop == 2)
	{
		Ps = new Player * [nop];
		Ps[0] = new Player("Hamza", BLUE, 'b');
		Ps[1] = new Player("Hassan", CYAN, 'c');
	}
	else if (nop == 4)
	{
		Ps = new Player * [nop];
		Ps[0] = new Player("Hamza", BLUE, 'b');
		Ps[1] = new Player("Hassan", RED, 'r');
		Ps[2] = new Player("Irfan",CYAN, 'c');
		Ps[3] = new Player("A.Manan", YELLOW, 'y');
	}
	else if (nop == 3)
	{
		Ps = new Player * [nop];
		Ps[0] = new Player("Hamza", BLUE, 'b');
		Ps[1] = new Player("Irfan", GREEN, 'g');
		Ps[2] = new Player("A.Rehman", CYAN, 'c');
	}
	else
	{
		Ps = new Player * [nop];
		Ps[0] = new Player("Hamza", BLUE, 'b');
		Ps[1] = new Player("Hassan", RED, 'r');
		Ps[2] = new Player("Irfan", GREEN, 'g');
		Ps[3] = new Player("A.Manan", PURPLE, 'p');
		Ps[4] = new Player("A.Moiz", CYAN, 'c');
		Ps[5] = new Player("A.Rehman", YELLOW, 'y');
	}
	
	B = new Board(window,nop);
}
int Ludo::getDiceNum(sf::RenderWindow& win,Dice D)
{
	int n = 0;
	srand(time(0));
	for(int i=0;i<15;i++)
	{
		int roll = rand() % 6 + 1;
		switch(roll)
		{
		case(1):
			D.drawDice(win, roll);
			D.Rotation();
			n = roll;
			break;
		case(2):
			D.drawDice(win, roll);
			D.Rotation();
			n = roll;
			break;
		case(3):
			D.drawDice(win, roll);
			D.Rotation();
			n = roll;

			break;
		case(4):
			D.drawDice(win, roll);
			D.Rotation();
			n = roll;
			break;
		case(5):
			D.drawDice(win, roll);
			D.Rotation();
			n = roll;

			break;
		case(6):
			D.drawDice(win, roll);
			D.Rotation();
			n = roll;

			break;
		}
	}
	return n;
}
void Ludo::play(sf::RenderWindow& window)
{

	sf::Font Ft;
	sf::Text Tx;
	Ft.loadFromFile("Button.ttf");
	Tx.setFont(Ft);
	Tx.setFillColor(sf::Color::Color(21, 67, 96));
	Tx.setString("Roll Dice");
	Tx.setCharacterSize(60);
	if (nop == 3 || nop == 6)
	{
		Tx.setPosition(Global::dimSqr.x * 25, Global::dimSqr.y * 7);
	}
	else if (nop == 2 || nop == 4)
	{
		Tx.setPosition(Global::dimSqr.x * 16, Global::dimSqr.y * 7);
	}

	Global::Ts = new sf::Texture[23];
	//------------------PIECES-------------------
	Global::Ts[0].loadFromFile("H_Blue.png");
	Global::Ts[1].loadFromFile("H_Red.png");
	Global::Ts[2].loadFromFile("H_Green.png");
	Global::Ts[3].loadFromFile("H_Yellow.png");
	Global::Ts[4].loadFromFile("H_Cyan.png");
	Global::Ts[5].loadFromFile("H_Purple.png");
	Global::Ts[6].loadFromFile("stop.png");
	Global::Ts[7].loadFromFile("pic_4.jpeg");
	Global::Ts[8].loadFromFile("center_Red.jpeg");
	Global::Ts[9].loadFromFile("pic_1.jpeg");
	Global::Ts[10].loadFromFile("center_two.jpeg");
	//---------------------HOME PICTURES------------------
	Global::Ts[11].loadFromFile("Blue_Home.jpeg");
	Global::Ts[12].loadFromFile("Red_Home.jpeg");
	Global::Ts[13].loadFromFile("Green_Home.jpeg");
	Global::Ts[14].loadFromFile("Purple_Home.jpeg");
	Global::Ts[15].loadFromFile("Cyan_Home.jpeg");
	Global::Ts[16].loadFromFile("Yellow_Home.jpeg");
	//---------------------HOME POINTS------------------
	Global::Ts[17].loadFromFile("B_H.jpeg");
	Global::Ts[18].loadFromFile("R_H.jpeg");
	Global::Ts[19].loadFromFile("G_H.jpeg");
	Global::Ts[20].loadFromFile("Y_H.jpeg");
	Global::Ts[21].loadFromFile("C-H.jpeg");
	Global::Ts[22].loadFromFile("P_H.jpeg");
	//------------------BACKGROUND IMAGE----------
	sf::Texture pic;
	sf::Sprite spr;
	pic.loadFromFile("Hamza_background.png");
	spr.setTexture(pic);
	spr.setScale(sf::Vector2f(1,1));
	spr.setPosition(0,0);
	
	// -----------------DICE---------------------
	sf::Texture *T;
	T = new sf::Texture[6];
	Dice D(window,T,nop);
	srand(time(0));
	while (window.isOpen())
	{
		sf::Event evnt;
	
		while (window.pollEvent(evnt))
		{
			if (evnt.type == evnt.Closed)
			{
				window.close();
			}
		}
		int dice = rand() % 6 + 1;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if(Tx.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
			{
				validMovement(window, D);
			}
		}
			
		window.clear();
		window.draw(spr);
		B->Drawboxes_shape(window);
		B->Drawboxes_piece(window);
		window.draw(B->ludo);
		window.draw(Tx);
		displayTurnmsg(window);
		displayGoti(window);
		window.display();

	}
}
void Ludo::displayTurnmsg(sf::RenderWindow& window)
{
	sf::Font F;
	sf::Text T;
	F.loadFromFile("Button.ttf"); 
	T.setFont(F);
	T.setFillColor(sf::Color::Color(31, 97, 141));
	T.setString("TURN:");
	T.setCharacterSize(60);
	if (nop == 3 || nop == 6)
	{
		T.setPosition(sf::Vector2f(1265, 80));
	}
	else if (nop == 2 || nop == 4)
	{
		T.setPosition(sf::Vector2f(1115, 80));
	}
	window.draw(T);


}
void Ludo::displayGoti(sf::RenderWindow& window)
{
	if (nop == 6)
	{
		if (turn == 0)
		{
			sf::Sprite S;
			S.setTexture(Global::Ts[0]);
		    S.setScale(0.30,0.30);
			S.setPosition(1430,70);
			window.draw(S);

		}
		else if (turn == 1)
		{
			sf::Sprite S;
			S.setTexture(Global::Ts[1]);
			S.setScale(0.30, 0.30);
			S.setPosition(1430, 70);
			window.draw(S);
		}
		else if (turn == 2)
		{
			sf::Sprite S;
			S.setTexture(Global::Ts[2]);
			S.setScale(0.30, 0.30);
			S.setPosition(1430, 70);
			window.draw(S);
		}
		else if (turn == 3)
		{
			sf::Sprite S;
			S.setTexture(Global::Ts[5]);
			S.setScale(0.30, 0.30);
			S.setPosition(1430, 70);
			window.draw(S);
		}
		else if (turn == 4)
		{
			sf::Sprite S;
			S.setTexture(Global::Ts[4]);
			S.setScale(0.30, 0.30);
			S.setPosition(1430, 70);
			window.draw(S);
		}
		else if (turn == 5)
		{
			sf::Sprite S;
			S.setTexture(Global::Ts[3]);
			S.setScale(0.30, 0.30);
			S.setPosition(1430, 70);
			window.draw(S);
		}
	}
	else if (nop == 3)
	{
		if (turn == 0)
		{
			sf::Sprite S;
			S.setTexture(Global::Ts[0]);
			S.setScale(0.30, 0.30);
			S.setPosition(1430, 70);
			window.draw(S);
		}
		else if (turn == 1)
		{
			sf::Sprite S;
			S.setTexture(Global::Ts[2]);
			S.setScale(0.30, 0.30);
			S.setPosition(1430, 70);
			window.draw(S);
		}
		else if (turn == 2)
		{
			sf::Sprite S;
			S.setTexture(Global::Ts[4]);
			S.setScale(0.30, 0.30);
			S.setPosition(1430, 70);
			window.draw(S);
		}
	}
	else if (nop == 2)
	{
		if (turn == 0)
		{
			sf::Sprite S;
			S.setTexture(Global::Ts[0]);
			S.setScale(0.30, 0.30);
			S.setPosition(1300, 70);
			window.draw(S);
		}
		else if (turn == 1)
		{
			sf::Sprite S;
			S.setTexture(Global::Ts[4]);
			S.setScale(0.30, 0.30);
			S.setPosition(1300, 70);
			window.draw(S);
		}
	}
	else if (nop == 4)
	{
		if (turn == 0)
		{
			sf::Sprite S;
			S.setTexture(Global::Ts[0]);
			S.setScale(0.30, 0.30);
			S.setPosition(1300, 70);
			window.draw(S);
		}
		else if (turn == 1)
		{
			sf::Sprite S;
			S.setTexture(Global::Ts[1]);
			S.setScale(0.30, 0.30);
			S.setPosition(1300, 70);
			window.draw(S);
		
		}
		else if (turn == 2)
		{
			sf::Sprite S;
			S.setTexture(Global::Ts[4]);
			S.setScale(0.30, 0.30);
			S.setPosition(1300, 70);
			window.draw(S);
		}
		else if (turn == 3)
		{
			sf::Sprite S;
			S.setTexture(Global::Ts[3]);
			S.setScale(0.30, 0.30);
			S.setPosition(1300, 70);
			window.draw(S);
		}
	}
}


