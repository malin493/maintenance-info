#add
def SecondToDHMS(time, ignoreSecTime = -1, useShortName = True):
	text = ""
	if time < 0:
		time *= -1
		text = "-"

	second = int(time % 60)
	minute = int((time / 60) % 60)
	hour = int(((time / 60) / 60) % 24)
	day = int(((time / 60) / 60) / 24)

	if ignoreSecTime > 0 and time >= ignoreSecTime:
		second = 0

	if day > 0:
		if day == 1:
			text += str(day) + " dzień "
		else:
			text += str(day) + " dni "

	if hour > 0:
		text += str(hour) + " "
		if useShortName == True:
			text += "godz. "

	if minute > 0:
		text += str(minute) + " "
		if useShortName == True:
			text += "min. "

	if second > 0 or (day == 0 and hour == 0 and minute == 0):
		text += str(second) + " "
		if useShortName == True:
			text += "sek. "

	return text[:-1]