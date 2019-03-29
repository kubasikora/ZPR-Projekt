from flask import Flask, Response
from config import DevConfig, ProdConfig
from scada import MeasurementController

app = Flask(__name__)
app.config.from_object(DevConfig)

@app.route('/')
def home():
    return Response(MeasurementController().postNewMeasurement())

if __name__ == '__main__':
    app.run()
