//find
	CGuildManager::instance().LoginMember(ch);
	
//add after
#ifdef MAINTENANCE_INFO
	DESC_MANAGER::Instance().SendMaintenanceInfo(ch->GetDesc());
#endif