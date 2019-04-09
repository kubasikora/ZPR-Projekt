from flask import Flask, Response, request
from config import DevConfig, ProdConfig
from scada import MeasurementController, SerializeDataController, StateController
import os
import json

app = Flask(__name__)
if os.environ.get("DEBUG"):
    app.config.from_object(DevConfig)
else:
    app.config.from_object(ProdConfig)

with open(app.config['DB_PASS']) as db_pass:
	db = json.load(db_pass)

@app.route('/measurement', methods = ['POST'])
def measurement():
    controller = MeasurementController(db)
    response = controller.postNewMeasurement(request.form)
    statusCode = controller.getStatusCode()
    return Response(response=response, status=statusCode)

@app.route('/getSerializedData', methods = ['GET'])
def getSerializedData():
    controller = SerializeDataController(db)
    response = controller.getSerializedData(request.args)
    statusCode = controller.getStatusCode()
    return Response(response=response, status=statusCode)

if __name__ == '__main__':
    app.run(threaded=True)
