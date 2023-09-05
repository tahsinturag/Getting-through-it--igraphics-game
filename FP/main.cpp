# include "iGraphics.h"			//iGraphics Is an OpenGL
# include "LoadGame.h"			//Contains Load From File & GameState Structure 
# include "GlobalVars.h"		//Contains All The Global Variables
# include "GamePlayAnimation.h"	//Contains Run, Jump, Crouch Animations
# include "Obstacle.h"			//Contains Obstacle Drawing, Movement, Collision Detection Funcs
# include "ShowStatistics.h"	//TimeCount, Score Increase, Draw Stats to the Screen
# include "SkyAnimation.h"		//Contains SkyBackGround, Cloud, Birds
# include "DrawGameStates.h"	//Draws the screen for each of the gamestates
# include <stdio.h>

//using namespace std;

bool musicOn = true;
//drawGameState
void iDraw(){  //fayyaz
	iClear();													//Clear and refreshes screen every gameloop
	iSetColor(0, 0, 0);											//Sets Color to rgb000 as in black
	if (GameCurrentState == MainMenuState){ 
		DrawMainMenu();
	}
	else if (GameCurrentState == GamePlayState){					//Game Play
		DrawGamePlay();
	}
	else if (GameCurrentState == PauseMenuState){					//Pause Menu
		DrawPauseMenu();
	}
	else if (GameCurrentState == HighScoreState){					//HighScore
		DrawHighScore();
	}
	else if (GameCurrentState == SettingsState){					//Settings
		DrawSettings();
	} 
	
	else if (GameCurrentState == AboutState){						//About
		DrawAbout();
	}
	else if (GameCurrentState == ExitState){						//Exit
		exit(0);
	}
	else if (GameCurrentState == GameOverState){					//Game Over
		DrawGameOver();
	}
}


void iKeyboard(unsigned char key){} //FOR other key like arrow

void iSpecialKeyboard(unsigned char key)
{
	if (key == GLUT_KEY_UP){   //Turag
		if (Crouch) Crouch = false;
		else Jump = true;
	}
	if (key == GLUT_KEY_DOWN){
		Crouch = true;
	}
	if (key == GLUT_KEY_F1){
		GameCurrentState *= -1;
	}

	if (key == GLUT_KEY_END){
		exit(0);
	}
}

void iMouseMove(int mx, int my){}

void iMouse(int button, int state, int mx, int my){
	//Fayyaz
	if (GameCurrentState == PauseMenuState){	 //pause button							
		if (mx>600 && mx<600 + 128 && my>600 && my<600 + 64){
			GameCurrentState = GamePlayState; //Resume //repeat vabe game shuru
		}

		else if (mx>600 && mx<600 + 128 && my>500 && my<500 + 64){			//Save And Exit Button
			FILE *SaveGameStats;                         //FILE diye data save
			SaveGameStats = fopen("saved.txt", "w");
			fprintf(SaveGameStats, "%d %d %d\n", GameState.Life, GameState.TimeLeft, GameState.ScoreValue);
			fclose(SaveGameStats);

			if (GameState.ScoreValue>HighScore){ //new highscore save
				HighScore = GameState.ScoreValue;
				FILE *HighScorePtr;
				HighScorePtr = fopen("highscore.txt", "w");
				fprintf(HighScorePtr, "%d\n", HighScore);
				fclose(HighScorePtr);
			}
			GameCurrentState = MainMenuState;  //Quit
		}


		else if (mx>600 && mx<600 + 128 && my>400 && my<400 + 64){			//Main Menu
			GameCurrentState = MainMenuState;
			if (GameState.ScoreValue>HighScore){
				HighScore = GameState.ScoreValue;
				FILE *HighScorePtr;
				HighScorePtr = fopen("highscore.txt", "w");
				fprintf(HighScorePtr, "%d\n", HighScore);
				fclose(HighScorePtr);
			}
		}
	}
	//ALIF
	if (GameCurrentState == MainMenuState){
		if (mx>100 && mx<356 && my>600 && my<664){			//New Game
			GameCurrentState = GamePlayState;
			LoadNew = 1;
			LoadGame(LoadNew);
		}
		
		else if (mx>100 && mx<356 && my>500 && my<564){		//Continue Game
			GameCurrentState = GamePlayState;
			LoadNew = 0; //false
			LoadGame(LoadNew); //loadgame.h 
		}
	
		//ALIF
		else if (mx>100 && mx<356 && my>400 && my<464){		//High Score
			GameCurrentState = HighScoreState;
		}
		else if (mx>100 && mx<356 && my>300 && my<364){		//Settings 
			GameCurrentState = SettingsState;
		}
		else if (mx>100 && mx<356 && my>200 && my<264){		//About
			GameCurrentState = AboutState;
		}
		if (mx>100 && mx<356 && my>100 && my<164){			//Exit
			GameCurrentState = ExitState;
		}
	}


	if (GameCurrentState == GamePlayState){
		if (mx>50 && mx<50 + 64 && my>ScrHeight - 100 && my<ScrHeight - 100 + 64){
			GameCurrentState = PauseMenuState;
		}
	}

	if (GameCurrentState == HighScoreState){
		if (mx>50 && mx<50 + 64 && my>ScrHeight - 100 && my<ScrHeight - 100 + 64){
			GameCurrentState = MainMenuState;
		}
	}

	if (GameCurrentState == SettingsState){
		if (mx>50 && mx<50 + 64 && my>ScrHeight - 100 && my<ScrHeight - 100 + 64){
			GameCurrentState = MainMenuState;
		}
		//Alif
		if (mx>400 && mx<528 && my>500 && my<564){				//difficulty level, Easy selected
			GameMode = 1;
		}
		if (mx>800 && mx<928 && my>500 && my<564){				////difficulty level, Hard selected
			GameMode = 2;
		}
		
	}

	if (GameCurrentState == AboutState){
		if (mx>50 && mx<50 + 64 && my>ScrHeight - 100 && my<ScrHeight - 100 + 64){
			GameCurrentState = MainMenuState;
		}
	}

	if (GameCurrentState == ExitState){
		if (mx>50 && mx<50 + 64 && my>ScrHeight - 100 && my<ScrHeight - 100 + 64){
			GameCurrentState = MainMenuState;
		}
	}

	if (GameCurrentState == GameOverState){
		if (mx>50 && mx<50 + 64 && my>ScrHeight - 100 && my<ScrHeight - 100 + 64){
			GameCurrentState = MainMenuState;
			LoadNew = 1;
		}
	}
}

int main(){
	LoadGame(1);
	itoa(GameState.Life,LifeValueStr,05);//for score print //int  to char
	itoa(GameState.TimeLeft,TimeValueStr,05);
	itoa(GameState.ScoreValue,ScoreValueStr,05); //wtf
	//Turag
	iSetTimer(250,ScoreIncrease);  //i set 250 mm por f call 
	iSetTimer(1000, TimeCount);
	iSetTimer(ObstacleFrameRate,ChangeObstacle); //obstacle,h
	iSetTimer(Obstacle1FrameRate, ChangeObstacle1);
		iSetTimer (500, Clouds);
	
		//fayyaz
		if (musicOn);
	PlaySound("music//Tmusic.wav",NULL, SND_ASYNC);
	 //PlaySound("music//yb.wav", NULL, SND_LOOP | SND_ASYNC);
	iInitialize(ScrWidth, ScrHeight, "Getting Through It");  //Window Initialization

	return 0;
}


