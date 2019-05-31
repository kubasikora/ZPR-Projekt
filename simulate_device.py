import requests 
import random
import json
import time
import sys

DEVICE_ID = sys.argv[1]
DEVICE_OPERATING_POINT = float(sys.argv[2])
DEVICE_SAMPLING_TIME = float(sys.argv[3])
SCADA_SERVER_URL = "http://localhost:5000"

time.sleep(20)

SIGMA = DEVICE_OPERATING_POINT/100
while True:
    payload = {
        "deviceId": DEVICE_ID,
        "value": DEVICE_OPERATING_POINT + random.gauss(0, SIGMA)
    }
    try:
        r = requests.post(SCADA_SERVER_URL + "/measurement", data=payload)
    except:
        print("Device {0} finished its job".format(DEVICE_ID))
        exit(0)
    time.sleep(DEVICE_SAMPLING_TIME)
