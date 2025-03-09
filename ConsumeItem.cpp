// *************************************************************************
// Name: Daniel Puckett
// Course: CS-355
// Assignment: Project 3
// Date: 2/23/2025
// Description: This is the implementation file for the ConsumeItem class 
//	that inherits from the Item class
// *************************************************************************

#ifndef H_CONSUMEITEM
	#define H_CONSUMEITEM
	#include "ConsumeItem.h"
#endif

// *************************************************************************
// The default no parameter constructor for the ConsumeItem class
// Incoming Data: none
// Outgoing Data: none
// *************************************************************************
ConsumeItem::ConsumeItem()
{
	type = "consume";
}

// *************************************************************************
// setActiveMessage overrides the inherited virtual method from the Item 
//	class to properly handle the activeMessage variable
// Incoming Data: string message
// Outgoing Data: none
// *************************************************************************
void ConsumeItem::setActiveMessage(string s)
{
	activeMessage = s;
}

// *************************************************************************
// setActiveArea overrides the inherited virtual method from the Item 
//	class to properly handle the activeArea variable
// Incoming Data: int area
// Outgoing Data: none
// *************************************************************************
void ConsumeItem::setActiveArea(int i)
{
	activeArea = i;
}

// *************************************************************************
// addRule overrides the inherited virtual method from the Item 
//	class to send a debug message since this is only for UseItems
// Incoming Data: Rule* rule
// Outgoing Data: none
// *************************************************************************
void ConsumeItem::addRule(Rule* rule)
{
	cout << "DEBUG INFO: THIS CANNOT BE USED WITH CONSUME ITEMS" << endl;
}

// *************************************************************************
// addEffect overrides the inherited virtual method from the Item 
//	class to properly handle the effects variable
// Incoming Data: string message
// Outgoing Data: none
// *************************************************************************
void ConsumeItem::addEffect(Effect* effect)
{
	effects.push_back(effect);
} 

// *************************************************************************
// getActiveMessage overrides the inherited virtual method from the Item
//	class to properly return the active message.
// Incoming Data: none
// Outgoing Data: string activeMessage
// *************************************************************************
string ConsumeItem::getActiveMessage()
{
	return activeMessage;
}

// *************************************************************************
// getActiveArea overrides the inherited virtual method from the Item
//	class to properly return the active area.
// Incoming Data: none
// Outgoing Data: int activeArea
// *************************************************************************
int ConsumeItem::getActiveArea()
{
	return activeArea;
}
 
// *************************************************************************
// getItemUseRules overrides the inherited virtual method from the Item
//	class to properly return a blank rules pointer vector.
// Incoming Data: none
// Outgoing Data: vector<Rule*> blank
// *************************************************************************
vector<Rule*> ConsumeItem::getItemUseRules()
{
	vector<Rule*> blank;
	return blank;
}

// *************************************************************************
// getItemConsumeRules overrides the inherited virtual method from the Item
//	class to properly return the effects vector.
// Incoming Data: none
// Outgoing Data: vector<Effect*> effects
// *************************************************************************
vector<Effect*> ConsumeItem::getItemConsumeEffects()
{
	return effects;
}