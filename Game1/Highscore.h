#include<stdio.h>
void highScoreFunction(){

	FILE *fp = fopen("highscore.txt", "r");

	fscanf(fp, "%d", &highscore);

	sprintf(highscores, "%d", highscore);

	fclose(fp);
}

void highScoreCalculation(){
	final = Score;
	FILE *fp = fopen("highscore.txt","r");

	fscanf(fp, "%d", &highscore);

	if(highscore < final)
	{
		highscore = final;
		FILE *fp = fopen("highscore.txt", "w");
		fprintf(fp, "%d", highscore);

		fclose(fp);
	}
	fclose(fp);
}