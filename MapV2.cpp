// *************************************************************************
// Name: Daniel Puckett
// Course: CS-355
// Assignment: Project 2
// Description: MapV2 extends the functionality while adding support for
//	Item class. This file defines all overridden methods along with unique
//	methods.
// *************************************************************************

#include "MapV2.h"

// *************************************************************************
// This is the default no argument constructor for the MapV2 class. It also
// calls the default constructor for the extended Map class.
// Incoming Data: none
// Outgoing Data: none
// *************************************************************************
MapV2::MapV2()
{
	// No data to initiate
}

// *************************************************************************
// makeItem() is a private member method designed to call methods to create
//	the correct type of item.
// Incoming Data: none
// Outgoing Data: none
// *************************************************************************
void MapV2::makeItem()
{
	while (nextToken != "</item>")
	{
		if (nextToken == "<basic>")
		{
			parser.eatToken();
			nextToken = parser.getNext();
			makeBasicItem();
		}
		else if (nextToken == "<use>")
		{
			parser.eatToken();
			nextToken = parser.getNext();
			makeUseItem();
		}
		else if (nextToken == "<consumable>")
		{
			parser.eatToken();
			nextToken = parser.getNext();
			makeConsumeItem();
		}
		else if (nextToken == "<equipment>")
		{
			parser.eatToken();
			nextToken = parser.getNext();
			makeEquipmentItem();
		}
		else if (nextToken == "</basic>" || nextToken == "</use>" ||
			nextToken == "</consume>" || nextToken == "</equipment>")
		{
			// Do nothing
		}
		else 
		{
			cout<<"Parse Error Location 2"<<endl;
			cout << nextToken << endl;
            ifderr = true;
            break;
		}
		parser.eatToken();
        nextToken = parser.getNext();
	}
}

// *************************************************************************
// makeBasicItem creates an Item object then stores it into the item vector
// Incoming Data: none
// Outgoing Data: none
// *************************************************************************
void MapV2::makeBasicItem()
{
	Item* tempItem = new Item();
	string xstr;
	
	while (nextToken != "</basic>")
	{
		if (nextToken == "<name>")
		{
			parser.eatToken();
			xstr = parser.getNext();
			tempItem->setName(xstr);
		}
		else if (nextToken == "<desc>")
		{
			parser.eatToken();
			xstr = parser.getNext();
			tempItem->setDesc(xstr);
		}
		else if (nextToken == "<star>")
		{
			parser.eatToken();
			xstr = parser.getNext();
			int temp = atoi(xstr.c_str());
			tempItem->setSR(temp);
		}
		
		parser.eatToken();
		nextToken = parser.getNext();
	}
	items.push_back(tempItem);
}

// *************************************************************************
// makeUseItem creates an UseItem object then stores it into the item vector
// Incoming Data: none
// Outgoing Data: none
// *************************************************************************
void MapV2::makeUseItem()
{
	Item* tempItem = new UseItem();
	string xstr;
	
	while (nextToken != "</use>")
	{
		if (nextToken == "<name>")
		{
			parser.eatToken();
			xstr = parser.getNext();
			tempItem->setName(xstr);
		}
		else if (nextToken == "<desc>")
		{
			parser.eatToken();
			xstr = parser.getNext();
			tempItem->setDesc(xstr);
		}
		else if (nextToken == "<star>")
		{
			parser.eatToken();
			xstr = parser.getNext();
			int temp = atoi(xstr.c_str());
			tempItem->setSR(temp);
		}
		else if (nextToken == "<actmess>")
		{
			parser.eatToken();
			xstr = parser.getNext();
			tempItem->setActiveMessage(xstr);
		}
		else if (nextToken == "<actar>")
		{
			parser.eatToken();
			xstr = parser.getNext();
			int temp = atoi(xstr.c_str());
			tempItem->setActiveArea(temp);
		}
		else if (nextToken == "<rule>")
		{
			Rule* tempRule = new Rule;
			parser.eatToken();
			xstr = parser.getNext();
			int temp = atoi(xstr.substr(0, xstr.find(',')).c_str());
			tempRule->beginRm = temp;
			xstr = xstr.substr(xstr.find(',')+1, xstr.length() - 1);
			parser.trim(xstr);
			tempRule->direction = xstr.substr(0, xstr.find(','))[0];
			xstr = xstr.substr(xstr.find(',')+1, xstr.length()-1);
			parser.trim(xstr);
			temp = atoi(xstr.c_str());
			tempRule->destRm = temp;
			tempItem->addRule(tempRule);
		}
		else if (nextToken == "<code>")
		{
			parser.eatToken();
			xstr = parser.getNext();
			char temp = xstr[0];
			tempItem->setItemChar(temp);
		}
		else
		{
			cout << "Error parsing in makeUseItem()" << endl;
		}
		
		parser.eatToken();
		nextToken = parser.getNext();
	}
	items.push_back(tempItem);
}

// *************************************************************************
// makeConsumeItem creates an ConsumeItem object then stores it into the 
//	item vector
// Incoming Data: none
// Outgoing Data: none
// *************************************************************************
void MapV2::makeConsumeItem()
{
	Item* tempItem = new ConsumeItem();
	string xstr;
	
	while (nextToken != "</consumable>")
	{
		if (nextToken == "<name>")
		{
			parser.eatToken();
			xstr = parser.getNext();
			tempItem->setName(xstr);
		}
		else if (nextToken == "<desc>")
		{
			parser.eatToken();
			xstr = parser.getNext();
			tempItem->setDesc(xstr);
		}
		else if (nextToken == "<star>")
		{
			parser.eatToken();
			xstr = parser.getNext();
			int temp = atoi(xstr.c_str());
			tempItem->setSR(temp);
		}
		else if (nextToken == "<actmess>")
		{
			parser.eatToken();
			xstr = parser.getNext();
			tempItem->setActiveMessage(xstr);
		}
			else if (nextToken == "<actar>")
		{
			parser.eatToken();
			xstr = parser.getNext();
			int temp = atoi(xstr.c_str());
			tempItem->setActiveArea(temp);
		}
		else if (nextToken == "<effect>")
		{
			Effect* effect = new Effect;
			parser.eatToken();
			xstr = parser.getNext();
			int temp = atoi(xstr.substr(0, xstr.find(',')).c_str());
			effect->effectID = temp;
			xstr = xstr.substr(xstr.find(',')+1, xstr.length() - 1);
			parser.trim(xstr);
			temp = atoi(xstr.substr(0, xstr.find(',')).c_str());
			xstr = xstr.substr(xstr.find(',') + 1, xstr.length() - 1);
			parser.trim(xstr);
			effect->effectAmt = temp;
			int numUses = atoi(xstr.c_str());
			tempItem->addEffect(effect);
			tempItem->setNumUses(numUses);
		}
		else if (nextToken == "<code>")
		{
			parser.eatToken();
			xstr = parser.getNext();
			char temp = xstr[0];
			tempItem->setItemChar(temp);
		}
		else if (nextToken == "</name>" || nextToken == "</desc>" ||
			nextToken == "</star>" || nextToken == "</actmess>" ||
			nextToken == "</actar>" || nextToken == "</effect>" ||
			nextToken == "</code>")
		{
			// do nothing
		}
		else
		{
			cout << "Error parsing in makeConsumeItem()" << endl;
		}
		parser.eatToken();
		nextToken = parser.getNext();
	}
	items.push_back(tempItem);
}

// *************************************************************************
// makeEquipmentItem creates an Equipment object then stores it into the
//	item vector
// Incoming Data: none
// Outgoing Data: none
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Daniel Puckett
// Date: 3/15/2025
// Description: Created the method to handle equipment items
// *************************************************************************
void MapV2::makeEquipmentItem()
{
	Item* tempItem = new Equipment();
	string xstr;
	while (nextToken != "</equipment>")
	{
		if (nextToken == "<name>")
		{
			parser.eatToken();
			nextToken = parser.getNext();
			xstr = nextToken;
			tempItem->setName(xstr);
		}
		else if (nextToken == "<desc>")
		{
			parser.eatToken();
			nextToken = parser.getNext();
			xstr = nextToken;
			tempItem->setDesc(xstr);
		}
		else if (nextToken == "<star>")
		{
			parser.eatToken();
			nextToken = parser.getNext();
			xstr = nextToken;
			int temp = atoi(xstr.c_str());
			tempItem->setSR(temp);
		}
		else if (nextToken == "<code>")
		{
			parser.eatToken();
			nextToken = parser.getNext();
			xstr = nextToken;
			char temp = xstr[0];
			tempItem->setItemChar(temp);
		}
		else if (nextToken == "<stat>")
		{
			parser.eatToken();
			nextToken = parser.getNext();
			xstr = nextToken;
			int rule = atoi(xstr.substr(0, xstr.find(',')).c_str());
			xstr = xstr.substr(xstr.find(',') + 1, xstr.length() - 1);
			parser.trim(xstr);
			int effect = atoi(xstr.c_str());
			Equip* tempEquip = new Equip;
			tempEquip->effect = effect;
			tempEquip->rule = rule;
			tempItem->addEquipStat(tempEquip);
		}
		else if (nextToken == "<actar>")
		{
			parser.eatToken();
			nextToken = parser.getNext();
			xstr = nextToken;
			int temp = atoi(xstr.c_str());
			tempItem->setActiveArea(temp);
		}
		else if (nextToken == "<actmess>")
		{
			parser.eatToken();
			nextToken = parser.getNext();
			xstr = nextToken;
			tempItem->setActiveMessage(xstr);
		}
		else if (nextToken == "</name>" || nextToken == "</desc>" ||
			nextToken == "</star>" || nextToken == "</code>" ||
			nextToken == "</stat>" || nextToken == "</actar>" ||
			nextToken == "</actmess>")
		{
			// do nothing
		}
		else
		{
			cout << "Error parsing in makeEquipmentItem()" << endl;
		}
		parser.eatToken();
		nextToken = parser.getNext();
	}
	items.push_back(tempItem);
}

// *************************************************************************
// insertItems() is a private member method designed to handle insertion of 
//	new items in into the correct areas.
// Incoming Data: none
// Outgoing Data: none
// *************************************************************************
void MapV2::insertItems()
{
	Item* tempItemPtr;
	int currentIndex = 0;
	for (int i = 0; i < areasVec.size(); i++)
	{
		if (currentIndex >= items.size())
		{
			break;
		}

		tempItemPtr = items[currentIndex];

		while (tempItemPtr->getSR() == i)
		{	
			areasVec[i-1]->info.items.insertLast(tempItemPtr);
			currentIndex++;
			if (currentIndex < items.size())
			{
				tempItemPtr = items[currentIndex];
			}
			else 
			{
				break;
			}
		
		}
	}
}

// *************************************************************************
// setPlayerType() parses the the token to set the correct player type.
//	This value is then saved to playerType.
// Incoming Data: none
// Outgoing Data: none
// *************************************************************************
void MapV2::setPlayerType()
{
	while (nextToken != "</ptype>")
	{
		if (nextToken == "basic" || nextToken == "hpsp" || nextToken  == "combat")
		{
			playerType = nextToken;
		}
		parser.eatToken();
		nextToken = parser.getNext();
	}
}

// *************************************************************************
// buildMap() is the overridden buildMap method from the Map class.
//  It has been redesigned to include support for items.
// Incoming Data: none
// Outgoing Data: none
// *************************************************************************
void MapV2::buildMap()
{
	ifderr = false;
	parser.tokenIt();

    nextToken = parser.getNext();
    if(nextToken == "<game>"){
		parser.eatToken();
        nextToken = parser.getNext();
        while(nextToken != "</game>")
		{
            if(nextToken == "<area>")
			{
                parser.eatToken();
                nextToken = parser.getNext();
                makeArea();
            }
            else if(nextToken == "<links>")
			{
                parser.eatToken();
                nextToken = parser.getNext();
                makeLinks();
            }
            else if (nextToken == "<item>")
			{
				parser.eatToken();
				nextToken = parser.getNext();
				makeItem();
			}
			else if (nextToken == "<ptype>")
			{
				parser.eatToken();
				nextToken = parser.getNext();
				setPlayerType();
			}
            else{
                cout<<"Parse Error Location 1"<<endl;
                ifderr = true;
                break;
            }
            parser.eatToken();
            nextToken = parser.getNext();
        }// while !</game>

        if(ifderr)
		{
            cout<<" :: ERROR :: IF Document Formatting Error"<<endl;
            cout<<"Game Loading Failed"<<endl;
            cout<<"General Area of Parsing Failure:"<<endl;
            cout<<"-------------------------------------"<<endl;
            cout<<nextToken<<endl;
            parser.eatToken();
            nextToken = parser.getNext();
            cout<<nextToken<<endl;
            parser.eatToken();
            nextToken = parser.getNext();
            cout<<nextToken<<endl;
            parser.eatToken();
            nextToken = parser.getNext();
            cout<<nextToken<<endl;
            cout<<"-------------------------------------"<<endl;
            return;
        }
    }
    else
	{
        cout<<" :: ERROR :: No \"<game>\" tag found."<<endl;
        cout<<"Game Loading Failed"<<endl;
    }

    //link up areas
    linkLinks();
    insertItems();
}

// *************************************************************************
// resetItems() adds all items back to the areas they are supposed to be in.
// Incoming Data: none
// Outgoing Data: none
// *************************************************************************
void MapV2::resetItems()
{
	for (int i = 0; i < areasVec.size(); i++)
	{
		areasVec[i]->info.items.destroyList();
	}
	insertItems();
}

// *************************************************************************
// getPlayerType returns the string playerType to be used in Game.cpp to set
//	the correct Player type.
// Incoming Data: none
// Outgoing Data: string playerType
// *************************************************************************
string MapV2::getPlayerType()
{
	return playerType;
}

// *************************************************************************
// updateLink changes the links to match the changes from objects
// Incoming Data: int x, int y, char c
// Outgoing Data: none
// *************************************************************************
void MapV2::updateLinks(int x, int y, char c)
{
	if (c == 'u')
	{
		areasVec[x-1]->u = areasVec[y-1];
	}
	else if (c == 'd')
	{
		areasVec[x-1]->d = areasVec[y-1];
	}
	else if (c == 'l')
	{
		areasVec[x-1]->l = areasVec[y-1];
	}
	else if (c == 'r')
	{
		areasVec[x-1]->r = areasVec[y-1];
	}
}

// *************************************************************************
// This is the overloaded and overridden insertion operator friend function
//  designed to output all current rooms and items.
// Incoming Data: ostream& os, MapV2& map
// Outgoing Data: ostream& os
// *************************************************************************
ostream& operator<<(ostream& os, MapV2& map)
{
	int currentIndex = 0;
	
	os<<"******************************************************************"<<endl;
	os<<"CHEATING!!!! Printing the set of areas and connections on the map."<<endl;
	os<<"******************************************************************"<<endl;
	for(int i=0; i<map.areasVec.size(); i++)
	{
		os<<"This is area: "<<i+1<<endl;
		os<<map.areasVec[i]->info.getDescription()<<endl;
		if(map.areasVec[i]->info.getID() == 1){
			os<<"Area is INSTADEATH."<<endl;
		}
		if(map.areasVec[i]->info.getGoal() == 1){
			os<<"Area is GOAL."<<endl;
		}
		os<<"Connections:"<<endl;
		os<<"\t u: Area #"<<map.reverseLookUp(map.areasVec[i]->u)<<endl;
		os<<"\t d: Area #"<<map.reverseLookUp(map.areasVec[i]->d)<<endl;
		os<<"\t l: Area #"<<map.reverseLookUp(map.areasVec[i]->l)<<endl;
		os<<"\t r: Area #"<<map.reverseLookUp(map.areasVec[i]->r)<<endl;
	}
	
	os<<"******************************************************************"<<endl;
	os<<"CHEATING!!!! ITEM LOCATIONS FOR ALL NON-INVENTORY ITEMS."<<endl;
	os<<"******************************************************************"<<endl;
	for (int i = 0; i < map.areasVec.size(); i++)
	{
		Item* temp;
		os << "This is area: " << i+1 << ": ";
		os << map.areasVec[i]->info.getDescription() << endl;
		if (currentIndex >= map.items.size())
			break;
		temp = map.items[currentIndex];
		while (temp->getSR() - 1 == i)
		{
			os << temp->getName() << endl;
			currentIndex++;
			if (currentIndex < map.items.size())
			{
				temp = map.items[currentIndex];
			}
			else
			{
				break;
			}
		}
	}
	
	return os;
}