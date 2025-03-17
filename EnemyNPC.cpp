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
// *************************************************************************
// Name: Daniel Puckett
// Date: 3/16/2025
// Description: Added the updated the class to help implement the attack
// action
// *************************************************************************

#include "EnemyNPC.h"



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
Stats* EnemyNPC::getStats()
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
int EnemyNPC::attack()
{
	return stats->damage;
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
// Date: 3/14/2025
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

// *************************************************************************
// isHit method to handle the damage dealt to the enemy
// Incoming Data: int representing the damage dealt
// Outgoing Data: none
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Daniel Puckett
// Date: 3/16/2025
// Description: Created the method to handle the damage dealt to the enemy
// *************************************************************************
void EnemyNPC::isHit(int damage)
{
	int netDamage = damage - stats->defense;
	if (netDamage < 0)
	{
		netDamage = 0;
	}
	stats->health -= netDamage;
}

// *************************************************************************
// Method to get the health of the enemy
// Incoming Data: none
// Outgoing Data: int representing the health of the enemy
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Daniel Puckett
// Date: 3/16/2025
// Description: Created the method to get the health of the enemy
// *************************************************************************
int EnemyNPC::getHealth()
{
	return stats->health;
}

