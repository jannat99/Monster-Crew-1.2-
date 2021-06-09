# include "iGraphics.h"
#include "bitmap_loader.h"
#include "Variables.h"
#include "Highscore.h"
#include "jumpingMethods.h"
#include "collisionMethods.h"

void iDraw()
{
	///////////////// gamestate = -2 ---> logo /////////////////////
	///////////////// gamestate = -1 ---> menubar /////////////////////
	///////////////// gamestate = 1 ---> highscore /////////////////////
	///////////////// gamestate = 2 ---> control page /////////////////////
    ///////////////// gamestate = 3 ---> level1 starts  /////////////////////
	///////////////// gamestate = 4 ---> gameover page /////////////////////
	///////////////// gamestate = 5 ---> credits page /////////////////////
	///////////////// gamestate = 10 ---> level2 starts /////////////////////
	///////////////// gamestate = 11 ---> level3 starts /////////////////////
	///////////////// gamestate = 20 ---> success page /////////////////////
	///////////////// gamestate = 100 ---> level1 completed page /////////////////////
	///////////////// gamestate = 200 ---> level2 completed page /////////////////////


	iClear();

	////////////////logo page////////////////////
	if(gameState == -2)
	{
		iShowImage(0,0,972,583,monstercrew);
		iText(100,40,"Click on the screen to continue",GLUT_BITMAP_HELVETICA_18);
	}

	///////////////homemenu page/////////////////
	else if(gameState == -1)
	{
		iShowImage(0,0, 972, 583,homemenu);
 
		
	    iShowImage(100,400,180,60,newgame);
	    iText(100+180, 400+30, "(or press 'a')",GLUT_BITMAP_HELVETICA_18);
	    iShowImage(90,265,210,120,highscoreicon);
		iText(100+180, 310+27, "(or press 'e')",GLUT_BITMAP_HELVETICA_18);
	    iShowImage(100,220,180,50,controls);
		iText(100+180, 220+25, "(or press 'r')",GLUT_BITMAP_HELVETICA_18);
		iShowImage(100,130,180,50,credits);
		iText(100+180, 130+25, "(or press 'c')",GLUT_BITMAP_HELVETICA_18);
		iShowImage(90,40,195,50,back);
		iText(100+180, 40+25, "(or press 'x')",GLUT_BITMAP_HELVETICA_18);
	}

	///////////////////highscores//////////////////
	else if(gameState==1)
	{
		iShowImage(0, 0, 972, 583, homemenu);
		highScoreFunction();
		iText(550, 300, highscores, GLUT_BITMAP_HELVETICA_18);
		iText(375, 300, "HIGHSCORE:", GLUT_BITMAP_HELVETICA_18);
		iShowImage(370, 200, 180, 50, reset);
		iText(300, 100, "Press 'q' or click on the home icon to go back to homemenu", GLUT_BITMAP_HELVETICA_18);
		iShowImage(0, 0, 70, 70, homeicon);
		highScoreCalculation();
	}

	//////////////////instructions/////////////////
	else if(gameState==2)
	{
		iShowImage(0, 0, 972, 583, controlspage);
		iText(300, 100, "Press 'q' or click on the home icon to go back to homemenu", GLUT_BITMAP_HELVETICA_18);
		iShowImage(0, 0, 70, 70, homeicon);
	}

	////////////////////Game Over page//////////////////////
	else if(gameState == 4)
	{
		iShowImage(0, 0, 972, 583, gameOver);
	}

	////////////////////success page//////////////////
	else if(gameState == 20)
	{
		iShowImage(0, 0, 972, 583, finishpage);
	}

	//////////////////////Credits/////////////////////
	else if(gameState == 5)
	{
		iShowImage(0, 0, 972, 583, creditspage);
		iText(300, 100, "Press 'q' or click on the home icon to go back to homemenu", GLUT_BITMAP_HELVETICA_18);
		iShowImage(0, 0, 70, 70, homeicon);
		//iShowBMP(0, 0, "images\\creditspage-972x583.bmp");
	}

	/////////////////////if level1 completes this page shows up////////////////
	else if(gameState == 100)
	{
		iShowImage(0, 0, 972, 583, homemenu);
		iText(300, 256, "Level1 completed", GLUT_BITMAP_HELVETICA_18);
		iText(300, 220, "Click on screen to go to next level", GLUT_BITMAP_HELVETICA_18);
	}

	////////////////////if level2 completes this page shows up/////////////////
	else if(gameState == 200)
	{
		iShowImage(0, 0, 972, 583, homemenu);
		iText(300, 256, "Level2 completed", GLUT_BITMAP_HELVETICA_18);
		iText(300, 220, "Click on screen to go to next level", GLUT_BITMAP_HELVETICA_18);
	}

	//////////////////////////level1 starts/////////////////////////////////////////
	else if(gameState == 3)
	{
	level1_monsx=585;
	level1_monsy=45;
	iShowBMP(0, 0, "images\\Capture4.bmp");
	iShowImage(level1_monsx, level1_monsy, 450, 500, level1_image5);
	iShowImage(0,0,50,50,level1_heartlives);
	if(level1_monstercol)
	{
	iShowImage(level1_monspow_posx, level1_monspow_posy, 100, 100, level1_image7);
		 level1_monspow_posx -= 5;
		if(level1_monspow_posx == 130)
		{
		level1_monspow_posx = level1_monspow_posx - 3;
		level1_monspow_posx = 580;
		level1_monspow_posy = rand() % (700 + 50);
		level1_monstercol = false;
		}

	}
	if(!level1_monstercol){
		level1_monstercol = true;
	}
		level1_jumping();
		sprintf_s(scores, "Score: %d", Score);
		iText(10, 70, scores, GLUT_BITMAP_HELVETICA_18);
		sprintf_s(level1_printLives, "%d", level1_lives);
		iText(20, 20, level1_printLives, GLUT_BITMAP_HELVETICA_18);
		iSetColor(102, 255, 102);
		iText(0, 560, "Level 1", GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(0, 255, 0);
		iText(565, 560, "Shoot on the head 3 times to kill the monster fast", GLUT_BITMAP_HELVETICA_18);
		iText(160,550,"Press 'x' or the cross button to exit",GLUT_BITMAP_HELVETICA_18);
		iSetColor(255, 255, 255);
		highScoreFunction();
		highScoreCalculation();

//::::::::::::::::::::::::::::::::Collision codes of level1 are here::::::::::::::::::::::::::::::
	 if(level1_icecollision)
	 {   
		 level1_iceball_posy = level1_iceShootingPositiony;
		 iShowImage(level1_iceball_posx, level1_iceball_posy, 43, 55, level1_image2);
		 level1_iceball_posx += 5;
		if(level1_iceball_posx + level1_cartoon_posx == 680)
		{
		level1_iceball_posx = level1_iceball_posx - level1_iceballspeed;
		level1_iceball_posx = 250;
		level1_icecollision = false;
		}
	 }
	  if(level1_firecollision)
	 {
		 level1_fireball_posy = level1_fireShootingPositiony;
		 iShowImage(level1_fireball_posx + level1_cartoon_posx, level1_fireball_posy + level1_cartoon_posy, 43, 55, level1_image1);
		 level1_fireball_posx += 5;
		if(level1_fireball_posx + level1_cartoon_posx== 680)
		{
		level1_fireball_posx = level1_fireball_posx - level1_fireballspeed;
		level1_fireball_posx = 250;
		level1_firecollision = false;
		}
	 }
	   if(level1_boltcollision)
	 {
		 level1_bolt_posy = level1_boltShootingPositiony;
		 iShowImage(level1_bolt_posx + level1_cartoon_posx, level1_bolt_posy + level1_cartoon_posy, 43, 55, level1_image6);
		 level1_bolt_posx += 5;
		if(level1_bolt_posx + level1_cartoon_posx == 680)
		{
		level1_bolt_posx = level1_bolt_posx - level1_boltspeed;
		level1_bolt_posx = 250;
		level1_boltcollision = false;
		}
	 }
	  
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

}
/////////////////////////////////////////////////////////

///////////////// level2 starts /////////////////////////
else if(gameState == 10){
	iShowBMP(0, 0, "images\\dessert4.bmp");
	level2_monsx=560;
	level2_monsy=45;
	iShowImage(level2_monsx, level2_monsy, 450, 450, level2_image5);
	iShowImage(0,0,50,50,level2_heartlives);
	if(level2_monstercol)
	{
	iShowImage(level2_monspow_posx, level2_monspow_posy, 100, 100, level2_image7);
		 level2_monspow_posx -= 5;
		if(level2_monspow_posx == 130)
		{
		level2_monspow_posx = level2_monspow_posx - 3;
		level2_monspow_posx = 580;
		level2_monspow_posy = rand() % (700 + 50);
		level2_monstercol = false;
		}

	}
	if(!level2_monstercol){
		level2_monstercol = true;
	}
	iSetColor(102, 51, 0);
	iText(565, 560, "Shoot on the head 4 times to kill the monster fast", GLUT_BITMAP_HELVETICA_18);
	iText(160,550,"Press 'x' or the cross button to exit",GLUT_BITMAP_HELVETICA_18);
	iText(0, 560, "Level 2", GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(0, 0, 0);
		level2_jumping();
		sprintf_s(scores, "Score: %d", Score);
		iText(10, 70, scores, GLUT_BITMAP_HELVETICA_18);
		sprintf_s(level2_printLives, "%d", level2_lives);
		iText(20, 20, level2_printLives, GLUT_BITMAP_HELVETICA_18);
		highScoreFunction();
		highScoreCalculation();

//:::::::::::::::::::::::::::::Collision codes for level2 are here:::::::::::::::::::::::::::::::::::::::
	 if(level2_icecollision)
	 {   
		 level2_iceball_posy = level2_iceShootingPositiony;
		 iShowImage(level2_iceball_posx, level2_iceball_posy, 43, 55, level2_image2);
		 level2_iceball_posx += 5;

		if(level2_iceball_posx + level1_cartoon_posx == 680)
		{
		level2_iceball_posx = level2_iceball_posx - level2_iceballspeed;
		level2_iceball_posx = 250;
		level2_icecollision = false;
		}
	 }
	  if(level2_firecollision)
	 {
		 level2_fireball_posy = level2_fireShootingPositiony;
		 iShowImage(level2_fireball_posx + level2_cartoon_posx, level2_fireball_posy + level2_cartoon_posy, 43, 55, level2_image1);
		 level2_fireball_posx += 5;

		if(level2_fireball_posx + level2_cartoon_posx == 680)
		{
		level2_fireball_posx = level2_fireball_posx - level2_fireballspeed;
		level2_fireball_posx = 250;
		level2_firecollision = false;
		}
	 }
	   if(level2_boltcollision)
	 {
		 level2_bolt_posy = level2_boltShootingPositiony;
		 iShowImage(level2_bolt_posx + level2_cartoon_posx, level2_bolt_posy + level2_cartoon_posy, 43, 55, level2_image6);
		 level2_bolt_posx += 5;

		if(level2_bolt_posx + level2_cartoon_posx == 680)
		{
		level2_bolt_posx = level2_bolt_posx - level2_boltspeed;
		level2_bolt_posx = 250;
		level2_boltcollision = false;
		}
	 }
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	  iSetColor(255, 255, 255);

	}
//////////////////////////////////////////////////

////////////////////// level3 starts //////////////
else if(gameState == 11){
	iShowBMP(0, 0, "images\\castle4.bmp");
	level3_monsx=560;
	level3_monsy=40;
	iShowImage(level3_monsx, level3_monsy, 390, 490, level3_image5);
	iShowImage(0,0,50,50,level3_heartlives);
	if(level3_monstercol)
	{
	iShowImage(level3_monspow_posx, level3_monspow_posy, 100, 100, level3_image7);
		 level3_monspow_posx -= 6;
		if(level3_monspow_posx == 130)
		{
		level3_monspow_posx = level3_monspow_posx - 3;
		level3_monspow_posx = 580;
		level3_monspow_posy = rand() % (700 + 50);
		level3_monstercol = false;
		}

	}
	if(!level3_monstercol){
		level3_monstercol = true;
	}
		level3_jumping();
		sprintf_s(scores, "Score: %d", Score);
		iText(10, 70, scores, GLUT_BITMAP_HELVETICA_18);
		sprintf_s(level3_printLives, "%d", level3_lives);
		iText(20, 20, level3_printLives, GLUT_BITMAP_HELVETICA_18);
		iSetColor(0, 0, 255);
		iText(0, 560, "Level 3", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(160,550,"Press 'x' or the cross button to exit",GLUT_BITMAP_HELVETICA_18);
		iText(560, 560, "Shoot on the head 5 times to kill the monster fast", GLUT_BITMAP_HELVETICA_18);;
		iSetColor(255, 255, 255);
		highScoreFunction();
		highScoreCalculation();

//:::::::::::::::::::::::::::::Collision codes of level3 are here:::::::::::::::::::::::::::::::
	 if(level3_icecollision)
	 {   
		 level3_iceball_posy = level3_iceShootingPositiony;
		 iShowImage(level3_iceball_posx, level3_iceball_posy, 43, 55, level3_image2);
		 level3_iceball_posx += 5;
		if(level3_iceball_posx + level1_cartoon_posx == 680)
		{
		level3_iceball_posx = level3_iceball_posx - level3_iceballspeed;
		level3_iceball_posx = 250;
		level3_icecollision = false;
		}
	 }
	  if(level3_firecollision)
	 {
		 level3_fireball_posy = level3_fireShootingPositiony;
		 iShowImage(level3_fireball_posx + level3_cartoon_posx, level3_fireball_posy + level3_cartoon_posy, 43, 55, level3_image1);
		 level3_fireball_posx += 5;
		if(level3_fireball_posx + level3_cartoon_posx == 680)
		{
		level3_fireball_posx = level3_fireball_posx - level3_fireballspeed;
		level3_fireball_posx = 250;
		level3_firecollision = false;
		}
	 }
	   if(level3_boltcollision)
	 {
		 level3_bolt_posy = level3_boltShootingPositiony;
		 iShowImage(level3_bolt_posx + level3_cartoon_posx, level3_bolt_posy + level3_cartoon_posy, 43, 55, level3_image6);
		 level3_bolt_posx += 5;
		if(level3_bolt_posx + level3_cartoon_posx == 680)
		{
		level3_bolt_posx = level3_bolt_posx - level3_boltspeed;
		level3_bolt_posx = 250;
		level3_boltcollision = false;
		}
	 }
	  
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
}
//////////////////////////////////////////////////////////

}



void iMouseMove(int mx, int my)
{
}


void iMouse(int button, int state, int mx, int my)
{
if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		
		if(gameState == 20){
			if(mx>=0 && mx<=972 && my>=0  && my<=583)
				exit(0);
		}
		if(gameState == 4){
			if(mx>=0 && mx<=972 && my>=0  && my<=583)
				exit(0);
		}
		if(gameState == 100)
		{
			if(mx>=0 && mx<=972 && my>=0  && my<=583)
				gameState = 10;
		}
		if(gameState == 200)
		{
			if(mx>=0 && mx<=972 && my>=0  && my<=583)
				gameState = 11;
		}
		if(gameState == 1)
		{
			if(mx>=325 && mx<=325+180 && my>=200  && my<=200+50)
			{
				highscore = 0;
		        FILE *fp = fopen("highscore.txt", "w");
		        fprintf(fp, "%d", highscore);
				fclose(fp);
			}
			if(mx>=0 && mx<=70 && my>=0  && my<=70)
			{
				gameState = -1;
			}
		}
		if(gameState == 2)
				{
					if(mx>=0 && mx<=70 && my>=0  && my<=70)
			{
				gameState = -1;
			}
				}
		if(gameState == 5)
				{
					if(mx>=0 && mx<=70 && my>=0  && my<=70)
			{
				gameState = -1;
			}
				}
		if(gameState == -2)
		{
	    if(mx>=0 && mx<=972 && my>=0  && my<=583)
		{
				gameState = -1;
		}
        }
		else if(gameState == -1){
	     if(mx>=100 && mx<=100+180 && my>=400  && my<=60+400)
			{
				gameState=3;
			}
	 else if(mx>=105 && mx<=105+170 && my>=315  && my<=50+315)
			{
				gameState=1;
			}
	else if(mx>=100 && mx<=100+180 && my>=220  && my<=50+220)
			{
				gameState = 2;
			}
	else if(mx>=100 && mx<=100+180 && my>=130  && my<=130+50)
	{
		gameState = 5;
	}
	else if(mx>=104 && mx<=104+180 && my>=40  && my<=40+50)
	{
		exit(0);
	}
		}	
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
	}
}
void iKeyboard(unsigned char key)
{
/////////////Controls////////////////
	if(gameState == 1 || gameState == 2 || gameState == 5)
	{
	if(key == 'q')
	{
		gameState = -1;
	}
    }
	if(gameState == 5 || gameState == 2)
	{
	if(key == 'e')
	{
		gameState = 1;
	}
	}
	if(gameState == 1 || gameState ==5)
	{
	if(key == 'r')
	{
		gameState = 2;
	}
	}
	if(gameState == -1)
	{
	if(key == 'a')
	{
			gameState = 3;
	}
	}
	if(gameState == 1 || gameState == 2)
	{
	if(key == 'c')
	{
		gameState = 5;
	}
	}
	if(key == 'x')
	{
		exit(0);
	}
	/*if(key == 'm')
		{
			PlaySound(0,0,0);
	}
	if(key == 'n')
		{
			PlaySound("music\\sound",NULL,SND_LOOP|SND_ASYNC);
	}*/
	//////////////////////////////////


	//////////////////Ice throw for level1//////////////////
	if(gameState == 3){
	if(key == 'i')                 
	{
		
		level1_icecollision = true;
		level1_iceShootingPositiony = level1_cartoon_posy+level1_playerCordinateJump + 30;
		if(level1_iceShootingPositiony >= 290 && level1_iceShootingPositiony <= 600)
		{
			level1_count1++;
			temp += 1000;
		}
		else
		{
			level1_count2++;
			temp += 500;
		}
}


	////////////////// Fire throw for level1 ////////////
	if(key == 'f')
	{
		level1_firecollision = true;
		level1_fireShootingPositiony = level1_cartoon_posy+level1_playerCordinateJump + 30;
		if(level1_fireShootingPositiony >= 290 && level1_fireShootingPositiony <= 600)
		{
			level1_count1++;
			temp += 1000;
		}
		else
		{
			level1_count2++;
			temp += 500;
		}
	}


	/////////////////Thunderbolt throw for level1 ////////////
	if(key == 't')
	{
		level1_boltcollision = true;
		level1_boltShootingPositiony = level1_cartoon_posy+level1_playerCordinateJump + 30;
		if(level1_boltShootingPositiony >= 290 && level1_boltShootingPositiony <= 600)
		{
			level1_count1++;
			temp += 1000;
		}
		else
		{
			level1_count2++;
			temp += 500;
		}
	}
	}
	else if(gameState == 10){
	if(key == 'i')                 
	{
		level2_icecollision = true;
		level2_iceShootingPositiony = level2_cartoon_posy+level2_playerCordinateJump + 30;
		if(level2_iceShootingPositiony >= 290 && level2_iceShootingPositiony <= 600)
		{
		      level2_count1++;
			  temp += 1000; 
		}
		else
		{
		      level2_count2++;
			  temp += 500;
		}
}
	////////////////// Fire throw for level2 ////////////
	if(key == 'f')
	{
		level2_firecollision = true;
		level2_fireShootingPositiony = level2_cartoon_posy+level2_playerCordinateJump + 30;
		if(level2_fireShootingPositiony >= 290 && level2_fireShootingPositiony <= 600)
	    {
		      level2_count1++;
			  temp += 1000; 
		}
		else
		{
		      level2_count2++;
			  temp += 500;
		}
	}

	///////////////// Thunderbolt throw for level2 ////////////
	if(key == 't')
	{
		level2_boltcollision = true;
		level2_boltShootingPositiony = level2_cartoon_posy+level2_playerCordinateJump + 30;
		if(level2_boltShootingPositiony >= 290 && level2_boltShootingPositiony <= 600)
		{
		      level2_count1++;
			  temp += 1000; 
		}
		else
		{
		      level2_count2++;
			  temp += 500;
		}
	}
	}
	else if(gameState == 11){
	if(key == 'i')                 
	{
		
		level3_icecollision = true;
		level3_iceShootingPositiony = level3_cartoon_posy+level3_playerCordinateJump + 30;
		if(level3_iceShootingPositiony >= 290 && level3_iceShootingPositiony <= 700)
		{
			level3_count1++;
			temp += 1000;
		}
		else
		{
			level3_count2++;
			temp += 500;
		}
}


	////////////////// Fire throw for level3 ////////////
	if(key == 'f')
	{
		level3_firecollision = true;
		level3_fireShootingPositiony = level3_cartoon_posy+level3_playerCordinateJump + 30;
		if(level3_fireShootingPositiony >= 290 && level3_fireShootingPositiony <= 700)
		{
			level3_count1++;
			temp += 1000;
		}
		else
		{
			level3_count2++;
			temp += 500;
		}
	}


	/////////////////Thunderbolt throw for level3////////////
	if(key == 't')
	{
		level3_boltcollision = true;
		level3_boltShootingPositiony = level3_cartoon_posy+level3_playerCordinateJump + 30;
		if(level3_boltShootingPositiony >= 290 && level3_boltShootingPositiony <= 700)
		{
			level3_count1++;
			temp += 1000;
		}
		else
		{
			level3_count2++;
			temp += 500;
		}
	}
	}

	//////////////////////////////
	/*if (key == 'p')
	{
		iPauseTimer(0);
	}
	if (key == 'r')
	{
		iResumeTimer(0);
	}*/

	
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{
	if(key == GLUT_KEY_RIGHT){
	}

	if(key == GLUT_KEY_LEFT){
	}

	if(key == GLUT_KEY_UP){
		if(gameState == 3){
		if(!level1_jump)
		{
			level1_jump = true;
			level1_jumpUp = true;
		}
		}
		else if(gameState == 10){
		if(!level2_jump)
		{
			level2_jump = true;
			level2_jumpUp = true;
		}
		}
		else if(gameState == 11){
		if(!level3_jump)
		{
			level3_jump = true;
			level3_jumpUp = true;
		}
		}
	
	}
	if(key == GLUT_KEY_DOWN){
	}
	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
}



int main()
{


	iInitialize(972, 583, "Monster Crew");

	////////////////images are here/////////////////////

	//////////level1 images/////////////////////
	level1_image1 = iLoadImage("images\\fire.png");
	level1_image2 = iLoadImage("images\\ice.png");
	level1_image3 = iLoadImage("images\\background.png");
	level1_image4 = iLoadImage("images\\Capture 6.png");
	level1_image5 = iLoadImage("images\\mud monster6.png");
	level1_image6 = iLoadImage("images\\bolt.jpg");
	level1_image7 = iLoadImage("images\\dragpower1.png");
	level1_pic[0] = iLoadImage("images\\p1.png");
	level1_pic[1] = iLoadImage("images\\p2.png");
	level1_pic[2] = iLoadImage("images\\p3.png");
	level1_pic[3] = iLoadImage("images\\p4.png");
	level1_pic[4] = iLoadImage("images\\p5.png");
	level1_jumpOne = iLoadImage("images\\p3.png");
	level1_jumpTwo = iLoadImage("images\\p3.png");
	level1_heartlives = iLoadImage("images\\heart.png");
	//////////////////////////////////////////////

	//////////////level2 images///////////////////
	level2_image1 = iLoadImage("images\\fire.png");
	level2_image2 = iLoadImage("images\\ice.png");
	level2_image3 = iLoadImage("images\\desert.png");
	level2_image4 = iLoadImage("images\\Capture 6.png");
	level2_image5 = iLoadImage("images\\Capturesand1.png");
	level2_image6 = iLoadImage("images\\bolt.jpg");
	level2_image7 = iLoadImage("images\\sandstorm2.png");
	level2_pic[0] = iLoadImage("images\\p1.png");
	level2_pic[1] = iLoadImage("images\\p2.png");
	level2_pic[2] = iLoadImage("images\\p3.png");
	level2_pic[3] = iLoadImage("images\\p4.png");
	level2_pic[4] = iLoadImage("images\\p5.png");
	level2_jumpOne = iLoadImage("images\\p3.png");
	level2_jumpTwo = iLoadImage("images\\p3.png");
	level2_heartlives = iLoadImage("images\\heart.png");
	/////////////////////////////////////////////////


	//////////////////level3 images/////////////////
	level3_image1 = iLoadImage("images\\fire.png");
	level3_image2 = iLoadImage("images\\ice.png");
	level3_image3 = iLoadImage("images\\castle4.png");
	level3_image4 = iLoadImage("images\\Capture 6.png");
	level3_image5 = iLoadImage("images\\Darkness_Dragon.png");
	level3_image6 = iLoadImage("images\\bolt.jpg");
	level3_image7 = iLoadImage("images\\firepower3.png");
	level3_pic[0] = iLoadImage("images\\p1.png");
	level3_pic[1] = iLoadImage("images\\p2.png");
	level3_pic[2] = iLoadImage("images\\p3.png");
	level3_pic[3] = iLoadImage("images\\p4.png");
	level3_pic[4] = iLoadImage("images\\p5.png");
	level3_jumpOne = iLoadImage("images\\p3.png");
	level3_jumpTwo = iLoadImage("images\\p3.png");
	level3_heartlives = iLoadImage("images\\heart.png");
	////////////////////////////////////////////////

	////////////////common images////////////////////
	monstercrew = iLoadImage("images\\monstercrew.jpg");
	homemenu = iLoadImage("images\\monster1.bmp");
	newgame = iLoadImage("images\\NewGameButton.png");
	highscoreicon = iLoadImage("images\\highscorebutton.png");
	back = iLoadImage("images\\exitbutton.png");
	gameOver = iLoadImage("images\\gameOver1.png");
	credits = iLoadImage("images\\credits.png");
	controls = iLoadImage("images\\controls.png");
	controlspage = iLoadImage("images\\controlspage-972x583.png");
	creditspage = iLoadImage("images\\creditspage-972x583.png");
	finishpage = iLoadImage("images\\welldone.png");
	reset = iLoadImage("images\\reset.png");
	homeicon = iLoadImage("images\\homeicon.png");
	//loadingpic = iLoadImage("images\\9.png");
	//////////////////////////////////////////////////

	///////////////////////////////////////////////////////////

	srand(time(NULL));
	//PlaySound("music\\sound",NULL,SND_LOOP|SND_ASYNC);
		iSetTimer(50, level1_collide);
		iSetTimer(50, level2_collide);
		iSetTimer(50, level3_collide);

	iStart();

	return 0;
}

