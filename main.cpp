/** The Legend of AD: Adventure of Sean **/

#include <irrlicht.h>
#include <irrKlang.h>
#pragma comment(lib, "irrKlang.lib")
#include "driverChoice.h"
using namespace irr;
#ifdef _MSC_VER
#pragma comment(lib, "Irrlicht.lib")
#endif

/* Personal Include */
#include "include\eventReceiver.h"
#include "include\chara.h"
#include "include\enemy.h"
#include "include\enums.h"
#include "include\controls.h"

static int MAX_ENEMY = 10;


int main()
{
	//environment init
	engine = irrklang::createIrrKlangDevice();	//sound driver
	if (!engine) return 0;	//failsafe
	MyEventReceiver receiver;	//create input receiver
	bool fullscreen = false;	//just setup the fullscreen mode
	video::E_DRIVER_TYPE driverType = irr::video::E_DRIVER_TYPE(5);		//driverChoiceConsole();  if wants a custom console type
	if (driverType==video::EDT_COUNT) return 1;							//failsafe for errors
	IrrlichtDevice *device = createDevice(driverType, core::dimension2d<u32>(640, 230), 16, fullscreen, false, false, &receiver);	//setup the drivertype, size of window, color bit amount,  fullscreen?, idk, idk, address of the input reciever
	if (device == 0) return 1;											// failsafe for errors
	device->setWindowCaption(L"The Legend of AD: Adventure of Sean");			//make the window look nice ^^
	video::IVideoDriver* driver = device->getVideoDriver();				//grab the video driver

	/* input til textures for drawing */
	video::ITexture* title_texture = driver->getTexture("FLT/gfx/title.png"); driver->makeColorKeyTexture(title_texture, core::position2d<s32>(0,0));
	video::ITexture* tileset_texture = driver->getTexture("FLT/gfx/tileset.png"); driver->makeColorKeyTexture(tileset_texture, core::position2d<s32>(0,0));
	video::ITexture* attack_texture = driver->getTexture("FLT/gfx/attacks.png"); driver->makeColorKeyTexture(attack_texture, core::position2d<s32>(0,0));
	video::ITexture* menu_texture = driver->getTexture("FLT/gfx/menu.png"); driver->makeColorKeyTexture(menu_texture, core::position2d<s32>(0,0));
	video::ITexture* sean_texture = driver->getTexture("FLT/gfx/sean.png"); driver->makeColorKeyTexture(sean_texture, core::position2d<s32>(0,0));
	video::ITexture* baddy_texture = driver->getTexture("FLT/gfx/baddy.png"); driver->makeColorKeyTexture(baddy_texture, core::position2d<s32>(0,0));
	video::ITexture* heart_texture = driver->getTexture("FLT/gfx/heart.png"); driver->makeColorKeyTexture(heart_texture , core::position2d<s32>(0,0));

	/* Fonts */
	gui::IGUIFont* font = device->getGUIEnvironment()->getBuiltInFont();
	gui::IGUIFont* font2 = device->getGUIEnvironment()->getFont("FLT/font/fonthaettenschweiler.bmp");

	//colors
	video::SColor color_normal = video::SColor(255,255,255,255);
	video::SColor color_red = video::SColor(255,255,0,0);

	/* Prepare a nicely filtering 2d render mode for special cases. */
	driver->getMaterial2D().TextureLayer[0].BilinearFilter=true;
	driver->getMaterial2D().AntiAliasing=video::EAAM_FULL_BASIC;

	//misc
	u32 then = device->getTimer()->getTime();  //get a timer to ensure proper frame-rate
	bool running = true;	//keep the game going
	engine->play2D("FLT/midi/Zelda - Title.it", true);	//play bgm

	//game time
	while(device->run() && driver && running == true)
	{
		if (device->isWindowActive() && running == true)
		{
			running = ! receiver.IsKeyDown(KEY_RETURN);
			/* Deal with cycle routines */
			driver->beginScene(true, true, video::SColor(255,255,255,255));	//open the scene
			driver->draw2DImage(title_texture, core::position2d<s32> (0, 0),  core::rect<s32> (0, 0, 335, 276), 0, color_normal, false);
			driver->endScene();	//end the drawing scene
		}
	}

	//game data init
	engine->stopAllSounds();
	engine->play2D("FLT/midi/Zelda - Overworld.it", true);	//play bgm
	initAttackSet();
	mapGoTo(0, 0);
	irr::EKEY_CODE keys1[14] = {KEY_UP,KEY_RIGHT,KEY_DOWN,KEY_LEFT, KEY_KEY_Z,KEY_KEY_X,KEY_KEY_C,KEY_BACK,   KEY_KEY_Q,KEY_KEY_W, KEY_KEY_1,KEY_KEY_2, KEY_KEY_C,KEY_KEY_V};	//create default keyboard keys
	int button1[14] = {0,0,0,0, 2,1,3,4, 5,7, 6,8, 9,10};	//create default gamepad keys
	Controller ctrl = Controller(); //create a player set of controllers
	ctrl.ControllerSet(1, CtrlType_Keyboard, keys1, button1);	//Player 1's keys are set.
	Player sean = Player();  //create the player
	Enemy enemys[10];  //create 10 possible enemies
	core::position2d<f32> heartPos(0, 0);
	core::position2d<f32> ruppeePos(0, 0);
	int ruppeeAmount = 0;
	core::position2d<f32> codePos(0, 0);
	std::string codeData = " ";
	std::string code[20];
	for(int i = 0;i < 20;i++) {code[i] = "";}
	code[0] = "main()";
	int cursor = 1;

	//game time
	running = true;	
	while(device->run() && driver && running == true)
	{
		if (device->isWindowActive() && running == true)
		{
			/* Deal with cycle routines */
			time = device->getTimer()->getTime();	// get the timer
			frameDT = (f32)(time - then) / 1000.f;	// Recieve how much change in time there has been
			then = time;	//recycle 'then' to find the change in time next while loop
			
			/* Ensure buttons are up to date */
			for(int j = 0;j < 255;j++)
			{
				if(receiver.IsKeyDown((irr::EKEY_CODE) j)) ctrl.handleKeypress((irr::EKEY_CODE) j, -1, -1);
				else ctrl.handleKeyrelease((irr::EKEY_CODE) j, -1, -1);
			}

			/*=================player control and enemy ==================*/
			sean.ctrl = ctrl;		//give the player the updated controls
			sean.battleCycle();	//ensure the player goes through the battle cycle
			for(int i = 0;i < 10;i++)
			{
				if(enemys[i].name.compare("none") != 0)
				{
					enemys[i].battleCycle();
				}
			}
			maintainAttackSet();

			if(ctrl.press(1, Ctrl_X) == true && code[cursor].size() > 0)
				{code[cursor] = code[cursor].substr(0,code[cursor].size() - 1);}//backspace some code

			/*=================player offscreen==================*/
			bool transition = false;
			if(sean.pos.X >= 16*16 - 8)
			{
				sean.mapX ++;
				sean.pos.X = 0*16 + 10;
				transition = true;
			}
			else if(sean.pos.X <= 0*16 + 8)
			{
				sean.mapX --;
				sean.pos.X = 16*16 - 10;
				transition = true;
			}
			else if(sean.pos.Y <= 54 + 0*16 + 8)
			{
				sean.mapY --;
				sean.pos.Y = 54 + 11*16 - 12;
				transition = true;
			}
			else if(sean.pos.Y >= 54 + 11*16 - 8)
			{
				sean.mapY ++;
				sean.pos.Y = 54 + 0*16 + 10;
				transition = true;
			}
			if(transition == true)
			{
				heartPos.X = 0;
				ruppeePos.X = 0;
				codePos.X = 0;
				mapGoTo(sean.mapX, sean.mapY);
				for(int i = rand() % 10;i > 0;i--)
					{enemys[i].spawnRandomEnemy();}
			}

			/*=================detect collision===================*/
			if(heartPos.X != 0)//heart collision
			{
				if(collides(sean.pos.X -8, sean.pos.Y -8,
							sean.pos.X +8, sean.pos.Y +8,
							heartPos.X -2, heartPos.Y -2,
							heartPos.X +2, heartPos.Y +2))
								{sean.HP += 10;heartPos.X = 0;engine->play2D("FLT/sfx/Heart.wav", false);}

			}
			if(ruppeePos.X != 0)//ruppee collision
			{
				if(collides(sean.pos.X -8,sean.pos.Y -8,
							sean.pos.X +8,sean.pos.Y +8,
							ruppeePos.X -2,ruppeePos.Y -2,
							ruppeePos.X +2,ruppeePos.Y +2))
								{sean.money += ruppeeAmount;ruppeePos.X = 0;engine->play2D("FLT/sfx/Cancel.wav", false);}

			}
			if(codePos.X != 0)//code collision
			{
				if(collides(sean.pos.X -8,sean.pos.Y -8,
							sean.pos.X +8,sean.pos.Y +8,
							codePos.X -2,codePos.Y -2,
							codePos.X +2,codePos.Y +2))
				{
					if(codeData.compare("carriage return") == 0)
						{cursor++;}
					else
						{code[cursor] = code[cursor].append(codeData);}
					codePos.X = 0;
					engine->play2D("FLT/sfx/Cursor.wav", false);
				}
			}
			for(int i = 0;i < 20;i++)//attacks collision
			{
				if(attackSet[i].time > 0)
				{
					for(int j = 0;j < 10;j++)
					{
						if(enemys[j].name.compare("none") != 0)
						{
							if(enemys[j].hurtTimer <= 0 && attackSet[i].team.compare("Player") == 0)
							{
								if(collides(	enemys[j].pos.X - 8, enemys[j].pos.Y - 8,
												enemys[j].pos.X + 8, enemys[j].pos.Y + 8,
												attackSet[i].x - 10, attackSet[i].y - 10,
												attackSet[i].x + 10, attackSet[i].y + 10))
								{
									enemys[j].HP -= attackSet[i].ATT;
									enemys[j].hurtTimer = attackSet[i].time;
									engine->play2D("FLT/sfx/Damage.wav", false);
									if(enemys[j].HP < 0)
									{
										switch(rand() % 5)
										{
											case 0: heartPos = core::position2d<f32>(enemys[j].pos.X, enemys[j].pos.Y); break;
											case 1: ruppeePos = core::position2d<f32>(enemys[j].pos.X, enemys[j].pos.Y); ruppeeAmount = rand() % 5;break;
											default: codePos = core::position2d<f32>(enemys[j].pos.X, enemys[j].pos.Y); codeData = randomCode();break;
										}
									}
								}
							}
						}
					}
					if(sean.hurtTimer <= 0 && attackSet[i].team.compare("Enemy") == 0)
					{
						if(collides(sean.pos.X -8,sean.pos.Y -8,
									sean.pos.X +8,sean.pos.Y +8,
									attackSet[i].x -10,attackSet[i].y -10,
									attackSet[i].x +10,attackSet[i].y +10))
						{
							sean.HP -= attackSet[i].ATT;
							sean.hurtTimer = attackSet[i].time;
							engine->play2D("FLT/sfx/Damage.wav", false);
						}
					}
				}
			}

			/*=================player dead===================*/
			if(sean.HP <= 0)
			{
				sean.HP = 30;
				sean.mapX = 0;
				sean.mapY = 0;
				mapGoTo(0, 0);
			}

			/*=================begin drawing===================*/
			driver->beginScene(true, true, video::SColor(255,255,255,255));	//open the scene

			//draw map tiles
			for(int x = 0;x < 16;x += 1)
			{
				for(int y = 0;y < 11;y += 1)
				{
					if(map[x][y].address != ta_Null)
					{
						driver->draw2DImage(tileset_texture, core::position2d<s32> (x*16,54 + y*16),  //place map tiles below menu
										map[x][y].address, 0,
										color_normal, false);
					}
				}
			}

			//draw player
			int playerXOffset = 0;
			if((((int)sean.imageIndex) % 26) >= 26/2)
				{playerXOffset = 20;}
			int playerYOffset = sean.direction*20 + sean.attacking*20*4;
			core::rect<s32> tileAddress = core::rect<s32> (playerXOffset, playerYOffset,
								playerXOffset + 20, playerYOffset + 20);
			core::position2d<s32> playerPosition = core::position2d<s32>((s32)sean.pos.X - 10,(s32)sean.pos.Y - 20);
			
			video::SColor newColor;
			
			if(sean.hurtTimer > 0)
				{newColor = color_red;}
			else
				{newColor = color_normal;}

			driver->draw2DImage(sean_texture, playerPosition,  //place map tiles below menu
							tileAddress, 0,
							newColor, true);

			//draw enemy
			for(int i = 0;i < 10;i++)
			{
				if(enemys[i].name.compare("none") != 0)
				{
					int offsetX = 0;
					int offsetY = 0;
					
					//enemy type  offset on spritesheet
					if(enemys[i].name.compare("Blue Octorock") == 0){
						offsetX = 120;offsetY = 0;}
					else if(enemys[i].name.compare("Gremlin") == 0){
						offsetX = 0;offsetY = 60;}
					else if(enemys[i].name.compare("Blue Gremlin") == 0){
						offsetX = 120;offsetY = 60;}
					else if(enemys[i].name.compare("Moblin") == 0){
						offsetX = 0;offsetY = 120;}
					else if(enemys[i].name.compare("Blue Moblin") == 0){
						offsetX = 120;offsetY = 120;}

					//movement offset on spritesheet
					if((((int)enemys[i].imageIndex) % 26) >= 26/2){
						offsetY += 30;}
					
					//direction offset on spritesheet
					if(enemys[i].direction == dir_Left){
						offsetX = 1*30;}
					else if(enemys[i].direction == dir_Up){
						offsetX = 2*30;}
					else if(enemys[i].direction == dir_Right){
						offsetX = 3*30;}
					
					//finally the tile address
					core::rect<s32> tileAddress = core::rect<s32> (offsetX, offsetY,
										offsetX + 16, offsetY + 16);
					
					//enemy location on the map
					core::position2d<s32> position = core::position2d<s32>((s32)enemys[i].pos.X - 8,(s32)enemys[i].pos.Y - 16);
					
					if(enemys[i].hurtTimer > 0)
					{
						newColor = color_red;
					}
					else
					{
						newColor = color_normal;
					}

					//draw enemy
					driver->draw2DImage(baddy_texture, position,  //place map tiles below menu
									tileAddress, 
									0, newColor, true);
				}
			}
			
			//draw attacks
			for(int i=0;i < 20;i++)
			{
				if(attackSet[i].time > 0)
				{
					driver->draw2DImage(attack_texture, 
									core::position2d<s32>((s32) attackSet[i].x - 10,(s32) attackSet[i].y - 20),
									core::rect<s32> (
										attackSet[i].gfxPos.UpperLeftCorner.X,
										attackSet[i].gfxPos.UpperLeftCorner.Y + attackSet[i].dir * 20,
										attackSet[i].gfxPos.LowerRightCorner.X,
										attackSet[i].gfxPos.LowerRightCorner.Y + attackSet[i].dir * 20
											)
									, 0, color_normal, true);
				}
			}

			//menu
			driver->draw2DImage(menu_texture, 
							core::position2d<s32> (0,0), 
							core::rect<s32> (0, 0, 256, 54),
							0, color_normal, false);

			//draw map icon
			driver->draw2DImage(tileset_texture, core::position2d<s32> (15 + sean.mapX*4,15 + sean.mapY*4),  //place map tiles below menu
										core::rect<s32>(60,140,64,144), 0, //yes; the water from the tileset
										color_normal, false);

			// draw numbers
			font->draw(sean.getMoney(),core::rect<s32>(104,15, 104+64,15+ 8),video::SColor(255,255,255,0));
			
			// draw hearts
			for(int i = 0;i < 10;i++)
			{
				if(sean.HP >= (i+1)*10) //more hp than this?  draw a filled heart
					{driver->draw2DImage(heart_texture, core::position2d<s32> (175 + i*8, 28), core::rect<s32> (0, 0, 8, 8), 0, color_normal, true);}
				else if(sean.HP > (i)*10 && sean.HP < (i+1)*10) //less hp than this but more than before?  draw a halfheart
					{driver->draw2DImage(heart_texture, core::position2d<s32> (175 + i*8, 28), core::rect<s32> (8, 0, 16, 8), 0, color_normal, true);}
				else if(sean.HP < (i+1)*10 && sean.MHP >= (i+1)*10) //less hp than this but more MHP than this?  draw a emptyheart
					{driver->draw2DImage(heart_texture, core::position2d<s32> (175 + i*8, 28), core::rect<s32> (16, 0, 24, 8), 0, color_normal, true);}
			}

			//draw items
			if(heartPos.X != 0)//dropped hearts
				{driver->draw2DImage(heart_texture, core::position2d<s32>((s32)heartPos.X, (s32)heartPos.Y), core::rect<s32> (0, 0, 8, 8), 0, color_normal, true);}
			if(ruppeePos.X != 0)//dropped ruppee
				{driver->draw2DImage(heart_texture, core::position2d<s32>((s32)ruppeePos.X, (s32)ruppeePos.Y), core::rect<s32> (24, 0, 32, 8), 0, color_normal, true);}
			if(codePos.X != 0)//dropped code
				{font->draw(stringToIrr(codeData),core::rect<s32>((s32)codePos.X - 15,(s32)codePos.Y, (s32)codePos.X + 15,(s32)codePos.Y + 20),video::SColor(255,0,0,0));}

			//draw CODE
			for(int i = 0;i < 20;i++)
				{font->draw(stringToIrr(code[i]),core::rect<s32>(256,i*12, 640,i*12 + 12),video::SColor(255,0,0,0));}

			driver->endScene();	//end the drawing scene
			if(receiver.IsKeyDown(KEY_ESCAPE) == true) {running = false;}	///* Escape the main program */
		}
	}

	/* Clean up shop! */
	device->drop();
	engine->drop();
	return 0;
}