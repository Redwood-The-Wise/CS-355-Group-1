// *************************************************************************
// Name: Daniel Puckett
// Course: CS-355
// Assignment: Project 3
// Date: 2/23/2025
// Description: This is the implementation file for the Basic Player class 
//	that inherits from Player.h
// *************************************************************************


#include "BasicPlayer.h"


// *************************************************************************
// This is the default no parameter constructor for the BasicPlayer Class
// Incoming Data: none
// Outgoing Data: none
// *************************************************************************
BasicPlayer::BasicPlayer()
{
	// Calls the inherited Player() constructor. No new values to initialize
}

// *************************************************************************
// This is the implemented isGameOver virtual method inherited from Player.h
// Incoming Data: none
// Outgoing Data: int gameOverStatus
// *************************************************************************
int BasicPlayer::isGameOver()
{
	if (getCurrent()->info.getID()) 
    {
		return 2;
    }
    if (getCurrent()->info.getGoal())
    {
		return 1;
    }
    return 0;
}

// *************************************************************************
// This is the implmentation for the resetPlayerStats inherited method
// Incoming Data: none
// Outgoing Data: none
// *************************************************************************
void BasicPlayer::resetPlayerStats()
{
	cout << "There are no stats to reset" << endl;
}

// *************************************************************************
// This is the implmentation for the reportStats inherited virtual method
// Incoming Data: none
// Outgoing Data: none
// *************************************************************************
void BasicPlayer::reportStats()
{
	cout << "There are no stats to report" << endl;
}

// *************************************************************************
// This is the implmentation for the consume inherited virtual method
// Incoming Data: none
// Outgoing Data: Map* mapptr
// *************************************************************************
void BasicPlayer::consume(MapV2* mapptr)
{
	nodeType<Item*>* tempNode = items.getFirst();
	Item* item = nullptr;
	string itemName;
	bool found = false;
	
	cout << "What item to consume? " << endl;
	cin >> itemName;
	
	if (tempNode == NULL) 
	{
		cout << "There are no items in your inventory. " << endl;
	}
	
	while(!found || tempNode != NULL)
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
	
	if (item->getType() != "consume")
	{
		cout << itemName << " cannot be consumed." << endl;
		return;
	}
	
	if (item->getActiveArea() != 0 
		|| item->getActiveArea() != mapptr->reverseLookUp(currentLocation))
	{
		cout << itemName << " cannot be consumed in this location." 
			<< endl; 
		return;
	}
	
	cout << item->getActiveMessage() << endl;
}

// *************************************************************************
// This is the implmentation for the use inherited virtual method
// Incoming Data: Map* mapptr
// Outgoing Data: none
// *************************************************************************
void BasicPlayer::use(MapV2* mapptr)
{
	nodeType<Item*>* tempNode = items.getFirst();
	Item* item = nullptr;
	string itemName;
	bool found = false;
	
	cout << "What item to use? " << endl;
	cin >> itemName;
	
	if (tempNode == NULL) 
	{
		cout << "There are no items in your inventory. " << endl;
	}
	
	while(!found || tempNode != NULL)
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
	
	if (item->getType() != "use")
	{
		cout << itemName << " cannot be used." << endl;
		return;
	}
	
	if (item->getActiveArea() != 0 
		|| item->getActiveArea() != mapptr->reverseLookUp(currentLocation))
	{
		cout << itemName << " cannot be used in this location." << endl; 
		return;
	}
	
	cout << item->getActiveMessage() << endl;
	
	vector<Rule*> rules = item->getItemUseRules();
	
	for (int i = 0; i < rules.size(); i++)
	{
		Rule* rule = rules[i];
		cout << rule->beginRm << endl;
		if (rule->direction == 'u')
		{
			mapptr->updateLinks(rule->beginRm, rule->destRm, 'u');
		}
		else if (rule->direction == 'd')
		{
			mapptr->updateLinks(rule->beginRm, rule->destRm, 'd');
		}
		else if (rule->direction == 'l')
		{
			mapptr->updateLinks(rule->beginRm, rule->destRm, 'l');
		}
		else if (rule->direction == 'r')
		{
			mapptr->updateLinks(rule->beginRm, rule->destRm, 'r');
		}
	}
}

// *************************************************************************
// This is the implmentation for the equip inherited virtual method
// Incoming Data: Map* mapptr
// Outgoing Data: none
// *************************************************************************
// *************************************************************************
// Editing Log
// *************************************************************************
// *************************************************************************
// Name: Daniel Puckett
// Date: 3/16/2025
// Edited Description: Created the method to handle equipping
// *************************************************************************
void BasicPlayer::equip(MapV2* mapptr)
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

	cout << item->getType() << endl;
	if (item->getType() != "equip")
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
		cout << itemName << " cannot be equipped in this location." << endl;
		return;
	}

	cout << item->getActiveMessage() << endl;
}

// *************************************************************************
// This is the implmentation for the unequip inherited virtual method
// Incoming Data: none
// Outgoing Data: none
// *************************************************************************
// *************************************************************************
// Editing Log
// *************************************************************************
// *************************************************************************
// Name: Daniel Puckett
// Date: 3/16/2025
// Edited Description: Created the method to handle unequipping
// *************************************************************************
void BasicPlayer::unequip()
{
	string itemName;
	cout << "What item to unequip? " << endl;
	getline(cin, itemName);

	nodeType<Item*>* tempNode = items.getFirst();
	Item* item = nullptr;
	bool found = false;
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

	cout << itemName << " has been unequipped." << endl;
}

// *************************************************************************
// This is the implmentation for the attack inherited virtual method
// Incoming Data: none
// Outgoing Data: none
// *************************************************************************
// *************************************************************************
// Editing Log
// *************************************************************************
// *************************************************************************
// Name: Daniel Puckett
// Date: 3/16/2025
// Edited Description: Created the method to handle attacking
// *************************************************************************
void BasicPlayer::attack()
{
	vector<EnemyNPC*> enemies = getCurrent()->info.enemies;
	if (enemies.size() == 0)
	{
		cout << "No enemies in this room." << endl;
		return;
	}
	string enemyName;
	cout << "Which enemy to attack? " << endl;
	getline(cin, enemyName);
	bool found = false;
	EnemyNPC* enemy = nullptr;
	Stats* stats = new Stats;
	for (int i = 0; i < enemies.size(); i++)
	{
		stats = enemies[i]->getStats();
		if (stats->name == enemyName)
		{
			enemy = enemies[i];
			found = true;
			break;
		}
	}

	if (!found)
	{
		cout << "No enemy with that name in this room." << endl;
		return;
	}

	if (currentLocation->info.userMap->checkVailidEnemy(stats->mapChar))
	{
		currentLocation->info.userMap->deleteEnemy(stats->mapChar);
		currentLocation->info.enemies.erase(remove(currentLocation->info.enemies.begin(), currentLocation->info.enemies.end(), enemy), currentLocation->info.enemies.end());
		cout << "You have defeated " << enemyName << endl;
	}
}

// *************************************************************************
// isHit is the implementation for isHit inherited virtual method
// Incoming Data: none
// Outgoing Data: none
// *************************************************************************
// *************************************************************************
// Editing Log
// *************************************************************************
// *************************************************************************
// Name: Daniel Puckett
// Date: 3/16/2025
// Edited Description: Created the method to handle isHit
// *************************************************************************
void BasicPlayer::isHit(int damage)
{
	// No implementation needed for BasicPlayer
}