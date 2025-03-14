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
#ifndef H_STRUCTS
	#define H_STRUCTS
	#include "structs.h"
#endif

#ifndef COMBATPLAYER_H
	#define COMBATPLAYER_H
	#include "CombatPlayer.h"
#endif // !COMBATPLAYER_H


class EnemyNPC
{
private:
	Stats* stats;
public:
	EnemyNPC();
	Stats* getStats();
	void attack(CombatPlayer* obj);
	void setStats(Stats* s);
};
