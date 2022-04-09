//find
int CInputP2P::Analyze(LPDESC d, BYTE bHeader, const char * c_pData)
{
	[...]
}

//add before
#ifdef MAINTENANCE_INFO
void CInputP2P::MaintenanceInfo(const char* c_pData)
{
	TPacketGGMaintenanceInfo* p = (TPacketGGMaintenanceInfo*) c_pData;
	DESC_MANAGER::Instance().SetMaintenanceInfo(p->info);
}
#endif

//find
		case HEADER_GG_CHECK_AWAKENESS:
			IamAwake(d, c_pData);
			break;
			
//add after
#ifdef MAINTENANCE_INFO
		case HEADER_GG_MAINTENANCE_INFO:
			MaintenanceInfo(c_pData);
			break;
#endif