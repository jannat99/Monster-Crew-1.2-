void level1_collide()
{
	if((level1_monspow_posx >= level1_cartoon_posx-10)  && (level1_monspow_posx <= level1_cartoon_posx+100))
	{
	if((level1_monspow_posy >= level1_cartoon_posy+level1_playerCordinateJump-130) && (level1_monspow_posy <= level1_cartoon_posy+level1_playerCordinateJump+157))
	{
		level1_lives--;
		if(level1_lives == 0)
		{
		level1_over = true;
		if(level1_over)
	    {  
		gameState = 4;
		level1_cartoon_posx=-5888;
		level1_cartoon_posy=-5565;
		level1_monspow_posx = -10000;
		level1_iceball_posx = -10000;
		level1_fireball_posx = -10000;
		level1_bolt_posx = -10000;
	    }   
		}
		
	}
	}
	if(level1_monsx != -2344 && level1_monsy != -34343 && level1_monspow_posx != -10001)
	{
	if(level1_iceball_posx >= level1_monsx)
	{
		Score = temp;
		if(level1_iceShootingPositiony >= 290 && level1_iceShootingPositiony <= 600)
		 {
		if(level1_count1 >= 3)
		{
		level1_monsx = -2344;
		level1_monsy = -34343;
		level1_monspow_posx = -10001;
		gameState = 100;
		}
		}
		else if(level1_iceShootingPositiony >= 0 && level1_iceShootingPositiony < 290)
		{
		
		if(level1_count2 >= 4)
		{
		level1_monsx = -2344;
		level1_monsy = -34343;
	    level1_monspow_posx = -10001;
		gameState = 100;
		}
	    }
	}
	if(level1_fireball_posx > level1_monsx)
	{
		Score = temp;
		if(level1_fireShootingPositiony >= 290 && level1_fireShootingPositiony <= 600)
		 {
		
		if(level1_count1 >= 3)
		{
		level1_monsx = -2344;
		level1_monsy = -34343;
		level1_monspow_posx = -10001;
		gameState = 100;
		
		}
		}
		else if(level1_fireShootingPositiony >= 0 && level1_fireShootingPositiony < 290)
		{
		if(level1_count2 >= 4)
		{
		level1_monsx = -2344;
		level1_monsy = -34343;
	    level1_monspow_posx = -10001;
		gameState = 100;
		}
	    }
	}
	if(level1_bolt_posx > level1_monsx)
	{
		Score = temp;
		if(level1_boltShootingPositiony >= 290 && level1_boltShootingPositiony <= 600)
		 {
		if(level1_count1 >= 3)
		{
		level1_monsx = -2344;
		level1_monsy = -34343;
		level1_monspow_posx = -10001;
		gameState = 100;
		}
		}
		else if(level1_boltShootingPositiony >= 0 && level1_boltShootingPositiony < 290)
		{
		if(level1_count2 >= 4)
		{
		level1_monsx = -2344;
		level1_monsy = -34343;
	    level1_monspow_posx = -10001;
		gameState = 100;
		}
	    }
	}
}
}
void level2_collide()
{

	if((level2_monspow_posx >= level2_cartoon_posx-10)  && (level2_monspow_posx <= level2_cartoon_posx+100))
	{
	if((level2_monspow_posy >= level2_cartoon_posy+level2_playerCordinateJump-170) && (level2_monspow_posy <= level2_cartoon_posy+level2_playerCordinateJump+180))
	{
		level2_lives--;
		if(level2_lives == 0)
		{
		level2_over = true;
		if(level2_over)
	    {  
		gameState = 4;
		level2_cartoon_posx=-5888;
		level2_cartoon_posy=-5565;
		level2_monspow_posx = -10000;
		level2_iceball_posx = -10000;
		level2_fireball_posx = -10000;
		level2_bolt_posx = -10000;
	    }   
		}
		
	}
	}
	if(level2_monsx != -2344 && level2_monsy != -34343 && level2_monspow_posx != -10001)
	{
	if(level2_iceball_posx >= level2_monsx)
	{
		Score = temp;
		if(level2_iceShootingPositiony >= 290 && level2_iceShootingPositiony <= 600)
		 {
		if(level2_count1 >= 4)
		{
		level2_monsx = -2344;
		level2_monsy = -34343;
		level2_monspow_posx = -10001;
		gameState = 200;
		}
		}
		else if(level2_iceShootingPositiony >= 0 && level2_iceShootingPositiony < 290)
		{
		if(level2_count2 >= 5)
		{
		level2_monsx = -2344;
		level2_monsy = -34343;
	    level2_monspow_posx = -10001;
		gameState = 200;
		}
	    }
	}
	if(level2_fireball_posx > level2_monsx)
	{
		Score = temp;
		if(level2_fireShootingPositiony >= 290 && level2_fireShootingPositiony <= 600)
		 {
		if(level2_count1 >= 4)
		{
		level2_monsx = -2344;
		level2_monsy = -34343;
		level2_monspow_posx = -10001;
		gameState = 200;
		}
		}
		else if(level2_fireShootingPositiony >= 0 && level2_fireShootingPositiony < 290)
		{
		if(level2_count2 >= 5)
		{
		level2_monsx = -2344;
		level2_monsy = -34343;
	    level2_monspow_posx = -10001;
		gameState = 200;
		}
	    }
	}
	if(level2_bolt_posx > level2_monsx)
	{
		Score = temp;
		if(level2_boltShootingPositiony >= 290 && level2_boltShootingPositiony <= 600)
		 {
		if(level2_count1 >= 4)
		{
		level2_monsx = -2344;
		level2_monsy = -34343;
		level2_monspow_posx = -10001;
		gameState = 200;
		}
		}
		else if(level2_boltShootingPositiony >= 0 && level2_boltShootingPositiony < 290)
		{
		if(level2_count2 >= 5)
		{
		level2_monsx = -2344;
		level2_monsy = -34343;
	    level2_monspow_posx = -10001;
		gameState = 200;
		}
	    }
	}
	}
}
void level3_collide()
{

	if((level3_monspow_posx >= level3_cartoon_posx-10)  && (level3_monspow_posx <= level3_cartoon_posx+100))
	{
	if((level3_monspow_posy >= level3_cartoon_posy+level3_playerCordinateJump-135) && (level3_monspow_posy <= level3_cartoon_posy+level3_playerCordinateJump+180))
	{
		level3_lives--;
		if(level3_lives == 0)
		{
		level3_over = true;
		if(level3_over)
	    {  
		gameState = 4;
		level3_cartoon_posx=-5888;
		level3_cartoon_posy=-5565;
		level3_monspow_posx = -10000;
		level3_iceball_posx = -10000;
		level3_fireball_posx = -10000;
		level3_bolt_posx = -10000;
	    }   
		}
	}
	}
	if(level3_monsx != -2344 && level3_monsy != -34343 && level3_monspow_posx != -10001){
	if(level3_iceball_posx >= level3_monsx)
	{
		Score = temp;
		if(level3_iceShootingPositiony >= 290 && level3_iceShootingPositiony <= 700)
		 {
		if(level3_count1 >= 5)
		{
		level3_monsx = -2344;
		level3_monsy = -34343;
		level3_monspow_posx = -10001;
		gameState = 20;
		}
		}
		else if(level3_iceShootingPositiony >= 0 && level3_iceShootingPositiony < 290)
		{
		if(level3_count2 >= 6)
		{
		level3_monsx = -2344;
		level3_monsy = -34343;
	    level3_monspow_posx = -10001;
		gameState = 20;
		}
	    }
	}
	if(level3_fireball_posx > level3_monsx)
	{
		Score = temp;
		if(level3_fireShootingPositiony >= 290 && level3_fireShootingPositiony <= 700)
		 {
		if(level3_count1 >= 5)
		{
		level3_monsx = -2344;
		level3_monsy = -34343;
		level3_monspow_posx = -10001;
		gameState = 20;
		}
		}
		else if(level3_fireShootingPositiony >= 0 && level3_fireShootingPositiony < 290)
		{
		if(level3_count2 >= 6)
		{
		level3_monsx = -2344;
		level3_monsy = -34343;
	    level3_monspow_posx = -10001;
		gameState = 20;
		}
	    }
	}
	if(level3_bolt_posx > level3_monsx)
	{
		Score = temp;
		if(level3_boltShootingPositiony >= 290 && level3_boltShootingPositiony <= 700)
		 {
		if(level3_count1 >= 5)
		{
		level3_monsx = -2344;
		level3_monsy = -34343;
		level3_monspow_posx = -10001;
		gameState = 20;
		}
		}
		else if(level3_boltShootingPositiony >= 0 && level3_boltShootingPositiony < 290)
		{
		if(level3_count2 >= 6)
		{
		level3_monsx = -2344;
		level3_monsy = -34343;
	    level3_monspow_posx = -10001;
		gameState = 20;
		}
	    }
	}
	}
}