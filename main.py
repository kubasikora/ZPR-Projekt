from flask import Flask, Response, request
from config import DevConfig, ProdConfig
from scada import MeasurementController

app = Flask(__name__)
app.config.from_object(DevConfig)

db = {
    "host": "localhost",
    "user": "zpr",
    "password": "zpr",
    "port": "5432"
}

@app.route('/measurement')
def home():
    return Response(MeasurementController(db).postNewMeasurement(request.form))

if __name__ == '__main__':
    app.run()
