
  int SetGlobal(unsigned int globalId, int value, int wouldRead) 
{
	static unsigned int** arr = (unsigned int**)0x1E70370;
	switch (wouldRead)
	{
	case 0: arr[(globalId >> 18) & 0x3F][globalId & 0x3FFFF] = value; /*arr[globalId / 0x40000][globalId % 0x40000] = value;*/ break; //write
	case 1: return arr[(globalId >> 18) & 0x3F][globalId & 0x3FFFF]; /*return arr[globalId / 0x40000][globalId % 0x40000];*/ break; //read
	case 2: /*&arr[(globalId >> 18) & 0x3F][globalId & 0x3FFFF];*/ /*&return &arr[globalId / 0x40000][globalId % 0x40000];*/ break; //to address //returns int *
	}
	return 0;
}

bool NETWORK_IS_GAME_AND_PLAYER_READY()
{
	if (0 == (int)ReadByte(0x1D65D91) && NETWORK_IS_GAME_IN_PROGRESS() == true) return true;
	else return false;
}
bool IS_GAME_AND_PLAYER_READY()
{
	if (0 == (int)ReadByte(0x1D65D91))
	{
		if(!NETWORK_IS_GAME_IN_PROGRESS())
		{
			 return true;
		} else return false;
	}
	else return false;
	return false;
}
bool IsScriptActived(const char* scriptname)
{
	if (_GET_NUMBER_OF_INSTANCES_OF_SCRIPT_WITH_NAME_HASH(GET_HASH_KEY(scriptname)) > 0) return true;
    else return false;
}
void RequestControlOfid(Entity netid);
void TeleportMe(Ped ped, float x, float y, float z);
void TeleporttoNearestCar();
void TeleportWaypoint();
