#ifndef H_MAPV2
#define H_MAPV2
    #include "MapV2.h"
#endif // H_MAPV2

#ifndef H_PLAYER
#define H_PLAYER
    #include "Player.h"
#endif // H_PLAYER

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

  	public:
		Game();
  		void play();
  		void resetGame();
};