#include "Player.h"
#include"Global.h"

using namespace std;
Player::Player(string n, COLOR Clr, char Id)
{
	this->name = n;
	this->c = Clr;
	this->id = Id;
}
string Player::getname()
{
	return this->name;
}
COLOR Player::getcolor()
{
	return this->c;
}
char Player::getId_player()
{
	return this->id;
}


