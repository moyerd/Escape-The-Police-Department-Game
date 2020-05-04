#include "Room.h"

using namespace std;

Room::Room(string n, string desc, string look)
{
	rName = n;
	rDesc = desc;
	rLook = look;
}

Room::~Room()
{
}

void Room::getRoomItems()
{

	vector<string>::iterator iter;


	if (roomInventory.size() != 0)
	{
		cout << "\nThe rooms items:" << endl;
		for (iter = roomInventory.begin(); iter != roomInventory.end(); ++iter)
		{
			cout << *iter << endl;
		}
	}
	else
	{ 
		cout << "\nRoom inventory is empty!" << endl;
	}
}

void Room::pRoomName()
{
	cout << rName << endl;
}

void Room::pRoomDesc()
{
	cout << rDesc << endl;
}

void Room::pRoomLook()
{
	cout << rLook << endl;
}

string Room::RoomName()
{
	return rName;
}