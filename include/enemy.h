#ifndef ENEMY_H
#define ENEMY_H

/* Irrlicht includes */
#include <irrlicht.h>
#include "driverChoice.h"
using namespace irr;
#ifdef _MSC_VER
#pragma comment(lib, "Irrlicht.lib")
#endif
#include <math.h>

/* Personal Includes */
#include "include\enums.h"

/* define the header for the class */
class Enemy
{
	public:
		/* Basic Functions */
		Enemy();	//basic constructor
		void spawnEnemy(std::string enemyName, int x, int y);
		void spawnRandomEnemy();
		void battleCycle();				//do a common cycle of battle
		void checkCaps();				//ensure all caps on the stats are ok and fix them
		bool move(Direction dir);
		
		/* Map Vars */
		core::position2d<f32> pos;	//position on the map, feetwise

		/* Stats Vars */
		int HP; int MHP; int ATT; int DEF; int SPD; 
		f32 hurtTimer;
		std::string attackType;
		std::string name;

		/* Command Vars */
		f32 actionTime;					//amount of time left before next action
		f32 imageIndex;
		Direction direction;
		Attacking attacking;
};
/* initialize the character */
Enemy::Enemy()
{
	pos.X = 256/2;	//position on the map, feetwise
	pos.Y = 176/2;
	HP = 10; MHP = HP;
	ATT = 1; SPD = 50;
	attackType = "Melee";
	name = "none";
	actionTime = 0;					//amount of time left before next action
	direction = dir_Up;
	attacking = not_attacking;
	imageIndex = 0;
	hurtTimer = 0;
}
void Enemy::spawnRandomEnemy()
{
	int x = 16 + (rand() % 16) * 14;
	int y = 54 + 16 + (rand() % 16) * 8;
	std::string randName = "";
	switch(rand() % 6)
	{
		case 0:randName = "Octorock";break;
		case 1:randName = "Blue Octorock";break;
		case 2:randName = "Gremlin";break;
		case 3:randName = "Blue Gremlin";break;
		case 4:randName = "Moblin";break;
		case 5:randName = "Blue Moblin";break;
	}
	if(placeClear((irr::f32)x, (irr::f32)y) == true)
		{spawnEnemy(randName, x,y);}
}
/* Create an enemy at one location. */
void Enemy::spawnEnemy(std::string enemyName, int x, int y)
{
	name = enemyName;
	pos.X = (irr::f32)x;
	pos.Y = (irr::f32)y;
	hurtTimer = 0;
	if(name.compare("Octorock") == 0)
		{HP = 10; ATT = 1; SPD = 50;attackType = "Rock";}
	else if(name.compare("Blue Octorock") == 0)
		{HP = 20; ATT = 2; SPD = 70;attackType = "Rock";}
	else if(name.compare("Gremlin") == 0)
		{HP = 20; ATT = 2; SPD = 60;attackType = "Melee";}
	else
		{name = "none";}
}
/* Ensures that one is alowed to move somewhere and does it. */
bool Enemy::move(Direction dir)
{
	switch(dir)
	{
		case dir_Up:
			if(placeClear(pos.X,pos.Y - SPD * frameDT)){pos.Y -= SPD * frameDT;return true;}
		break;
		case dir_Down:
			if(placeClear(pos.X,pos.Y + SPD * frameDT)){pos.Y += SPD * frameDT;return true;}
		break;
		case dir_Right:
			if(placeClear(pos.X + SPD * frameDT,pos.Y)){pos.X += SPD * frameDT;return true;}
		break;
		case dir_Left:
			if(placeClear(pos.X - SPD * frameDT,pos.Y)){pos.X -= SPD * frameDT;return true;}
		break;
	}
	return false;
}
/* Check all caps and fix them */
void Enemy::checkCaps()
{
	if(HP > MHP) {
		HP = (int)(MHP);}
	if(HP < 0) {
		HP = 0;
		name = "none";}
}

/* Standard battle cycle */
void Enemy::battleCycle()
{
	if(name.compare("") == 0){return;}	//if there is no enemy name, LEAVE
	if(hurtTimer > 0){hurtTimer -= 100*frameDT;return;}
	int decide = rand();  //randomize the decision making
	checkCaps();  //check caps for stats, including death check
	if(attacking == not_attacking) //mobile only if not attacking
	{
		/*==========================Run =============================*/
		//change movement only by chance
		switch(decide % 100){
			case 0: direction = dir_Up; break;
			case 1: direction = dir_Right; break;
			case 2: direction = dir_Down; break;
			case 3: direction = dir_Left; break;}

		//dont walk only by chance
		if(rand() % 100 > 3){
			imageIndex += 1;
			move(direction);}

		/*========================== Attack ==========================*/
		if(rand() % 200 < 3)
		{
			imageIndex = 0;
			actionTime = 64;
			attacking = is_attacking;
			engine->play2D("FLT/sfx/Rock.wav", false);
			requestAttack(pos.X, pos.Y,
				"Rock",ATT,"Enemy", direction);
		}
	}
	else  //attacking phase
	{
		/*========================== Attacking ==========================*/
		if(actionTime <= 0)  //done attacking, lets go home
			{attacking = not_attacking;}
		else
			{actionTime -= 100*frameDT;}
	}
}

#endif