#!/bin/bash

cd server && python main.py -d&
PIDPY=$!

cd client && npm start&
PIDJS=$!

python3 simulate_device.py 1 25.00 1.0 &
PIDDEV1=$!

python3 simulate_device.py 2 2400 2.0 &
PIDDEV2=$!

python3 simulate_device.py 3 0.32 0.50 &
PIDDEV3=$!

python3 simulate_device.py 4 39 1.00 &
PIDDEV4=$!


trap "kill $PIDPY; kill $PIDJS; kill $PIDDEV1; kill $PIDDEV2; kill $PIDDEV3; kill $PIDDEV4;"SIGINT

echo "Press ^C to exit"
sleep infinity