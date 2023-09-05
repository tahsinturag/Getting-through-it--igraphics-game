#include<stdio.h> //Contains All The Global Variables

# define ScrWidth 1280
# define ScrHeight 720

enum States{					//Definition of Game-State variables
	PauseMenuState = -1, MainMenuState, GamePlayState, HighScoreState, SettingsState, AboutState, ExitState, GameOverState 
};


int LoadNew=1;								// 1 to load new game by default
char LifeValueStr[99],TimeValueStr[99999],ScoreValueStr[99999];
int bgX=0,bgY=0, CloudX=ScrWidth, CloudY=ScrHeight/2, Cloud1X=ScrWidth+300, Cloud1Y=2*ScrHeight/3;//CLOUD KOTHAY URBE
int BirdX=ScrWidth, BirdY=ScrHeight/2, Bird1X = ScrWidth+300, Bird1Y = ScrHeight/2+100;



//TURAG //RENDERING
char RunAnime[5][10]={"1.bmp","2.bmp","3.bmp","4.bmp","5.bmp"};//using double array for movement
char BirdAnime[8][8]={"b1.bmp","b1.bmp","b1.bmp","b1.bmp","b2.bmp","b2.bmp","b2.bmp","b2.bmp"};
char JumpAnime[10]={"Jump.bmp"}, CrouchAnime[20]={"Crouch.bmp"};
int initialBoyY=45, initialBoyX=160;
int boyX = initialBoyX, boyY = initialBoyY;
int ScoreValue = 0;
char ScoreString[500];
int RunIndex=0,BirdIndex=0,Bird1Index=0;
bool Jump=false, Crouch=false;



int GameCurrentState = MainMenuState;		//0 Main Menu, 1 GamePlay, 2 HighScore, 3 Settings, 4 About,  5 Exit,  -1 PauseMenu,  6 Game Over Screen

int GameMode = 1;						//variable declare	// 1. Easy

int HighScore = 0;
char HighScoreValue[10];
int JumpLimit[3]={250,250,300} , up=1, JumpSpeed[3] = {25,25,30};

int ObstacleX= ScrWidth, ObstacleY = initialBoyY, ObstacleSpeed[3] = {20,14,11}; //obstacle MOVEMENT
int Obstacle1X= ScrWidth+500, Obstacle1Y = initialBoyY;
int ObstacleFrameRate = 35, Obstacle1FrameRate = 35,ObstacleAvoidSuccess = 0; //Obstacle2FrameRate=35
int MissileX = ScrWidth+900, MissileY = 196;//96