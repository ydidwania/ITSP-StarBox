import serial

arduino=serial.Serial('/dev/ttyACM1',9600)

while(True):
	data=raw_input("Enter what you want to see on the Star-Box \n")
	for i in range(0,len(data)):
		arduino.write(data[i])
	arduino.write(' ')
	repeat=raw_input("Once more?? (Y/N)")
	if(repeat=="n" or repeat=="N"):
		break

print "Thanks for visiting!! Have a nice day.."
