// *************************************************************************
// Group: Group 1
// Course: CS-355-01
// Assignment: Project 4
// Due Date: 3/16/2025
// Description: Equipment class derives from Item and provides bonuses to player HP and SP.
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Daniel Puckett
// Date: 3/7/2025
// Description: Created the class with the ability to display the map and
//	track player positioning
// *************************************************************************
// *************************************************************************
// Name: Connor Reed
// Date: 3/10/2025
// Description: Began writing and implementing the equipment methods and overrides
// *************************************************************************
// *************************************************************************
// Name: Daniel Puckett
// Date: 3/15/2025
// Description: Updated all methods and fields to make sure that equipment
// 	follows the expected API and simplified data handling.
// *************************************************************************

#ifndef H_EQUIPMENT
#define H_EQUIPMENT

#include "Item.h"
#include "structs.h"

class Equipment : public Item
{
    public:
        Equipment();
        void displayEquipmentInfo();
        void setActiveMessage(string s);
        string getActiveMessage();
        void setActiveArea(int i);
        int getActiveArea();
        void addRule(Rule* temp);
        vector<Rule*> getItemUseRules();
        void addEffect(Effect* temp);
        vector<Effect*> getItemConsumeEffects(bool&);
		vector<Equip*> getEquipmentInfo();
		void addEquipStat(Equip* temp);

    private:
        vector<Equip*> stats;
};
#endif