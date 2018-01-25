#!/usr/bin/python3
import time
import Adafruit_DHT

DHT_TYPE = Adafruit_DHT.DHT11                                                           
DHT_PIN = 4

# humidity, temperature = Adafruit_DHT.read_retry(sensor, pin)

while True:
    humidity, temp = Adafruit_DHT.read(DHT_TYPE, DHT_PIN)

    if humidity is None or temp is None:
        time.sleep(2)
        continue

    
    print('Temperature: {0:0.1f} C'.format(temp))
    print('Humidity:    {0:0.1f} %'.format(humidity))

    time.sleep(3)
