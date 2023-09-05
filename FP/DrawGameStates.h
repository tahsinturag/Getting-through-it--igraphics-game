# include <stdio.h> //Draws the screen for each of the gamestates

void DrawMainMenu(){
	//main menu goes here
	iPauseTimer(0);
	iPauseTimer(1);
	iPauseTimer(2);
	iPauseTimer(3);
	iPauseTimer(4);
	FILE *HighScoreShow;
	HighScoreShow = fopen("highscore.txt","r");
	fscanf(HighScoreShow,"%d",&HighScore);
	//ALIF
	iShowBMP(0,0,"menu.bmp");
	iShowBMP(100,600,"newgame.bmp");
	iShowBMP(100,500,"loadgame.bmp");
	iShowBMP(100,400,"highscore.bmp");
	iShowBMP(100,300,"Dificulty1.bmp");
	iShowBMP(100,200,"about.bmp");
	iShowBMP(100,100,"exit.bmp");
}

void DrawPauseMenu(){
	iShowBMP(0,0,"pausebg.bmp");
	iPauseTimer(0);//PAUSE
	iPauseTimer(1);
	iPauseTimer(2);
	iPauseTimer(3);
	iPauseTimer(4);
	iShowBMP(600, 600,"presume.bmp");
	iShowBMP(600, 500,"psaveexit.bmp");
	iShowBMP(600, 400,"pquit.bmp");
	
}

void DrawGamePlay(){
	iResumeTimer(0);
	iResumeTimer(1);
	iResumeTimer(2);
	iResumeTimer(3);
	iResumeTimer(4);
	BackgroundImage();

	Birds();
	Birds1();
	Clouds();
	Clouds1();

	iShowBMP(50,ScrHeight-100,"pause.bmp");
	DrawObstacle();
	if(GameMode==2) DrawObstacle1(); 
	DetectCollision();

	if(GameMode==2) DetectCollision1();
	Missile();
	DetectExplosion();
	RunAnimation();
	//Final Gameover //Turag
	ShowStats();
	if(GameState.Life<1 || GameState.TimeLeft<0){
		GameCurrentState=GameOverState;
	}
}
//ALIF
void DrawHighScore(){
	iShowBMP(0,0,"hig.bmp");
	iShowBMP(50,ScrHeight-100,"backtohome.bmp");
	iFilledRectangle(164, ScrHeight*0.05, 5, ScrHeight*0.9); 
	FILE *HighScoreShow; //file create
	HighScoreShow = fopen("highscore.txt","r"); //read
	fscanf(HighScoreShow,"%d",&HighScore);

	sprintf(HighScoreValue,"HIGHSCORE: %d",HighScore);
	iText(ScrWidth/2.2,ScrHeight/2,HighScoreValue,GLUT_BITMAP_TIMES_ROMAN_24);
}
//ALIF 100
	void DrawSettings(){
	iShowBMP(0,0,"Dificulty.bmp");//screen show
	iShowBMP(50,ScrHeight-100,"backtohome.bmp");
	//iFilledRectangle(164,ScrHeight*0.05,5,ScrHeight*0.9);
	//iShowBMP(200,ScrHeight*0.85,"difficulty.bmp");
	iShowBMP(800,500,"hard.bmp");
	iShowBMP(400,500,"easy.bmp");
	if(GameMode ==1) iText(900,100,"EASY DIFFICULTY SELECTED",GLUT_BITMAP_HELVETICA_18);
	if(GameMode ==2) iText(900,100,"HARD DIFFICULTY SELECTED",GLUT_BITMAP_HELVETICA_18);
		

}

	//ALIF
void DrawAbout(){
	iShowBMP(0,0,"tu.bmp");
	iShowBMP(50,ScrHeight-100,"backtohome.bmp");
	//iFilledRectangle(164,ScrHeight*0.05,5,ScrHeight*0.9);
}

//Turag 100
void DrawGameOver(){
	iShowBMP(0,0,"gameover.bmp");
	iShowBMP(50,ScrHeight-100,"backtohome.bmp");
	sprintf(ScoreValueStr,"Score: %d",GameState.ScoreValue); 
	iText(ScrWidth / 2, ScrHeight / 2 - 115, ScoreValueStr, GLUT_BITMAP_TIMES_ROMAN_24);
	
	if(GameState.ScoreValue>HighScore){ //save increase highscore 
		HighScore = GameState.ScoreValue;
		FILE *HighScorePtr;
		HighScorePtr = fopen("highscore.txt","w");
		fprintf(HighScorePtr,"%d\n",HighScore);
		fclose(HighScorePtr);
	}
	iPauseTimer(0);
}