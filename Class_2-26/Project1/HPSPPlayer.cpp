// *************************************************************************
// Name: Daniel Puckett
// Course: CS-355
// Assignment: Project 3
// Date: 2/23/2025
// Description: This is the implementation of the Hit Point Sanity Point 
//	Player class that inherits from the Player class
// *************************************************************************

#ifndef H_HPSPPLAYER
	#define H_HPSPPLAYER
	#include "HPSPPlayer.h"
#endif

// *************************************************************************
// This is the default no parameter constructor for the HPSPPlayer class
// Incoming Data: none
// Outgoing Data: none
// *************************************************************************
HPSPPlayer::HPSPPlayer()
{
	hitPoints = 100;
	sanityPoints = 100;
}

// *************************************************************************
// This is the implementation for the inherited virtual method isGameOver
// Incoming Data: none
// Outgoing Data: none
// *************************************************************************
int HPSPPlayer::isGameOver()
{
	if (hitPoints == 0 || sanityPoints == 0 || getCurrent()->info.getID())
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
void HPSPPlayer::resetPlayerStats()
{
	hitPoints = 100;
	sanityPoints = 100;
	cout << "Stats Reset" << endl;
}

// *************************************************************************
// This is the implmentation for the reportStats inherited virtual method
// Incoming Data: none
// Outgoing Data: none
// *************************************************************************
void HPSPPlayer::reportStats()
{
	cout << "Hit Points: " << hitPoints << endl;
	cout << "Sanity Points: " << sanityPoints << endl;
}

// *************************************************************************
// This is the implmentation for the consume inherited virtual method
// Incoming Data: none
// Outgoing Data: Map* mapptr
// *************************************************************************
void HPSPPlayer::consume(MapV2* mapptr)
{
	nodeType<Item*>* tempNode = items.getFirst();
	Item* item = nullptr;
	string itemName;
	bool found = false;
	
	cout << "What item to consume? " << endl;
	getline(cin, itemName);
	
	if (tempNode == NULL) 
	{
		cout << "There are no items in your inventory. " << endl;
	}
	
	while(!found && tempNode != NULL)
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
	
	cout << item->getActiveArea() << endl;
	
	int itemArea = item->getActiveArea();
	int mapArea = mapptr->reverseLookUp(currentLocation);
	if (item->getActiveArea() != 0 
		&& itemArea != mapArea)
	{
		cout << itemName << " cannot be consumed in this location." << endl; 
		return;
	}
	
	cout << item->getActiveMessage() << endl;
	
	vector<Effect*> effects = item->getItemConsumeEffects();
	
	for (int i = 0; i < effects.size(); i++)
	{
		Effect* effect = effects[i];
		if (effect->effectID == 0)
		{
			hitPoints -= effect->effectAmt;
		}
		else if (effect->effectID == 1)
		{
			hitPoints += effect->effectAmt;
		}
		else if (effect->effectID == 2)
		{
			sanityPoints -= effect->effectAmt;
		}
		else if (effect->effectID == 3)
		{
			sanityPoints += effect->effectAmt;
		}
	}
}

// *************************************************************************
// This is the implmentation for the use inherited virtual method
// Incoming Data: Map* mapptr
// Outgoing Data: none
// *************************************************************************
void HPSPPlayer::use(MapV2* mapptr)
{
	nodeType<Item*>* tempNode = items.getFirst();
	Item* item = nullptr;
	string itemName;
	bool found = false;
	
	cout << "What item to use? " << endl;
	getline(cin, itemName);
	
	if (tempNode == NULL) 
	{
		cout << "There are no items in your inventory. " << endl;
	}
	
	while(!found && tempNode != NULL)
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
	if (item->getType() != "use")
	{
		cout << itemName << " cannot be used." << endl;
		return;
	}
	
	cout << item->getActiveArea() << endl;
	int itemArea = item->getActiveArea();
	int mapArea = mapptr->reverseLookUp(currentLocation);
	if (item->getActiveArea() != 0 
		&& itemArea != mapArea)
	{
		cout << itemName << " cannot be used in this location." << endl; 
		return;
	}
	
	cout << item->getActiveMessage() << endl;
	
	vector<Rule*> rules = item->getItemUseRules();
	
	for (int i = 0; i < rules.size(); i++)
	{
		Rule* rule = rules[i];
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