import ui
import wndMgr
import time
import app
import locale
import chat
import constInfo
import localeInfo

class MaintenanceWindow(ui.ScriptWindow):
	def __init__(self):
		ui.ScriptWindow.__init__(self)
		self.__LoadWindow()
		self.remaining_time = 0
		self.end_time = 0

	def __LoadWindow(self):
		try:
			pyScrLoader = ui.PythonScriptLoader()
			pyScrLoader.LoadScriptFile(self, "UIScript/maintenancewindow.py")
		except:
			import exception
			exception.Abort("MaintenanceWindow.LoadWindow.LoadObject")
		try:
			self.main = {
				"close" : self.GetChild("close"),
				"remaining_time" : self.GetChild("remaining_time"),
				"cause" : self.GetChild("cause"),
				"duration" : self.GetChild("duration"),
			}

		except:
			import exception
			exception.Abort("MaintenanceWindow.LoadWindow.BindObject")
		self.main["close"].SAFE_SetEvent(self.Close)

	def Destroy(self):
		self.Close()
		ui.ScriptWindow.Destroy(self)
		self.main = None

	def Open(self, remaining_time, cause, duration):
		self.end_time = app.GetLocalTime() + remaining_time
		self.remaining_time = self.GetRemainingTime()
		if self.remaining_time == 0:
			self.Close()
			return
		self.__RefreshRemainingTime()
		self.main["cause"].SetText(localeInfo.MAINTENANCE_CAUSE % cause)
		self.main["duration"].SetText(localeInfo.MAINTENANCE_DURATION % localeInfo.SecondToDHMS(duration))
		self.Show()

	def Close(self):
		self.Hide()

	def OnUpdate(self):
		remaining_time = self.GetRemainingTime()
		if remaining_time == self.remaining_time:
			return
		self.remaining_time = remaining_time
		if self.remaining_time <= 0:
			self.Close()
			return
		self.__RefreshRemainingTime()

	def GetRemainingTime(self):
		time = int(self.end_time - app.GetLocalTime())
		if time <= 0:
			return 0
		return time

	def __RefreshRemainingTime(self):
		self.main["remaining_time"].SetText(localeInfo.MAINTENANCE_REMAINING_TIME % localeInfo.SecondToDHMS(self.remaining_time))