#include <iostream>

#include "Game.h"


Game::Game(){
	map = new MapV2();
    map->buildMap();
	string playerType = map->getPlayerType();
	if (playerType == "basic")
	{
		cout << "Creating Basic Player" << endl;
		player1 = new BasicPlayer();
	}
	else if (playerType == "hpsp")
	{
		cout << "Creating HPSP Player" << endl;
		player1 = new HPSPPlayer();
	}
    else if (playerType == "combat")
    {
		cout << "Creating Combat Player" << endl;
		player1 = new CombatPlayer();
    }
    player1->setCurrent(map->getStart());
	player1->getCurrent()->info.userMap->setPlayerPos();
}

void Game::play(){
    string userInput;
    //cin.ignore();
	cout << "Welcome to the game!" << endl;
	player1->getCurrent()->info.userMap->print();
    while(true){
        //check game status
        if(player1->isGameOver() != 0){
            player1->getCurrent()->info.displayArea();
            return;
        }
        //display area data
        if(player1->playerMoved()){
                player1->getCurrent()->info.displayArea();
        }
        else{
            if(userInput != "reset"){
                cout<<"There appears to be no way to go that direction."<<endl;
            }
        }

        //get movement selection
        cout<<"Which way would you like to go?  Enter u, d, l, or r"<<endl;
        getline(cin, userInput);

        //update area
        if(userInput == "u"){
            player1->getCurrent()->info.userMap->updatePlayerPos('u');
            moveArea();
            player1->getCurrent()->info.userMap->print();
        }
        else if(userInput == "d"){
            player1->getCurrent()->info.userMap->updatePlayerPos('d');
            moveArea();
            player1->getCurrent()->info.userMap->print();
        }
        else if(userInput == "l"){
            player1->getCurrent()->info.userMap->updatePlayerPos('l');
            moveArea();
            player1->getCurrent()->info.userMap->print();
        }
        else if(userInput == "r"){
            player1->getCurrent()->info.userMap->updatePlayerPos('r');
            moveArea();
            player1->getCurrent()->info.userMap->print();
        }
        else if(userInput == "iseedeadpeople"){ //issdeadpeople cheat code to reveal map
            //map.print();
            cout<<*map;
        }
        else if(userInput == "reset"){
            resetGame();
        }
        else if(userInput == "exit"){
            cout<<"Good bye!"<<endl;
            return;
        }
        else if(userInput == "search"){
            player1->getCurrent()->info.search();
        }
        else if(userInput == "inventory"){
            player1->inventory();
        }
        else if(userInput == "take"){
            player1->take();
        }
        else if(userInput == "leave"){
            player1->leave();
        }
        else if(userInput == "examine"){
            player1->examine();
        }
        else if (userInput == "stats")
		{
			player1->reportStats();
		}
		else if (userInput == "use")
		{
			player1->use(map);
		}
		else if (userInput == "consume")
		{
			player1->consume(map);
		}
        else if (userInput == "attack")
        {
			player1->attack();
        }
        else if (userInput == "equip")
        {
            player1->equip(map);
        }
		else if (userInput == "unequip")
		{
			player1->unequip();
		}
        else if(userInput == "help"){
            cout<<"You may type: "<<endl;
            cout<<"\t u, d, l, or r: to move up, down, left or right on the map,"<<endl;
            cout<<"\t search: to search for items in current area,"<<endl;
            cout<<"\t take: to attempt to take an item,"<<endl;
            cout<<"\t leave: to attempt to leave an item,"<<endl;
            cout<<"\t examine: to examine an item in your inventory,"<<endl;
            cout<<"\t stats: to display health points and sanity points,"<< endl;
            cout<<"\t use: to use an item in your inventory,"<<endl;
            cout<<"\t consume: to consume an item in your inventory,"<<endl;
            cout<<"\t reset: to reset the game,"<<endl;
            cout<<"\t exit: to exit the game."<<endl;
            cout<<endl;
        }
        else{
            cout<<"I do not understand: "<<userInput<<endl<<endl;
        }
    }//end while
}//end play()



void Game::resetGame(){
    player1->setCurrent(map->getStart());
    player1->resetPlayerStats();
    //remove item from player list
    player1->items.destroyList();
    //remove item from each area in turn
    map->resetItems();
    map->linkLinks();
}

// *************************************************************************
// moveArea checks to see if the player is currently at the same location as
//  as the move character in the ActiveMap matrix
// Incoming Data: none
// Outgoing Data: none
// *************************************************************************
// *************************************************************************
// Editing Log
// *************************************************************************
// *************************************************************************
// Name: Daniel Puckett
// Date: 3/7/2025
// Edited Description: Created the method to handle moving player
// *************************************************************************
void Game::moveArea()
{
    char nextArea = player1->getCurrent()->info.userMap->checkMoveArea();
    bool playerMoved = false;

    if (nextArea == 'n')
    {
        return;
    }
    if (nextArea == 'u')
    {
        player1->setCurrent(player1->getCurrent()->u);
        playerMoved = true;
    }
    else if (nextArea == 'd')
    {
        player1->setCurrent(player1->getCurrent()->d);
        playerMoved = true;
    }
    else if (nextArea == 'l')
    {
        player1->setCurrent(player1->getCurrent()->l);
        playerMoved = true;
    }
    else if (nextArea == 'r')
    {
        player1->setCurrent(player1->getCurrent()->r);
        playerMoved = true;
    }
    if (playerMoved) {
        player1->getCurrent()->info.userMap->setPlayerPos();
    }
	cout << playerMoved << endl;
}