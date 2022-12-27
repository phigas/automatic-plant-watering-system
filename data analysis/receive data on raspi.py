import time
import serial

ser = serial.Serial(
    port='/dev/ttyUSB0',
    baudrate=9600,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS,
    timeout=1
)

file = 'log.txt' # or use complete path

current_time = time.strftime('%m:%d:%H:%M:%S', time.localtime())
with open(file, 'a') as f:
    f.write(current_time + ',startlogging\n')
    
while 1:
    x = ser.readline()
    x = x.decode()
    x = x.strip('\n')
    x = x.strip('\t')
    
    if x:
        current_time = time.strftime('%m:%d:%H:%M:%S', time.localtime())
        x = current_time + ',' + x
        with open(file, 'a') as f:
            f.write(x)