#!/bin/bash

python main.py&
PIDPY=$!

cd client && npm start&
PIDJS=$!

trap "kill $PIDPY; kill $PIDJS" SIGINT

echo "Press ^C to exit"
sleep infinity