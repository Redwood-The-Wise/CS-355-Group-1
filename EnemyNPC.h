// *************************************************************************
// Group: Group 1
// Course: CS-355-01
// Assignment: Project 4
// Due Date: 3/16/2025
// Description:
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Logan Noles
// Date: 3/13/2025
// Description: Created the class header to give a map of what needs to be
//	implemented. I'm not sure if we need attack() here or if I am missing
// anything else.
// *************************************************************************
// *************************************************************************
// Name: Daniel Puckett
// Date: 3/16/2025
// Description: Added the updated the class to help implement the attack 
//	action
// *************************************************************************

#ifndef H_ENEMYNPC
#define H_ENEMYNPC

#include "structs.h"
#include <iostream>

class EnemyNPC
{
private:
	Stats* stats;
public:
	EnemyNPC();
	Stats* getStats();
	int attack();
	void setStats(Stats* s);
	void isHit(int damage);
	int getHealth();
	void displayEnemy();
};
#endif