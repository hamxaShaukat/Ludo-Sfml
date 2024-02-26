#pragma once
#include"Global.h"
#include<iostream>
#include<string>
#include"Global.h"
using namespace std;
class Player
{
protected:
	string name;
	COLOR c;
	char id;
public:
	Player(string nam, COLOR c, char Id);
	string getname();
	COLOR getcolor();
	char getId_player();
};


