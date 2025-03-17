// *************************************************************************
// Name: Daniel Puckett
// Course: CS-355
// Assignment: Project 3
// Date: 2/23/2025
// Description: This is the definition file for the UseItem class that
//	inherits from the Item class
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Daniel Puckett
// Date: 3/16/2025
// Description: Added the addEquipStats and getEquipInfo methods
// *************************************************************************

#ifndef H_USEITEM
#define H_USEITEM

#include "Item.h"

class UseItem: public Item
{
	private: 
		vector<Rule*> rules;
		
	public:
		UseItem();
		void setActiveMessage(string s);
		void setActiveArea(int i);
		void addRule(Rule* rule);
		void addEffect(Effect* effect);
		void addEquipStat(Equip* equip);
		string getActiveMessage();
		int getActiveArea();
		vector<Rule*> getItemUseRules();
		vector<Effect*> getItemConsumeEffects();
		vector<Equip*> getEquipmentInfo();
};

#endif