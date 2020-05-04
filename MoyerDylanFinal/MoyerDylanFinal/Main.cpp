#include "Map.h"

#include <windows.h> //For Font and Font Color

using namespace std;

void PlayAgain();

int main()
{
//For Font and Font Color
//-----------------------------------------------------------------------------------------------------------------
	HANDLE outcon = GetStdHandle(STD_OUTPUT_HANDLE);//you don't have to call this function every time

	CONSOLE_FONT_INFOEX font;//CONSOLE_FONT_INFOEX is defined in some windows header
	GetCurrentConsoleFontEx(outcon, false, &font);//PCONSOLE_FONT_INFOEX is the same as CONSOLE_FONT_INFOEX*
	font.dwFontSize.X = 7;
	font.dwFontSize.Y = 12;
	SetCurrentConsoleFontEx(outcon, false, &font);

	//A-lime green, B-ice blue, C-Red, D-purple, E-yellow, F-white
	SetConsoleTextAttribute(outcon, 0x0B);
//-----------------------------------------------------------------------------------------------------------------

	Map* GameMap = new Map;

	GameMap->move();

	delete GameMap;

	PlayAgain();

	//system("pause");
	return 0;
}

void PlayAgain()
{	
	char input;
	cout << "\nPlay again? (y/n): ";
	cin >> input;

	if (input == 'y' || input == 'Y') 
	{ 
		main(); 
	}
}