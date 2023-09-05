#include<stdio.h>

//Fayyaz
void DrawObstacle(){
    iShowBMP(ObstacleX,ObstacleY,"obs1.bmp");
}


void DrawObstacle1(){
    iShowBMP(Obstacle1X,Obstacle1Y,"obs2.bmp");
}


void Missile(){
	iShowBMP(MissileX,MissileY,"missile.bmp");
	MissileX-=ObstacleSpeed[GameMode];
	if (MissileX < 0) MissileX = ScrWidth + 600 + rand() % 100;
}


//TURAG
void ChangeObstacle(){  //obs 1
	ObstacleX-=ObstacleSpeed[GameMode];								//Obstacle Moves at given Speed
    if(ObstacleX<0){
		ObstacleX = ScrWidth;							//Bring obstacle to the right when it crosses left
	}
}


void ChangeObstacle1(){ //obs 2
	Obstacle1X-=ObstacleSpeed[GameMode];							//Obstacle Moves at given Speed
    if(Obstacle1X<0){
		Obstacle1X = ScrWidth + rand()%400 + 400;		//so that obstacles may come at a distance
	}
}



void DetectCollision(){  //obs 1 collision
	if(ObstacleX < boyX+64 && ObstacleX > boyX+64-ObstacleSpeed[GameMode]-1 && boyY < ObstacleY+128){
		iShowBMP(boyX, boyY, "ag.bmp");
		PlaySound("ouch.wav", NULL, SND_ASYNC); //Fay
		GameState.Life-=1;  //life decrease
    }
	else if (ObstacleX < boyX+64 && ObstacleX > boyX+64-ObstacleSpeed[GameMode]-1 && boyY > ObstacleY+128){
		GameState.ScoreValue += 10;						//increase score 10 if avoid obstacle 
	}
}
//TURAG
void DetectCollision1(){ //SCORE //obs2 collision
	if(Obstacle1X < boyX+64 && Obstacle1X > boyX+64-ObstacleSpeed[GameMode]-1 && boyY < Obstacle1Y+128){
		iShowBMP(boyX, boyY, "ag.bmp");
		PlaySound("ouch.wav",NULL,SND_ASYNC); //Music
		GameState.Life-=1; 
    }
	else if(Obstacle1X < boyX+64 && Obstacle1X > boyX+64-ObstacleSpeed[GameMode]-1 && boyY > Obstacle1Y+64) {
		GameState.ScoreValue += 10;						//increase score 10 if avoid obstacle
	}
}


void DetectExplosion(){
	if (MissileX < boyX + 64 && MissileX > boyX + 64 - ObstacleSpeed[GameMode] - 1 && boyY > MissileY + 48){
		//PlaySound("ouch.wav", NULL, SND_ASYNC); //music
		GameState.Life -= 0;
	}
	else if (MissileX < boyX + 64 && MissileX > boyX + 64 - ObstacleSpeed[GameMode] - 1 && boyY < MissileY + 48){
		GameState.ScoreValue += 1;
	}
}
