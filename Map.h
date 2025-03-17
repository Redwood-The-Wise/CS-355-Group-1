#ifndef H_MAP
#define H_MAP

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>


#include "areaNode.h"
#include "Area.h"
#include "IFDParser.h"
#include "LinkData.h"
#include "structs.h"
#include "EnemyNPC.h"


using namespace std;

class Map {
protected:
	vector<areaNode*> areasVec;
	int areacnt;

	//Here is the instance of IFDParser
	IFDParser parser;

	//Some additional class attributes here
	vector<LinkData*> linkVec;
	string nextToken;
	bool ifderr;

	EnemyNPC* makeEnemy();

public:
	Map();
	void buildMap();
	void makeArea();
	void makeLinks();
	void linkLinks();
	areaNode* getStart();
	//void print();
	int reverseLookUp(areaNode*);

	friend ostream& operator<<(ostream&, Map&);
};
#endif