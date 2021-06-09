////////////////////////jumping method for level1/////////////////////////////////
void level1_jumping(){

	if(level1_jump)
	{
		if(level1_jumpUp){
			
			iShowImage(level1_cartoon_posx, level1_cartoon_posy+ level1_playerCordinateJump, 200, 200, level1_jumpOne);
			level1_playerCordinateJump += level1_playerCordinateJumpSpeedUp;
			
			if(level1_icecollision)
			{
		     level1_iceball_posy = level1_cartoon_posy + level1_playerCordinateJump;
			 
		    level1_iceball_posx += 5;
			
		     if(level1_iceball_posx == 695)
		     {
		        level1_iceball_posx = level1_iceball_posx - level1_iceballspeed;
		        level1_iceball_posx = 250;
		        level1_icecollision = false;
				
		     }
			 level1_iceball_posy = 100;
			 
			}
			if(level1_firecollision)
			{
		     level1_fireball_posy = level1_cartoon_posy + level1_playerCordinateJump;
		    level1_fireball_posx += 5;
			
		     if(level1_fireball_posx == 695)
		     {
		        level1_fireball_posx = level1_fireball_posx - level1_fireballspeed;
		        level1_fireball_posx = 250;
		        level1_firecollision = false;
				
		     }
			 level1_fireball_posy = 100;
			}
			if(level1_boltcollision)
			{
		     level1_bolt_posy = level1_cartoon_posy + level1_playerCordinateJump;
		    level1_bolt_posx += 5;
			
		     if(level1_bolt_posx == 695)
		     {
		        level1_bolt_posx = level1_bolt_posx - level1_boltspeed;
		        level1_bolt_posx = 250;
		        level1_boltcollision = false;
				
		     }
			 level1_bolt_posy = 100;
			}
			if(level1_playerCordinateJump >= 400)
			{
				level1_jumpUp = false;
			}
		}
		else
		{  
			
			iShowImage(level1_cartoon_posx, level1_cartoon_posy+ level1_playerCordinateJump, 200, 200, level1_jumpTwo);
			level1_playerCordinateJump -= level1_playerCordinateJumpSpeedDown;

			if(level1_playerCordinateJump < 40)
			{
				level1_jump = false;
				level1_playerCordinateJump = 0;
			}
		}
	}
	else{
		
	
		iShowImage(level1_cartoon_posx, level1_cartoon_posy, 200, 200, level1_pic[level1_playerIndex]);
	}

	
}
//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////jumping method for level2///////////////////
void level2_jumping(){

	if(level2_jump)
	{
		if(level2_jumpUp){
			
			iShowImage(level2_cartoon_posx, level2_cartoon_posy+ level2_playerCordinateJump, 200, 200, level2_jumpOne);
			level2_playerCordinateJump += level2_playerCordinateJumpSpeedUp;
			
			if(level2_icecollision)
			{
		     level2_iceball_posy = level2_cartoon_posy + level2_playerCordinateJump;
			 
		    level2_iceball_posx += 5;
			
		     if(level2_iceball_posx == 695)
		     {
		        level2_iceball_posx = level2_iceball_posx - level2_iceballspeed;
		        level2_iceball_posx = 250;
		        level2_icecollision = false;
				
		     }
			 level2_iceball_posy = 100;
			
			}
			if(level2_firecollision)
			{
		     level2_fireball_posy = level2_cartoon_posy + level2_playerCordinateJump;
		    level2_fireball_posx += 5;
			
		     if(level2_fireball_posx == 695)
		     {
		        level2_fireball_posx = level2_fireball_posx - level2_fireballspeed;
		        level2_fireball_posx = 250;
		        level2_firecollision = false;
				
		     }
			 level2_fireball_posy = 100;
			}
			if(level2_boltcollision)
			{
		     level2_bolt_posy = level2_cartoon_posy + level2_playerCordinateJump;
		    level2_bolt_posx += 5;
			
		     if(level2_bolt_posx == 695)
		     {
		        level2_bolt_posx = level2_bolt_posx - level2_boltspeed;
		        level2_bolt_posx = 250;
		        level2_boltcollision = false;
				
		     }
			 level2_bolt_posy = 100;
			}
			if(level2_playerCordinateJump >= 400)
			{
				level2_jumpUp = false;
			}
		}
		else
		{ 
			
			iShowImage(level2_cartoon_posx, level2_cartoon_posy + level2_playerCordinateJump, 200, 200, level2_jumpTwo);
			level2_playerCordinateJump -= level2_playerCordinateJumpSpeedDown;

			if(level2_playerCordinateJump < 40)
			{
				level2_jump = false;
				level2_playerCordinateJump = 0;
			}
		}
	}
	else{
		
	
		iShowImage(level2_cartoon_posx, level2_cartoon_posy, 200, 200, level2_pic[level2_playerIndex]);
	}

	
}
////////////////////////////////////////////////////////////////////////////



////////////////////////////jumping method for level3///////////////////////
void level3_jumping(){

	if(level3_jump)
	{
		if(level3_jumpUp){
			
			iShowImage(level3_cartoon_posx, level3_cartoon_posy + level3_playerCordinateJump, 200, 200, level3_jumpOne);
			level3_playerCordinateJump += level3_playerCordinateJumpSpeedUp;
			
			if(level3_icecollision)
			{
		     level3_iceball_posy = level3_cartoon_posy + level3_playerCordinateJump;
			 
		    level3_iceball_posx += 5;
			
		     if(level3_iceball_posx == 695)
		     {
		        level3_iceball_posx = level3_iceball_posx - level3_iceballspeed;
		        level3_iceball_posx = 250;
		        level3_icecollision = false;
				
		     }
			 level3_iceball_posy = 100;
			 
			}
			if(level3_firecollision)
			{
		     level3_fireball_posy = level3_cartoon_posy + level3_playerCordinateJump;
		    level3_fireball_posx += 5;
			
		     if(level3_fireball_posx == 695)
		     {
		        level3_fireball_posx = level3_fireball_posx - level3_fireballspeed;
		        level3_fireball_posx = 250;
		        level3_firecollision = false;
				
		     }
			 level3_fireball_posy = 100;
			}
			if(level3_boltcollision)
			{
		     level3_bolt_posy = level3_cartoon_posy + level3_playerCordinateJump;
		    level3_bolt_posx += 5;
			
		     if(level3_bolt_posx == 695)
		     {
		        level3_bolt_posx = level3_bolt_posx - level3_boltspeed;
		        level3_bolt_posx = 250;
		        level3_boltcollision = false;
				
		     }
			 level3_bolt_posy = 100;
			}
			if(level3_playerCordinateJump >= 400)
			{
				level3_jumpUp = false;
			}
		}
		else
		{  
			
			iShowImage(level3_cartoon_posx, level3_cartoon_posy + level3_playerCordinateJump, 200, 200, level3_jumpTwo);
			level3_playerCordinateJump -= level3_playerCordinateJumpSpeedDown;

			if(level3_playerCordinateJump < 40)
			{
				level3_jump = false;
				level3_playerCordinateJump = 0;
			}
		}
	}
	else{
		
	
		iShowImage(level3_cartoon_posx, level3_cartoon_posy, 200, 200, level3_pic[level3_playerIndex]);
	}

	
}
//////////////////////////////////////////////////////////////////////////