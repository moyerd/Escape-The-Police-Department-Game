#include "Player.h"

using namespace std;

Player::Player()
{
	pLoc = mStart;
}

Player::~Player()
{
}

void Player::getInventory()
{
	vector<string>::iterator iter;

	if (playerInventory.size() != 0)
	{
		cout << "\nYour items:" << endl;
		for (iter = playerInventory.begin(); iter != playerInventory.end(); ++iter)
		{
			cout << *iter << endl;
		}
	}
	else
	{
		cout << "\nYour inventory is empty!" << endl;
	}
}
