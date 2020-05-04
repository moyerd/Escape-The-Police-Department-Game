#include "Map.h"
#include "Player.h"

using namespace std;

Map::~Map()
{
	delete mStart->pNorth;
	delete mStart->pEast;
	delete mStart->pSouth;
	delete mStart->pWest;
}

void Map::helpList()
{
	cout << "\nType 'north' to move north or shortcut 'n'.";
	cout << "\nType 'east' to move north or shortcut 'e'.";
	cout << "\nType 'south' to move north or shortcut 's'.";
	cout << "\nType 'west' to move north or shortcut 'w'.";
	cout << "\nType 'look' to look at more room descriptions or shortcut 'l' and see room items.";
	cout << "\nType 'get [ItemName]' or 'take [ItemName]' without the [] to put item in your inventory and shortcut 'g' or 't'.";
	cout << "\nAll item names are lower case.";
	cout << "\nType 'inventory' to show player inventory or shortcut 'i'.";
	cout << "\nType 'help' for or shortcut 'h'.";
	cout << "\nType 'quit' to quit game or shortcut 'q'.\n\n";
}

Map::Map()
{
	//Center of Map
	Room* p1 = new Room("Outside",  "You are outside and see a sign on a building saying police department.", "You see a big double door in front of you leading north.");

	Room* p2 = new Room("Main Hall Room", "You are in a big room with a reception desk, a computer, a typewriter.", "You see a redkey on the desk and you see a four different doorways leading somewhere\na door north with a black keyhole, a door east with a red keyhole,\na door west with a green keyhole, and a door leading south.");

	//win room add last key to win to this room
	Room* p3 = new Room("Escape Room", "You open a secret door that leads to an escape to safety.\nCongratulations on beating my Game.\nProgrammed By: Dylan Moyer.", "");

	// Right side of Map
	Room* p4 = new Room("Right Hallway", "There are three windows and two of them are broken and one barricaded with wood.", "You see four different doors that leads to somewhere north, east, west, and south.");

	Room* p5 = new Room("Bathroom", "You see a bunch of stalls, blood on the floor and a dead body on the ground ", "You see a bluekey hanging from the dead body's pocket. Also, you see a door leading north.");

	Room* p6 = new Room("East Office Room", "You see multiples boxes, copy machine, several computers, files, cases, and\na small office in the back which contains a computer desk with some papers stacked on top.", "You see a door leading south looks very dark and a door leading west.");

	Room* p7 = new Room("Press Room", "There is a trail of blood that leads to a dead body. The room is scattered with papers, tables and equipments.", "You see a door leading north with a blue keyhole and a door leading south.");

	Room* p8 = new Room("Right Upper Hallway", "You are in a hallway with plants, a bench, and a soda machine.", "You see four different doors in four different directions leading north, west, east, and south.");

	Room* p9 = new Room("Observation Room", "You see audio equipment on a table with a microphone beside it and\na big window looking into a different room.", "You see a door leading north with blood leaking through the bottom of the door and a door leading east.");

	Room* p10 = new Room("Interragation Room", "You see a big table on the center with tables around, and a one-way mirror on one side of the room that says\n'Let me out'.", "You see a door leading west with blood on the door knob and some on the door and a door leading south.");

	Room* p11 = new Room("Storage Room", "There is a bunch of boxes and you see a jacket hanging on a hanging rack.", "You see a greenkey in one of the pockets of the jacket and a door leading west.");

	// Left side of Map
	Room* p12 = new Room("Reception Room", "There is a desk located on the far right side of the room\nand looks like all the drawers are opened with nothing inside them.", "You see a door leading west and a door leading east.");

	Room* p13 = new Room("Left Hallway", "You are in the left hallway that has red carpet with some windows barricaded and glass on the floor.", "You see four doors in that leads in four different locations north, south, west, and east.");

	Room* p14 = new Room("Records Room", "You see a bunch of shelves with records of people and a table in the center.", "You see a door leading north.");

	Room* p15 = new Room("West Office Room", "There are a bunch of desk joined together in the center of the room and\nbook shelves on the walls and a dead body on the ground.", "You see a door leading north and a door leading south.");

	Room* p16 = new Room("Operations Room", "You see table arm desks, a chalk board that says 'Run or get killed', and paper everyhere.", "You see a door leading north, a door leading east, and a door leading south.");

	Room* p17 = new Room("Fitting Room", "There are a bunch of lockers and some of them are open.", "You see a yellowkey inside one of the lockers slightly open.\nAlso, you see a door leading south.");

	Room* p18 = new Room("Left Upper Hallway", "You are in the left upper hallway that has red carpet, dead bodies on the floor, and glass on the floor.", "You see four different doorways one leading north with a yellow keyhole, a door leading east,\na door leading south and a door leading west.");

	Room* p19 = new Room("Safety Deposit Room", "There are gun lockers with windows some of them are locked and one of them looks like it is barely opened.", "You see blackkey inside the locker that is barely opened. Also, a door leading south.");

	Room* p20 = new Room("Deadend Hallway", "You reach a deadend of the Left Upper hallway with a dead body on the ground.", "You see a door leading south and you hear a bunch or groaning and spitty hisses and a door leading west.");

	// Death Rooms
	Room* p21 = new Room("Bottomless Pit Room", "You fell in a long fall dark pit and Died.", "");

	Room* p22 = new Room("Spike Pit Room", "You fell on a bunch of spikes and died.", "");

	Room* p23 = new Room("Zombie Pit Room", "You fell in a pit full of zombies. They ate you and you died.", "");

	// Ouside Connection
	p1->pNorth = p2;
	p1->pEast = 0;
	p1->pSouth = 0;
	p1->pWest = 0;
	mStart = p1; // start room Outside

	// Main Hall Room Connection
	p2->pNorth = p3;
	p2->pEast = p4;
	p2->pSouth = p1;
	p2->pWest = p12;
	p2->roomInventory.push_back("redkey");

	// Key Room Connection
	p3->pNorth = 0;
	p3->pEast = 0;
	p3->pSouth = p2;
	p3->pWest = 0;

	// Right Hallway Connection
	p4->pNorth = p7;
	p4->pEast = p6;
	p4->pSouth = p5;
	p4->pWest = p2;

	// Bathroom Connection
	p5->pNorth = p4;
	p5->pEast = 0;
	p5->pSouth = 0;
	p5->pWest = 0;
	p5->roomInventory.push_back("bluekey");

	// East Office Room Connection
	p6->pNorth = 0;
	p6->pEast = 0;
	p6->pSouth = p21;
	p6->pWest = p4;

	// Press Room Connection
	p7->pNorth = p8;
	p7->pEast = 0;
	p7->pSouth = p4;
	p7->pWest = 0;

	// Right Upper Hallway Connection
	p8->pNorth = p10;
	p8->pEast = p11;
	p8->pSouth = p7;
	p8->pWest = p9;

	// Observation Room Connection
	p9->pNorth = p22;
	p9->pEast = p8;
	p9->pSouth = 0;
	p9->pWest = 0;

	// Interragation Room Connection
	p10->pNorth = 0;
	p10->pEast = 0;
	p10->pSouth = p8;
	p10->pWest = p22;

	// Closet Connection
	p11->pNorth = 0;
	p11->pEast = 0;
	p11->pSouth = 0;
	p11->pWest = p8;
	p11->roomInventory.push_back("greenkey");

	// Reception Room Connection
	p12->pNorth = 0;
	p12->pEast = p2;
	p12->pSouth = 0;
	p12->pWest = p13;

	// Left Hallway Connection
	p13->pNorth = p15;
	p13->pEast = p12;
	p13->pSouth = p14;
	p13->pWest = p16;

	// Records Room Connection
	p14->pNorth = p13;
	p14->pEast = 0;
	p14->pSouth = 0;
	p14->pWest = 0;

	// West Office Room Connection
	p15->pNorth = p18;
	p15->pEast = 0;
	p15->pSouth = p13;
	p15->pWest = 0;

	// Operations Room Connection
	p16->pNorth = p17;
	p16->pEast = p18;
	p16->pSouth = p13;
	p16->pWest = 0;

	// Fitting Room Connection
	p17->pNorth = 0;
	p17->pEast = 0;
	p17->pSouth = p16;
	p17->pWest = 0;
	p17->roomInventory.push_back("yellowkey");

	// Left Upper Hallway Connection
	p18->pNorth = p19;
	p18->pEast = p20;
	p18->pSouth = p15;
	p18->pWest = p16;

	// Safety Deposit Room Connection
	p19->pNorth = 0;
	p19->pEast = 0;
	p19->pSouth = p18;
	p19->pWest = 0;
	p19->roomInventory.push_back("blackkey");

	// Deadend Hallway Connection
	p20->pNorth = 0;
	p20->pEast = 0;
	p20->pSouth = p23;
	p20->pWest = p18;

	// Death Rooms
	// Bottomless Pit Room
	p21->pNorth = 0;
	p21->pEast = 0;
	p21->pSouth = 0;
	p21->pWest = 0;

	// Spike Pit Room 
	p22->pNorth = 0;
	p22->pEast = 0;
	p22->pSouth = 0;
	p22->pWest = 0;

	// Zombie Pit Room
	p23->pNorth = 0;
	p23->pEast = 0;
	p23->pSouth = 0;
	p23->pWest = 0;
};

void Map::move()
{

	//Create Pointer to Player Class
	Player* Survivor = new Player();

	cout << "Find keys for the required doors to Escape the Police Department.\nAlso, watch out for death rooms." << endl;

	helpList(); // Gets Help Instructions from Map Class

	cout << endl;
	Survivor->pLoc->pRoomName(); //gets room name
	Survivor->pLoc->pRoomDesc(); //gets room description

	while (gameIsRunning != false)
	{

		cout << "\nEnter a command: ";
		cin >> command;

		if (command == "North" || command == "north" || command == "N" || command == "n")
		{
			if (Survivor->pLoc->pNorth == 0)
			{
				cout << "\nYou can't go that way." << endl;
			}
			else if (Survivor->pLoc->RoomName() == "Press Room")
			{
				if (bluekey == false)
				{
					cout << "\nYou can't open the door, it looks like a blue key hole for this door.\n";
				}
				else
				{
					cout << "\nYou open the door with the blue key.\n";
					Survivor->pLoc = Survivor->pLoc->pNorth;
					cout << endl;
					Survivor->pLoc->pRoomName(); //gets room name
					Survivor->pLoc->pRoomDesc(); //gets room description
				}
			}
			else if (Survivor->pLoc->RoomName() == "Main Hall Room")
			{
				if (blackkey == false)
				{
					cout << "\nYou can't open the door, it looks like a black key hole for this door.\n";
				}
				else
				{
					cout << "\nYou open the door with the black key.\n";
					Survivor->pLoc = Survivor->pLoc->pNorth;
					cout << endl;
					Survivor->pLoc->pRoomName(); //gets room name
					Survivor->pLoc->pRoomDesc(); //gets room description
					gameIsRunning = false;
				}
			}
			else if (Survivor->pLoc->RoomName() == "Left Upper Hallway")
			{
				if (yellowkey == false)
				{
					cout << "\nYou can't open the door, it looks like a yellow key hole for this door.\n";
				}
				else
				{
					cout << "\nYou open the door with the yellow key.\n";
					Survivor->pLoc = Survivor->pLoc->pNorth;
					cout << endl;
					Survivor->pLoc->pRoomName(); //gets room name
					Survivor->pLoc->pRoomDesc(); //gets room description
				}
			}
			else if (Survivor->pLoc->RoomName() == "Observation Room")
			{
				Survivor->pLoc = Survivor->pLoc->pNorth;
				cout << endl;
				Survivor->pLoc->pRoomName(); //gets room name
				Survivor->pLoc->pRoomDesc(); //gets room description
				gameIsRunning = false;
			}
			else
			{
				Survivor->pLoc = Survivor->pLoc->pNorth;
				cout << endl;
				Survivor->pLoc->pRoomName(); //gets room name
				Survivor->pLoc->pRoomDesc(); //gets room description
			}

		}
		else if (command == "East" || command == "east" || command == "E" || command == "e")
		{
			if (Survivor->pLoc->pEast == 0)
			{
				cout << "\nYou can't go that way." << endl;
			}
			else if (Survivor->pLoc->RoomName() == "Main Hall Room")
			{
				if (redkey == false)
				{
					cout << "\nYou can't open the door, it looks like a red key hole for this door.\n";
				}
				else
				{
					cout << "\nYou open the door with the red key.\n";
					Survivor->pLoc = Survivor->pLoc->pEast;
					cout << endl;
					Survivor->pLoc->pRoomName(); //gets room name
					Survivor->pLoc->pRoomDesc(); //gets room description
				}
			}
			else
			{
				Survivor->pLoc = Survivor->pLoc->pEast;
				cout << endl;
				Survivor->pLoc->pRoomName(); //gets room name
				Survivor->pLoc->pRoomDesc(); //gets room description
			}

		}
		else if (command == "South" || command == "south" || command == "S" || command == "s")
		{
			if (Survivor->pLoc->pSouth == 0)
			{
				cout << "\nYou can't go that way." << endl;
			}
			else if (Survivor->pLoc->RoomName() == "East Office Room")
			{
				Survivor->pLoc = Survivor->pLoc->pSouth;
				cout << endl;
				Survivor->pLoc->pRoomName(); //gets room name
				Survivor->pLoc->pRoomDesc(); //gets room description
				gameIsRunning = false;
			}
			else if (Survivor->pLoc->RoomName() == "Deadend Hallway")
			{
				Survivor->pLoc = Survivor->pLoc->pSouth;
				cout << endl;
				Survivor->pLoc->pRoomName(); //gets room name
				Survivor->pLoc->pRoomDesc(); //gets room description
				gameIsRunning = false;
			}
			else
			{
				Survivor->pLoc = Survivor->pLoc->pSouth;
				cout << endl;
				Survivor->pLoc->pRoomName(); //gets room name
				Survivor->pLoc->pRoomDesc(); //gets room description
			}

		}
		else if (command == "West" || command == "west" || command == "W" || command == "w")
		{
			if (Survivor->pLoc->pWest == 0)
			{
				cout << "\nYou can't go that way." << endl;
			}
			else if (Survivor->pLoc->RoomName() == "Main Hall Room")
			{
				if (greenkey == false)
				{
					cout << "\nYou can't open the door, it looks like a green key hole for this door.\n";
				}
				else
				{
					cout << "\nYou open the door with the green key.\n";
					Survivor->pLoc = Survivor->pLoc->pWest;
					cout << endl;
					Survivor->pLoc->pRoomName(); //gets room name
					Survivor->pLoc->pRoomDesc(); //gets room description
				}
			}
			else if (Survivor->pLoc->RoomName() == "Interragation Room")
			{
				Survivor->pLoc = Survivor->pLoc->pWest;
				cout << endl;
				Survivor->pLoc->pRoomName(); //gets room name
				Survivor->pLoc->pRoomDesc(); //gets room description
				gameIsRunning = false;
			}
			else
			{
				Survivor->pLoc = Survivor->pLoc->pWest;
				cout << endl;
				Survivor->pLoc->pRoomName(); //gets room name
				Survivor->pLoc->pRoomDesc(); //gets room description
			}
		}

		else if (command == "Get" || command == "get" || command == "G" || command == "g" || command == "Take" || command == "take" || command == "T" || command == "t")
		{

			cout << "\nWhat item do you want to pick up?" << endl << "item name: ";
			cin >> pickupItem;

			vector<string>::iterator findItem;
			findItem = find(Survivor->pLoc->roomInventory.begin(), Survivor->pLoc->roomInventory.end(), pickupItem);
			if (findItem != Survivor->pLoc->roomInventory.end())
			{
				cout << "\nYou picked up the " << pickupItem << "." << endl;
				Survivor->playerInventory.push_back(pickupItem);
				Survivor->pLoc->roomInventory.pop_back();
				if (pickupItem == "redkey")
				{
					redkey = true;
				}
				else if(pickupItem == "bluekey")
				{
					bluekey = true;
				}
				else if (pickupItem == "greenkey")
				{
					greenkey = true;
				}
				else if (pickupItem == "yellowkey")
				{
					yellowkey = true;
				}
				else if (pickupItem == "blackkey")
				{
					blackkey = true;
				}
			}
			else
			{
				cout << "\nThe item " << pickupItem << " is not in here."  << endl;
			}
		}
		else if (command == "Look" || command == "look" || command == "L" || command == "l")
		{
			cout << endl;
			Survivor->pLoc->pRoomLook(); //gets room description
			Survivor->pLoc->getRoomItems(); //gets room Inv
		}
		else if (command == "Inventory" || command == "inventory" || command == "I" || command == "i")
		{
			Survivor->getInventory(); //gets player Inv
		}
		else if (command == "Quit" || command == "quit" || command == "Q" || command == "q")
		{
			cout << "\nGoodbye!" << endl;
			gameIsRunning = false; // breaks loop and quits game
			//or use 
			//break; to break the loop
		}
		else if (command == "Help" || command == "help" || command == "H" || command == "h")
		{
			helpList(); // Gets Help Instructions
		}
		else
		{
			cout << "\nInvalid command!\n" << endl;
		}
	}

}