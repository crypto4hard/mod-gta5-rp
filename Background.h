void DRAW_TEXTURE1(char *spritedict, char *sprite, float X, float Y, float Width, float Height, float Rotation, int R, int G, int B, int A)
{
	if (!HAS_STREAMED_TEXTURE_DICT_LOADED((char*)spritedict))
	{
		REQUEST_STREAMED_TEXTURE_DICT((char*)spritedict, false);
	}
	else
	{
		DRAW_SPRITE((char*)spritedict, (char*)sprite, X, Y, Width, Height, Rotation, R, G, B, A);
	}
}

char* BackgroundPic = "corona_point";

void BG()
{
	if(GET_THIS_SCRIPT_NAME(), "ingamehud")
	{
		if (optionCount > maxOptions)
		{
			DRAW_TEXTURE1("TESTBACKGROUND", BackgroundPic, Menu_X, (((maxOptions * 0.030f) / 2) + 0.1565f), CenterDraw, (maxOptions * 0.030f), 0, 255, 255, 255, 255);
		}
		else
		{
			DRAW_TEXTURE1("TESTBACKGROUND", BackgroundPic, Menu_X, (((optionCount * 0.030f) / 2) + 0.1565f), CenterDraw, (optionCount * 0.030f), 0, 255, 255, 255, 255);
		}
	}
}