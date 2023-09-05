#include<stdio.h>   //TimeCount, Score Increase, Draw Stats to the Screen
//TURAG
void TimeCount(){
	GameState.TimeLeft--; //TIME 
}

void ScoreIncrease(){
	GameState.ScoreValue++; //for running score increase
}

void ShowStats(){
	
	iText(ScrWidth-140,ScrHeight-50,"Life: ",GLUT_BITMAP_HELVETICA_18);//SCREEN E PRINT
	sprintf(LifeValueStr,"%d",GameState.Life);

	iText(ScrWidth-100,ScrHeight-50,LifeValueStr,GLUT_BITMAP_HELVETICA_18);
	sprintf(TimeValueStr,"Time Left: %d s",GameState.TimeLeft);
	iText(ScrWidth-140,ScrHeight-75,TimeValueStr,GLUT_BITMAP_HELVETICA_18);
	sprintf(ScoreValueStr,"Score: %d",GameState.ScoreValue); 
	iText(ScrWidth-140,ScrHeight-100,ScoreValueStr,GLUT_BITMAP_HELVETICA_18);	
	iText(20,ScrHeight-20,"Press F1 To Pause/Resume",GLUT_BITMAP_HELVETICA_12);
	
}