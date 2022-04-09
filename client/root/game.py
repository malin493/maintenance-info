#add
	if app.MAINTENANCE_INFO:
		def BINARY_Maintenance(self, remaining_time, cause, duration):
			self.interface.OpenMaintenance(remaining_time, cause, duration)