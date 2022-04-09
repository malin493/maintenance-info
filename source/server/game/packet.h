//find
	HEADER_GC_RESPOND_CHANNELSTATUS				= 210,
	
//add after
#ifdef MAINTENANCE_INFO
	HEADER_GC_MAINTENANCE_INFO					= 211,
#endif

//find
	HEADER_GG_CHECK_AWAKENESS			= 29,
	
//add after
#ifdef MAINTENANCE_INFO
	HEADER_GG_MAINTENANCE_INFO			= 30,
#endif

//find
#pragma pack()

//add before
#ifdef MAINTENANCE_INFO
typedef struct SPacketGCMaintenanceInfo
{
	BYTE header;
	WORD size;
	DWORD remaining_time;
	BYTE cause_len;
	DWORD duration;
} TPacketGCMaintenanceInfo;

typedef struct SServerMaintenanceInfo
{
	SServerMaintenanceInfo()
	{
		shutdown_time = 0;
		cause[0] = '\0';
		duration = 0;
	}

	DWORD shutdown_time;
	char cause[100];
	DWORD duration;
} TServerMaintenanceInfo;

typedef struct SPacketGGMaintenanceInfo
{
	BYTE header;
	TServerMaintenanceInfo info;
} TPacketGGMaintenanceInfo;
#endif