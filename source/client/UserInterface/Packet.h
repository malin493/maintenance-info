//find
	HEADER_GC_RESPOND_CHANNELSTATUS				= 210,
	
//add after
#ifdef MAINTENANCE_INFO
	HEADER_GC_MAINTENANCE_INFO					= 211,
#endif

//find
#pragma pack(pop)

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
#endif