//add
#ifdef MAINTENANCE_INFO
#include "packet.h"
#include "buffer_manager.h"
#endif

//find
		bool			IsP2PDescExist(const char * szHost, WORD wPort);
		
//add after
#ifdef MAINTENANCE_INFO
		bool 			BuildClientMaintenance(TEMP_BUFFER& buf);
		void 			SetMaintenanceInfo(const TServerMaintenanceInfo& info);
		void 			SendMaintenanceInfo(LPDESC desc);
		void 			ClearMaintenanceInfo();
		const TServerMaintenanceInfo* GetMaintenanceInfo() const { return m_pMaintenanceInfo.get(); }
#endif

//find
		bool			m_bDestroyed;
		
//add after
#ifdef MAINTENANCE_INFO
		std::unique_ptr<TServerMaintenanceInfo>	m_pMaintenanceInfo;
		LPEVENT m_pMaintenanceEvent;
#endif