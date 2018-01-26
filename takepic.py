#!/usr/bin/python3
import picamera
import RPi.GPIO
import datetime

camera = picamera.PiCamera()
camera.resolution = (100, 100)
stamp = str(datetime.datetime.now())
camera.capture("imageAt " + stamp + ".jpg")
