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
// Description: Implemented part of the EnemyNPC class.
// I'm not sure if we need attack() here or if I am missing something.
// *************************************************************************
#ifndef H_ENEMYNPC
#define H_ENEMYNPC
	#include "EnemyNPC.h"
#endif


// *************************************************************************
// Default contructor for EnemyNPC
// Incoming Data: none
// Outgoing Data: none
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Logan Noles
// Date: 3/13/2025
// Description: Created the constructor but am not sure if it needs to be used.
// *************************************************************************
EnemyNPC::EnemyNPC(){}

// *************************************************************************
// Method returns the stats of the enemy
// Incoming Data: none
// Outgoing Data: stats
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Logan Noles
// Date: 3/13/2025
// Description: Created the method to return the stats of the enemy.
// *************************************************************************
EnemyStats* EnemyNPC::getStats()
{
	return stats;
}

// *************************************************************************
// Method which allows enemy NPCs to attack the player.
// Incoming Data: none
// Outgoing Data: none
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Logan Noles
// Date: 3/13/2025
// Description: Created the method outline and added the ability to deal damage to the player.
// *************************************************************************
void EnemyNPC::defend(CombatPlayer* obj)
{
	//for balance reasons, the enemy deals damage equal to its damage minus the player's defense.
	obj->getPoints()[0] -= stats->damage - stats->defense;
}

// *************************************************************************
// Method to set the stats of the enemy from our file.
// Incoming Data: none
// Outgoing Data: none
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Logan Noles
// Date: 3/11/2025
// Description: Created the method to set enemy stats.
// *************************************************************************
void EnemyNPC::setStats(Stats* s)
{
	stats->health = s->health;
	stats->damage = s->damage;
	stats->mapChar = s->mapChar;
	stats->desc = s->desc;
	stats->name = s->name;
	stats->defense = s->defense;
}
