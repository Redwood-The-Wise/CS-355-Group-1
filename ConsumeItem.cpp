// *************************************************************************
// Name: Daniel Puckett
// Course: CS-355
// Assignment: Project 3
// Date: 2/23/2025
// Description: This is the implementation file for the ConsumeItem class 
//	that inherits from the Item class
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Daniel Puckett
// Date: 3/16/2025
// Description: Added the getEquipmentInfo method
// *************************************************************************

#include "ConsumeItem.h"


// *************************************************************************
// The default no parameter constructor for the ConsumeItem class
// Incoming Data: none
// Outgoing Data: none
// *************************************************************************
ConsumeItem::ConsumeItem()
{
	type = "consume";
	numUses = 1;
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
// setNumUses sets the number of uses for the item
// Incoming Data: int i
// Outgoing Data: none
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Daniel Puckett
// Date: 3/16/2025
// Description: Added the setNumUses method
// *************************************************************************
void ConsumeItem::setNumUses(int i)
{
	numUses = i;
}

// *************************************************************************
// getNumUses returns the number of uses for the item
// Incoming Data: none
// Outgoing Data: int numUses
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Daniel Puckett
// Date: 3/16/2025
// Description: Added the getNumUses method
// *************************************************************************
int ConsumeItem::getNumUses()
{
	return numUses;
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

// *************************************************************************
// getEquipmentInfo overrides the inherited virtual method from the Item
//	class to properly return a blank Equip vector.
// Incoming Data: none
// Outgoing Data: vector<Equip*> blank
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Daniel Puckett
// Date: 3/16/2025
// Description: Added the getEquipmentInfo method
// *************************************************************************
vector<Equip*> ConsumeItem::getEquipmentInfo() {
	vector<Equip*> blank;
	return blank;
}

// *************************************************************************
// addEquipStat overrides the inherited virtual method from the Item
//	class to send a debug message since this is only for EquipItems
// Incoming Data: Equip* equip
// Outgoing Data: none
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Daniel Puckett
// Date: 3/16/2025
// Description: Added the addEquipStat method
// *************************************************************************
void ConsumeItem::addEquipStat(Equip* temp) {
	cout << "DEBUG WARNING: Objects of the Item (consume items) class don't have equipment stats." << endl;
}

bool ConsumeItem::consume()
{
	if (numUses == -1)
	{
		return false;
	}
	if (numUses > 0)
	{
		numUses--;
		return false;
	}
	else
	{
		return true;
	}
}