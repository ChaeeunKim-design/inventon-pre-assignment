import serial
import time

ser = serial.Serial('/dev/ttyS0', 9600, timeout=1)
time.sleep(2)  # 연결 안정화

while True:
    ser.write(b'ON\n')      # LED ON 신호 전송
    print("LED ON 전송")
    time.sleep(2)

    ser.write(b'OFF\n')     # LED OFF 신호 전송
    print("LED OFF 전송")
    time.sleep(2)
