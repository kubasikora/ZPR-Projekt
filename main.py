from flask import Flask, Response, request
from config import DevConfig, ProdConfig
from scada import MeasurementController

app = Flask(__name__)
app.config.from_object(DevConfig)

@app.route('/measurement')
def home():
    return Response(MeasurementController().postNewMeasurement(request.form))

if __name__ == '__main__':
    app.run()
