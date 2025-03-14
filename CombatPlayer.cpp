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
// Description: Created CombatPlayer.cpp
// *************************************************************************

#ifndef COMBATPLAYER_H
	#define COMBATPLAYER_H
	#include "CombatPlayer.h"
#endif // !COMBATPLAYER_H

CombatPlayer::CombatPlayer()
{
	
}
// *************************************************************************
// attack is a public method method to deal with the attacks.
//
// Incoming Data: EnemyNPC* enemy
// Outgoing Data: None
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Logan Noles
// Date: 3/13/2025
// Description: Created attack and added the check for the enemy being near.
// *************************************************************************
void CombatPlayer::attack(EnemyNPC* enemy)
{
	if (true) //we need a method to check if the enemy is near.
	{
		initiateCombat(enemy);
	}
	else
	{
		cout << "You swing wildly at the air." << endl;
	}
}
void CombatPlayer::equip()
{

}
// *************************************************************************
// initiateCombat is a private helper method to deal with the math for the combat.
//
// Incoming Data: EnemyNPC* enemy
// Outgoing Data: None
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Logan Noles
// Date: 3/13/2025
// Description: Created initiateCombat.
// *************************************************************************
void CombatPlayer::initiateCombat(EnemyNPC* enemy)
{
	//for balance reasons, we check if our armor is greater than our damage.
	//if it is, we deal 1 damage to the enemy, else we deal the difference between our damage and armor.
	if (armor > damage)
	{
		enemy->getStats()->health -= 1;
	}
	else
	{
		enemy->getStats()->health -= damage - armor;
	}
}
