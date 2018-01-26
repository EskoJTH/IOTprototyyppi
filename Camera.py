import picamera
import RPi.GPIO
from time import sleep

camera = picamera.PiCamera()
camera.resolution = (100, 100)
RPi.GPIO.setmode(RPi.GPIO.BCM)

pin = 4
RPi.GPIO.setup(pin, RPi.GPIO.IN, pull_up_down=RPi.GPIO.PUD_DOWN)

value = 0
i = 0

try:
    while True:
        value = RPi.GPIO.input(pin)
        print(value)
        if value:
            camera.start_preview()
            camera.start_recording("videota" + str(i) + ".h264")
            i=i+1

        
            while value:
                sleep(1)
                value = RPi.GPIO.input(pin)


            camera.stop_recording()
            camera.stop_preview()
        sleep(1)

except KeyboardInterrupt:
    pass
finally:
    print("exit succesfull")
    RPi.GPIO.cleanup()
