import redis
from time import sleep
r = redis.StrictRedis(host='localhost', port=6379, db=0)
pub = r.pubsub()
pub.subscribe("random")
while True:
    viesti = pub.get_message()
    if viesti != None:
        print viesti["channel"]
        print viesti["data"]
    sleep(1)
