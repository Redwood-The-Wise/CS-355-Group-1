// *************************************************************************
// Name: Daniel Puckett
// Course: CS-355
// Assignment: Project 3
// Date: 2/23/2025
// Description: This is the definition of the Hit Point Sanity Point Player
//	class that inherits from the Player class
// *************************************************************************
#ifndef H_HPSPPLAYER
#define H_HPSPPLAYER


#include "Player.h"
#include "MapV2.h"

class HPSPPlayer: public Player
{
	protected:
		int hitPoints;
		int sanityPoints;
	public:
		HPSPPlayer();
		int isGameOver();
		void resetPlayerStats();
		void reportStats();
		void consume(MapV2* mapptr);
		void use(MapV2* mapptr);
		void equip(MapV2* mapptr);
		void unequip();
		void attack();
		void isHit(int);
};
#endif