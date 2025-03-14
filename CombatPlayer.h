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

#ifndef H_PLAYER
	#define H_HPSPPLAYER
	#include "HPSPPlayer.h"
#endif
#ifndef H_EQUIPMENT
	#define H_EQUIPMENT
	#include "Equipment.h"
#endif

#ifndef H_ENEMYNPC
	#define H_ENEMYNPC
	#include "EnemyNPC.h"
#endif

#ifndef H_STRUCTS
	#define H_STRUCTS
	#include "structs.h"
#endif

class CombatPlayer : public HPSPPlayer
{
private:
	Stats* stats;
	void initiateCombat(EnemyNPC* enemy);
	vector<Equipment*> equipment;


public:
	CombatPlayer();
	void attack(EnemyNPC* enemy);
	void equip();
};
