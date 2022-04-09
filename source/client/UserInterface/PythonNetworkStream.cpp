//find
			Set(HEADER_GC_DRAGON_SOUL_REFINE,		CNetworkPacketHeaderMap::TPacketType(sizeof(TPacketGCDragonSoulRefine), STATIC_SIZE_PACKET));
			
//add after
#ifdef MAINTENANCE_INFO
			Set(HEADER_GC_MAINTENANCE_INFO, CNetworkPacketHeaderMap::TPacketType(sizeof(TPacketGCMaintenanceInfo), DYNAMIC_SIZE_PACKET));
#endif