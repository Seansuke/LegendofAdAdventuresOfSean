#ifndef CHARA_H
#define CHARA_H

/* Irrlicht includes */
#include <irrlicht.h>
#include "driverChoice.h"
using namespace irr;
#ifdef _MSC_VER
#pragma comment(lib, "Irrlicht.lib")
#endif

/* Personal Includes */
#include "include\enums.h"
#include "include\controls.h"

/* define the header for the class */
class Player
{
	public:
		/* Basic Functions */
		Player();	//basic constructor
		void battleCycle();				//do a common cycle of battle
		void checkCaps();				//ensure all caps on the stats are ok and fix them
		irr::core::stringw getMoney();  //return the amount of money as a string
		bool move(Direction dir);

		/* Map Vars */
		core::position2d<f32> pos;	//position on the map, feetwise

		/* Stats Vars */
		int HP; int MHP;
		int ATT; int DEF; int SPD;
		int money;

		/* Command Vars */
		f32 actionTime;					//amount of time left before next action
		f32 imageIndex;
		Direction direction;
		Attacking attacking;
		Controller ctrl;				//current controller state
		int mapX;						//longitude
		int mapY;						//latitude
		f32 hurtTimer;

		/* Control functions */
		bool Press(Control control);		//check to see if a control is being pressed
		bool Held(Control control);			//check to see if a control is being held
		bool Released(Control control);		//check to see if a control is being released
};
/* initialize the character */
Player::Player()
{
	pos.X = 256/2;	//position on the map, feetwise
	pos.Y = 176/2;

	HP = 30; 
	MHP = 30;
	ATT = 5; 
	DEF = 0; 
	SPD = 100;
	money = 0;
	hurtTimer = 0;

	actionTime = 0;					//amount of time left before next action
	direction = dir_Up;
	attacking = not_attacking;
	Controller ctrl;				//current controller state
	imageIndex = 0;

	mapX = 0;
	mapY = 0;
}

/* Check all caps and fix them */
void Player::checkCaps()
{
	if(HP > MHP) {
		HP = (int)(MHP);}
	if(HP < 0) {
		HP = 0;}
	if(money > 255){
		money = 255;}
}
/* Returns the amount of money as an Irrlicht string */
irr::core::stringw Player::getMoney()
{
	return (irr::core::stringw)(money);
}
/* Ensures that one is alowed to move somewhere and does it. */
bool Player::move(Direction dir)
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

/* All control functions */
bool Player::Press(Control control)
{
	return ctrl.press(1, control);
}
bool Player::Held(Control control)
{
	return ctrl.held(1, control);
}
bool Player::Released(Control control)
{
	return ctrl.released(1, control);
}

/* Standard battle cycle */
void Player::battleCycle()
{
	if(hurtTimer > 0){hurtTimer -= 100*frameDT;}
	checkCaps();
	if(attacking == not_attacking)
	{
		/*========================== Run =============================*/
		//horizontal movement
		if(Held(Ctrl_Right))
		{
			direction = dir_Right;
			imageIndex += 100*frameDT;
			move(direction);
		}
		else if(Held(Ctrl_Left))
		{
			direction = dir_Left;
			imageIndex += 100*frameDT;
			move(direction);
		}

		//vertical movement
		if(Held(Ctrl_Up))
		{
			direction = dir_Up;
			imageIndex += 100*frameDT;
			move(direction);
		}
		else if(Held(Ctrl_Down))
		{
			direction = dir_Down;
			imageIndex += 100*frameDT;
			move(direction);
		}
		
		/*========================== Attack ==========================*/
		if(Press(Ctrl_A) == true)
		{
			imageIndex = 0;
			actionTime = 32;
			attacking = is_attacking;
			engine->play2D("FLT/sfx/Sword.wav", false);
			requestAttack(pos.X, pos.Y,
				"Sword",ATT,"Player", direction);
		}
	}
	else
	{
		/*========================== Attacking ==========================*/
		if(actionTime <= 0)  //done attacking, lets go home
			{attacking = not_attacking;}
		else
			{actionTime -= 100*frameDT;}
	}
}
#endif