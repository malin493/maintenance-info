//find
void DESC_MANAGER::Destroy()
{
	if (m_bDestroyed) {
		return;
	}
	m_bDestroyed = true;
	
//add after
#ifdef MAINTENANCE_INFO
	event_cancel(&m_pMaintenanceEvent);
#endif

//add
#ifdef MAINTENANCE_INFO
EVENTFUNC(maintenance_event)
{
	DESC_MANAGER::Instance().ClearMaintenanceInfo();
	Shutdown(10);
	return 0;
}

bool DESC_MANAGER::BuildClientMaintenance(TEMP_BUFFER& buf)
{
	if (!m_pMaintenanceInfo)
	{
		return false;
	}

	DWORD remaining_time = 0;

	if (m_pMaintenanceInfo->shutdown_time > 0)
	{
		remaining_time = m_pMaintenanceInfo->shutdown_time;
	}

	TPacketGCMaintenanceInfo pack;
	pack.header = HEADER_GC_MAINTENANCE_INFO;
	pack.remaining_time = remaining_time;
	pack.duration = m_pMaintenanceInfo->duration;
	pack.cause_len = strlen(m_pMaintenanceInfo->cause) + 1;
	pack.size = sizeof(pack) + pack.cause_len;
	buf.write(&pack, sizeof(pack));
	buf.write(m_pMaintenanceInfo->cause, pack.cause_len);
	return true;
}

void DESC_MANAGER::SetMaintenanceInfo(const TServerMaintenanceInfo& info)
{
	event_cancel(&m_pMaintenanceEvent);

	if (!m_pMaintenanceInfo)
	{
		m_pMaintenanceInfo = std::unique_ptr<TServerMaintenanceInfo>(new TServerMaintenanceInfo());
	}

	thecore_memcpy(m_pMaintenanceInfo.get(), &info, sizeof(TServerMaintenanceInfo));

	DWORD remaining_time = 0;

	if (info.shutdown_time > 0)
	{
		remaining_time = info.shutdown_time;
		m_pMaintenanceEvent = event_create(maintenance_event, AllocEventInfo<event_info_data>(), PASSES_PER_SEC(remaining_time));
	}

	TEMP_BUFFER buf;
	BuildClientMaintenance(buf);

	for (auto desc : m_set_pkDesc)
	{
		if (desc->IsPhase(PHASE_GAME) || desc->IsPhase(PHASE_DEAD))
		{
			desc->Packet(buf.read_peek(), buf.size());
		}
	}
}

void DESC_MANAGER::SendMaintenanceInfo(LPDESC desc)
{
	TEMP_BUFFER buf;
	if (!BuildClientMaintenance(buf))
	{
		return;
	}
	desc->Packet(buf.read_peek(), buf.size());
}

void DESC_MANAGER::ClearMaintenanceInfo()
{
	SetMaintenanceInfo(TServerMaintenanceInfo());
}
#endif