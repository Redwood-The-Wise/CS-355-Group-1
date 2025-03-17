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
	if (userMap.size() != 0)
	{
		userMap.clear();
	}
	for (int i = 0; i < objectMap.size(); i++)
	{
		userMap.push_back(objectMap[i]);
	}
}

// *************************************************************************
// createObjectMap creates a deep copy of the original textMap vector to
//	handle Item and Enemy interaction
// Incoming Data: none
// Outgoing Data: none
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Daniel Puckett
// Date: 3/15/2025
// Description: Created the method to create the deep copy
// *************************************************************************
void ActiveMap::createObjectMap()
{
	for (int i = 0; i < textMap.size(); i++)
	{
		objectMap.push_back(textMap[i]);
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
	createUserMap();
	if (dir == 'u')
	{
		playerPos[1] -= 1;
		cout << playerPos[1] << endl;
	}
	else if (dir == 'd')
	{
		playerPos[1] += 1;
		cout << playerPos[1] << endl;
	}
	else if (dir == 'l')
	{
		playerPos[0] -= 1;
		cout << playerPos[1] << endl;
	}
	else if (dir == 'r')
	{
		playerPos[0] += 1;
		cout << playerPos[1] << endl;
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
	if (objectMap[playerPos[1]][playerPos[0]] != '*' &&
		objectMap[playerPos[1]][playerPos[0]] != '.' &&
		objectMap[playerPos[1]][playerPos[0]] != 'U' &&
		objectMap[playerPos[1]][playerPos[0]] != 'D' &&
		objectMap[playerPos[1]][playerPos[0]] != 'L' &&
		objectMap[playerPos[1]][playerPos[0]] != 'R')
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
	createUserMap();
	for (int y = 0; y < userMap.size(); y++)
	{
		for (int x = 0; x < userMap[y].size(); x++)
		{
			if (userMap[y][x] == '*')
			{
				playerPos[0] = x;
				playerPos[1] = y;
			}
		}
	}

	userMap[playerPos[1]][playerPos[0]] = 'C';
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
	if (objectMap[playerPos[1]][playerPos[0]] == 'U')
	{
		return 'u';
	}
	else if (objectMap[playerPos[1]][playerPos[0]] == 'D')
	{
		return 'd';
	}
	else if (objectMap[playerPos[1]][playerPos[0]] == 'L')
	{
		return 'l';
	}
	else if (objectMap[playerPos[1]][playerPos[0]] == 'R')
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
// checkVailidEnemy checks to see if the Player is on an Enemy character
// Incoming Data: char enemyChar
// Outgoing Data: bool
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Daniel Puckett
// Date: 3/15/2025
// Description: Created the method to handle Enemy interaction validation
// *************************************************************************
bool ActiveMap::checkVailidEnemy(char enemyChar)
{
	if (userMap[playerPos[1]][playerPos[0]] == enemyChar)
	{
		return true;
	}
	else if (userMap[playerPos[1] - 1][playerPos[0]] == enemyChar)
	{
		return true;
	}
	else if (userMap[playerPos[1] + 1][playerPos[0]] == enemyChar)
	{
		return true;
	}
	else if (userMap[playerPos[1]][playerPos[0] - 1] == enemyChar)
	{
		return true;
	}
	else if (userMap[playerPos[1]][playerPos[0] + 1] == enemyChar)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// *************************************************************************
// deleteItem removes the Item from the ASCII map
// Incoming Data: char itemChar
// Outgoing Data: none
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Daniel Puckett
// Date: 3/15/2025
// Description: Created the method to handle Item deletion
// *************************************************************************
void ActiveMap::deleteEnemy(char enemyChar)
{
	for (int i = 0; i < objectMap.size(); i++)
	{
		for (int j = 0; j < objectMap[i].size(); j++)
		{
			if (objectMap[i][j] == enemyChar)
			{
				objectMap[i][j] = '.';
			}
		}
	}
}

// *************************************************************************
// deleteItem removes the Item from the ASCII map
// Incoming Data: char itemChar
// Outgoing Data: none
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Daniel Puckett
// Date: 3/15/2025
// Description: Created the method to handle Item deletion
// *************************************************************************
void ActiveMap::deleteItem(char itemChar)
{
	if (objectMap[playerPos[1]][playerPos[0]] == itemChar)
	{
		objectMap[playerPos[1]][playerPos[0]] = '.';
	}
	else if (objectMap[playerPos[1] - 1][playerPos[0]] == itemChar)
	{
		objectMap[playerPos[1] - 1][playerPos[0]] = '.';
	}
	else if (objectMap[playerPos[1] + 1][playerPos[0]] == itemChar)
	{
		objectMap[playerPos[1] + 1][playerPos[0]] = '.';
	}
	else if (objectMap[playerPos[1]][playerPos[0] - 1] == itemChar)
	{
		objectMap[playerPos[1]][playerPos[0] - 1] = '.';
	}
	else if (objectMap[playerPos[1]][playerPos[0] + 1] == itemChar)
	{
		objectMap[playerPos[1]][playerPos[0] + 1] = '.';
	}
}

// *************************************************************************
// dropItem places the Item on the ASCII map
// Incoming Data: char itemChar
// Outgoing Data: void
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Daniel Puckett
// Date: 3/15/2025
// Description: Created the method to handle Item placement
// *************************************************************************
void ActiveMap::dropItem(char itemChar)
{
	objectMap[playerPos[1]][playerPos[0]] = itemChar;
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
	for (int i = 0; i < userMap.size(); i++)
	{
		cout << userMap[i] << endl;
	}
}