#include <iostream>
#ifndef H_AREA
	#define H_AREA
	#include "Area.h"
#endif

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
	if (items.isEmptyList()) 
	{
		cout << "No items are in this area." << endl;
		return;
	}
	
	nodeType<Item*>* ptr = items.getFirst();
	while (ptr != NULL)
	{
		ptr->info->displayName();
		ptr = ptr->link;
	}
}