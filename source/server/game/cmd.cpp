//find
struct command_info cmd_info[] =

//add before
#ifdef MAINTENANCE_INFO
ACMD(do_maintenance);
#endif

//find
	{ "\n",						NULL,						0,				POS_DEAD,		GM_IMPLEMENTOR	}
	
//add before
#ifdef MAINTENANCE_INFO
	{ "maintenance", 			do_maintenance, 			0, 				POS_DEAD, 		GM_IMPLEMENTOR 	},
#endif