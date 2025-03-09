// *************************************************************************
// Group: Group 1
// Course: CS-355-01
// Assignment: Project 4
// Due Date: 3/16/2025
// Description: Implementation of the ActiveMap class
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Daniel Puckett
// Date: 3/7/2025
// Description: Created the implementation for core functionality and
//	tracking player position.
// *************************************************************************
// *************************************************************************
// Name: Daniel Puckett
// Date: 3/9/2025
// Description: Created the implementation for Item position handling and
//	Player pick up validation
// *************************************************************************


#ifndef H_ACTIVEMAP
	#define H_ACTIVEMAP
	#include "ActiveMap.h"
#endif

// *************************************************************************
// Default contructor for ActiveMap
// Incoming Data: none
// Outgoing Data: none
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Daniel Puckett
// Date: 3/7/2025
// Description: Created the constructor to initialize player (x,y)
// coordinates
// *************************************************************************
ActiveMap::ActiveMap()
{
	playerPos[0] = 0;
	playerPos[1] = 0;
}

// *************************************************************************
// addRow allows the MapV2 to store the parsed tokens into the string 
//	vector that functions as the ASCII map.
// Incoming Data: string line
// Outgoing Data: none
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Daniel Puckett
// Date: 3/7/2025
// Description: Created the method to store the input into the vector
// *************************************************************************
void ActiveMap::addRow(string line)
{
	textMap.push_back(line);
}

// *************************************************************************
// createUserMap creates a deep copy of the original textMap vector to
//	handle palyer movement
// Incoming Data: none
// Outgoing Data: none
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Daniel Puckett
// Date: 3/7/2025
// Description: Created the method to create the deep copy
// *************************************************************************
void ActiveMap::createUserMap()
{
	for (int i = 0; i < textMap.size(); i++)
	{
		userMap[i] = textMap[i];
	}
}

// *************************************************************************
// updatePlayerPos handles player movement on the ASCII map
// Incoming Data: char direction
// Outgoing Data: none
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Daniel Puckett
// Date: 3/7/2025
// Description: Created the method handle updating the player coordinate
// *************************************************************************
void ActiveMap::updatePlayerPos(char dir)
{
	if (dir == 'u')
	{
		playerPos[1] += 1;
	}
	else if (dir == 'd')
	{
		playerPos[1] -= 1;
	}
	else if (dir == 'l')
	{
		playerPos[0] -= 1;
	}
	else if (dir == 'r')
	{
		playerPos[0] += 1;
	}
	else 
	{
		cout << "DEBUG: INVALID USER MOVEMENT DIRECTION IN ACTIVEMAP" << endl;
		return;
	}
	if (!checkValidMove())
	{
		if (dir == 'u')
		{
			playerPos[1] += 1;
		}
		else if (dir == 'd')
		{
			playerPos[1] -= 1;
		}
		else if (dir == 'l')
		{
			playerPos[0] -= 1;
		}
		else if (dir == 'r')
		{
			playerPos[0] += 1;
		}
		cout << "You cannot move there" << endl;
		return;
	}
	overrideChar();
}

// *************************************************************************
// checkValidMove is a private helper method that handles movement 
//	validation
// Incoming Data: none
// Outgoing Data: bool
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Daniel Puckett
// Date: 3/7/2025
// Description: Created the method to store the input into the vector
// *************************************************************************
bool ActiveMap::checkValidMove()
{
	if (userMap[playerPos[1]][playerPos[0]] == '#')
	{
		return false;
	}
	return true;
}

// *************************************************************************
// setPlayerPos sets the player's starting position on the ASCII map
// Incoming Data: none
// Outgoing Data: none
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Daniel Puckett
// Date: 3/7/2025
// Description: Created the method to update the playerPos array based on
//	the x,y coordinates of the '*' character.
// *************************************************************************
void ActiveMap::setPlayerPos()
{
	for (int y = 0; y < userMap.size(); y++)
	{
		for (int x = 0; x < userMap[y].size(); x++)
		{
			if (userMap[y][x] == '*')
			{
				playerPos[x] = x;
				playerPos[1] = y;
			}
		}
	}
}

// *************************************************************************
// overrideChar sets the Player position on the userMap vector with the 
//	character 'C'
// Incoming Data: none
// Outgoing Data: none
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Daniel Puckett
// Date: 3/7/2025
// Description: Created the method to update the userMap vector with the 
//	Player ASCII character
// *************************************************************************
void ActiveMap::overrideChar()
{
	createUserMap();
	userMap[playerPos[1]][playerPos[0]] = 'C';
}

// *************************************************************************
// checkMoveArea checks to see if the Player's current position is on an
//	exit from the area. It then returns a char that matches the direction
//	of the area to move the Player  to.
// Incoming Data: none
// Outgoing Data: char areaMoveDirection
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Daniel Puckett
// Date: 3/7/2025
// Description: Created the method to handle area movement confirmation
// *************************************************************************
char ActiveMap::checkMoveArea()
{
	if (userMap[playerPos[1]][playerPos[0]] == 'u')
	{
		return 'u';
	}
	else if (userMap[playerPos[1]][playerPos[0]] == 'd')
	{
		return 'd';
	}
	else if (userMap[playerPos[1]][playerPos[0]] == 'l')
	{
		return 'l';
	}
	else if (userMap[playerPos[1]][playerPos[0]] == 'r')
	{
		return 'r';
	}
	else {
		return 'n';
	}
}

// *************************************************************************
// checkValidItem validates that the Item requested is within range for the 
//	user to interact with
// Incoming Data: Item* item
// Outgoing Data: bool
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Daniel Puckett
// Date: 3/9/2025
// Description: Created the method handle Item interaction validation
// *************************************************************************
bool ActiveMap::checkValidItem(Item* item)
{
	char itemChar = item->getItemChar();

	if (textMap[playerPos[1]][playerPos[0]] == itemChar)
	{
		return true;
	}
	else if (userMap[playerPos[1] - 1][playerPos[0]] == itemChar)
	{
		return true;
	}
	else if (userMap[playerPos[1] + 1][playerPos[0]] == itemChar)
	{
		return true;
	}
	else if (userMap[playerPos[1]][playerPos[0] - 1] == itemChar)
	{
		return true;
	}
	else if (userMap[playerPos[1]][playerPos[0] + 1] == itemChar)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

// *************************************************************************
// print outputs the string vector as the ASCII map for the user
// Incoming Data: string line
// Outgoing Data: none
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Daniel Puckett
// Date: 3/7/2025
// Description: Created the method to store the input into the vector
// *************************************************************************
void ActiveMap::print()
{
	for (string line : userMap)
	{
		cout << line << endl;
	}
}