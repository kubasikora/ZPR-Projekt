from flask import Flask, Response, request
from config import DevConfig, ProdConfig
from scada import MeasurementController, SerializeDataController, StateController
import os, sys
import json

app = Flask(__name__)
if len(sys.argv) > 1 and sys.argv[1] == '-d':
    Config = DevConfig()
else:
    Config = ProdConfig()

db = {
    "host": Config.DB_HOST,
    "user": Config.DB_USER,
    "password": Config.DB_PASSWORD,
    "port": Config.DB_PORT
}

app.config.from_object(Config)

@app.route('/measurement', methods = ['POST'])
def measurement():
    controller = MeasurementController(db)
    response = controller.postNewMeasurement(request.form)
    statusCode = controller.getStatusCode()
    return Response(response=response, status=statusCode)

@app.route('/getSerializedData', methods = ['GET'])
def getSerializedData():
    controller = SerializeDataController(db)
    response = json.dumps(controller.getSerializedData(request.args))
    statusCode = controller.getStatusCode()
    return Response(response=response, status=statusCode)

@app.route('/state', methods = ['GET'])
def state():
    controller = StateController()
    response = json.dumps(controller.getState())
    statusCode = controller.getStatusCode()
    return Response(response=response, status=statusCode)

if __name__ == '__main__':
    app.run(threaded=True)
