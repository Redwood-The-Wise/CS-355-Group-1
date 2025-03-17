#ifndef H_GAME
#define H_GAME
#include "MapV2.h"
#include "Player.h"
#include "HPSPPlayer.h"
#include "BasicPlayer.h"
#include "CombatPlayer.h"

#ifndef H_BASICPLAYER
	#define H_BASICPLAYER
	#include "BasicPlayer.h"
#endif

#ifndef H_HPSPPLAYER
	#define H_HPSPPLAYER
	#include "HPSPPlayer.h"
#endif

class Game{
	private:
		Player* player1;
		MapV2* map;
		void moveArea();

  	public:
		Game();
  		void play();
  		void resetGame();
};
#endif