
#ifndef ENEMY_DIST
#define ENEMY_DIST ENEMY_HORIZONTAL_DIST
#endif

#ifndef ENEMY_VERY_BAD
#define ENEMY_VERY_BAD 0
#endif

#ifndef ENEMY_IN_AIR
#define ENEMY_IN_AIR 0
#endif

#define DWL_ENEMY_DIST $evalint( ENEMY_DIST*(1+ENEMY_IN_AIR) )

#define DWL_GAUNTLET_DIST ENEMY_DIST


#ifndef DWL_ENEMY_DIST_FACTOR 
#define DWL_ENEMY_DIST_FACTOR 8
#endif

#ifndef DWL_BOTAI_SELFPRESERVATION 
#define DWL_BOTAI_SELFPRESERVATION 90
#endif

#ifndef DWL_BOTAI_FINISH_HIM
#define DWL_BOTAI_FINISH_HIM 20
#endif


#define DWL_SELFPRESERVATION_CHECK(weap) \
				switch (ENEMY_DIST) \
				  {    case 20: return 0;\
					case 40: return $evalint(weap * (INVENTORY_ARMOR+INVENTORY_HEALTH)/120 ); \
					case 50: return $evalint(weap * (INVENTORY_ARMOR+INVENTORY_HEALTH)/110 ); \
					case 99: return $evalint(weap * (INVENTORY_ARMOR+INVENTORY_HEALTH)/90 ); \
					default: return 1; \
				  } //end switch


weight "Gauntlet"
{
	switch(INVENTORY_GAUNTLET)
	{
		case 1: return 0;
		default:
		// CHAOS begin BotAI
		{
			//return W_GAUNTLET;
			//the gauntlet has a limited range
			switch(DWL_GAUNTLET_DIST)
			{
				case 25: return $evalint(W_GAUNTLET*80);
				case 35: return $evalint(W_GAUNTLET*50);
				default: return 1;
			} //end switch
		} //end default
		// CHAOS end BotAI
	} //end switch
} //end weight

weight "Shotgun"
{
	switch(INVENTORY_SHOTGUN)
	{
		case 1: return 0;
		default:
		{
			switch(INVENTORY_SHELLS)
			{
				case 1: return 0;
				default:
				{
					// CHAOS begin BotAI
					//return W_SHOTGUN;
					//the shotgun has a limited range
					switch(DWL_ENEMY_DIST)
					{
						case 150: return $evalint(W_SHOTGUN*10);
						case 190: return $evalint(W_SHOTGUN*6);
						case 300: return $evalint(W_SHOTGUN*2);
						case 400: return $evalint(W_SHOTGUN);
						case 700: return $evalint(W_SHOTGUN*3/4);
						default: return $evalint(W_SHOTGUN/32);
					} //end switch
					// CHAOS end BotAI
				} //end default
			} //end switch
		} //end default
	} //end switch
} //end weight

weight "Machinegun"
{
	switch(INVENTORY_MACHINEGUN)
	{
		case 1: return 0;
		default:
		{
			switch(INVENTORY_BULLETS)
			{
				case 1: return 0;
				default: return $evalint(W_MACHINEGUN + ENEMY_VERY_BAD*10*INVENTORY_BULLETS );
			} //end switch
		} //end default
	} //end switch
} //end weight

weight "Grenade Launcher"
{
	switch(INVENTORY_GRENADELAUNCHER)
	{
		case 1: return 0;
		default:
		{
			switch(INVENTORY_GRENADES)
			{
				case 1: return 0;
				default:
				{
					// CHAOS begin BotAI
					//return W_GRENADELAUNCHER;
					//the grenade launcher has a limited range
					switch(ENEMY_HEIGHT)
					{
					    case 400:
					    {
							switch(DWL_ENEMY_DIST)
							{
								case 240: 
								  {
									DWL_SELFPRESERVATION_CHECK(W_GRENADELAUNCHER)
								  } 
								case 500: return W_GRENADELAUNCHER;
								case 700: return $evalint(W_GRENADELAUNCHER/2);
								default: return $evalint(W_GRENADELAUNCHER/100);
							} //end switch
						} //end case
						default: return $evalint(W_GRENADELAUNCHER/100);
					} //end switch
					// CHAOS end BotAI
				} //end default
			} //end switch
		} //end default
	} //end switch
} //end weight

weight "Rocket Launcher"
{
	switch(INVENTORY_ROCKETLAUNCHER)
	{
		case 1: return 0;
		default:
		{
			switch(INVENTORY_ROCKETS)
			{
				case 1: return 0;
				default:
				{
					// CHAOS begin BotAI
					//return W_ROCKETLAUNCHER;
					switch(DWL_ENEMY_DIST_FACTOR)
					{
					    case 4:
						{
							switch(DWL_ENEMY_DIST)
							{
								case 150:
								  {
									DWL_SELFPRESERVATION_CHECK(W_ROCKETLAUNCHER)
								  } // end case 100
								case 400: return $evalint(W_ROCKETLAUNCHER*7);
								case 800: return $evalint(W_ROCKETLAUNCHER*4);
								default: return W_ROCKETLAUNCHER;
							} //end switch
						} //end case
					    case 8:
						{
							switch(DWL_ENEMY_DIST)
							{
								case 150:
								  {
									DWL_SELFPRESERVATION_CHECK(W_ROCKETLAUNCHER)
								  } // end case 100
								case 400: return $evalint(W_ROCKETLAUNCHER*7);
								case 500: return $evalint(W_ROCKETLAUNCHER*6);
								default: return $evalint(W_ROCKETLAUNCHER/5);
							} //end switch
						} //end case
					    case 12:
						{
							switch(DWL_ENEMY_DIST)
							{
								case 150:
								  {
									DWL_SELFPRESERVATION_CHECK(W_ROCKETLAUNCHER)
								  } // end case 100
								case 500: return W_ROCKETLAUNCHER;
								case 800: return $evalint(W_ROCKETLAUNCHER*3/4);
								case 1400:return $evalint(W_ROCKETLAUNCHER/2);
								default: return $evalint(W_ROCKETLAUNCHER/4);
							} //end switch
						} //end case
					    case 15:
						{
							switch(DWL_ENEMY_DIST)
							{
								case 150:
								  {
									DWL_SELFPRESERVATION_CHECK(W_ROCKETLAUNCHER)
								  } // end case 100
								case 500: return $evalint(W_ROCKETLAUNCHER/2);
								case 800: return $evalint(W_ROCKETLAUNCHER/4);
								default: return $evalint(W_ROCKETLAUNCHER/6);
							} //end switch
						} //end case
						default:
						{
							switch(DWL_ENEMY_DIST)
							{
								case 150:
								  {
									DWL_SELFPRESERVATION_CHECK(W_ROCKETLAUNCHER)
								  } // end case 100
								case 500: return $evalint(W_ROCKETLAUNCHER/4);
								case 800: return $evalint(W_ROCKETLAUNCHER/6);
								default: return $evalint(W_ROCKETLAUNCHER/8);
							} //end switch
						} //end case
					} //end switch
					// CHAOS end BotAI
				} //end default
			} //end switch
		} //end default
	} //end switch
} //end weight

weight "Lightning Gun"
{
	switch(INVENTORY_LIGHTNING)
	{
		case 1: return 0;
		default:
		{
			switch(INVENTORY_LIGHTNINGAMMO)
			{
				case 1: return 0;
				default:
				{
					//the lightning gun has a limited range
					switch(DWL_ENEMY_DIST)
					{
						case 768: return $evalint(3*W_LIGHTNING + 3*INVENTORY_LIGHTNINGAMMO);
						default: return $evalint(W_LIGHTNING/100);
					} //end switch
				} //end default
			} //end switch
		} //end default
	} //end switch
} //end weight

weight "Railgun"
{
	switch(INVENTORY_RAILGUN)
	{
		case 1: return 0;
		default:
		{
			switch(INVENTORY_SLUGS)
			{
				case 1: return 0;
				default:
				{
					// CHAOS begin BotAI
					//return W_RAILGUN;
					//use railgun from long range
					switch(DWL_BOTAI_FINISH_HIM)
					{
						case 1:
						{
							switch(DWL_ENEMY_DIST)
							{
								case 200: return $evalint(W_RAILGUN/2);
								case 350: return W_RAILGUN;
								case 500: return $evalint(W_RAILGUN*5);
								default: return $evalint(W_RAILGUN*30);
							} //end switch
						}
						case 20:
						{
                                            switch(INVENTORY_HEALTH)  
                                            {
                                             case 20: return $evalint(W_RAILGUN*5);  
						    default:
                                              {
                                             	switch(DWL_ENEMY_DIST)
							{
								case 300: return $evalint(W_RAILGUN/10);
								case 450: return $evalint((W_RAILGUN+INVENTORY_SLUGS)*4);
								case 600: return $evalint((W_RAILGUN+INVENTORY_SLUGS)*10);
								default: return $evalint((W_RAILGUN+INVENTORY_SLUGS)*30);
							} //end switch
                                              }
						   }	
						}
						default:
						{
							switch(DWL_ENEMY_DIST)
							{
								case 200: return $evalint(W_RAILGUN/100);
								case 500: return $evalint(W_RAILGUN/10);
								case 700: return $evalint(W_RAILGUN*3);
								default: return $evalint(W_RAILGUN*10);
							} //end switch
						} //end switch
					}
					// CHAOS end BotAI
				} //end default
			} //end switch
		} //end default
	} //end switch
} //end weight

weight "Plasma Gun"
{
	switch(INVENTORY_PLASMAGUN)
	{
		case 1: return 0;
		default:
		{
			switch(INVENTORY_CELLS)
			{
				case 1: return 0;
				default:
				{
					// CHAOS begin BotAI
					//return W_PLASMAGUN;
					switch(DWL_ENEMY_DIST)
					{
						case 30:
						  {
						    DWL_SELFPRESERVATION_CHECK(W_PLASMAGUN)
						  } // end case 20
						case 400: return $evalint(W_PLASMAGUN+INVENTORY_CELLS);
						case 500: return $evalint(W_PLASMAGUN*3/2+INVENTORY_CELLS);
						case 700: return $evalint(W_PLASMAGUN*2+INVENTORY_CELLS);
						case 1000: return $evalint(W_PLASMAGUN*5+INVENTORY_CELLS);
						default: return W_PLASMAGUN;
					} //end switch
					// CHAOS end BotAI
				} //end default
			} //end switch
		} //end default
	} //end switch
} //end weight

weight "BFG10K"
{
	switch(INVENTORY_BFG10K)
	{
		case 1: return 0;
		default:
		{
			switch(INVENTORY_BFGAMMO)
			{
				case 1: return 0;
				default:
				{
					// CHAOS begin BotAI
					//return W_BFG10K;
					switch(DWL_ENEMY_DIST)
					{
						case 150:
						  {
						    DWL_SELFPRESERVATION_CHECK(W_BFG10K)
						  } // end case 150
						default: return W_BFG10K;
					} //end switch
					// CHAOS end BotAI
				} //end default
			} //end switch
		} //end default
	} //end switch
} //end weight

weight "Grappling Hook"
{
	switch(INVENTORY_GRAPPLINGHOOK)
	{
		case 1: return 0;
		default:
		{
			return W_GRAPPLE;
		} //end default
	} //end switch
} //end weight

