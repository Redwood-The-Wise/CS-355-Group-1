// *************************************************************************
// Name: Daniel Puckett
// Course: CS-355
// Assignment: Project 3
// Date: 2/23/2025
// Description: This is the definition file for the ConsumeItem class that
//	inherits from the Item class
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Daniel Puckett
// Date: 3/16/2025
// Description: Added the addEquipStats, getEquipInfo methods, and changed
//   implementation to allow for limited use items
// *************************************************************************

#ifndef H_CONSUMEITEM
#define H_CONSUMEITEM
#include "structs.h"
#include "Item.h"

class ConsumeItem: public Item
{
	private: 
		vector<Effect*> effects;
		int numUses;
		
	public:
		ConsumeItem();
		void setActiveMessage(string s);
		void setActiveArea(int i);
		void setNumUses(int i);
		int getNumUses();
		void addRule(Rule* rule);
		void addEffect(Effect* effect);
		void addEquipStat(Equip* equip);
		string getActiveMessage();
		int getActiveArea();
		vector<Rule*> getItemUseRules();
		vector<Effect*> getItemConsumeEffects(bool&);
		vector<Equip*> getEquipmentInfo();
		bool consume();
};
#endif