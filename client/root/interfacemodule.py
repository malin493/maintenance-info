#add
if app.MAINTENANCE_INFO:
	import uimaintenance
	
#find
		self.wndGuildBuilding = None
		
#add after
		if app.MAINTENANCE_INFO:
			self.wndMaintenance = None
			
#find
		if self.wndItemSelect:
			self.wndItemSelect.Destroy()
			
#add after
		if app.MAINTENANCE_INFO:
			if self.wndMaintenance:
				self.wndMaintenance.Hide()
				self.wndMaintenance.Destroy()
				
#find
		del self.wndItemSelect

#add after
		if app.MAINTENANCE_INFO:
			del self.wndMaintenance
			
#add
	if app.MAINTENANCE_INFO:
		def OpenMaintenance(self, remaining_time, cause, duration):
			if not self.wndMaintenance:
				self.wndMaintenance = uimaintenance.MaintenanceWindow()
			self.wndMaintenance.Open(remaining_time, cause, duration)