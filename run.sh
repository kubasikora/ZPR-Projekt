#!/bin/bash

cd server && python main.py -d&
PIDPY=$!

cd client && npm start&
PIDJS=$!

trap "kill $PIDPY; kill $PIDJS" SIGINT

echo "Press ^C to exit"
sleep infinity