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
// *************************************************************************
// Name: Daniel Puckett
// Date: 3/16/2025
// Description: Updated the attack and equip methods to utilize ActiveMap
// *************************************************************************


#include "CombatPlayer.h"


CombatPlayer::CombatPlayer()
{
	stats = new Stats;
	hitPoints = 100;
	stats->damage = 10;
	stats->defense = 0;
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
void CombatPlayer::attack()
{
	vector<EnemyNPC*> enemies = currentLocation->info.enemies;
	EnemyNPC* enemy = nullptr;
	string enemyName;
	bool found = false;

	cout << "What enemy to attack? " << endl;
	getline(cin, enemyName);

	for (int i = 0; i < enemies.size(); i++)
	{
		if (enemies[i]->getStats()->name == enemyName)
		{
			enemy = enemies[i];
			found = true;
		}
	}

	if (!found)
	{
		cout << "No enemy with that name in this location." << endl;
		return;
	}

	if (!currentLocation->info.userMap->checkVailidEnemy(enemy->getStats()->mapChar))
	{
		cout << "Enemy is not near you." << endl;
		return;
	}
	enemy->isHit(stats->damage);
	cout << "You hit " << enemyName << " for " << stats->damage << " damage." << endl;
	isHit(enemy->attack());
	cout << enemyName << " hit you for " << enemy->attack() << " damage." << endl;
	if (enemy->getStats()->health <= 0)
	{
		cout << enemyName << " has been defeated." << endl;
		currentLocation->info.userMap->deleteEnemy(enemy->getStats()->mapChar);
		currentLocation->info.enemies.erase(remove(currentLocation->info.enemies.begin(), currentLocation->info.enemies.end(), enemy), currentLocation->info.enemies.end());
	}
}

// *************************************************************************
// equip is a public method method to handle equiping items.
// Incoming Data: MapV2* map
// Outgoing Data: None
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Daniel Puckett
// Date: 3/16/2025
// Description: Created the equip method
// *************************************************************************
void CombatPlayer::equip(MapV2* mapptr)
{
	nodeType<Item*>* tempNode = items.getFirst();
	Item* item = nullptr;
	string itemName;
	bool found = false;

	cout << "What item to equip? " << endl;
	getline(cin, itemName);

	if (tempNode == NULL)
	{
		cout << "There are no items in your inventory. " << endl;
	}

	while (!found && tempNode != NULL)
	{
		if (tempNode->info->getName() == itemName)
		{
			item = tempNode->info;
			found = true;
		}
		tempNode = tempNode->link;
	}

	if (!found)
	{
		cout << "No Item with that name in your inventory." << endl;
		return;
	}

	if (item->getType() != "Equipment")
	{
		cout << itemName << " cannot be equipped." << endl;
		return;
	}

	cout << item->getActiveArea() << endl;

	int itemArea = item->getActiveArea();
	int mapArea = mapptr->reverseLookUp(currentLocation);
	if (item->getActiveArea() != 0
		&& itemArea != mapArea)
	{
		return;
	}

	cout << item->getActiveMessage() << endl;

	vector<Equip*> equip = item->getEquipmentInfo();

	for (int i = 0; i < equip.size(); i++)
	{
		Equip* stat = equip[i];
		cout << "Rule: " << stat->rule << " Effect: " << stat->effect << endl;
		if (stat->rule == 0)
		{
			stats->defense += stat->effect;
		}
		else if (stat->rule == 1)
		{
			stats->damage += stat->effect;
		}
	}
}

// *************************************************************************
// unequip is a public method method to handle unequiping items.
// Incoming Data: None
// Outgoing Data: None
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Daniel Puckett
// Date: 3/16/2025
// Description: Created the unequip method
// *************************************************************************
void CombatPlayer::unequip()
{
	Equipment* item = nullptr;
	string itemName;
	bool found = false;

	cout << "What item to unequip? " << endl;
	getline(cin, itemName);

	for (int i = 0; i < equipment.size(); i++)
	{
		if (equipment[i]->getName() == itemName)
		{
			item = equipment[i];
			found = true;
		}
	}

	if (!found)
	{
		cout << "No Item with that name in your inventory." << endl;
		return;
	}
	else
	{
		vector<Equip*> equip = item->getEquipmentInfo();
		for (int i = 0; i < equip.size(); i++)
		{
			Equip* stat = equip[i];
			if (stat->rule == 0)
			{
				stats->defense -= stat->effect;
			}
			else if (stat->rule == 1)
			{
				stats->damage -= stat->effect;
			}
		}
		equipment.erase(remove(equipment.begin(), equipment.end(), item), equipment.end());
		items.insertLast(item);
		cout << itemName << " unequipped." << endl;
	}
}

// *************************************************************************
// Method to check if the player is hit by the enemy.
// Incoming Data: int damage
// Outgoing Data: none
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Daniel Puckett
// Date: 3/16/2025
// Description: Created the isHit method
// *************************************************************************
void CombatPlayer::isHit(int damage)
{
	int netDamage = damage - stats->defense;
	if (netDamage < 0)
	{
		netDamage = 0;
	}
	hitPoints -= netDamage;
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
// Description: Created the method to set user stats.
// *************************************************************************
void CombatPlayer::setStats(Stats* s)
{
	stats->health = s->health;
	stats->damage = s->damage;
	stats->mapChar = s->mapChar;
	stats->desc = s->desc;
	stats->name = s->name;
	stats->defense = s->defense;
}

// *************************************************************************
// Method to set the stats of the Combat player from our file.
// Incoming Data: none
// Outgoing Data: none
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Logan Noles
// Date: 3/14/2025
// Description: Created the method to set user stats.
// *************************************************************************
Stats* CombatPlayer::getStats()
{
    return stats;
}

// *************************************************************************
// Method to set the stats of the Combat player from our file.
// Incoming Data: none
// Outgoing Data: none
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Logan Noles
// Date: 3/14/2025
// Description: Created the method to set user stats.
// *************************************************************************
void CombatPlayer::reportStats()
{
    cout << "Player stats:\n"
         << "\tHit Points: " << hitPoints
         <<  "\n\tDamage: " << stats->damage
         << "\n\tDefense: " << stats->defense << endl;
}

// *************************************************************************
// Method to reset the player stats.
// Incoming Data: none
// Outgoing Data: none
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Daniel Puckett
// Date: 3/16/2025
// Description: Created the resetPlayerStats method
void CombatPlayer::resetPlayerStats()
{
	HPSPPlayer:resetPlayerStats();
	stats->damage = 10;
	stats->defense = 0;
}