int BKG_R = 0;
int BKG_G = 0;
int BKG_B = 0;
int BannerR = 216;
int BannerG = 18; 
int BannerB = 16;
int timerLoading;
int RandCheckBox = 0;
int RandomCLR;
int SelClrR = 0;
int SelClrG = 0;
int SelClrB = 255;
int TitleFont = 0;
int OptionsFont = 0;
int gGlareHandle; // int
int OpenMenuTimer = 0;
int maxTimerCount;
int TextTimer = 0,
 CreditTextTimer = 0,
 lastButtonPress = 0,
 buttonPressDelay = 200,
 NumMenu = 0,
 NumMenuLevel,
 lastNumMenu[20],
 lastOption[20],
 currentOption,
 optionCount,
 SELECTED_INDEX,
 maxOptions = 25,
 player_count =0;
bool EnableMusic = true;
bool SelectedItem;
bool SelectedItem4;
bool  PressX = false;
bool  rightPress = false;
bool  leftPress = false;
bool  fastRPress = false;
bool  fastLPress = false;
bool WhiteColor;
bool WhiteColor_toggle;
bool newTimerTick = true;
#define GlobalCharBufferD "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
#define NULL 0
char* InfoText = "";
char* SONG;
 char* CreditText = " ";
char* GlobalCharBuffer0 = GlobalCharBufferD;//256
float 
 CenterDraw = 0.26f,
 Menu_X = 0.758,
 Title_X = 0.6350,
 Cunt = 0.648,
 CuntStat = 0.853;
float GlareX = 1.1499, GlareY = 0.4550, GlareXs = 1.1529, GlareYs = 0.8350;