#ifndef H_ITEM
	#define H_ITEM
	#include "Item.h"
#endif
#ifndef H_ULL
	#define H_ULL
	#include "ull.h"
#endif
#ifndef H_ACTIVEMAP
    #define H_ACTIVEMAP
    #include "ActiveMap.h"
#endif
#ifndef H_ENEMYNPC
    #define H_ENEMYNPC
    #include "EnemyNPC.h"
#endif


#include <string>
#include <iostream>

using namespace std;

class Area{
  public:
    ActiveMap* userMap;
    vector<EnemyNPC*> enemies;
  	uLList<Item*> items;
    Area();
    void setDescription (string);
    void setGoal(bool);
    void setID(bool);
    string getDescription();
    bool getID();
    bool getGoal();
    void displayArea();
    void search();
  private:

     string description;
     bool instadeath;
     bool goal;
};