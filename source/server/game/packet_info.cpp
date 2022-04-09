//find
	Set(HEADER_GG_CHECK_AWAKENESS,			sizeof(TPacketGGCheckAwakeness),	"CheckAwakeness",		false);
	
//add after
#ifdef MAINTENANCE_INFO
	Set(HEADER_GG_MAINTENANCE_INFO, 		sizeof(TPacketGGMaintenanceInfo),	"MaintenanceInfo", 		false);
#endif