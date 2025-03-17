// *************************************************************************
// Name: Connor Reed
// Course: CS-355
// Assignment: Project 3
// Date: 2/23/2025
// Description: This is the implementation file for the Equipment class
//	that inherits from the Item class
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Daniel Puckett
// Date: 3/15/2025
// Description: Updated all methods to ensure proper execution and to
//  maintain code integrity
// *************************************************************************


#include "Equipment.h"

// *************************************************************************
// Default constructor for Equipment
// Incoming Data: none
// Outgoing Data: none
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Connor Reed
// Date: 3/10/2025
// Description: Created the constructor to initialize hp and sp bonuses
// coordinates
// *************************************************************************
Equipment::Equipment()
{
	type = "Equipment";

}

// *************************************************************************
// Displays information about the equipment
// Incoming Data: none
// Outgoing Data: none
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Connor Reed
// Date: 3/10/2025
// Description: Created the Display information method
// coordinates
// *************************************************************************
// *************************************************************************
// Name: Daniel Puckett
// Date: 3/16/2025
// Description: Updated the display information method to include the stats
// *************************************************************************
void Equipment::displayEquipmentInfo()
{
	for (Equip* stat : stats)
	{
        displayName();
        displayDesc();
        for (Equip* stat : stats)
        {
            if (stat->rule == 0)
            {
                cout << "Armor Bonus: " << stat->effect << endl;
            }
            else if (stat->rule == 1)
            {
                cout << "Damage Bonus: " << stat->effect << endl;
            }
            else
            {
                cout << "No bonus" << endl;
            }
        }
	}
    
}

// *************************************************************************
// Override: Sets active message for the equipment
// Incoming Data: string representing the active message
// Outgoing Data: none
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Connor Reed
// Date: 3/10/2025
// Description: Created the setter for the active message method
// coordinates
// *************************************************************************
void Equipment::setActiveMessage(string s)
{
	activeMessage = s;
}

// *************************************************************************
// Returns a default message for activeMessage
// Incoming Data: none
// Outgoing Data: string representing the active message of the equipment
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Connor Reed
// Date: 3/10/2025
// Description: Created the setter for the active message override
// *************************************************************************
string Equipment::getActiveMessage()
{
    return activeMessage;
}

// *************************************************************************
// Active area setter override for equipment
// Incoming Data: int representing the active area
// Outgoing Data: none
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Connor Reed
// Date: 3/10/2025
// Description: Created the setter for the equipment active message
// *************************************************************************
void Equipment::setActiveArea(int i)
{
	activeArea = i;
}

// *************************************************************************
// Getter for the equipment active area
// Incoming Data: none
// Outgoing Data: integer representing the active area of the equipment
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Connor Reed
// Date: 3/10/2025
// Description: Created the getter for the active area
// coordinates
// *************************************************************************
int Equipment::getActiveArea()
{
    return activeArea; // Indicate no active area
}

// *************************************************************************
// Rule setter for the Equipment
// Incoming Data: temporary Rule pointer representing the rules associated
//  with the equipment
// Outgoing Data: none
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Connor Reed
// Date: 3/10/2025
// Description: Created the add rule override method for Equipment
// *************************************************************************
void Equipment::addRule(Rule* temp)
{
    cout << "DEBUG: Equipment doesn't have associated rules." << endl;
}

// *************************************************************************
// Rule getter for the Equipment
// Incoming Data: none
// Outgoing Data: vector array of Rule pointers associated with the equipment
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Connor Reed
// Date: 3/10/2025
// Description: Created the get rule override method for Equipment
// *************************************************************************
vector<Rule*> Equipment::getItemUseRules()
{
    cout << "DEBUG: Equipment doesn't have associated use rules." << endl;
    return vector<Rule*>(); // Return empty
}

// *************************************************************************
// Effect setter for the Equipment
// Incoming Data: temporary Effect pointer representing the effects 
//  associated with the equipment
// Outgoing Data: none
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Connor Reed
// Date: 3/10/2025
// Description: Created the set Effect override method for Equipment
// *************************************************************************
void Equipment::addEffect(Effect* temp)
{
    cout << "DEBUG: Equipment doesn't have associated effects." << endl;
}

// *************************************************************************
// Effect getter for the Equipment
// Incoming Data: none
// Outgoing Data: vector array of Effect pointers associated with the equipment
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Connor Reed
// Date: 3/10/2025
// Description: Created the get Effect override method for Equipment
// *************************************************************************
vector<Effect*> Equipment::getItemConsumeEffects(bool& remove)
{
    cout << "DEBUG: Equipment doesn't have associated consume effects." << endl;
    return vector<Effect*>();
}

// *************************************************************************
// getEquipmentInfo getter for the Equip struct
// Incoming Data: none
// Outgoing Data: vector array of Equip pointers associated with the equipment
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Daniel Puckett
// Date: 3/16/2025
// Description: Created the get Equipment Info override method for Equipment
// *************************************************************************
vector<Equip*> Equipment::getEquipmentInfo()
{
	return stats;
}

// *************************************************************************
// addEquipStat setter for the Equip struct
// Incoming Data: temporary Equip pointer representing the equipment stats
// Outgoing Data: none
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Daniel Puckett
// Date: 3/16/2025
// Description: Created the add Equip Stat override method for Equipment
// *************************************************************************
void Equipment::addEquipStat(Equip* temp)
{
	stats.push_back(temp);
}