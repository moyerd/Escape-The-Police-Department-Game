#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Room.h"
#include "Map.h"

using namespace std;

class Player : public Map //Makes Map Class public is player class can access pLoc
{
public:
	Player();
	~Player();

	Room* pLoc;

	vector<string> playerInventory;

	void getInventory();

};