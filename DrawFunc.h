void DRAW_TEXT8(const char * text, float x, float y, float scalex, float scaley, int r, int g, int b, int a, bool center)
{
	SET_TEXT_FONT(0);
	SET_TEXT_SCALE(scalex, scaley);
	SET_TEXT_COLOUR(r, g, b, a);
	SET_TEXT_WRAP(0.0f, 1.0f);
	SET_TEXT_CENTRE(center);
    SET_TEXT_OUTLINE();
	BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
	END_TEXT_COMMAND_DISPLAY_TEXT(x, y);
}
void DRAW_TEXT_OPTION(char * text, int Font, float x, float y, float scalex, float scaley, bool center, int R, int G, int B, int A)
{
	SET_TEXT_FONT(Font);
	if(SelectedItem)
	{
	SET_TEXT_SCALE(0.43, 0.43);
	SET_TEXT_COLOUR(SelClrR, SelClrG, SelClrB, 255);
	SET_TEXT_OUTLINE();
	}
    else
	{
		SET_TEXT_SCALE(scalex, scaley);
		SET_TEXT_COLOUR(R, G, B, A);
		SET_TEXT_OUTLINE();
	}
	SET_TEXT_WRAP(0.0f, 1.0f);
	SET_TEXT_CENTRE(center);
	BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
	END_TEXT_COMMAND_DISPLAY_TEXT(x, y);
}
void DRAW_TEXT5(char * text, int Font, float x, float y, float scalex, float scaley, bool center, bool UseEdge , int RD, int GD, int BD)
{
	SET_TEXT_FONT(Font);
	SET_TEXT_SCALE(scalex, scaley);
	SET_TEXT_WRAP(0.0f, 1.0f);
	SET_TEXT_CENTRE(center);
	if(WhiteColor_toggle == true)
	{
	SET_TEXT_COLOUR(255, 255, 255, 255);
	SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
	SET_TEXT_OUTLINE();
	}
	else if (WhiteColor_toggle == false)
	{
		SET_TEXT_COLOUR(0, 0, 0, 255);
		SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
	}
	BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
	END_TEXT_COMMAND_DISPLAY_TEXT(x, y);
}

void DRAW_TEXT3(char * text, int Font, float x, float y, float scalex, float scaley, bool center, bool UseEdge , int RD, int GD, int BD)
{
	SET_TEXT_FONT(Font);
	SET_TEXT_SCALE(scalex, scaley);
	SET_TEXT_WRAP(0.0f, 1.0f);
	SET_TEXT_CENTRE(center);
	if(WhiteColor == true)
	{
	SET_TEXT_COLOUR(255, 255, 255, 255);
	SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
	SET_TEXT_OUTLINE();
	}
	else if (WhiteColor == false)
	{
		SET_TEXT_COLOUR(0, 0, 0, 255);
		SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
	}
	BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
	END_TEXT_COMMAND_DISPLAY_TEXT(x, y);
}

void DRAW_TEXT(const char * text, int Font, float x, float y, float scalex, float scaley, int r, int g, int b, int a, bool center, bool UseEdge , int RD, int GD, int BD)
{
	SET_TEXT_FONT(Font);
	SET_TEXT_SCALE(scalex, scaley);
	SET_TEXT_COLOUR(r, g, b, a);
	SET_TEXT_WRAP(0.0f, 1.0f);
	SET_TEXT_CENTRE(center);
	SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
	SET_TEXT_OUTLINE();
	BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
	END_TEXT_COMMAND_DISPLAY_TEXT(x, y);
}


void DRAW_TEXT_NEW(const char * text, int Font, float x, float y, float scalex, float scaley, int r, int g, int b, int a, bool center, bool UseEdge , int RD, int GD, int BD)
{
	SET_TEXT_FONT(Font);
	SET_TEXT_SCALE(scalex, scaley);
	SET_TEXT_COLOUR(r, g, b, a);
	SET_TEXT_WRAP(0.0f, 1.0f);
	SET_TEXT_CENTRE(center);
	BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
	END_TEXT_COMMAND_DISPLAY_TEXT(x, y);
}

void DRAW_TEXT_NEW2(const char * text, int Font, float x, float y, float scalex, float scaley, int r, int g, int b, int a, bool center, bool UseEdge , int RD, int GD, int BD)
{
	SET_TEXT_FONT(Font);
	SET_TEXT_SCALE(scalex, scaley);
	SET_TEXT_COLOUR(r, g, b, a);
	SET_TEXT_WRAP(0.0f, 1.0f);
	SET_TEXT_CENTRE(center);
	SET_TEXT_DROPSHADOW(1, 0, 0, 0, 255);
	BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
	END_TEXT_COMMAND_DISPLAY_TEXT(x, y);
}


void DRAW_TEXT2(char * text, int Font, float x, float y, float scalex, float scaley, int r, int g, int b, int a, bool center)
{
	SET_TEXT_FONT(Font);
	SET_TEXT_SCALE(scalex, scaley);
	SET_TEXT_COLOUR(r, g, b, a);
	SET_TEXT_WRAP(0.0f, 1.0f);
	SET_TEXT_CENTRE(center);
	SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
	SET_TEXT_OUTLINE();
	BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
	END_TEXT_COMMAND_DISPLAY_TEXT(x, y);
}


void DRAW_TEXT4(char * text, int Font, float x, float y, float scalex, float scaley, int r, int g, int b, int a,  bool center, bool UseEdge , int RD, int GD, int BD)
{
	SET_TEXT_FONT(Font);
	if(SelectedItem4)
	{
	SET_TEXT_SCALE(0.45, 0.45);
	SET_TEXT_COLOUR(SelClrR, SelClrG, SelClrB, 255);
	}
    else
	{
		SET_TEXT_SCALE(scalex, scaley);
		SET_TEXT_COLOUR(r, g, b, a);
		SET_TEXT_OUTLINE();
	}
	SET_TEXT_WRAP(0.0f, 1.0f);
	SET_TEXT_CENTRE(center);
	BEGIN_TEXT_COMMAND_DISPLAY_TEXT("STRING");
	ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(text);
	END_TEXT_COMMAND_DISPLAY_TEXT(x, y);
}




void SPRITE(char* TextOne, char* TextTwo, float X, float Y, float Width, float Height, float Rotation, int R, int G, int B, int A)
{
	if (HAS_STREAMED_TEXTURE_DICT_LOADED(TextOne))
		DRAW_SPRITE(TextOne, TextTwo, X, Y, Width, Height, Rotation, R, G, B, A);
}



void drawFloat(float Val, bool center, float x, float y, float scalex, float scaley, int r, int b, int g, int a)
{
	SET_TEXT_FONT(0);
	SET_TEXT_SCALE(scalex, scaley);
	SET_TEXT_COLOUR(r, g, b, a);
	SET_TEXT_WRAP(0.0f, 1.0f);
	SET_TEXT_CENTRE(center);
	SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
	SET_TEXT_OUTLINE();
	BEGIN_TEXT_COMMAND_DISPLAY_TEXT("NUMBER");
	ADD_TEXT_COMPONENT_FLOAT(Val, 4);
	END_TEXT_COMMAND_DISPLAY_TEXT(x, y);
}
void DrawFloat(float val, int dp, int font, float x, float y, float scalex, float scaley, int r, int b, int g, int a, bool center)
{
	SET_TEXT_FONT(font);
	SET_TEXT_SCALE(scalex, scaley);
	SET_TEXT_COLOUR(r, g, b, a);
	SET_TEXT_WRAP(0.0f, 1.0f);
	SET_TEXT_CENTRE(center);
	SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
	SET_TEXT_OUTLINE();
	BEGIN_TEXT_COMMAND_DISPLAY_TEXT("NUMBER");
	ADD_TEXT_COMPONENT_FLOAT(val, 4);
	END_TEXT_COMMAND_DISPLAY_TEXT(x, y);
}

void drawNumber(int Val, int font,  float x, float y, float scalex, float scaley, int r, int b, int g, int a, int center)
{
	SET_TEXT_FONT(font);
	SET_TEXT_SCALE(scalex, scaley);
	SET_TEXT_COLOUR(r, g, b, a);
	SET_TEXT_WRAP(0.0f, 1.0f);
	SET_TEXT_CENTRE(center);
	SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
	SET_TEXT_OUTLINE();
	BEGIN_TEXT_COMMAND_DISPLAY_TEXT("NUMBER");
	ADD_TEXT_COMPONENT_INTEGER(Val);
	END_TEXT_COMMAND_DISPLAY_TEXT(x, y);
}


void draw_item_count(float x, float y, float xs, float ys)
{
	SET_TEXT_FONT(0);
	SET_TEXT_SCALE(xs,  ys);
	SET_TEXT_LEADING(2);
	SET_TEXT_COLOUR(255, 255, 255, 255);
	SET_TEXT_WRAP(0, 1);
	SET_TEXT_CENTRE(1);
	SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
	SET_TEXT_EDGE(0, 0, 0, 0, 0);
	SET_TEXT_OUTLINE(0);
	BEGIN_TEXT_COMMAND_DISPLAY_TEXT("CM_ITEM_COUNT");
	ADD_TEXT_COMPONENT_INTEGER(currentOption);
	ADD_TEXT_COMPONENT_INTEGER(optionCount);
	END_TEXT_COMMAND_DISPLAY_TEXT(x,y);
}
