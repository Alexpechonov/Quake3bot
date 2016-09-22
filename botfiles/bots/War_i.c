#include "inv.h"

//initial health/armor states
#define FS_HEALTH			2
#define FS_ARMOR			2

//initial weapon weights
#define W_SHOTGUN				50
#define W_MACHINEGUN			70
#define W_GRENADELAUNCHER		40
#define W_ROCKETLAUNCHER		220
#define W_RAILGUN				585
#define W_BFG10K				130
#define W_LIGHTNING				150
#define W_PLASMAGUN				150

//the bot has the weapons, so the weights change a little bit
#define GWW_SHOTGUN				35
#define GWW_MACHINEGUN			50
#define GWW_GRENADELAUNCHER		30
#define GWW_ROCKETLAUNCHER		90
#define GWW_RAILGUN				525
#define GWW_BFG10K				141
#define GWW_LIGHTNING			140
#define GWW_PLASMAGUN			140

//initial powerup weights
#define W_TELEPORTER			50
#define W_MEDKIT				300
#define W_QUAD					400
#define W_ENVIRO				400
#define W_HASTE					100
#define W_INVISIBILITY			100
#define W_REGEN					400
#define W_FLIGHT				40

//flag weight
#define FLAG_WEIGHT				50

//
#include "bots/War/fw_items.c"

