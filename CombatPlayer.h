// *************************************************************************
// Group: Group 1
// Assignment: Project 4
// Date: 3/16/2025
// Description: CombatPlayer extends HPSPPlayer to add combat mechanics
// *************************************************************************

// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Daniel Puckett
// Date Edited: 3/7/2025
// Edited Notes: Created the CombatPlayer.h file ready for implementation
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Logan Noles
// Date Edited: 3/14/2025
// Edited Notes: changed attack to accept a pointer to an EnemyNPC
// *************************************************************************
// *************************************************************************
// Name: Daniel Puckett
// Date Edited: 3/16/2025
// Edited Notes: Updated the attack method to utilize ActiveMap
// *************************************************************************
#ifndef COMBATPLAYER_H
#define COMBATPLAYER_H

#include "HPSPPlayer.h"
#include "Equipment.h"
#include "EnemyNPC.h"
#include "structs.h"

class CombatPlayer : public HPSPPlayer
{
private:
	Stats* stats;
	vector<Equipment*> equipment;


public:
	CombatPlayer();
	void attack();
	void equip(MapV2*);
	void unequip();
	void isHit(int);
	void setStats(Stats*);
	Stats* getStats();
	void reportStats();
	void resetPlayerStats();
};
#endif