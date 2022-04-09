//add
#ifdef MAINTENANCE_INFO
ACMD(do_maintenance)
{
	char arg1[256], arg2[256], arg3[256];
	one_argument(two_arguments(argument, arg1, sizeof(arg1), arg2, sizeof(arg2)), arg3, sizeof(arg3));

	if (!*arg1)
	{
		if (ch)
		{
			ch->ChatPacket(CHAT_TYPE_INFO, "Use:");
			ch->ChatPacket(CHAT_TYPE_INFO, "	 Start: maintenance <shutdown time> <cause> <duration in seconds>");
			ch->ChatPacket(CHAT_TYPE_INFO, "	 Cancel: maintenance 0");
		}
		return;
	}

	TPacketGGMaintenanceInfo pack;
	pack.header = HEADER_GG_MAINTENANCE_INFO;
	TServerMaintenanceInfo info;
	memset(&info, 0, sizeof(info));
	str_to_number(info.shutdown_time, arg1);

	if (info.shutdown_time > 0)
	{
		strlcpy(info.cause, arg2, sizeof(info.cause) - 1);
		str_to_number(info.duration, arg3);
	}

	pack.info = info;
	P2P_MANAGER::Instance().Send(&pack, sizeof(pack));
	DESC_MANAGER::Instance().SetMaintenanceInfo(info);
}
#endif