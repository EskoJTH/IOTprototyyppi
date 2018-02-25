import paho.mqtt.client as mqtt

address = "localhost"
topic = "testi"
message = "kirahvi"

client = mqtt.Client()
client.connect(address)
client.publish(topic, message)
client.disconnect()
