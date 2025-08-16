

	void SetMemory(int Address, byte Data[], int byteSize)
{
    for(int i = 0; i < byteSize; i++)
        *(byte *)(Address + i) = Data[i];
}
unsigned int ReadUint32(int Address)
	{
		return *(unsigned int*)Address;
	}
void WriteByte(int Address, unsigned char Input)
	{
		*(unsigned char*)Address = Input;
	}
			
	
		int ReadInt32(int Address)
	{
		return *(int*)Address;
	}
	
	

	void WriteBool(int Address, bool Input)
	{
		WriteByte(Address, (int)Input);
	}
	void WriteBytes(int address, char* input, int length)
	{
		for (int i = 0; i < length; i++)
		{
			*(char*)(address + (i)) = input[i];
		}
	}
char byteArray[100];
	char* ReadBytes(int address, int length)
	{
		for (int i = 0; i < length; i++)
		{
			byteArray[i] = *(char*)(address + (i));
		}
		return byteArray;
	}
	char returnRead[100];

	void WriteString(int address, char* string)
	{
		int FreeMem = 0x1D00000;
		int strlength = GET_LENGTH_OF_LITERAL_STRING(string);
		char* strpointer = *(char**)FreeMem = string;
		char* StrBytes = ReadBytes(*(int*)FreeMem, strlength);
		WriteBytes(address, StrBytes, strlength);
		*((char*)address + strlength) = '\0';
	}
	

	char* ReadString(int address)
	{
		memset(&returnRead[0], 0, sizeof(returnRead));
		int strlength = 100;
		char* StrBytes = ReadBytes(address, strlength);
		for (int i = 0; i < strlength; i++)
		{
			if (StrBytes[i] != 0x00)
				returnRead[i] = StrBytes[i];
			else
				break;
		}
		return returnRead;
	}

	void WriteInt32(int Address, int Input)
	{
		*(int*)Address = Input;
	}
	float intArray[100];
	float* ReadInt(int address, int length)
	{
		for (int i = 0; i < length; i++)
		{
			intArray[i] = *(int*)(address + (i * 0x04));
		}
		return intArray;
	}

	
void WriteFloat(int Address, float Input)
	{
		*(float*)Address = Input;
	}

	

	void WriteSingle(int Address, float Input, int Length)
	{
		for (int i = 0; i < Length; i++)
			WriteFloat(Address + (i * 4), Input);
	}
	float floatArray[100];
	float ReadFloat(int address, int length)
	{
		for (int i = 0; i < length; i++)
		{
			floatArray[i] = *(float*)(address + (i * 0x04));
		}
		return *floatArray;
	}

	float ReadSingleFloat(int Address)
	{
		return *(float*)Address;
	}

	float* ReadSingle(int Address, int Length)
	{
		float* Value;
		for (int i = 0; i < Length; i++)
			Value[i] = ReadSingleFloat(Address + (i * 4));
		return Value;
	}

	

	  unsigned char ReadByte(int Address)
	{
		return *(unsigned char*)Address;
	}
	
	bool ReadBool(int Address)
	{
		return ReadByte(Address) != 0;
	}

