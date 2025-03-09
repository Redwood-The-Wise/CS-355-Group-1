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

#ifndef H_PLAYER
	#define H_HPSPPLAYER
	#include "HPSPPlayer.h"
#endif
#ifndef H_EQUIPMENT
	#define H_EQUIPMENT
	#include "Equipment.h"
#endif

class CombatPlayer : public HPSPPlayer
{
private:
	int armor;
	int damage;
	vector<Equipment*> equipment;


public:
	CombatPlayer();
	void attack();
	void equip();
};