#include <iostream>

#include "Map.h"

Map::Map(){
   areacnt = 0;
   ifderr = false;
   nextToken = "";
}
void Map::buildMap(){
    ifderr = false;
    cout << "Calling Parser" << endl;
    parser.tokenIt();
    
    nextToken = parser.getNext();

    if(nextToken == "<game>"){
		cout << nextToken << endl;
        parser.eatToken();
        nextToken = parser.getNext();
        while(nextToken != "</game>"){  //consider what happens when run out of tokens && not error state
        	cout << nextToken << endl;
            if(nextToken == "<area>"){
                parser.eatToken();
                nextToken = parser.getNext();
                makeArea();
            }
            else if(nextToken == "<links>"){
                parser.eatToken();
                nextToken = parser.getNext();
                makeLinks();
            }
            else{
                cout<<"Parse Error Location 1"<<endl;
                ifderr = true;
                break;
            }
            parser.eatToken();
            nextToken = parser.getNext();
        }// while !</game>

        if(ifderr){
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
    else{
        cout<<" :: ERROR :: No \"<game>\" tag found."<<endl;
        cout<<"Game Loading Failed"<<endl;
    }

    //link up areas
    linkLinks();
}
void Map::makeArea(){
    string xstr;
    areaNode* tempNodePtr = new areaNode;
	tempNodePtr->info.userMap = new ActiveMap();

    while(nextToken != "</area>"){ 
        if(nextToken == "<desc>"){
            parser.eatToken();
            nextToken = parser.getNext();
            tempNodePtr->info.setDescription(nextToken);
        }
        else if(nextToken == "<feats>"){
            parser.eatToken();
            nextToken = parser.getNext();
            istringstream ss(nextToken);
            getline(ss, xstr, ',');
            tempNodePtr->info.setID(atoi(xstr.c_str()));

            getline(ss, xstr, ',');
            tempNodePtr->info.setGoal(atoi(xstr.c_str()));
        }
        else if (nextToken == "<map>")
        {
            parser.eatToken();
            nextToken = parser.getNext();
            tempNodePtr->info.userMap->addRow(nextToken);
        }
        else if (nextToken == "<enemy>")
        {
            parser.eatToken();
			nextToken = parser.getNext();
			tempNodePtr->info.permenantList.push_back(makeEnemy());
        }
        else if(nextToken == "</desc>" || nextToken == "</feats>" ||
            nextToken == "</map>" || nextToken == "</enemy>") {
            //do nothing
        }
        else{
            cout<<"Parse Error Location 2"<<endl;
            ifderr = true;
            break;
        }

        parser.eatToken();
        nextToken = parser.getNext();
    }//while !</area>

    //add area to vector
    areasVec.push_back(tempNodePtr);
    tempNodePtr->info.userMap->createObjectMap();
    tempNodePtr->info.userMap->createUserMap();
} //end makeArea()

void Map::makeLinks(){
    string xstr;
    int u, d, l, r;
    while(nextToken != "</links>"){
        if(nextToken == "<linkset>"){
            parser.eatToken();
            nextToken = parser.getNext();

            LinkData* tempLDPtr = new LinkData;
            istringstream ss(nextToken);
            getline(ss, xstr, ',');
            u = atoi(xstr.c_str());
            getline(ss, xstr, ',');
            d = atoi(xstr.c_str());
            getline(ss, xstr, ',');
            l = atoi(xstr.c_str());
            getline(ss, xstr, ',');
            r = atoi(xstr.c_str());

            tempLDPtr->setDigits(u, d, l, r);
            linkVec.push_back(tempLDPtr);
        }
        else if(nextToken == "</linkset>"){
            //do nothing
        }
        else{
			cout << nextToken << endl;
            cout<<"Parse Error Location 3"<<endl;
            ifderr = true;
            break;
        }
        parser.eatToken();
        nextToken = parser.getNext();
    }//while !</links>
}//makeLinks()


void Map::linkLinks(){
    for(int i=0; i<linkVec.size(); i++){
        areasVec[i]->u = areasVec[(linkVec[i]->getDigit(0))-1];
        areasVec[i]->d = areasVec[(linkVec[i]->getDigit(1))-1];
        areasVec[i]->l = areasVec[(linkVec[i]->getDigit(2))-1];
        areasVec[i]->r = areasVec[(linkVec[i]->getDigit(3))-1];
    }
}


areaNode* Map::getStart(){
    return areasVec[0];  //returns a pointer to the first area listed
}

/*void Map::print(){
    cout<<"******************************************************************"<<endl;
    cout<<"CHEATING!!!! Printing the set of areas and connections on the map."<<endl;
    cout<<"******************************************************************"<<endl;
    for(int i=0; i<areasVec.size(); i++){
        cout<<"This is area: "<<i+1<<endl;
        cout<<areasVec[i]->info.getDescription()<<endl;
        if(areasVec[i]->info.getID() == 1){
            cout<<"Area is INSTADEATH."<<endl;
        }
        if(areasVec[i]->info.getGoal() == 1){
            cout<<"Area is GOAL."<<endl;
        }
        cout<<"Connections:"<<endl;
        cout<<"\t u: Area #"<<reverseLookUp(areasVec[i]->u)<<endl;
        cout<<"\t d: Area #"<<reverseLookUp(areasVec[i]->d)<<endl;
        cout<<"\t l: Area #"<<reverseLookUp(areasVec[i]->l)<<endl;
        cout<<"\t r: Area #"<<reverseLookUp(areasVec[i]->r)<<endl;
    }
}*/

int Map::reverseLookUp(areaNode* addy){
    for(int i=0; i<areasVec.size(); i++){
        if(areasVec[i] == addy){
            return i+1;
        }
    }
    //this should not happen
    return -1;
}



ostream& operator<<(ostream& osObject, Map& map)
{
	osObject<<"******************************************************************"<<endl;
	osObject<<"CHEATING!!!! Printing the set of areas and connections on the map."<<endl;
	osObject<<"******************************************************************"<<endl;
	for(int i=0; i<map.areasVec.size(); i++){
		cout<<"This is area: "<<i+1<<endl;
		cout<<map.areasVec[i]->info.getDescription()<<endl;
		if(map.areasVec[i]->info.getID() == 1){
			cout<<"Area is INSTADEATH."<<endl;
		}
		if(map.areasVec[i]->info.getGoal() == 1){
			cout<<"Area is GOAL."<<endl;
		}
		cout<<"Connections:"<<endl;
		cout<<"\t u: Area #"<<map.reverseLookUp(map.areasVec[i]->u)<<endl;
		cout<<"\t d: Area #"<<map.reverseLookUp(map.areasVec[i]->d)<<endl;
		cout<<"\t l: Area #"<<map.reverseLookUp(map.areasVec[i]->l)<<endl;
		cout<<"\t r: Area #"<<map.reverseLookUp(map.areasVec[i]->r)<<endl;
	}
	return osObject;
}

// *************************************************************************
// makeEnemy() - creates an EnemyNPC object from the IFDParser
// Incoming Data: none
// Outgoing Data: EnemyNPC* object
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Daniel Puckett
// Date: 3/16/2025
// Description: Created the method to handle creating an enemy
// *************************************************************************
EnemyNPC* Map::makeEnemy()
{
    EnemyNPC* tempEnemy = new EnemyNPC;
    string xstr;
    Stats* tempStats = new Stats;
    while (nextToken != "</enemy>")
    {
        if (nextToken == "<name>")
        {
            parser.eatToken();
            nextToken = parser.getNext();
            tempStats->name = nextToken;
        }
        else if (nextToken == "<desc>")
        {
            parser.eatToken();
			nextToken = parser.getNext();
			tempStats->desc = nextToken;
		}
		else if (nextToken == "<stats>")
		{
			parser.eatToken();
			nextToken = parser.getNext();
			xstr = nextToken;
			tempStats->damage = atoi(xstr.substr(0, xstr.find(',')).c_str());
			xstr = xstr.substr(xstr.find(',') + 1);
			tempStats->defense = atoi(xstr.substr(0, xstr.find(',')).c_str());
			xstr = xstr.substr(xstr.find(',') + 1);
			tempStats->health = atoi(xstr.c_str());
        }
        else if (nextToken == "<code>")
        {
			parser.eatToken();
			nextToken = parser.getNext();
			tempStats->mapChar = nextToken[0];
        }
		else if (nextToken == "</name>" || nextToken == "</desc>" ||
            nextToken == "</stats>" || nextToken == "</code>")
		{
			//do nothing
		}
		else
		{
			cout << "Parse Error Location 4" << endl;
			ifderr = true;
			break;
		}
		parser.eatToken();
		nextToken = parser.getNext();
    }
	tempEnemy->setStats(tempStats);
	return tempEnemy;
}