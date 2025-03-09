struct Rule
{
	int beginRm;
	char direction;
	int destRm;
};
struct Effect
{
    int effectID;
    int effectAmt;
};

// *************************************************************************
// EnemyStats is a new struct to handle the stats stored by the EnemyNPC
//	Class.
// *************************************************************************
struct EnemyStats
{
	int health;
	int damage;
	char mapChar;
	string desc;
};
// *************************************************************************
// Equip is a new struct to handle the stats stored by the Equipment class
// *************************************************************************
struct Equip
{
	int beginRm;
	int rule;
	int effect;
};
