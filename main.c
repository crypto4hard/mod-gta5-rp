#include "types.h"
#include "constants.h"
#include "intrinsics.h"
#include "natives.h"
#include "common.h"
#include "Vars.h"
#include "enums.h"
#include "DrawFunc.h"
#include "PS3.h"
#include "Functions.h"
#include "Background.h"

void RequestControlOfid(Entity netid)
{
	int tick = 0;

	while (!NETWORK_HAS_CONTROL_OF_NETWORK_ID(netid) && tick <= 25)
	{
		NETWORK_REQUEST_CONTROL_OF_NETWORK_ID(netid);
		tick++;
	}
}

void TeleportMe(Ped ped, float x, float y, float z)
{
	Entity entityToTele = ped;
	if (IS_PED_SITTING_IN_ANY_VEHICLE(ped))
		entityToTele = GET_VEHICLE_PED_IS_USING(ped);
	RequestControlOfid(entityToTele);
	SET_ENTITY_COORDS(entityToTele, x, y, z, false, false, false, true);
	_ANIMATE_GAMEPLAY_CAM_ZOOM(0.0f, 250.0f);
	LOAD_ALL_OBJECTS_NOW();
}

void TeleporttoNearestCar()
{
	int VehicleHandle = GET_CLOSEST_VEHICLE(GET_ENTITY_COORDS(PLAYER_PED_ID(), true), 100.0, 0, 71);
	SET_PED_INTO_VEHICLE(PLAYER_PED_ID(), VehicleHandle, -1);
}

void TeleportWaypoint()
{
	int WaypointHandle = GET_FIRST_BLIP_INFO_ID(8);
	if (DOES_BLIP_EXIST(WaypointHandle))
	{
		vector3 WaypointPos = GET_BLIP_COORDS(WaypointHandle);
		int Handle = PLAYER_PED_ID();
		if (IS_PED_IN_ANY_VEHICLE(Handle, 0))
			Handle = GET_VEHICLE_PED_IS_IN(PLAYER_PED_ID(), 0);
		SET_ENTITY_COORDS(Handle, WaypointPos.x, WaypointPos.y, WaypointPos.z + 5.0f, 0, 0, 0, 1);
		_ANIMATE_GAMEPLAY_CAM_ZOOM(0.0f, 250.0f);
		LOAD_ALL_OBJECTS_NOW();
	}
	else print("~r~Please set a Waypoint!", 3000);
}

void ChangeMenu(int Menu)
{
	lastNumMenu[NumMenuLevel] = NumMenu;
	lastOption[NumMenuLevel] = currentOption;
	currentOption = 1;
	NumMenu = Menu;
	NumMenuLevel++;
}

int SR, SG, SB;

void AddTitle(char* Text)
{
	if(IS_GAME_AND_PLAYER_READY() == true)
	{
	DRAW_TEXT2(Text, TitleFont, (Title_X), (0.0840 + 0.0050), 0.9, 0.9, 0, 0, 0, 255, 0);
	DRAW_TEXT2(Text, TitleFont, (Title_X), (0.0840 - 0.0050), 0.9, 0.9, 0, 0, 0, 255, 0);
	DRAW_TEXT2(Text, TitleFont,  (Title_X + 0.0050), (0.0840), 0.9, 0.9, 0, 0, 0, 255, 0);
	DRAW_TEXT2(Text, TitleFont, (Title_X - 0.0050), (0.0840), 0.9, 0.9, 0, 0, 0, 255, 0);
	DRAW_TEXT2(Text, TitleFont, (Title_X), (0.0840), 0.9, 0.9, 240, 240, 240, 255, 0);
	}
	else if(NETWORK_IS_GAME_AND_PLAYER_READY() == true)
	{
	DRAW_TEXT2(Text, TitleFont, (Title_X), (0.0840 + 0.0050), 0.9, 0.9, 0, 0, 0, 255, 0);
	DRAW_TEXT2(Text, TitleFont, (Title_X), (0.0840 - 0.0050), 0.9, 0.9, 0, 0, 0, 255, 0);
	DRAW_TEXT2(Text, TitleFont,  (Title_X + 0.0050), (0.0840), 0.9, 0.9, 0, 0, 0, 255, 0);
	DRAW_TEXT2(Text, TitleFont, (Title_X - 0.0050), (0.0840), 0.9, 0.9, 0, 0, 0, 255, 0);
	DRAW_TEXT2(Text, TitleFont, (Title_X), (0.0840), 0.9, 0.9, 240, 240, 240, 255, 0);
	}
}

void AddOption(char *option, char* spritedict, char* sprite, bool Normal, int color, char* Infox)
{
	optionCount++;
	if (currentOption == optionCount)
		InfoText = Infox;

	SelectedItem = false;
	SR = 255; SG = 255;  SB = 255;
	if (optionCount == currentOption)
	{
		SelectedItem = true;
		SR = 255; SG = 255;  SB = 255;
	}
	else
	SET_TEXT_OUTLINE();
if(IS_GAME_AND_PLAYER_READY() == true || NETWORK_IS_GAME_AND_PLAYER_READY() == true)
	{
	if(Normal == true)
	{
	if (currentOption <= maxOptions && optionCount <= maxOptions)
	{
		if(color == 1)
		{
		DRAW_RECT(Menu_X, (optionCount * 0.030f + 0.1410f), CenterDraw, 0.0285, BKG_R, BKG_G, BKG_B, 200);
		}
		if(color == 0)
		{
		DRAW_RECT(Menu_X, (optionCount * 0.030f + 0.1410f), CenterDraw, 0.0285, 0, 0, 0, 145);
		if(NumMenu == SubMenu1)
		DRAW_RECT(0.8250, (optionCount * 0.030f + 0.1410f), 0.0600, 0.0285, BKG_R, BKG_G, BKG_B, 180);
		}
		DRAW_TEXT_OPTION(option, OptionsFont, Cunt - 0.015 , (optionCount * 0.030f + 0.127f), 0.35000000, 0.35000000, false, 216, 18, 16, 255);
	}
	else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
	{
		if(color == 1)
		{
		DRAW_RECT(Menu_X, ((optionCount - (currentOption - maxOptions)) * 0.030f + 0.1410f), CenterDraw, 0.0285, BKG_R, BKG_G, BKG_B, 200);
		}
		if(color == 0)
		{
		DRAW_RECT(Menu_X,  ((optionCount - (currentOption - maxOptions)) * 0.030f + 0.1410f), CenterDraw, 0.0285, 0, 0, 0, 145);
		if(NumMenu == SubMenu1)
		DRAW_RECT(0.8250, ((optionCount - (currentOption - maxOptions)) * 0.030f + 0.1410f), 0.0600, 0.0285, BKG_R, BKG_G, BKG_B, 180);
		}
		DRAW_TEXT_OPTION(option, OptionsFont, Cunt - 0.015, ((optionCount - (currentOption - maxOptions)) * 0.030f + 0.127f), 0.35000000, 0.35000000, false, 216, 18, 16, 255);
	}
	
	}
	else
	{
	if (currentOption <= maxOptions && optionCount <= maxOptions)
	{
		if(color == 1)
		{
		DRAW_RECT(Menu_X, (optionCount * 0.030f + 0.1410f), CenterDraw, 0.0285, BKG_R, BKG_G, BKG_B, 200);
		}
		if(color == 0)
		{
		DRAW_RECT(Menu_X, (optionCount * 0.030f + 0.1410f), CenterDraw, 0.0285, 0, 0, 0, 145);
		if(NumMenu == SubMenu1)
		DRAW_RECT(0.8250, (optionCount * 0.030f + 0.1410f), 0.0600, 0.0285, BKG_R, BKG_G, BKG_B, 180);
		}
		
		SPRITE(spritedict, sprite, 0.6395, (optionCount * 0.030f + 0.1413f), 0.018, 0.028, 0, SR, SG, SB, 255);
		DRAW_TEXT_OPTION(option, OptionsFont, Cunt, (optionCount * 0.030f + 0.127f), 0.35000000, 0.35000000, false, 216, 18, 16, 255);
	}
	else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
	{
		if(color == 1)
		{
		DRAW_RECT(Menu_X, ((optionCount - (currentOption - maxOptions)) * 0.030f + 0.1410f), CenterDraw, 0.0285, BKG_R, BKG_G, BKG_B, 200); 
		}
		if(color == 0)
		{
		DRAW_RECT(Menu_X, ((optionCount - (currentOption - maxOptions)) * 0.030f + 0.1410f), CenterDraw, 0.0285, 0, 0, 0, 145);
		if(NumMenu == SubMenu1)
		DRAW_RECT(0.8250, ((optionCount - (currentOption - maxOptions)) * 0.030f + 0.1410f), 0.0600, 0.0285, BKG_R, BKG_G, BKG_B, 180);
		}
		DRAW_TEXT_OPTION(option, OptionsFont, Cunt, ((optionCount - (currentOption - maxOptions)) * 0.030f + 0.127f), 0.35000000, 0.35000000, false, 216, 18, 16, 255);
	}

	}
	}
}



void addOption(char* option,  char* sprite, char* sprite2, int color, char* info)
{
	AddOption(option, sprite, sprite2, false, color, info);
}


void Toggle(char* Stat)
{

    //optionCount++;
	if (currentOption <= maxOptions && optionCount <= maxOptions)
		DRAW_TEXT(Stat, 0, CuntStat + 0.010, (optionCount * 0.030f + 0.127f), 0.36f, 0.36f, 255, 255, 255, 255, false,false, 0,0,0);
	else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
	{
		DRAW_TEXT(Stat, 0, CuntStat  + 0.010, (maxOptions * 0.030f + 0.127f), 0.36f, 0.36f, 255, 255, 255, 255, false,false, 0,0,0);
	}

}

float FixButtonsPos2 = 0.0040;
float SmallIcons = 0.0020;
float FixButtonsPos = 0.0100;
void CheckBox(char *option, bool BOOL, char *spritedict, char* sprite, int color, char* info)
{
	if (BOOL)
	{
		AddOption(option, spritedict, sprite, false, color, info);
		if(RandCheckBox == 0)
		{
		SPRITE("timerbars", "circle_checkpoints_big", 0.8700, (optionCount * 0.030f + 0.1413f), 0.0150 - SmallIcons, 0.0200 - SmallIcons, 0,  114, 204, 114, 200);//114	204	114
		}
		else if(RandCheckBox == 1)
		{
		Toggle("On");
		}
	}
	else
	{
		AddOption(option, spritedict, sprite, false, color, info);
		if(RandCheckBox == 0)
		{
		SPRITE("timerbars", "circle_checkpoints_big", 0.8700, (optionCount * 0.030f + 0.1413f), 0.0150 - SmallIcons, 0.0200 - SmallIcons, 0,  244, 50, 50, 200);//224	50	50
		}
		else if(RandCheckBox == 1)
		{
			Toggle("Off");
		}
	}
}
void AddScript(char *option, bool BOOL, char* button_1, char* button_2, char *spritedict, char* sprite, int color, char* info)
{
	if (BOOL)
	{
		AddOption(option, spritedict, sprite, false, color, info);
		if(RandCheckBox == 0)
		{
		SPRITE("timerbars", "circle_checkpoints_big", 0.8700, (optionCount * 0.030f + 0.1413f), 0.0150 - SmallIcons, 0.0200 - SmallIcons, 0,  114, 204, 114, 200);//114	204	114
		}
		else if(RandCheckBox == 1)
		{
		Toggle("On");
		}
	}
	else
	{
		AddOption(option, spritedict, sprite, false, color, info);
		if(RandCheckBox == 0)
		{
		SPRITE("timerbars", "circle_checkpoints_big", 0.8700, (optionCount * 0.030f + 0.1413f), 0.0150 - SmallIcons, 0.0200 - SmallIcons, 0,  244, 50, 50, 200);//224	50	50
		}
		else if(RandCheckBox == 1)
		{
			Toggle("Off");
		}
	}
	SPRITE("erootiik", button_1, 0.8240 - FixButtonsPos - FixButtonsPos2, (optionCount * 0.030f + 0.1413f), 0.015, 0.025, 0, 255, 255, 255, 255);
	if (optionCount == currentOption)
	{
	SPRITE("shared", "menuplus_32", 0.8360 - FixButtonsPos, (optionCount * 0.030f + 0.1413f), 0.019, 0.029, 0, 255, 255, 255, 255);
	}
	else 
	{
		SPRITE("shared", "menuplus_32", 0.8360 - FixButtonsPos, (optionCount * 0.030f + 0.1413f), 0.019, 0.029, 0, 255, 255, 255, 255);
	}
	SPRITE("erootiik", button_2, 0.8480 - FixButtonsPos + FixButtonsPos2, (optionCount * 0.030f + 0.1413f), 0.015, 0.025, 0, 255, 255, 255, 255);
}
void CheckBoxOld(char *option, bool BOOL, char *spritedict, char* sprite, int color, char* info)
{
	AddOption(option, spritedict, sprite, false, color, info);
	if (BOOL){
	if (currentOption <= maxOptions && optionCount <= maxOptions)
	{
		SPRITE("darts", "xj_v_blackboard01", 0.8700, (optionCount * 0.030f + 0.1413f), 0.0500, 0.0150, 0,  118, 118, 118, 255);//BACKGOURND BOOL
		SPRITE("darts", "xj_v_blackboard01", 0.8700 + 0.0120, (optionCount * 0.030f + 0.1413f),  0.0260, 0.0150, 0,  0, 255, 0, 255);//ON
	}
	else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
	{
		SPRITE("darts", "xj_v_blackboard01", 0.8700, (maxOptions * 0.030f + 0.1413f), 0.0500, 0.0150, 0,  118, 118, 118, 255);//BACKGOURND BOOL
		SPRITE("darts", "xj_v_blackboard01", 0.8700 + 0.0120, (maxOptions * 0.030f + 0.1413f),  0.0260, 0.0150, 0,  0, 255, 0, 255);//ON
	}
	}
	else
	{
		if (currentOption <= maxOptions && optionCount <= maxOptions)
	{
		SPRITE("darts", "xj_v_blackboard01", 0.8700, (optionCount * 0.030f + 0.1413f), 0.0500, 0.0150, 0,  118, 118, 118, 255);//BACKGOURND BOOL
		SPRITE("darts", "xj_v_blackboard01", 0.8700 - 0.0120, (optionCount * 0.030f + 0.1413f),  0.0260, 0.0150, 0,  255, 0, 0, 255);//ON
	}
	else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
	{
		SPRITE("darts", "xj_v_blackboard01", 0.8700, (maxOptions * 0.030f + 0.1413f), 0.0500, 0.0150, 0,  118, 118, 118, 255);//BACKGOURND BOOL
		SPRITE("darts", "xj_v_blackboard01", 0.8700 - 0.0120, (maxOptions * 0.030f + 0.1413f),  0.0260, 0.0150, 0,  255, 0, 0, 255);//ON
	}
	}
}



void FloatOption(char *option, float *var, float min, float max, float Default, char *spritedict, char* sprite, int color, char* info )
{
	AddOption(option, spritedict, sprite, false, color, info);
	if (currentOption <= maxOptions && optionCount <= maxOptions)
	{
	drawFloat(*var, true, 0.860, (optionCount  * 0.030f + 0.1250f), 0.36f, 0.36f, 255, 255, 255, 255);
	}
	else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
	{
		drawFloat(*var, true, 0.860, (maxOptions  * 0.030f + 0.1250f), 0.36f, 0.36f, 255, 255, 255, 255);
	}
 	if (currentOption == optionCount)
	{
				
				if (rightPress == true)
		{
			if (*var >= max)
			{
				*var = min;
			}
			else
			{
				*var = *var + 0.1000f;
			}
			rightPress = false;
		}
		else if (leftPress == true)
		{
			if (*var <= min)
			{
				*var = max;
			}
			else
			{
				*var = *var - 0.1000f;
			}
		leftPress = false;
		}
	}
}



void FloatOptionFaster(char *option, float *var, float min, float max, float Default, char *spritedict, char* sprite, int color, char* info )
{
	AddOption(option, spritedict, sprite, false, color, info);
	if (currentOption <= maxOptions && optionCount <= maxOptions)
	{
	drawFloat(*var, true, 0.858, (optionCount  * 0.030f + 0.1250f), 0.36f, 0.36f, 255, 255, 255, 255);
	}
	else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
	{
		drawFloat(*var, true, 0.858, (maxOptions  * 0.030f + 0.1250f), 0.36f, 0.36f, 255, 255, 255, 255);
	}
 	if (currentOption == optionCount)
	{
				
				if (rightPress == true)
		{
			if (*var >= max)
			{
				*var = min;
			}
			else
			{
				*var = *var + 10.0000f;
			}
			rightPress = false;
		}
		else if (leftPress == true)
		{
			if (*var <= min)
			{
				*var = max;
			}
			else
			{
				*var = *var - 10.0000f;
			}
		leftPress = false;
		}
	}
}


int timerScrollSpeed;
bool fast;
bool check_button(int buttonID, bool checkSpeed)
{
	bool isPressed = false;
	if (IS_DISABLED_CONTROL_JUST_PRESSED(2, buttonID))
		return true;
	if (checkSpeed)
	{
		if(IS_DISABLED_CONTROL_PRESSED(2, buttonID))
		{
			timerScrollSpeed++;
			if (timerScrollSpeed > 7)
			{
				timerScrollSpeed = 6;
				fast = true;
				isPressed = true;
			}
		}
		if (IS_DISABLED_CONTROL_JUST_RELEASED(2, buttonID))
		{
			timerScrollSpeed = 0;
			fast = false;
		}
	}
	return isPressed;
}
bool delayed_key_press(int control)
{
	if (GET_GAME_TIMER() - lastButtonPress < buttonPressDelay)
	{
		return false;
	}

	if (IS_DISABLED_CONTROL_PRESSED(2, control) == true) 
	{
		lastButtonPress = GET_GAME_TIMER();
		return true;
	}
	return false;
}


int GET()
{
	if (PressX == true)
	{
		return currentOption;
		PressX = false;
	}
	else return 0;
}


void SetupTimer(int tickTime)
{
	if (newTimerTick) 
	{
		maxTimerCount = GET_GAME_TIMER() + tickTime;
		newTimerTick = false;
	}
}
bool IsTimerReady()
{
	return GET_GAME_TIMER() > maxTimerCount;
}
void ResetTimer()

{
	newTimerTick = true;
}
int Static_67  = 0;
float TimerGui = 0.0;
bool testT;
void SetupButtons()
{
	Static_67 = GET_FRAME_COUNT();
 if ( !( GET_FRAME_COUNT() - Static_67 >= 2 ) )
        {
             testT = true;   
        } else testT = false;
        Static_67 = GET_FRAME_COUNT();
	//SetupTimer(20);
	if (NumMenu == Closed)
	{
		//if (IsTimerReady())
		//{//RS = R3 | LS = L3
			if (IS_DISABLED_CONTROL_PRESSED(2 ,INPUT_SCRIPT_PAD_DOWN) && IS_DISABLED_CONTROL_PRESSED(2, INPUT_FRONTEND_ACCEPT) /* && SetGlobal(2394218 + 550 + 6, NULL, 1) != 0*/)
			{
				if(NETWORK_IS_GAME_AND_PLAYER_READY() == true || IS_GAME_AND_PLAYER_READY() == true)
				{
				SET_INPUT_EXCLUSIVE(2, INPUT_FRONTEND_RB);
				OpenMenuTimer++;
				if(OpenMenuTimer == 7)
				{
				if(EnableMusic)
				{
				TRIGGER_MUSIC_EVENT(SONG);
				}
				PLAY_SOUND_FRONTEND(-1, "YES", "HUD_FRONTEND_DEFAULT_SOUNDSET");
				NumMenu = Main_Menu;
				NumMenuLevel = 0;
				currentOption = 1;
				CreditText = " ";
				CreditTextTimer = 10;
				lastButtonPress = GET_GAME_TIMER();
				OpenMenuTimer = 0;
				}
				}
			}
			else if (!IS_DISABLED_CONTROL_PRESSED(2 ,INPUT_FRONTEND_ACCEPT) && !IS_DISABLED_CONTROL_PRESSED(2, INPUT_FRONTEND_RIGHT))
			{
				OpenMenuTimer = 0;
			}
			//ResetTimer();
		//}
	}
	else 
	{
		if(testT == true)
		{
		//if (IsTimerReady())
		//{
			 if (check_button(INPUT_FRONTEND_CANCEL, 0))
			{
				if (NumMenu == Main_Menu)
				{
					SET_PED_CAN_SWITCH_WEAPON(PLAYER_PED_ID(), true);
					if(EnableMusic)
				    {
					TRIGGER_MUSIC_EVENT(SONG);
					TRIGGER_MUSIC_EVENT("GLOBAL_KILL_MUSIC");
				    }
					PLAY_SOUND_FRONTEND(-1, "BACK", "HUD_FRONTEND_DEFAULT_SOUNDSET");
					NumMenu = Closed;
				}
				else 
				{
					NumMenu = lastNumMenu[NumMenuLevel - 1];
					currentOption = lastOption[NumMenuLevel - 1];
					NumMenuLevel--;
					PLAY_SOUND_FRONTEND(-1, "BACK", "HUD_FRONTEND_DEFAULT_SOUNDSET");
				}
			}
				
			else if (check_button(INPUT_FRONTEND_ACCEPT, 0))
			{
				PLAY_SOUND_FRONTEND(-1, "SELECT", "HUD_FRONTEND_DEFAULT_SOUNDSET");
				PressX = true;
			}
			else if (check_button(INPUT_SCRIPT_PAD_UP, 1))
			{
				currentOption--;
				if (currentOption < 1)
				 {
			     currentOption = optionCount;
				 }
				PLAY_SOUND_FRONTEND(-1, "NAV_UP_DOWN", "HUD_FRONTEND_DEFAULT_SOUNDSET");
			}
			else if (check_button(INPUT_SCRIPT_PAD_DOWN, 1))
			{
				currentOption++;
				if (currentOption > optionCount)
				{
					currentOption = 1;
				}
				PLAY_SOUND_FRONTEND(-1, "NAV_UP_DOWN", "HUD_FRONTEND_DEFAULT_SOUNDSET");
			}
			
			
			else if (check_button(INPUT_SCRIPT_PAD_RIGHT, 1))
			{
				rightPress = true;
				//PLAY_SOUND_FRONTEND(-1, "NAV_LEFT_RIGHT", "HUD_FRONTEND_DEFAULT_SOUNDSET");
			}
			else if (check_button(INPUT_SCRIPT_PAD_LEFT, 1))
			{
				leftPress = true;
				//PLAY_SOUND_FRONTEND(-1, "NAV_LEFT_RIGHT", "HUD_FRONTEND_DEFAULT_SOUNDSET");
			}
			//ResetTimer();
		//}
		}

	}
}

float conv360(float base, float min, float max) {
    // This is the function the script used. I just adapted it for C++.
    float fVar0;
    if (min == max) return min;
    fVar0 = max - min;
    base -= ROUND(base - min / fVar0) * fVar0;
    if (base < min) base += fVar0;
    return base;
}

void drawGlare(float pX, float pY, float sX , float sY, int r, int g, int b) {
    // Request the scaleform
    gGlareHandle = REQUEST_SCALEFORM_MOVIE("MP_MENU_GLARE");
    // Draw Scaleform
    DRAW_SCALEFORM_MOVIE(gGlareHandle, pX, pY, sX, sY, r, g, b, 255, 0); // Custom positioning & size
    // DRAW_SCALEFORM_MOVIE_FULLSCREEN(gGlareHandle, r, g, b, 255, 0); // Default positioning & size
}



int TimerGui2 = 0;
void SetupActions()
{
	 SET_PED_CAN_SWITCH_WEAPON(PLAYER_PED_ID(), false);
	if(IS_WARNING_MESSAGE_ACTIVE())
	{
		NumMenu = Closed;
	}
	DISABLE_CONTROL_ACTION(0, 19);
	DISABLE_CONTROL_ACTION(0, 20);
	DISABLE_CONTROL_ACTION(0, 21);
	DISABLE_CONTROL_ACTION(0, 27);
	DISABLE_CONTROL_ACTION(0, 54);
	DISABLE_CONTROL_ACTION(0, 123);
	DISABLE_CONTROL_ACTION(0, 124);
	DISABLE_CONTROL_ACTION(0, 125);
	DISABLE_CONTROL_ACTION(0, 126);
	DISABLE_CONTROL_ACTION(0, 138);
	DISABLE_CONTROL_ACTION(0, 139);
	DISABLE_CONTROL_ACTION(0, 140);
	DISABLE_CONTROL_ACTION(0, 177);
	DISABLE_CONTROL_ACTION(0, 178);
	DISABLE_CONTROL_ACTION(0, 179);
	DISABLE_CONTROL_ACTION(0, 207);
	SET_INPUT_EXCLUSIVE(2, 166);
	SET_INPUT_EXCLUSIVE(2, 167);
	SET_INPUT_EXCLUSIVE(2, 177);
	SET_INPUT_EXCLUSIVE(2, 178);
	SET_INPUT_EXCLUSIVE(2, 193);
	SET_INPUT_EXCLUSIVE(2, 194);
	SET_INPUT_EXCLUSIVE(2, 195);
	SET_INPUT_EXCLUSIVE(2, 202);
	SET_INPUT_EXCLUSIVE(2, 203);
	SET_INPUT_EXCLUSIVE(2, 204);
	SET_INPUT_EXCLUSIVE(2, 205);
	if(IS_PAUSE_MENU_ACTIVE())
	{
		NumMenu = Closed;
    }
	if(IS_WARNING_MESSAGE_ACTIVE())
	{
		NumMenu = Closed;
	}
	if(IS_GAME_AND_PLAYER_READY() == true)
	{
	if (optionCount > maxOptions)
	{
		DRAW_RECT(Menu_X - 0.1321, (((maxOptions * 0.030f) / 2) + 0.1332f), 0.0040, (maxOptions * 0.030f) + 0.1113, BannerR, BannerG, BannerB, 255);
		DRAW_RECT(Menu_X + 0.1322, (((maxOptions * 0.030f) / 2) + 0.1332f), 0.0040, (maxOptions * 0.030f) + 0.1113, BannerR, BannerG, BannerB, 255);
	}
	else
	{
		DRAW_RECT(Menu_X - 0.1321, (((optionCount * 0.030f) / 2) + 0.1332f), 0.0040, (optionCount * 0.030f) + 0.1113, BannerR, BannerG, BannerB, 255);
		DRAW_RECT(Menu_X + 0.1322, (((optionCount * 0.030f) / 2) + 0.1332f), 0.0040, (optionCount * 0.030f) + 0.1113, BannerR, BannerG, BannerB, 255);
	}
	DRAW_RECT(Menu_X, 0.1177f, CenterDraw, 0.080f,BannerR, BannerG, BannerB, 255);
	drawGlare(GlareX, GlareY, GlareXs, GlareYs, 115, 255, 255);
	BG();
		if (!IS_STRING_NULL_OR_EMPTY(InfoText))
		{
		if (optionCount > maxOptions)
		{
		DRAW_TEXT(InfoText, 0, 0.758 - 0.125, ((maxOptions + 2.2080) * 0.030f + 0.125f), 0.35f, 0.35f, 255, 255, 255, 255, false, false, 0, 0, 0);
		DRAW_RECT(Menu_X, (((maxOptions + 2.2080) * 0.030f) + 0.1415f), CenterDraw + 0.0080, 0.035f, BannerR, BannerG, BannerB, 255); //Info Box
		}
		else
		{
		DRAW_TEXT(InfoText, 0, 0.758- 0.125, ((optionCount + 2.2080) * 0.030f + 0.125f), 0.35f, 0.35f, 255, 255, 255, 255, false, false, 0, 0, 0);
		DRAW_RECT(Menu_X, (((optionCount + 2.2080) * 0.030f) + 0.1415f), CenterDraw + 0.0080, 0.035f, BannerR, BannerG, BannerB, 255); //Info Box
	    }
		}
		if (optionCount > maxOptions)
		{
		DRAW_TEXT("v2.0", 0, 0.758 - 0.125, ((maxOptions + 1) * 0.030f + 0.125f), 0.4f, 0.4f, 255, 255, 255, 255, false, false, 0, 0, 0);
		if(timerLoading != 0)
		{
		SPRITE("mpcarhud", "schyster", 0.6660, ((maxOptions + 2.2080) * 0.030f + 0.1055f), 0.018, 0.028, timerLoading, 255, 255, 255, 255);
		}
		draw_item_count(0.758 + 0.102, ((maxOptions + 1) * 0.030f + 0.125f), 0.4f, 0.4f);
		DRAW_RECT(Menu_X, (((maxOptions + 1) * 0.030f) + 0.1415f), CenterDraw, 0.035f, BannerR, BannerG, BannerB, 255); //Info Box
		}
		else
		{
			DRAW_TEXT("v2.0", 0, 0.758- 0.125, ((optionCount + 1) * 0.030f + 0.125f), 0.4f, 0.4f, 255, 255, 255, 255, false, false, 0, 0, 0);
			if(timerLoading != 0)
		{
		SPRITE("mpcarhud", "schyster", 0.6660, ((optionCount + 2.2080) * 0.030f + 0.1055f), 0.018, 0.028, timerLoading, 255, 255, 255, 255);
		}
		draw_item_count(0.758 + 0.102, ((optionCount + 1) * 0.030f + 0.125f), 0.4f, 0.4f);
		DRAW_RECT(Menu_X, (((optionCount + 1) * 0.030f) + 0.1415f), CenterDraw, 0.035f, BannerR, BannerG, BannerB, 255); //Info Box
	    }
	}
	else if(NETWORK_IS_GAME_AND_PLAYER_READY() == true)
	{
			DRAW_RECT(Menu_X, 0.1177f, CenterDraw, 0.080f,BannerR, BannerG, BannerB, 255);
	if (optionCount > maxOptions)
	{
		DRAW_RECT(Menu_X - 0.1321, (((maxOptions * 0.030f) / 2) + 0.1332f), 0.0040, (maxOptions * 0.030f) + 0.1113, BannerR, BannerG, BannerB, 255);
		DRAW_RECT(Menu_X + 0.1322, (((maxOptions * 0.030f) / 2) + 0.1332f), 0.0040, (maxOptions * 0.030f) + 0.1113, BannerR, BannerG, BannerB, 255);
	}
	else
	{
		DRAW_RECT(Menu_X - 0.1321, (((optionCount * 0.030f) / 2) + 0.1332f), 0.0040, (optionCount * 0.030f) + 0.1113, BannerR, BannerG, BannerB, 255);
		DRAW_RECT(Menu_X + 0.1322, (((optionCount * 0.030f) / 2) + 0.1332f), 0.0040, (optionCount * 0.030f) + 0.1113, BannerR, BannerG, BannerB, 255);
	}
	drawGlare(GlareX, GlareY, GlareXs, GlareYs, 115, 255, 255);
		if (!IS_STRING_NULL_OR_EMPTY(InfoText))
		{
		if (optionCount > maxOptions)
		{
		DRAW_TEXT(InfoText, 0, 0.758 - 0.125, ((maxOptions + 2.2080) * 0.030f + 0.125f), 0.35f, 0.35f, 255, 255, 255, 255, false, false, 0, 0, 0);
		DRAW_RECT(Menu_X, (((maxOptions + 2.2080) * 0.030f) + 0.1415f), CenterDraw + 0.0080, 0.035f, BannerR, BannerG, BannerB, 255); //Info Box
		}
		else
		{
		DRAW_TEXT(InfoText, 0, 0.758- 0.125, ((optionCount + 2.2080) * 0.030f + 0.125f), 0.35f, 0.35f, 255, 255, 255, 255, false, false, 0, 0, 0);
		DRAW_RECT(Menu_X, (((optionCount + 2.2080) * 0.030f) + 0.1415f), CenterDraw + 0.0080, 0.035f, BannerR, BannerG, BannerB, 255); //Info Box
	    }
		}
		if (optionCount > maxOptions)
		{
		DRAW_TEXT("v2.0", 0, 0.758 - 0.125, ((maxOptions + 1) * 0.030f + 0.125f), 0.4f, 0.4f, 255, 255, 255, 255, false, false, 0, 0, 0);
		if(timerLoading != 0)
		{
		SPRITE("mpcarhud", "schyster", 0.6630, ((maxOptions + 2.2080) * 0.030f + 0.1055f), 0.018, 0.028, timerLoading, 255, 255, 255, 255);
		}
		draw_item_count(0.758 + 0.102, ((maxOptions + 1) * 0.030f + 0.125f), 0.4f, 0.4f);
		DRAW_RECT(Menu_X, (((maxOptions + 1) * 0.030f) + 0.1415f), CenterDraw, 0.035f, BannerR, BannerG, BannerB, 255); //Info Box
		}
		else
		{
			DRAW_TEXT("v2.0", 0, 0.758- 0.125, ((optionCount + 1) * 0.030f + 0.125f), 0.4f, 0.4f, 255, 255, 255, 255, false, false, 0, 0, 0);
			if(timerLoading != 0)
		{
		SPRITE("mpcarhud", "schyster", 0.6630, ((optionCount + 2.2080) * 0.030f + 0.1055f), 0.018, 0.028, timerLoading, 255, 255, 255, 255);
		}
		draw_item_count(0.758 + 0.102, ((optionCount + 1) * 0.030f + 0.125f), 0.4f, 0.4f);
		DRAW_RECT(Menu_X, (((optionCount + 1) * 0.030f) + 0.1415f), CenterDraw, 0.035f, BannerR, BannerG, BannerB, 255); //Info Box
	    }
		if (optionCount > maxOptions)
		{
		SPRITE("commonmenu", "shop_arrows_upanddown", 0.758, ((maxOptions *  0.030f) + 0.1720f), 0.0320f, 0.0450f, 0, 255, 255, 255, 255);//draw up and down
		}
	}

}

void Setup_System()
{
	PressX = false;
	rightPress = false;
	leftPress = false;
}

void Loop()
{
}

void Menu(void)
{
	optionCount = 0;
	if (NumMenu == Main_Menu)
	{
		AddTitle("Monster Menu");
		addOption("Teleport Menu", "commonmenutu", "custom_mission", 1, "");
		addOption("Self options", "commonmenutu", "custom_mission", 1, "");
		addOption("Vehicle options", "commonmenutu", "custom_mission", 1, "");
		addOption("SubMenu 4", "commonmenutu", "custom_mission", 1, "");
		addOption("SubMenu 5", "commonmenutu", "custom_mission", 1, "");
		addOption("Credits", "commonmenutu", "custom_mission", 1, "");
		if (GET() == 1)
		{
			ChangeMenu(SubMenu1);
		}
		if (GET() == 2)
		{
			ChangeMenu(SubMenu2);
		}
		if (GET() == 3)
		{
			ChangeMenu(SubMenu3);
		}
		if (GET() == 4)
		{
			ChangeMenu(SubMenu4);
		}
		if (GET() == 5)
		{
			ChangeMenu(SubMenu5);
		}
		if (GET() == 6)
		{
			ChangeMenu(Credits);
		}
	}
	else if (NumMenu == SubMenu1)
	{
		AddTitle("TeleportMenu");
		addOption("Los Santos Custom", "commonmenutu", "custom_mission", 0, "");
		addOption("Ammu Nation", "commonmenutu", "custom_mission", 1, "");
		addOption("Clothes Shop", "commonmenutu", "custom_mission", 0, "");
		addOption("Tattoo Studio", "commonmenutu", "custom_mission", 1, "");
		addOption("Barber Shop", "commonmenutu", "custom_mission", 0, "");
		addOption("Mask Shop", "commonmenutu", "custom_mission", 1, "");
		addOption("Airport", "commonmenutu", "custom_mission", 0, "");
		addOption("Beach", "commonmenutu", "custom_mission", 1, "");
		addOption("Mountain Chilliad", "commonmenutu", "custom_mission", 0, "");
		addOption("Ford Zancudo", "commonmenutu", "custom_mission", 1, "");
		addOption("FIB Building", "commonmenutu", "custom_mission", 0, "");
		addOption("Maze Bank Heliport", "commonmenutu", "custom_mission", 1, "");
		addOption("IAA Building", "commonmenutu", "custom_mission", 0, "");
		addOption("Trevor's Airport", "commonmenutu", "custom_mission", 1, "");
		addOption("Farm", "commonmenutu", "custom_mission", 0, "");
		addOption("Prison", "commonmenutu", "custom_mission", 1, "");
		addOption("Island", "commonmenutu", "custom_mission", 0, "");
		addOption("Island2", "commonmenutu", "custom_mission", 1, "");
		addOption("Deep Ocean", "commonmenutu", "custom_mission", 0, "");
		addOption("High In The Sky", "commonmenutu", "custom_mission", 1, "");
		addOption("DJ Club Striptease", "commonmenutu", "custom_mission", 0, "");
		addOption("Into Nearest Vehicle", "commonmenutu", "custom_mission", 1, "");
		addOption("Waypoint", "commonmenutu", "custom_mission", 0, "");
		if (GET() == 1)
		{
			TeleportMe(PLAYER_PED_ID(), -378.2f, -115.5f, 39.6f);

		}
		else if (GET() == 2)
		{
			TeleportMe(PLAYER_PED_ID(), 235.5f, -41.7f, 69.8f);
		}
		else if (GET() == 3)
		{
			TeleportMe(PLAYER_PED_ID(), 129.1f, -201.3f, 54.6f);
		}
		else if (GET() == 4)
		{
			TeleportMe(PLAYER_PED_ID(), 320.3f, 172.3f, 103.8f);
		}
		else if (GET() == 5)
		{
			TeleportMe(PLAYER_PED_ID(), -29.4f, -141.9f, 57.1f);
		}
		else if (GET() == 6)
		{
			TeleportMe(PLAYER_PED_ID(), -1341.7f, -1279.4f, 4.9f);
		}
		else if (GET() == 7)
		{
			TeleportMe(PLAYER_PED_ID(), -1084.0f, -2986.5f, 14.2f);
		}
		else if (GET() == 8)
		{
			TeleportMe(PLAYER_PED_ID(), -1465.1f, -1259.2f, 2.9f);
		}
		else if (GET() == 9)
		{
			TeleportMe(PLAYER_PED_ID(), 501.9f, 5594.1f, 795.7f);
		}
		else if (GET() == 10)
		{
			TeleportMe(PLAYER_PED_ID(), -2026.0f, 3151.9f, 32.8f);
		}
		else if (GET() == 11)
		{
			TeleportMe(PLAYER_PED_ID(), 136.8f, -749.2f, 258.3f);
		}
		else if (GET() == 12)
		{
			TeleportMe(PLAYER_PED_ID(), -75.0f, -818.0f, 326.1f);
		}
		else if (GET() == 13)
		{
			TeleportMe(PLAYER_PED_ID(), 128.4f, -617.7f, 206.2f);
		}
		else if (GET() == 14)
		{
			TeleportMe(PLAYER_PED_ID(), 1715.1f, 3260.1f, 41.1f);
		}
		else if (GET() == 15)
		{
			TeleportMe(PLAYER_PED_ID(), 2208.7f, 5578.2f, 53.8f);
		}
		else if (GET() == 16)
		{
			TeleportMe(PLAYER_PED_ID(), 1733.9f, 2583.2f, 45.7f);
		}
		else if (GET() == 17)
		{
			TeleportMe(PLAYER_PED_ID(), 24.4f, 7643.9f, 19.2f);
		}
		else if (GET() == 18)
		{
			TeleportMe(PLAYER_PED_ID(), 3633.1f, 5006.4f, 12.8f);
		}
		else if (GET() == 19)
		{
			TeleportMe(PLAYER_PED_ID(), 3202.6f, -4774.5f, -179.3f);
		}
		else if (GET() == 20)
		{
			TeleportMe(PLAYER_PED_ID(), -129.7f, 8130.4f, 6703.9f);
		}
		else if (GET() == 21)
		{
			SET_ENTITY_COORDS(PLAYER_PED_ID(), 124.2f, -1279.8f, 29.9f, 0, 0, 0, 1);

		}
		else if (GET() == 22)
		{
			TeleporttoNearestCar();
		}
		else if (GET() == 23)
		{
			TeleportWaypoint();

		}
	}
	else if (NumMenu == SubMenu2)
	{
		AddTitle("Player Menu");
		CheckBox("Never Wanted", true, "commonmenutu", "custom_mission", 1, "Police will ignore you.");
	}
	if (GET() == 1)
	{
		SET_MAX_WANTED_LEVEL(0);
		CLEAR_PLAYER_WANTED_LEVEL(PLAYER_ID());
		print("~g~Police disabled", 3000);

	}
	else if(NumMenu == SubMenu3)
	{
		AddTitle("SubMenu 3");
	}
	else if(NumMenu == SubMenu4)
	{
		AddTitle("SubMenu 4");
	}
	else if(NumMenu == SubMenu5)
	{	
		AddTitle("SubMenu 5");
	}
	else if (NumMenu == Credits)
	{
		AddTitle("Credits");
		addOption("Credits by Mstafa", "", "", 1, "");
	}
	Setup_System();
	if(NumMenu != Closed)
		SetupActions();
}

void main()
{
	SONG = "TRV4_START";
	_SET_NOTIFICATION_TEXT_ENTRY("STRING");
    ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("Mod Menu by mstafa");
    _SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_SOCIAL_CLUB", "CHAR_SOCIAL_CLUB", 1, 7, "~r~BIGBOSS", "", 1, "___DEV*", 8);
    _DRAW_NOTIFICATION(5000, 1);
	*(double*)0x424CF8 = 0x4014000000000000;//Limited Mspeed Bypsss to 5.0
	*(double*)0x424CF0 = 0x0000000000000000;//Limited Mspeed Bypsss to 0.0
	do
	{
	REQUEST_STREAMED_TEXTURE_DICT("hunting", false);
	REQUEST_STREAMED_TEXTURE_DICT("timerbars", false);
	REQUEST_STREAMED_TEXTURE_DICT("mpleaderboard", false);
	REQUEST_STREAMED_TEXTURE_DICT("mpinventory", false);
	REQUEST_STREAMED_TEXTURE_DICT("mprankbadge", false);
	REQUEST_STREAMED_TEXTURE_DICT("mpoverview", false);
	REQUEST_STREAMED_TEXTURE_DICT("commonmenu", false);
	REQUEST_STREAMED_TEXTURE_DICT("commonmenutu", false);
	REQUEST_STREAMED_TEXTURE_DICT("erootiik", false);
	REQUEST_STREAMED_TEXTURE_DICT("shared", false);
	REQUEST_STREAMED_TEXTURE_DICT("mpcarhud", false);
	REQUEST_STREAMED_TEXTURE_DICT("speedo", 1);
		SetupButtons();
		Menu();
		Loop();
		if (NETWORK_IS_GAME_IN_PROGRESS())
        {
	     NETWORK_SET_THIS_SCRIPT_IS_NETWORK_SCRIPT(18, 0, 0);
	     NETWORK_GET_SCRIPT_STATUS();
        }
		
		if(ReadInt32(0x100225F0) == 0x00000001)
		{
			GlareX = 1.1209;
			GlareY = 0.4330;
		}
		if (SetGlobal(2394218 + 550 + 6 , NULL, 1) == 0)
		{
		   *(int*)0x100225F0 = 0x00000001;
			GlareX = 1.1209;
			GlareY = 0.4330;
		}
		if (SetGlobal(2394218 + 550 + 6, NULL, 1) == 0)
			{
				ENABLE_ALL_CONTROL_ACTIONS(2);
				ENABLE_ALL_CONTROL_ACTIONS(0);
				NumMenu = Closed;
			}
	WAIT(0);
	} while(true);
}