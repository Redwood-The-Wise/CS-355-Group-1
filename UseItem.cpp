// *************************************************************************
// Name: Daniel Puckett
// Course: CS-355
// Assignment: Project 3
// Date: 2/23/2025
// Description: This is the implementation file for the UseItem class 
//	that inherits from the Item class
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Daniel Puckett
// Date: 3/16/2025
// Description: Added the addEquipStats and getEquipInfo methods
// *************************************************************************


#include "UseItem.h"

// *************************************************************************
// The default no parameter constructor for the UseItem class
// Incoming Data: none
// Outgoing Data: none
// *************************************************************************
UseItem::UseItem()
{
	type = "use";
}

// *************************************************************************
// setActiveMessage overrides the inherited virtual method from the Item 
//	class to properly handle the activeMessage variable
// Incoming Data: string message
// Outgoing Data: none
// *************************************************************************
void UseItem::setActiveMessage(string s)
{
	activeMessage = s;
}

// *************************************************************************
// setActiveArea overrides the inherited virtual method from the Item 
//	class to properly handle the activeArea variable
// Incoming Data: int area
// Outgoing Data: none
// *************************************************************************
void UseItem::setActiveArea(int i)
{
	activeArea = i;
}

// *************************************************************************
// addRule overrides the inherited virtual method from the Item 
//	class to send a debug message since this is only for UseItems
// Incoming Data: Rule* rule
// Outgoing Data: none
// *************************************************************************
void UseItem::addRule(Rule* rule)
{
	rules.push_back(rule);
}

// *************************************************************************
// addEffect overrides the inherited virtual method from the Item 
//	class to properly handle the effects variable
// Incoming Data: string message
// Outgoing Data: none
// *************************************************************************
void UseItem::addEffect(Effect* effect)
{
	cout << "DEBUG INFO: THIS CANNOT BE USED WITH USE ITEMS" << endl;
} 

// *************************************************************************
// getActiveMessage overrides the inherited virtual method from the Item
//	class to properly return the active message.
// Incoming Data: none
// Outgoing Data: string activeMessage
// *************************************************************************
string UseItem::getActiveMessage()
{
	return activeMessage;
}

// *************************************************************************
// getActiveArea overrides the inherited virtual method from the Item
//	class to properly return the active area.
// Incoming Data: none
// Outgoing Data: int activeArea
// *************************************************************************
int UseItem::getActiveArea()
{
	return activeArea;
}
 
// *************************************************************************
// getItemUseRules overrides the inherited virtual method from the Item
//	class to properly return the effects vector.
// Incoming Data: none
// Outgoing Data: vector<Rule*> rules
// *************************************************************************
vector<Rule*> UseItem::getItemUseRules()
{
	return rules;
}

// *************************************************************************
// getItemConsumeRules overrides the inherited virtual method from the Item
//	class to properly return a blank Effect vector.
// Incoming Data: none
// Outgoing Data: vector<Effect*> blank
// *************************************************************************
vector<Effect*> UseItem::getItemConsumeEffects()
{
	vector<Effect*> blank;
	return blank;
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
vector<Equip*> UseItem::getEquipmentInfo() {
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
void UseItem::addEquipStat(Equip* temp) {
	cout << "DEBUG WARNING: Objects of the Item (use items) class don't have equipment stats." << endl;
}