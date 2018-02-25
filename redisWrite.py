import redis
import random
from time import sleep
r = redis.StrictRedis(host='localhost', port=6379, db=0)
while True:
    x = random.random()
    r.publish("random",str(x))
    sleep(10)












