// *************************************************************************
// Name: Daniel Puckett
// Course: CS-355
// Assignment: Project 2
// Description: MapV2 extends the functionality while adding support for
//	Item class.
// *************************************************************************

#ifndef H_MAPV2
#define H_MAPV2

#include "Map.h"
#include "Item.h"
#include "UseItem.h"
#include "ConsumeItem.h"
#include "structs.h"
#include "Equipment.h"

#include <string>
#include <vector>

class MapV2 : public Map
{
private:
    std::vector<Item*> items;
    std::string playerType;
    void makeItem();
    void makeBasicItem();
    void makeUseItem();
    void makeConsumeItem();
    void makeEquipmentItem();
    void insertItems();
    void setPlayerType();

public:
    MapV2();
    void buildMap();
    void resetItems();
    std::string getPlayerType();
    void updateLinks(int x, int y, char c);

    friend std::ostream& operator<<(std::ostream& os, MapV2& map);
};

#endif