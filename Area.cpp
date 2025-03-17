#include <iostream>
#include "Area.h"


Area::Area()
{
	userMap = new ActiveMap();
}

void Area::setDescription (string desc){
    description = desc;
}
void Area::setGoal(bool g){
    goal = g;
}
void Area::setID(bool id){
    instadeath = id;
}
string Area::getDescription(){
    return description;
}
bool Area::getID(){
    return instadeath;
}
bool Area::getGoal(){
    return goal;
}
void Area::displayArea(){
    cout<<description<<endl;
}

// *************************************************************************
// Iterates through all Items stored in the linked list
//  and displays the result
// Incoming Data: none
// Outgoing Data: none
// *************************************************************************
void Area::search()
{
	if (!items.isEmptyList()) 
	{
		nodeType<Item*>* ptr = items.getFirst();
		while (ptr != NULL)
		{
			ptr->info->displayName();
			cout << "Map Character: " << ptr->info->getItemChar() << endl;
			ptr = ptr->link;
		}
	}
	else
	{
		cout << "No items in this area." << endl;
	}
	if (enemies.size() != 0)
	{
		for (EnemyNPC* enemy : enemies)
		{
			enemy->displayEnemy();
		}
	}
	else
	{
		cout << "No enemies in this area." << endl;

	}
	
}

// *************************************************************************
// Iterates through all EnemyNPCs stored in the permanentList vector
//  and displays the result
// Incoming Data: none
// Outgoing Data: none
// *************************************************************************
void Area::generateEnemies()
{
	for (int i = 0; i < permenantList.size(); i++)
	{
		enemies.push_back(permenantList[i]);
	}
}
