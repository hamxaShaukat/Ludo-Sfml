#pragma once
#include"Player.h"
#include"Board.h"
#include"Global.h"
#include"Dice.h"
#include"Piece.h"
#include<vector>

class Board;
class Piece;
class Player;
class Dice;
struct Position;
class Ludo
{
private:
	Board* B;
	bool canRollDice=true;
	Player* p2[2];
	Player* p3[3];
	Player* p4[4];
	Player* p6[6];
	Player** Ps;
	int nop;
	int countSix=0;
	int turn;
	sf::Vector3f src;
	Position source;
	Position destination;
	//vector<int>scoreTracker;
	int count = 0;
	vector<char> Receiver;

public:
	Ludo(sf::RenderWindow& window,int nop);
	void selectSource(sf::RenderWindow& window);
	void selectDestination(sf::RenderWindow& window);
	void computeDestination(sf::RenderWindow& window,Player* Aikplayer);
	void Turnchange(int nop);
	void setNop(int Ns);
	void validMovement(sf::RenderWindow& window, Dice D);
	void selectSourceDice(sf::RenderWindow& window,Dice d, Player *Aikplayer);
	bool Isvalidsource(Player Aikplayer);
	void play(sf::RenderWindow& window);
	int getDiceNum(sf::RenderWindow& win, Dice D);
	void displayTurnmsg(sf::RenderWindow& window);
	void displayGoti(sf::RenderWindow& window);
	bool Inbound(Position P);
	
};

