#ifndef ENUMS_H
#define ENUMS_H

/* Irrlicht includes */
#include <irrlicht.h>
#include <irrKlang.h>
#pragma comment(lib, "irrKlang.lib")
#include "driverChoice.h"
using namespace irr;
#ifdef _MSC_VER
#pragma comment(lib, "Irrlicht.lib")
#endif

//constants
const core::rect<s32> ta_Null(0, 0, 1, 1);

const core::rect<s32> ta_Dirt(0, 0, 16, 16);
const core::rect<s32> ta_Grass(16, 0, 16*2, 16);
const core::rect<s32> ta_Concrete(16*2, 0, 16*3, 16);
const core::rect<s32> ta_StoneConcrete(16*3, 0, 16*4, 16);
const core::rect<s32> ta_RockGround(16*4, 0, 16*5, 16);
const core::rect<s32> ta_Shadow(16*5, 0, 16*6, 16);

const core::rect<s32> ta_Grave	(16*0, 16, 16*1, 16*2);
const core::rect<s32> ta_DarkGrave(16*1, 16, 16*2, 16*2);
const core::rect<s32> ta_Bush		(16*2, 16, 16*3, 16*2);
const core::rect<s32> ta_BrownBush(16*3, 16, 16*4, 16*2);
const core::rect<s32> ta_Rock		(16*4, 16, 16*5, 16*2);
const core::rect<s32> ta_BrownRock(16*5, 16, 16*6, 16*2);

const core::rect<s32> ta_Armos(16*0, 16*2, 16*0, 16*3);
const core::rect<s32> ta_WhiteArmos(16*1, 16*2, 16*1, 16*3);
const core::rect<s32> ta_BrownArmos(16*2, 16*2, 16*2, 16*3);

const core::rect<s32> ta_Dock(16*0, 16*3, 16*1, 16*4);
const core::rect<s32> ta_Stairs(16*1, 16*3, 16*2, 16*4);
const core::rect<s32> ta_Ladder(16*2, 16*3, 16*3, 16*4);

const core::rect<s32> ta_Tree(16*0, 16*4, 16*2, 16*6);
const core::rect<s32> ta_DeadTree(16*2, 16*4, 16*4, 16*6);

const core::rect<s32> ta_Entrance(16*0, 16*6, 16*3, 16*8);

const core::rect<s32> ta_Waterfall(16*0, 16*8, 16*1, 16*10);

const core::rect<s32> ta_Mountain(16*1, 16*12, 16*2, 16*13);



//enums
enum Direction
{
	dir_Right = 0,
	dir_Left = 1,
	dir_Up = 2,
	dir_Down = 3
};

enum Attacking
{
    not_attacking = 0,
    is_attacking = 1
};

//CONTORL ENUMS
enum PressType
{
	PressType_NotHeld = 0,
	PressType_Press = 1,
	PressType_Held = 2,
	PressType_Released = 3
};
enum ControlType
{
	CtrlType_Keyboard = 0,
	CtrlType_Mouse = 1,
	CtrlType_Gamepad = 2,
	CtrlType_Null = 3
};
enum Control
{
	Ctrl_Up = 0,
	Ctrl_Right = 1,
	Ctrl_Down = 2,
	Ctrl_Left = 3,
	Ctrl_A = 4,
	Ctrl_B = 5,
	Ctrl_Y = 6,
	Ctrl_X = 7,
	Ctrl_L = 8,
	Ctrl_R = 9,
	Ctrl_ZL = 10,
	Ctrl_ZR = 11,
	Ctrl_Start = 12,
	Ctrl_Select = 13
};
struct ControlSet
{
	ControlType ctrlType;
	unsigned char keys[14];
	int button[14];
	int ctrlDown[14];
};

//structures
struct Tile
{
	bool passable;					//can walk on or attack
	core::rect<s32> address;	//contains the x,y placement of the tile on the bmp
};

struct Attack
{
	irr::f32 x;				//left most position of damage box
	irr::f32 y;				//upper most position of damage box
	int width;			//add this to x and you get right most position
	int height;		//add this to y and you get bottom most position
	std::string type;	//type of attack, like melee or shot
	std::string team;	//team name to diffentiate between good/bad
	core::rect<s32> gfxPos;//graphic position on tilesheet
	f32 time;			//time remaining for damage
	int ATT;			//damage to do
	f32 SPD;
	Direction dir;
};

//globals
Attack attackSet[20];
Tile map[16][11];
irrklang::ISoundEngine* engine;
u32 time;
f32 frameDT;

//Functions
/* Reset the map back to null data */
void setMap(int i, core::rect<s32> ta1, core::rect<s32> ta2, core::rect<s32> ta3, core::rect<s32> ta4,
					core::rect<s32> ta5, core::rect<s32> ta6, core::rect<s32> ta7, core::rect<s32> ta8,
					core::rect<s32> ta9, core::rect<s32> ta10, core::rect<s32> ta11, core::rect<s32> ta12,
					core::rect<s32> ta13, core::rect<s32> ta14, core::rect<s32> ta15, core::rect<s32> ta16)
{
	map[0][i].address = ta1;
	map[1][i].address = ta2;
	map[2][i].address = ta3;
	map[3][i].address = ta4;

	map[4][i].address = ta5;
	map[5][i].address = ta6;
	map[6][i].address = ta7;
	map[7][i].address = ta8;

	map[8][i].address = ta9;
	map[9][i].address = ta10;
	map[10][i].address = ta11;
	map[11][i].address = ta12;

	map[12][i].address = ta13;
	map[13][i].address = ta14;
	map[14][i].address = ta15;
	map[15][i].address = ta16;
}

/* Reset the map back to null data */
void setMapPasses(int i, bool ta1, bool ta2, bool ta3, bool ta4,
					bool ta5, bool ta6, bool ta7, bool ta8,
					bool ta9, bool ta10, bool ta11, bool ta12,
					bool ta13, bool ta14, bool ta15, bool ta16)
{
	map[0][i].passable = ta1;
	map[1][i].passable = ta2;
	map[2][i].passable = ta3;
	map[3][i].passable = ta4;

	map[4][i].passable = ta5;
	map[5][i].passable = ta6;
	map[6][i].passable = ta7;
	map[7][i].passable = ta8;

	map[8][i].passable = ta9;
	map[9][i].passable = ta10;
	map[10][i].passable = ta11;
	map[11][i].passable = ta12;

	map[12][i].passable = ta13;
	map[13][i].passable = ta14;
	map[14][i].passable = ta15;
	map[15][i].passable = ta16;
}

//return the map top all null values
void resetMap()
{
	for(int i = 0;i < 16;i++)
	{
		for(int j = 0;j < 11;j++)
		{
			map[i][j].address = ta_Null;
			map[i][j].passable = true;
		}
	}
}

//Owned by http://www.cplusplus.com/forum/articles/3638/
double round( double value )
{
  return floor( value + 0.5 );
}

//ensure the map has proper passes
void fixMapPasses()
{
	for(int x = 0;x < 16;x++)
	{
		for(int y = 0;y < 11;y++)
		{
			if(map[x][y].address == ta_Dirt || 
				map[x][y].address == ta_Dock || 
				map[x][y].address == ta_Entrance || 
				map[x][y].address == ta_Grass || 
				map[x][y].address == ta_Ladder || 
				map[x][y].address == ta_Null || 
				map[x][y].address == ta_RockGround || 
				map[x][y].address == ta_Shadow || 
				map[x][y].address == ta_Stairs || 
				map[x][y].address == ta_StoneConcrete)
					{map[x][y].passable = true;}
			else
				{map[x][y].passable = false;}
		}
	}
}

//transition to another map
void mapGoTo(int x, int y)
{
	resetMap();
	if(x == 0 && y == 0)
	{
		setMap(0, ta_Mountain     ,	ta_Mountain,	ta_Mountain,	ta_Mountain,	ta_Mountain,	ta_Mountain,	ta_Mountain,	ta_Mountain,	ta_Mountain,	ta_Mountain,	ta_Mountain,	ta_Mountain,	ta_Mountain,	ta_Mountain,	ta_Mountain,	ta_Mountain);
		setMap(1, ta_Mountain, ta_Mountain, ta_Entrance, ta_Null,   ta_Null, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Mountain, ta_Mountain);
		setMap(2, ta_Mountain, ta_Mountain, ta_Null, ta_Null,   ta_Null, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Mountain, ta_Mountain);
		setMap(3, ta_Mountain, ta_Mountain, ta_Dirt, ta_Dirt,   ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Mountain, ta_Mountain);
		setMap(4, ta_Mountain, ta_Mountain, ta_Dirt, ta_Dirt,   ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Mountain, ta_Mountain);
		setMap(5, ta_Mountain, ta_Mountain, ta_Dirt, ta_Dirt,   ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Grass        , ta_Grass        );
		setMap(6, ta_Mountain, ta_Mountain, ta_Dirt, ta_Dirt,   ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Grass        , ta_Grass        );
		setMap(7, ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     );
		setMap(8, ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     );
		setMap(9, ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     );
		setMap(10,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     );
	}
	else if(x == 1 && y == 0)
	{
		setMap(0, ta_Mountain,	ta_Mountain,	ta_Mountain,	ta_Mountain,	ta_Mountain,	ta_Mountain,	ta_Mountain,	ta_Mountain,	ta_Mountain,	ta_Mountain,	ta_Mountain,	ta_Mountain,	ta_Mountain,	ta_Mountain,	ta_Mountain,	ta_Mountain);
		setMap(1, ta_Mountain, ta_Mountain, ta_Entrance, ta_Null,   ta_Null, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Mountain, ta_Mountain);
		setMap(2, ta_Mountain, ta_Mountain, ta_Null, ta_Null,   ta_Null, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Mountain, ta_Mountain);
		setMap(3, ta_Mountain, ta_Mountain, ta_Dirt, ta_Dirt,   ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Mountain, ta_Mountain);
		setMap(4, ta_Mountain, ta_Mountain, ta_Dirt, ta_Dirt,   ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Mountain, ta_Mountain);
		setMap(5, ta_Grass        , ta_Mountain,ta_Mountain     , ta_Dirt,   ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Dirt, ta_Dirt);
		setMap(6, ta_Grass        , ta_Mountain,ta_Mountain     , ta_Dirt,   ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Dirt, ta_Dirt);
		setMap(7, ta_Mountain, ta_Mountain,ta_Mountain     , ta_Dirt,   ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Mountain, ta_Mountain);
		setMap(8, ta_Mountain, ta_Mountain, ta_Dirt, ta_Dirt,   ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Mountain, ta_Mountain);
		setMap(9, ta_Mountain, ta_Mountain, ta_Dirt, ta_Dirt,   ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Mountain, ta_Mountain);
		setMap(10,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     );
	}
	else if(x == 2 && y == 0)
	{
		setMap(0, ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    );
		setMap(1, ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_BrownRock    );
		setMap(2, ta_Mountain     ,ta_Dirt         ,ta_BrownRock    ,ta_Dirt         ,ta_BrownRock    ,ta_Dirt         ,ta_Dirt         ,ta_BrownRock    ,ta_Dirt         ,ta_BrownRock    ,ta_Dirt         ,ta_RockGround   ,ta_RockGround   ,ta_BrownRock    ,ta_RockGround   ,ta_BrownRock    );
		setMap(3, ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_BrownRock    );
		setMap(4, ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_BrownRock    ,ta_Dirt         ,ta_Dirt         ,ta_BrownRock    ,ta_Dirt         ,ta_RockGround   ,ta_RockGround   ,ta_BrownRock    ,ta_RockGround   ,ta_BrownRock    ,ta_BrownRock    );
		setMap(5, ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_BrownRock    ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_BrownRock    ,ta_Dirt         ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   );
		setMap(6, ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_BrownRock    ,ta_Dirt         ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_BrownRock    ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   );
		setMap(7, ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_RockGround   ,ta_RockGround   ,ta_BrownRock    ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_BrownRock    ,ta_BrownRock    );
		setMap(8, ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_BrownRock    ,ta_Dirt         ,ta_Dirt         ,ta_BrownRock    ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_BrownRock    ,ta_RockGround   ,ta_RockGround   ,ta_BrownRock    );
		setMap(9, ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_BrownRock    );
		setMap(10,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_RockGround   ,ta_RockGround   ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    );
	}
	else if(x == 3 && y == 0)
	{
		setMap(0, ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    );
		setMap(1, ta_BrownRock    ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_BrownRock    );
		setMap(2, ta_BrownRock    ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_BrownRock    );
		setMap(3, ta_BrownRock    ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_BrownRock    );
		setMap(4, ta_BrownRock    ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_BrownRock    );
		setMap(5, ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_BrownRock    );
		setMap(6, ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_BrownRock    );
		setMap(7, ta_BrownRock    ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_BrownRock    );
		setMap(8, ta_BrownRock    ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_BrownRock    );
		setMap(9, ta_BrownRock    ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_BrownRock    );
		setMap(10,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_RockGround   ,ta_RockGround   ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    );
	}
	else if(x == 4 && y == 0)
	{
		setMap(0, ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    );
		setMap(1, ta_BrownRock    ,ta_BrownBush    ,ta_RockGround   ,ta_RockGround   ,ta_BrownBush    ,ta_RockGround   ,ta_RockGround   ,ta_BrownBush    ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_BrownBush    ,ta_BrownRock    );
		setMap(2, ta_BrownRock    ,ta_RockGround   ,ta_BrownBush    ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_BrownBush    ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_BrownRock    );
		setMap(3, ta_BrownRock    ,ta_RockGround   ,ta_RockGround   ,ta_BrownBush    ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_BrownBush    ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_BrownBush    ,ta_BrownRock    );
		setMap(4, ta_BrownRock    ,ta_RockGround   ,ta_BrownBush    ,ta_RockGround   ,ta_BrownBush    ,ta_RockGround   ,ta_RockGround   ,ta_BrownBush    ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_BrownBush    ,ta_BrownRock    );
		setMap(5, ta_BrownRock    ,ta_BrownBush    ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_BrownBush    ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   );
		setMap(6, ta_BrownRock    ,ta_RockGround   ,ta_BrownBush    ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_BrownBush    ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   );
		setMap(7, ta_BrownRock    ,ta_RockGround   ,ta_RockGround   ,ta_BrownBush    ,ta_RockGround   ,ta_RockGround   ,ta_BrownBush    ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_BrownBush    ,ta_BrownRock    );
		setMap(8, ta_BrownRock    ,ta_RockGround   ,ta_BrownBush    ,ta_RockGround   ,ta_RockGround   ,ta_BrownBush    ,ta_RockGround   ,ta_BrownBush    ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_BrownRock    );
		setMap(9, ta_BrownRock    ,ta_BrownBush    ,ta_RockGround   ,ta_RockGround   ,ta_BrownBush    ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_BrownBush    ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_RockGround   ,ta_BrownBush    ,ta_BrownRock    );
		setMap(10,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_RockGround   ,ta_RockGround   ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    ,ta_BrownRock    );
	}
	else if(x == 0 && y == 1)
	{
		setMap(0,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     );
		setMap(1, ta_Mountain, ta_Mountain, ta_Entrance, ta_Null,   ta_Null, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Mountain, ta_Mountain);
		setMap(2, ta_Mountain, ta_Mountain, ta_Null, ta_Null,   ta_Null, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Mountain, ta_Mountain);
		setMap(3, ta_Mountain, ta_Mountain, ta_Dirt, ta_Dirt,   ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Mountain, ta_Mountain);
		setMap(4, ta_Mountain, ta_Mountain, ta_Dirt, ta_Dirt,   ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Mountain, ta_Mountain);
		setMap(5, ta_Mountain, ta_Mountain, ta_Dirt, ta_Dirt,   ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Dirt, ta_Dirt);
		setMap(6, ta_Mountain, ta_Mountain, ta_Dirt, ta_Dirt,   ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Dirt, ta_Dirt);
		setMap(7, ta_Mountain, ta_Mountain, ta_Dirt, ta_Dirt,   ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Mountain, ta_Mountain);
		setMap(8, ta_Mountain, ta_Mountain, ta_Dirt, ta_Dirt,   ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Mountain, ta_Mountain);
		setMap(9, ta_Mountain, ta_Mountain, ta_Dirt, ta_Dirt,   ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Mountain, ta_Mountain);
		setMap(10,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     );
	}
	else if(x == 1 && y == 1)
	{
		setMap(0, ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     );
		setMap(1, ta_Mountain, ta_Mountain, ta_Mountain, ta_Mountain,   ta_Mountain, ta_Dirt,	   ta_Dirt, ta_Dirt, ta_Dirt, ta_Dirt,      ta_Dirt, ta_Mountain,  ta_Mountain, ta_Mountain, ta_Mountain, ta_Mountain);
		setMap(2, ta_Mountain, ta_Mountain, ta_Mountain, ta_Mountain,   ta_Dirt    , ta_Dirt,      ta_Dirt, ta_Dirt, ta_Dirt, ta_Dirt,  ta_Dirt    , ta_Dirt,      ta_Mountain, ta_Mountain, ta_Mountain, ta_Mountain);
		setMap(3, ta_Mountain, ta_Mountain, ta_Mountain, ta_Mountain,   ta_Dirt    , ta_Dirt,      ta_Dirt, ta_Dirt, ta_Dirt, ta_Dirt,  ta_Dirt    , ta_Dirt    ,  ta_Mountain, ta_Mountain, ta_Mountain, ta_Mountain);
		setMap(4, ta_Mountain, ta_Mountain     , ta_Dirt, ta_Dirt,   ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Dirt, ta_Mountain);
		setMap(5, ta_Grass        , ta_Mountain     , ta_Dirt, ta_Dirt,   ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Dirt, ta_Dirt         );
		setMap(6, ta_Grass        , ta_Mountain     , ta_Dirt, ta_Dirt,   ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Dirt, ta_Dirt         );
		setMap(7, ta_Mountain, ta_Mountain     , ta_Dirt, ta_Dirt,   ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Dirt, ta_Mountain);
		setMap(8, ta_Mountain, ta_Mountain     , ta_Dirt, ta_Dirt,   ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt,  ta_Dirt, ta_Dirt, ta_Dirt, ta_Mountain);
		setMap(9, ta_Mountain, ta_Mountain, ta_Mountain, ta_Mountain,   ta_Mountain, ta_Mountain,  ta_Dirt, ta_Dirt, ta_Dirt, ta_Dirt,  ta_Mountain, ta_Mountain,  ta_Mountain, ta_Mountain, ta_Mountain, ta_Mountain);
		setMap(10,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     );
	}
	else if(x == 2 && y == 1)
	{
		setMap(0, ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     );
		setMap(1, ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     );
		setMap(2, ta_Mountain     ,ta_Dirt         ,ta_Mountain     ,ta_Mountain     ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         ,ta_Mountain     ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     );
		setMap(3, ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     );
		setMap(4, ta_Mountain     ,ta_Mountain     ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     );
		setMap(5, ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         );
		setMap(6, ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         );
		setMap(7, ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Mountain     );
		setMap(8, ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     );
		setMap(9, ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     );
		setMap(10,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     );
	}
	else if(x == 3 && y == 1)
	{
		setMap(0, ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     );
		setMap(1, ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     );
		setMap(2, ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     );
		setMap(3, ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     );
		setMap(4, ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     );
		setMap(5, ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         );
		setMap(6, ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         );
		setMap(7, ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     );
		setMap(8, ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     );
		setMap(9, ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     );
		setMap(10,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     );
	}
	else if(x == 4 && y == 1)
	{
		setMap(0, ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     );
		setMap(1, ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     );
		setMap(2, ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     );
		setMap(3, ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     );
		setMap(4, ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Mountain     );
		setMap(5, ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         );
		setMap(6, ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         );
		setMap(7, ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Mountain     );
		setMap(8, ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     );
		setMap(9, ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     );
		setMap(10,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     );
	}
	else if(x == 0 && y == 2)
	{
		setMap(0, ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         );
		setMap(1, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(2, ta_Bush         ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(3, ta_Bush         ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(4, ta_Bush         ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(5, ta_Bush         ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        );
		setMap(6, ta_Bush         ,ta_Grass        ,ta_Bush         ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        );
		setMap(7, ta_Bush         ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(8, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(9, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(10,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         );
	}
	else if(x == 1 && y == 2)
	{
		setMap(0, ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         );
		setMap(1, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(2, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(3, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Bush         );
		setMap(4, ta_Bush         ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(5, ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        );
		setMap(6, ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        );
		setMap(7, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(8, ta_Bush         ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Bush         );
		setMap(9, ta_Bush         ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(10,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         );
	}
	else if(x == 2 && y == 2)
	{
		setMap(0, ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         );
		setMap(1, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(2, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(3, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(4, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(5, ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        );
		setMap(6, ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        );
		setMap(7, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(8, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(9, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(10,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         );
	}
	else if(x == 0 && y == 3)
	{
		setMap(0, ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         );
		setMap(1, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(2, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(3, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(4, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(5, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(6, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(7, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(8, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(9, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(10,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         );
	}
	else if(x == 1 && y == 3)
	{
		setMap(0, ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         );
		setMap(1, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(2, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(3, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(4, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(5, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        );
		setMap(6, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        );
		setMap(7, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(8, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(9, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(10,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         );
	}
	else if(x == 2 && y == 3)
	{
		setMap(0, ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         );
		setMap(1, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(2, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(3, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(4, ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(5, ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        );
		setMap(6, ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        );
		setMap(7, ta_Bush         ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_DeadTree     ,ta_Null         ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(8, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Null         ,ta_Null         ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(9, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(10,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         );
	}
	else if(x == 3 && y == 3)
	{
		setMap(0, ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         );
		setMap(1, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(2, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(3, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(4, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(5, ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        );
		setMap(6, ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        );
		setMap(7, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(8, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(9, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(10,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         );
	}
	else if(x == 3 && y == 4)
	{
		setMap(0, ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Dirt         ,ta_Dirt         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         );
		setMap(1, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(2, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(3, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(4, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(5, ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        );
		setMap(6, ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        );
		setMap(7, ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(8, ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(9, ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(10,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         );
	}
	else if(x == 4 && y == 4)
	{
		setMap(0, ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         );
		setMap(1, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Bush         );
		setMap(2, ta_Bush         ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(3, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(4, ta_Bush         ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Bush         );
		setMap(5, ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        );
		setMap(6, ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        );
		setMap(7, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(8, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Bush         );
		setMap(9, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Grass        ,ta_Bush         );
		setMap(10,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         );
	}
	else if(x == 5 && y == 5)
	{
		setMap(0, ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         );
		setMap(1, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(2, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(3, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(4, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(5, ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        );
		setMap(6, ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        );
		setMap(7, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(8, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(9, ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Grass        ,ta_Bush         );
		setMap(10,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Grass        ,ta_Grass        ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         ,ta_Bush         );
	}
	else if(x == 0)
	{
		setMap(0, ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     );
		setMap(1, ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     );
		setMap(2, ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     );
		setMap(3, ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     );
		setMap(4, ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     );
		setMap(5, ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         );
		setMap(6, ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         );
		setMap(7, ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     );
		setMap(8, ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     );
		setMap(9, ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     );
		setMap(10,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     );
	}
	else if(y == 0)
	{
		setMap(0, ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     );
		setMap(1, ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     );
		setMap(2, ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     );
		setMap(3, ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     );
		setMap(4, ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     );
		setMap(5, ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         );
		setMap(6, ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         );
		setMap(7, ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     );
		setMap(8, ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     );
		setMap(9, ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     );
		setMap(10,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     );
	}
	else
	{
		setMap(0, ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     );
		setMap(1, ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     );
		setMap(2, ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     );
		setMap(3, ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     );
		setMap(4, ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     );
		setMap(5, ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         );
		setMap(6, ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         );
		setMap(7, ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     );
		setMap(8, ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     );
		setMap(9, ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     );
		setMap(10,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Dirt         ,ta_Dirt         ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     ,ta_Mountain     );
	}
	fixMapPasses();
}

//check if map allows you to pass
bool placeClear(irr::f32 x, irr::f32 y)
{
	if((int)round((x) / 16) < 0) {return true;}
	if((int)round((x) / 16) > 16) {return true;}
	if((int)round((y - 54) / 16) < 0) {return true;}
	if((int)round((y - 54) / 16) > 10) {return true;}

	if(map[(int)floor((x-6) / 16)][(int)ceil((y - 54-10) / 16)].passable == false){return false;}
	if(map[(int)ceil((x-10) / 16)][(int)floor((y - 54-6) / 16)].passable == false){return false;}
	if(map[(int)floor((x-6) / 16)][(int)floor((y - 54-6) / 16)].passable == false){return false;}
	if(map[(int)ceil((x-10) / 16)][(int)ceil((y - 54-10) / 16)].passable == false){return false;}

	return map[(int)round((x-8) / 16)][(int)round((y - 54-8) / 16)].passable;
}

//string functions to assist in conversion from IRR strings to std strings
irr::core::stringw addString(irr::core::stringw str1, irr::core::stringw str2)
{
	return (irr::core::stringw)(str1 + str2);
}
irr::core::stringw addString(irr::core::stringw str1, int str2)
{
	return (irr::core::stringw)(str1 + ((irr::core::stringw) str2));
}
void convertStringToChar(char * filePath, std::string strn1, std::string strn2, std::string strn3)
{
	strn2 = strn2.append(strn3);
	strn1 = strn1.append(strn2);
	for(int i = 0;i < 256;i++)//dump it into a char array
	{
		filePath[i] = strn1[i];
	}
	std::cout << "Current Filename:" << filePath << std::endl;
}
irr::core::stringw stringToIrr(std::string strn1)
{
	char arr[256];
	for(int i = 0;i < 256;i++)//dump it into a char array
	{
		arr[i] = strn1[i];
	}
	irr::core::stringw result;
	result = arr;
	return result;
}

//continue lowering times for attacks
void maintainAttackSet()
{
	for(int i = 0;i < 20;i++)
	{
		if(attackSet[i].time > 0) 
		{
			if(attackSet[i].SPD > 0)
			{
				switch(attackSet[i].dir)
				{
					case dir_Up:
						attackSet[i].y -= attackSet[i].SPD * frameDT;
					break;
					case dir_Down:
						attackSet[i].y += attackSet[i].SPD * frameDT;
					break;
					case dir_Right:
						attackSet[i].x += attackSet[i].SPD * frameDT;
					break;
					case dir_Left:
						attackSet[i].x -= attackSet[i].SPD * frameDT;
					break;
				}
			}
			attackSet[i].time -= 100*frameDT;
		}
	} 
}

//allows players and enemies to request attacks
void requestAttack(irr::f32 posX,irr::f32 posY,std::string name,int ATT,std::string team, Direction dir)
{
	int i = 0;for(i = 0;attackSet[i].time > 0 && i < 20;i++){} //find a free place
	if(i == 20){std::cout << "attack full!\n";return;} //failed to find a free place
	attackSet[i].x = posX - (dir==dir_Left) * 20 + (dir==dir_Right) * 20;				//left most position of damage box
	attackSet[i].y = posY + (dir==dir_Down) * 20 - (dir==dir_Up) * 20;				//upper most position of damage box
	attackSet[i].width = 20;			//add this to x and you get right most position
	attackSet[i].height = 20;			//add this to y and you get bottom most position
	attackSet[i].type = name;	//type of attack, like melee or shot
	attackSet[i].team = team;	//team name to diffentiate between good/bad
	if(name.compare("Sword") == 0)
	{
		attackSet[i].gfxPos = core::rect<s32> (0,0, 20,20);//graphic position on tilesheet
		attackSet[i].time = 32;	
		attackSet[i].SPD = 0;			//damage to do
	}
	else if(name.compare("Rock") == 0)
	{
		attackSet[i].gfxPos = core::rect<s32> (20,0, 40,20);//graphic position on tilesheet
		attackSet[i].time = 64;	
		attackSet[i].SPD = 80;			//damage to do
	}
	attackSet[i].ATT = ATT;			//damage to do
	attackSet[i].dir = dir;			//damage to do
}

//intialize all attacks
void initAttackSet()
{
	for(int i = 0; i < 20; i ++)
	{
		requestAttack(-1,-1, "none", 0, "none", dir_Up);
		attackSet[i].gfxPos = core::rect<s32> (0,0, 24,24);
		attackSet[i].time = -1;	
		attackSet[i].SPD = 0;
	}
}

//check for a single collision between 2 rectangles
bool collides(f32 x1,f32 y1,f32 x2,f32 y2, f32 xA,f32 yA,f32 xB,f32 yB)
{
	if (y2 < yA) return(false);
    if (y1 > yB) return(false);

    if (x2 < xA) return(false);
    if (x1 > xB) return(false);

	return true;
}

//dumps a random string of code onto the user
std::string randomCode()
{
	switch(rand() % 43)
	{
		case 0: return "[bin] "; break;
		case 1: return "[num] "; break;
		case 2: return "[txt] "; break;
		case 3: return "[safe] "; break;
		case 4: return "[locked] "; break;
		case 5: return "[unlocked] "; break;
		case 6: return "[doubleLocked] "; break;
		case 7: return "[childProofLock] "; break;
		case 8: return "[list] "; break;
		case 9: return "[table] "; break;
		case 10: return "[stack] "; break;
		case 11: return "[tree] "; break;
		case 12: return "[heap] "; break;
		case 13: return "[queue] "; break;
		case 14: return "[trie] "; break;
		case 15: return "[web] "; break;
		case 16: return ";"; break;
		case 17: return "("; break;
		case 18: return ")"; break;
		case 19: return ", "; break;
		case 20: return " + "; break;
		case 21: return " - "; break;
		case 22: return " * "; break;
		case 23: return " / "; break;
		case 24: return " = "; break;
		case 25: return " < "; break;
		case 26: return " > "; break;
		case 27: return "."; break;
		case 28: return "RETURN "; break;
		case 29: return "DATA "; break;
		case 30: return "PRINT "; break;
		case 31: return "END "; break;
		case 32: return "INITIALIZE "; break;
		case 33: return "CLASS "; break;
		case 34: return "FUNCTION "; break;
		case 35: return "carriage return"; break;
		case 36: return "var1"; break;
		case 37: return "var2"; break;
		case 38: return "var3"; break;
		case 39: return "var4"; break;
		case 40: return "var5"; break;
		case 41: return "var6"; break;
		case 42: return "var7"; break;
	}
	return " ";
}
#endif