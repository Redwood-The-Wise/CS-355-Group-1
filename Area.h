#ifndef H_AREA
#define H_AREA

#include "Item.h"
#include "ull.h"
#include "ActiveMap.h"
#include "EnemyNPC.h"


#include <string>
#include <iostream>

using namespace std;

class Area{
  public:
    ActiveMap* userMap;
    vector<EnemyNPC*> permenantList;
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
	void generateEnemies();
  private:

     string description;
     bool instadeath;
     bool goal;
};
#endif