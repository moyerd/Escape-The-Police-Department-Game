#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Room.h"

using namespace std;

class Map
{
public:
	Map();
	~Map();

	Room* mStart;

	void helpList(); // Help Instructions function
	void move();

	bool gameIsRunning = true;
	string command;
	string pickupItem;
	//inv flags
	bool redkey = false;
	bool bluekey = false;
	bool greenkey = false;
	bool yellowkey = false;
	bool blackkey = false;
};