import paho.mqtt.client as mqtt
import time

address = "localhost"
topic = "testi"

def on_message(client1, userdata, message):
    print("Message received", str(message.payload.decode("utf-8")))
    
def on_connect(client, userdata, flags, rc):
    client.subscribe(topic)

client = mqtt.Client()
client.on_message = on_message
time.sleep(1)

client.connect(address)
client.loop_start()
client.subscribe(topic)

time.sleep(20)
client.disconnect()
client.loop_stop




