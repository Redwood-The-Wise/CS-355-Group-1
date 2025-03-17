#ifndef H_PLAYER
#define H_PLAYER

#include "ull.h"
#include "Item.h"
#include "areaNode.h"
#include "MapV2.h"


class Player{
  public:
  	uLList<Item*> items;
    Player(){
		lastLocation = NULL;
		currentLocation = NULL;
	}

	void setCurrent(areaNode* loc){
      	lastLocation = currentLocation;
		currentLocation = loc;
	}

	bool playerMoved(){
		return !(lastLocation == currentLocation);
	}
	areaNode* getCurrent(){
		return currentLocation;
	}

	void inventory(){
		nodeType<Item*>* temp;
      	temp = items.getFirst();
		//cout<<temp<<endl;
		if(temp == NULL){
			cout<<"No items are in your inventory."<<endl;
		}
		else{
			cout<<"You have the following items:"<<endl;
			while(temp != NULL){
				cout<<"\t"<<temp->info->getName()<<endl;
				temp = temp->link;
			}
		}
	}

	void take(){
		cout<<"Take what item?"<<endl;
		string n;
		getline(cin, n);
		//cout<<"Looking for item: "<<n<<endl;
      		nodeType<Item*>* temp = NULL;
		temp = currentLocation->info.items.getFirst();
		//cout<<temp<<endl;
		if(temp == NULL){
			cout<<"No items are in this room to take."<<endl;
		}
		else{
			bool found = false;
			cout << "Searching for item: " << n << endl;
			while(temp != NULL && !found){
				if(n == temp->info->getName()){
					if (currentLocation->info.userMap->checkValidItem(temp->info))
					{

						found = true;
						//add to player list
						items.insertLast(temp->info);
						//delete from room list
						currentLocation->info.userMap->deleteItem(temp->info->getItemChar());
						currentLocation->info.items.deleteNode(temp->info);
					}
					else {
						cout << "You can't take that item." << endl;
						return;
					}
				}
				else{
					temp = temp->link;
				}
			}
			if (found)
			{
				cout<<"You have taken: "<<n<<endl;
			}
			else{
				cout<<"No item by that name here."<<endl;
			}
		}
	}

	void leave(){
		cout<<"Leave what item?"<<endl;
		string n;
		getline(cin, n);
		//cout<<"Looking for item: "<<n<<endl;
      		nodeType<Item*>* temp = NULL;
		temp = items.getFirst();
		//cout<<temp<<endl;
		if(temp == NULL){
			cout<<"You have no items in your inventory."<<endl;
		}
		else{
			bool found = false;
			while(temp != NULL && !found){
				if(n == temp->info->getName()){
					found = true;
					//add to room list
					currentLocation->info.items.insertLast(temp->info);
					//delete from player list
					currentLocation->info.userMap->dropItem(temp->info->getItemChar());
					items.deleteNode(temp->info);
				}
				else{
					temp = temp->link;
				}
			}
			if(found){
				cout<<"You have dropped: "<<n<<endl;
			}
			else{
				cout<<"No item by that name in your inventory."<<endl;
			}
		}
	}

	void examine(){
		cout<<"Examine what item?"<<endl;
		string n;
		getline(cin, n);
		//cout<<"Looking for item: "<<n<<endl;
      		nodeType<Item*>* temp = NULL;
		temp = items.getFirst();
		//cout<<temp<<endl;
		if(temp == NULL){
			cout<<"You have no items in your inventory to examine."<<endl;
		}
		else{
			bool found = false;
			while(temp != NULL && !found){
				if(n == temp->info->getName()){
					found = true;
					//display item description
					cout<<temp->info->getDesc()<<endl;
				}
				else{
					temp = temp->link;
				}
			}
			if(!found){
				cout<<"No item by that name in your inventory."<<endl;
			}
		}
	}

	virtual int isGameOver() = 0;
	virtual void resetPlayerStats() = 0;
	virtual void reportStats() = 0;
	virtual void consume(MapV2* mapptr) = 0;
	virtual void use(MapV2* mapptr) = 0;
	virtual void equip(MapV2* mapptr) = 0;
	virtual void unequip() = 0;
	virtual void attack() = 0;
	virtual void isHit(int) = 0;

  protected:
		areaNode* currentLocation;
		areaNode* lastLocation;

};

#endif