#include<stdio.h>  //Contains Load From File & GameState Structure 

struct GameState{   //structure
	int Life;
	int TimeLeft;
	int ScoreValue;
} GameState;

//File er kaaj
void LoadGame(int LoadType){									//LoadType: 0 false load--> saved game, 
	                                                              //1 New Game
	FILE *InputLoadGameStatPtr;
	FILE *InputSaveGameStatPtr;
	
	if(LoadType){												// True statement 
		                                                        //1 Loads the -->"new" default values for life, Time, Score
		InputLoadGameStatPtr = fopen("load.txt","r");			
		fscanf(InputLoadGameStatPtr,"%d %d %d",&GameState.Life,&GameState.TimeLeft,&GameState.ScoreValue);
		//fclose(InputGameStatPtr);
	}

	//Alif
	else if(!LoadType){	          // 0 means False statement --> "saved.txt" 
		InputSaveGameStatPtr = fopen("saved.txt","r");			// requires to read file only
		fscanf(InputSaveGameStatPtr,"%d %d %d",&GameState.Life,&GameState.TimeLeft,&GameState.ScoreValue);
		
	} 
	
}

