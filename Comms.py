#!/usr/bin/env python3
 
import serial
import sys


ser = serial.Serial()
ser.baudrate = 9600
ser.port = "/dev/rfcomm0"

ser.timeout = 10        # 10 second timeout
ser.open()

'''if ser.isOpen():
    print('Port ' + ser.portstr + ' open.')
else: 
    print('Port ' + ser.portstr + ' not open.')'''

message = sys.argv[1]
ser.write(message.encode())

ser.close()
