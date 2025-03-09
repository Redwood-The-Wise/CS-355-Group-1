// *************************************************************************
// Name: Daniel Puckett
// Course: CS-355
// Assignment: Project 2
// Description: MapV2 extends the functionality while adding support for
//	Item class.
// *************************************************************************

#ifndef H_MAP
	#define H_MAP
	#include "Map.h"
#endif

#ifndef H_ITEM
	#define H_ITEM
	#include "Item.h"
#endif

#ifndef H_USEITEM
	#define H_USEITEM
	#include "UseItem.h"
#endif

#ifndef H_CONSUMEITEM
	#define H_CONSUMEITEM
	#include "ConsumeItem.h"
#endif

#ifndef H_STRUCTS
	#define H_STRUCTS
	#include "structs.h"
#endif

#include <string>

class MapV2: public Map
{
	private:
		vector<Item*> items;
		string playerType;
		void makeItem();
		void makeBasicItem();
		void makeUseItem();
		void makeConsumeItem();
		void insertItems();
		void setPlayerType();
		
	
	public:
		MapV2();
		void buildMap();
		void resetItems();
		string getPlayerType();
		void updateLinks(int x, int y, char c);
		
		friend ostream& operator<<(ostream& os, MapV2& map);
		
};