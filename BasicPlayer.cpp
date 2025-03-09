// *************************************************************************
// Name: Daniel Puckett
// Course: CS-355
// Assignment: Project 3
// Date: 2/23/2025
// Description: This is the implementation file for the Basic Player class 
//	that inherits from Player.h
// *************************************************************************

#ifndef H_BASICPLAYER
	#define H_BASICPLAYER
	#include "BasicPlayer.h"
#endif

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
	Item* item;
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
	Item* item;
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