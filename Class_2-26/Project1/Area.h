#ifndef H_ITEM
	#define H_ITEM
	#include "Item.h"
#endif
#ifndef H_ULL
	#define H_ULL
	#include "ull.h"
#endif

#include <string>
#include <iostream>

using namespace std;

class Area{
  public:
  	uLList<Item*> items;
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