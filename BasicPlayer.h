// *************************************************************************
// Name: Daniel Puckett
// Course: CS-355
// Assignment: Project 3
// Date: 2/23/2025
// Description: This is the definition file for the Basic Player class that
//	inherits from Player.h
// *************************************************************************

#ifndef H_PLAYER
	#define H_PLAYER
	#include "Player.h"
#endif

class BasicPlayer: public Player
{
	public:
		BasicPlayer();
		int isGameOver();
		void resetPlayerStats();
		void reportStats();
		void consume(MapV2* mapptr);
		void use(MapV2* mapptr);
};