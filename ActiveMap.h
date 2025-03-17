// *************************************************************************
// Group: Group 1
// Course: CS-355-01
// Assignment: Project 4
// Due Date: 3/16/2025
// Description: ActiveMap is a class designed to track and display ASCII
//	maps of each area to provide a display for the user
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Daniel Puckett
// Date: 3/7/2025
// Description: Created the class with the ability to display the map and
//	track player positioning
// *************************************************************************
// *************************************************************************
// Name: Daniel Puckett
// Date: 3/9/2025
// Description: Updated teh class to properly handle player interaction with
//	objects
// *************************************************************************

#ifndef ACTIVEMAP_H
#define ACTIVEMAP_H

#include "Item.h"


#include <vector>
#include <iostream>
using namespace std;

class ActiveMap
{
private:
	vector<string> textMap;
	vector<string> objectMap;
	vector<string> userMap;
	int playerPos[2];
	bool checkValidMove();
	void overrideChar();

public:
	ActiveMap();
	void addRow(string);
	void createUserMap();
	void updatePlayerPos(char);
	char checkMoveArea();
	void setPlayerPos();
	bool checkValidItem(Item*);
	bool checkVailidEnemy(char);
	void createObjectMap();
	void deleteItem(char);
	void deleteEnemy(char);
	void dropItem(char);
	void print();
};
#endif