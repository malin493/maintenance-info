//find
			case HEADER_GC_DRAGON_SOUL_REFINE:
				ret = RecvDragonSoulRefine();
				break;
				
//add after
#ifdef MAINTENANCE_INFO
			case HEADER_GC_MAINTENANCE_INFO:
				ret = RecvMaintenanceInfo();
				break;
#endif

//add
#ifdef MAINTENANCE_INFO
bool CPythonNetworkStream::RecvMaintenanceInfo()
{
	TPacketGCMaintenanceInfo pack;
	if (!Recv(sizeof(pack), &pack))
	{
		return false;
	}

	std::vector<char> cause(pack.cause_len);
	if (!Recv(pack.cause_len, &cause[0]))
	{
		return false;
	}

	PyCallClassMemberFunc(m_apoPhaseWnd[PHASE_WINDOW_GAME], "BINARY_Maintenance", Py_BuildValue("(isi)", pack.remaining_time, &cause[0], pack.duration));

	return true;
}
#endif