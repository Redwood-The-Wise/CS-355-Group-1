// *************************************************************************
// Name: Daniel Puckett
// Course: CS-355
// Assignment: Project 3
// Date: 2/23/2025
// Description: This is the definition file for the ConsumeItem class that
//	inherits from the Item class
// *************************************************************************

#ifndef H_ITEM
	#define H_ITEM
	#include "Item.h"
#endif

class ConsumeItem: public Item
{
	private: 
		vector<Effect*> effects;
		
	public:
		ConsumeItem();
		void setActiveMessage(string s);
		void setActiveArea(int i);
		void addRule(Rule* rule);
		void addEffect(Effect* effect);
		string getActiveMessage();
		int getActiveArea();
		vector<Rule*> getItemUseRules();
		vector<Effect*> getItemConsumeEffects();
};