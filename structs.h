// *************************************************************************
// Group: Group 1
// Course: CS-355-01
// Assignment: Project 4
// Due Date: 3/16/2025
// Description: 
// *************************************************************************
// *************************************************************************
// Edit Log
// *************************************************************************
// *************************************************************************
// Name: Logan Noles
// Date: 3/11/2025
// Description: Added string name to the EnemyStats struct and added 
// #include <string> and using namespace std because I was getting some weird errors.
// *************************************************************************
#include <string>
using namespace std;
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
	int defense; //added defense
	char mapChar;
	string desc;
	string name;
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
