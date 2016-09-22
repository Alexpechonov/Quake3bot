//#define WEAPONS_STAY

//balance range
#define BR_ARMOR				35
#define BR_HEALTH				35
#define BR_WEAPON				30
#define BR_AMMO				    10
#define BR_POWERUP				10

#ifndef DWL_FS_AMMO
#define DWL_FS_AMMO		1
#endif

#ifndef FS_ARMOR
#define FS_ARMOR				8
#endif

#ifndef FS_HEALTH
#define FS_HEALTH				2
#endif


//balance macros
#define MZ(value)		(value) < 0 ? 0 : (value)
#define ARMOR_SCALE(v)	balance($evalfloat(MZ(FS_ARMOR*v)), $evalfloat(MZ(FS_ARMOR*v-BR_ARMOR)), $evalfloat(MZ(FS_ARMOR*v+BR_ARMOR)))
#define HEALTH_SCALE(v)	balance($evalfloat(MZ(FS_HEALTH*v)), $evalfloat(MZ(FS_HEALTH*v-BR_HEALTH)), $evalfloat(MZ(FS_HEALTH*v+BR_HEALTH)))
#define WEAPON_SCALE(v)	balance($evalfloat(MZ(v)), $evalfloat(MZ(v-BR_WEAPON)), $evalfloat(MZ(v+BR_WEAPON)))
#define AMMO_SCALE(v)	balance($evalfloat(MZ(DWL_FS_AMMO*v)), $evalfloat(MZ(DWL_FS_AMMO*v-BR_AMMO)), $evalfloat(MZ(DWL_FS_AMMO*v+BR_AMMO)))
#define POWERUP_SCALE(v)	balance($evalfloat(MZ(v)), $evalfloat(MZ(v-BR_POWERUP)), $evalfloat(MZ(v+BR_POWERUP)))

//=============================================
// ARMOR
//=============================================

weight "item_armor_shard"
{
	switch(INVENTORY_ARMOR)
	{
		case 50: return ARMOR_SCALE(60);
		case 150: return ARMOR_SCALE(5);
		case 200: return ARMOR_SCALE(100);
		default: return 0;
	} //end switch
} //end weight

weight "item_armor_combat"
{
	switch(INVENTORY_ARMOR)
	{
		case 150: return $evalint(4500);
		case 200: return $evalint(4000);
		default: return 0;
	} //end switch
} //end weight

weight "item_armor_body"
{
	switch(INVENTORY_ARMOR)
	{
		case 180: return $evalint(7000);
		case 200: return $evalint(4000);
		default: return 100;
	} //end switch
} //end weight

//=============================================
// HEALTH
//=============================================

weight "item_health_small"
{
	switch(INVENTORY_HEALTH)
	{
		case 30: return HEALTH_SCALE(200);
		case 40: return HEALTH_SCALE(200);
		case 50: return HEALTH_SCALE(100);
		case 60: return HEALTH_SCALE(30);
		case 70: return HEALTH_SCALE(20);
		case 80: return HEALTH_SCALE(100);
		case 90: return HEALTH_SCALE(200);
		case 100: return HEALTH_SCALE(1);
		case 200: return $evalint(2000);
		default: return HEALTH_SCALE(1);
	} //end switch
} //end weight

weight "item_health"
{
	switch(INVENTORY_HEALTH)
	{
		case 50: return HEALTH_SCALE(400);
		case 60: return HEALTH_SCALE(300);
		case 70: return HEALTH_SCALE(200);
		case 80: return HEALTH_SCALE(100);
		case 90: return HEALTH_SCALE(100);
		case 100: return HEALTH_SCALE(30);
		default: return HEALTH_SCALE(30);
	} //end switch
} //end weight

weight "item_health_large"
{
	switch(INVENTORY_HEALTH)
	{
		case 60: return HEALTH_SCALE(500);
		case 70: return HEALTH_SCALE(300);
		case 80: return HEALTH_SCALE(300);
		case 90: return HEALTH_SCALE(10);
		case 100: return 0;
		default: return 0;
	} //end switch
} //end weight

weight "item_health_mega"
{
	switch(INVENTORY_HEALTH)
	{
		case 150: return 6500;
		default: return 3500;
	} //end switch
} //end weight

//=============================================
// WEAPONS
//=============================================

weight "weapon_shotgun"
{
	switch(INVENTORY_SHOTGUN)
	{
		case 1:
		{
			switch(INVENTORY_SHELLS)
			{
				case 5: return WEAPON_SCALE(W_SHOTGUN + 10);
				default: return 0;
			} //end switch
		} //end case
		default:
		{
#ifdef WEAPONS_STAY
			switch(INVENTORY_SHELLS)
			{
				case 5: return WEAPON_SCALE(GWW_SHOTGUN);
				default: return 0;
			} //end switch
#else
			return 1;
#endif			
		} //end default
	} //end switch
} //end weight

weight "weapon_machinegun"
{
	switch(INVENTORY_MACHINEGUN)
	{
		case 1:
		{
			switch(INVENTORY_BULLETS)
			{
				//case 40: return WEAPON_SCALE(W_MACHINEGUN - 10);
				default: return WEAPON_SCALE(W_MACHINEGUN);
			} //end switch
		} //end case
		default:
		{
#ifdef WEAPONS_STAY
			switch(INVENTORY_BULLETS)
			{
				case 50: return WEAPON_SCALE(GWW_MACHINEGUN);
				case 200: return WEAPON_SCALE(GWW_MACHINEGUN - 20);
				default: return balance(5, 3, 7);
			} //end switch
#else
			return 1;
#endif			
		} //end default
	} //switch
} //end weight

weight "weapon_grenadelauncher"
{
	switch(INVENTORY_GRENADELAUNCHER)
	{
		case 1: return WEAPON_SCALE(W_GRENADELAUNCHER);
		default:
		{
#ifdef WEAPONS_STAY
			switch(INVENTORY_GRENADES)
			{
				case 16: return WEAPON_SCALE(GWW_GRENADELAUNCHER);
				case 50: return WEAPON_SCALE(GWW_GRENADELAUNCHER - 20);
				default: return balance(5, 3, 7);
			} //end switch
#else
			return 1;
#endif			
		} //end default
	} //end switch
} //end weight

weight "weapon_rocketlauncher"
{
	switch(INVENTORY_ROCKETLAUNCHER)
	{
		case 1: return $evalint( (W_ROCKETLAUNCHER+INVENTORY_HEALTH+INVENTORY_ARMOR)*4 );
		default:
		{
#ifdef WEAPONS_STAY
			switch(INVENTORY_ROCKETS)
			{
				case 30: return $evalint( (W_ROCKETLAUNCHER+INVENTORY_HEALTH+INVENTORY_ARMOR)*3 );
				default: return balance(5, 3, 7);
			} //end switch
#else
			return 1;
#endif			
		} //end default
	} //end switch
} //end weight

weight "weapon_lightning"
{
	switch(INVENTORY_LIGHTNING)
	{
		case 1: return WEAPON_SCALE(W_LIGHTNING + 200);
		default:
		{
#ifdef WEAPONS_STAY
			switch(INVENTORY_LIGHTNINGAMMO)
			{
				case 16: return WEAPON_SCALE(GWW_LIGHTNING);
				case 50: return WEAPON_SCALE(GWW_LIGHTNING + 100);
				case 100: return WEAPON_SCALE(GWW_LIGHTNING + 200);
				default: return balance(5, 3, 7);
			} //end switch
#else
			return 1;
#endif			
		} //end default
	} //end switch
} //end weight

weight "weapon_railgun"
{
	switch(INVENTORY_RAILGUN)
	{
		case 1: return $evalint( W_RAILGUN*4 );
		default:
		{
#ifdef WEAPONS_STAY
			switch(INVENTORY_SLUGS)
			{
				case 30: return WEAPON_SCALE(GWW_RAILGUN + 50);
				default: return balance(5, 3, 7);
			} //end switch
#else
			return 1;
#endif			
		} //end default
	} //end switch
} //end weight

weight "weapon_plasmagun"
{
	switch(INVENTORY_PLASMAGUN)
	{
		case 1: return $evalint(W_PLASMAGUN+INVENTORY_HEALTH+INVENTORY_ARMOR);
		default:
		{
#ifdef WEAPONS_STAY
			switch(INVENTORY_CELLS)
			{
				case 40: return WEAPON_SCALE(GWW_PLASMAGUN+W_PLASMAGUN);
				case 80: return WEAPON_SCALE(GWW_PLASMAGUN);
				default: return 0;
			} //end switch
#else
			return 1;
#endif			
		} //end default
	} //end switch
} //end weight

weight "weapon_bfg"
{
	switch(INVENTORY_BFG10K)
	{
		case 1: return WEAPON_SCALE(W_BFG10K);
		default:
		{
#ifdef WEAPONS_STAY
			switch(INVENTORY_BFGAMMO)
			{
				case 16: return WEAPON_SCALE(GWW_BFG10K);
				case 200: return WEAPON_SCALE(GWW_BFG10K - 10);
				default: return balance(5, 3, 7);
			} //end switch
#else
			return 1;
#endif			
		} //end default
	} //end switch
} //end weight

//=============================================
// AMMO
//=============================================

weight "ammo_shells"
{
	switch (INVENTORY_SHOTGUN)
	{
	case 1: return 0;
       default:
            {
		switch(INVENTORY_SHELLS)
		{
		case 15: return AMMO_SCALE(W_SHOTGUN + 90);
		default: return 0;
		}
            }
	} //end switch
} //end weight

weight "ammo_bullets"
{
	switch (INVENTORY_MACHINEGUN)
	{
	case 1: return 0;
       default:
        {
		switch(INVENTORY_BULLETS)
		{
		case 80: return AMMO_SCALE(300);
		case 100: return AMMO_SCALE(6);
		case 120: return AMMO_SCALE(5);
		case 140: return AMMO_SCALE(4);
		case 160: return AMMO_SCALE(3);
		case 180: return AMMO_SCALE(2);
		case 200: return AMMO_SCALE(1);
		default: return 0;
		}	
         }
	} //end switch	
} //end weight

weight "ammo_grenades"
{
	switch (INVENTORY_GRENADELAUNCHER)
	{
	case 1: return 0;
       default:
         {
		switch(INVENTORY_GRENADES)
		{
		case 20: return AMMO_SCALE(10);
		case 40: return AMMO_SCALE(5);
		case 60: return AMMO_SCALE(2);
		case 80: return AMMO_SCALE(1);
		case 100: return AMMO_SCALE(0);
		case 120: return AMMO_SCALE(0);
		case 140: return AMMO_SCALE(0);
		case 160: return AMMO_SCALE(0);
		case 180: return AMMO_SCALE(0);
		case 200: return AMMO_SCALE(0);
		default: return 0;
		}
         }
	} //end switch
} //end weight

weight "ammo_cells"
{
	switch (INVENTORY_PLASMAGUN)
	{
	case 1: return 0;
       default:
         {
		switch(INVENTORY_CELLS)
		{
		case 130: return AMMO_SCALE(W_PLASMAGUN+INVENTORY_HEALTH+INVENTORY_ARMOR);
		case 140: return AMMO_SCALE(4);
		case 160: return AMMO_SCALE(3);
		case 180: return AMMO_SCALE(2);
		case 200: return AMMO_SCALE(1);
		default: return 0;
		}
         }
	} //end switch
} //end weight

weight "ammo_lightning"
{
	switch (INVENTORY_LIGHTNING)
	{
	case 1: return 0;
       default:
         {
		switch(INVENTORY_LIGHTNINGAMMO)
		{
		case 100: return AMMO_SCALE(100);
		case 200: return AMMO_SCALE(300);
		default: return 0;
		}
         }
	} //end switch
} //end weight

weight "ammo_rockets"
{
	switch (INVENTORY_ROCKETLAUNCHER)
	{
	case 1: return 0;
       default:
         {
		switch(INVENTORY_ROCKETS)
		{
		case 25: return $evalint(200+INVENTORY_HEALTH+INVENTORY_ARMOR);
		default: return 0;
		}
          }
	} //end switch
} //end weight

weight "ammo_slugs"
{
	switch (INVENTORY_RAILGUN)
	{
	case 1: return 0;
       default:
         { 
		switch(INVENTORY_SLUGS)
		{
		case 10: return $evalint(250+250);
		case 30: return $evalint(2000);
		default: return 100;
		}
         }
	} //end switch
} //end weight

weight "ammo_bfg"
{
	switch (INVENTORY_BFG10K)
	{
	case 1:
		switch (INVENTORY_BFGAMMO)
		{
		case 10: return AMMO_SCALE(20);
		case 20: return AMMO_SCALE(10);
		case 30: return AMMO_SCALE(10);
		case 40: return AMMO_SCALE(5);
		case 50: return AMMO_SCALE(5);
		default: return 0;
		}
	default: return 0;
	} //end switch
} //end weight


//=============================================
// POWERUPS
//=============================================

weight "holdable_teleporter"
{
	switch(INVENTORY_TELEPORTER)
	{
		case 1:
		{
			switch(INVENTORY_MEDKIT)
			{
				case 1: return POWERUP_SCALE(W_TELEPORTER + 50);
				default: return 0; //already has a medkit
			} //end switch
		} //end case
		default: return 0; //already has a personal teleporter
	} //end switch
} //end weight

weight "holdable_medkit"
{
	switch(INVENTORY_MEDKIT)
	{
		case 1:
		{
			switch(INVENTORY_TELEPORTER)
			{
				case 1: return POWERUP_SCALE(W_MEDKIT + 200);
				default: return 10; //already has a personal teleporter
			} //end switch
		} //end case
		default: return 0; //already has a medkit
	} //end switch
} //end weight

weight "item_quad"
{
	return POWERUP_SCALE(W_QUAD*10);
} //end weight

weight "item_enviro"
{
	return POWERUP_SCALE(W_ENVIRO*10);
} //end weight

weight "item_haste"
{
	return POWERUP_SCALE(W_HASTE);
} //end weight

weight "item_invisibility"
{
	return POWERUP_SCALE(W_INVISIBILITY);
} //end weight

weight "item_regen"
{
	return POWERUP_SCALE(W_REGEN*9);
} //end weight

weight "item_flight"
{
	return 0;//POWERUP_SCALE(W_FLIGHT);
} //end weight

//=============================================
// This is only used to pickup dropped CTF
// flags now. The logic in here makes no
// sense since the bot has specific CTF AI.
//=============================================

weight "team_CTF_redflag" //Red Flag
{
	switch(INVENTORY_REDFLAG)
	{
		case 1: //not carrying the red flag
		{
			switch(INVENTORY_BLUEFLAG)
			{
				case 1: //not carrying the blue flag
				{
					return FLAG_WEIGHT;
				} //end case
				default: //bot carrying the blue flag so go back to the base
				{
					return 200;
				} //end case
			} //end switch
		} //end case
		default: //bot carrying the red flag, so don't go back
		{
			return 0;
		} //end default
	} //end switch
} //end weight

weight "team_CTF_blueflag" //Blue Flag
{
	switch(INVENTORY_BLUEFLAG)
	{
		case 1: //not carrying the blue flag
		{
			switch(INVENTORY_REDFLAG)
			{
				case 1: //not carrying the red flag
				{
					return FLAG_WEIGHT;
				} //end case
				default: //bot is carrying the red flag so go back to the base
				{
					return 200;
				} //end case
			} //end switch
		} //end case
		default: //bot is carrying the blue flag, so don't go back
		{
			return 0;
		} //end default
	} //end switch
} //end weight

//=============================================
// bot roam goal
//=============================================

weight "item_botroam"
{
	return 400;
} //end weight


