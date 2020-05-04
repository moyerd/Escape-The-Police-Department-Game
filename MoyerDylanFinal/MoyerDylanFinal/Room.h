#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Room
{
public:
	Room(string n, string desc, string look);
	~Room();
	string RoomName();
	void pRoomName();
	void pRoomDesc();
	void pRoomLook();

	vector<string> roomInventory;
	void getRoomItems();

	Room* pEast;
	Room* pWest;
	Room* pNorth;
	Room* pSouth;

private:
	string rName;
	string rDesc;
	string rLook;
};